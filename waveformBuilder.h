#pragma once

#include <cstdint>
#include "waveFile.h"
#include "dataBuffer.h"
#include "durationHandler.h"
#include "frequencyHandler.h"
#include "amplitudeHandler.h"

template<typename T>
class WaveformBuilder {
public:
	T& setAmplitudeByValue(const uint64_t value);
	T& setAmplitudeByPercentage(const double percentage);
	T& setDuration(const Duration& duration);
	T& setDurationByNoOfPeriods(const unsigned int noOfPeriods);
	T& setDurationByNoOfSamples(const unsigned int noOfSamples);
	T& setFrequency(const Frequency& frequency);
	T& setPeriod(const Duration& period);

	T& appendWaveformToFile(WaveFile& waveFile);

protected:
	const DurationHandler& getDurationHandler() const;
	const FrequencyHandler& getFrequencyHandler() const;
	const AmplitudeHandler& getAmplitudeHandler() const;

private:
	virtual uint64_t calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude,
		const uint32_t frequency, const uint32_t sampleRate) const = 0;

	DataBuffer generateWaveform(const FmtSubChunk& fmtSubChunk) const;
	void appendForEveryChannel(DataBuffer& buffer, const uint64_t value,
		const int numChannels, const int bytesPerSample) const;

	T& self();

	DurationHandler mDurationHandler;
	FrequencyHandler mFrequencyHandler;
	AmplitudeHandler mAmplitudeHandler;
};

template<typename T>
const DurationHandler& WaveformBuilder<T>::getDurationHandler() const {
	return mDurationHandler;
}

template<typename T>
const FrequencyHandler& WaveformBuilder<T>::getFrequencyHandler() const {
	return mFrequencyHandler;
}

template<typename T>
const AmplitudeHandler& WaveformBuilder<T>::getAmplitudeHandler() const {
	return mAmplitudeHandler;
}

template<typename T>
T& WaveformBuilder<T>::setAmplitudeByValue(const uint64_t value) {
	mAmplitudeHandler.setValue(value);
	return self();
}

template<typename T>
T& WaveformBuilder<T>::setAmplitudeByPercentage(const double percentage) {
	mAmplitudeHandler.setPercentage(percentage);
	return self();
}

template<typename T>
T& WaveformBuilder<T>::setDuration(const Duration& duration) {
	mDurationHandler.setDuration(duration);
	return self();
}

template<typename T>
T& WaveformBuilder<T>::setDurationByNoOfPeriods(const unsigned int noOfPeriods) {
	mDurationHandler.setNoOfPeriods(noOfPeriods);
	return self();
}

template<typename T>
T& WaveformBuilder<T>::setDurationByNoOfSamples(const unsigned int noOfSamples) {
	mDurationHandler.setNoOfSamples(noOfSamples);
	return self();
}

template<typename T>
T& WaveformBuilder<T>::setFrequency(const Frequency& frequency) {
	mFrequencyHandler.setFrequency(frequency);
	return self();
}

template<typename T>
T& WaveformBuilder<T>::setPeriod(const Duration& period) {
	mFrequencyHandler.setPeriod(period);
	return self();
}

template<typename T>
T& WaveformBuilder<T>::appendWaveformToFile(WaveFile& waveFile) {
	DataBuffer waveform = generateWaveform(waveFile.getFmtSubChunk());
	waveFile.addData(std::move(waveform));
	return self();
}

template<typename T>
DataBuffer WaveformBuilder<T>::generateWaveform(const FmtSubChunk& fmtSubChunk) const {
	const auto bitsPerSample = fmtSubChunk.getBitsPerSample();
	const auto blockAlign = fmtSubChunk.getBlockAlign();
	const auto sampleRate = fmtSubChunk.getSampleRate();
	const auto numChannels = fmtSubChunk.getNumChannels();
	const auto frequency = mFrequencyHandler.getFrequency().hertz();
	const auto noOfSamples = mDurationHandler.calculateNoOfSamples(sampleRate, frequency);
	const auto amplitude = mAmplitudeHandler.calculateAmplitude(bitsPerSample);
	const auto offset = mAmplitudeHandler.calculateOffset(bitsPerSample);
	const auto bytesPerSample = bitsPerSample / 8;

	DataBuffer buffer(noOfSamples * blockAlign);
	for (uint64_t timeIndex = 0; timeIndex < noOfSamples; ++timeIndex) {
		const uint64_t value = offset + calculateSampleValue(timeIndex, amplitude, frequency, sampleRate);
		appendForEveryChannel(buffer, value, numChannels, bytesPerSample);
	}
	return buffer;
}

template<typename T>
void WaveformBuilder<T>::appendForEveryChannel(DataBuffer& buffer,
	const uint64_t value, const int numChannels, const int bytesPerSample) const {
	constexpr uint8_t BYTE_MASK = 0xff;
	for (int channel = 0; channel < numChannels; ++channel) {
		for (int byteIndex = 0; byteIndex < bytesPerSample; ++byteIndex) {
			buffer.append((value >> (byteIndex * 8)) & BYTE_MASK);
		}
	}
}

template<typename T>
inline T& WaveformBuilder<T>::self() {
	return static_cast<T&>(*this);
}