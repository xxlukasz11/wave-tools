#pragma once

#include <cstdint>
#include "WaveformBuilder.h"
#include "dataBuffer.h"
#include "durationHandler.h"
#include "frequencyHandler.h"
#include "amplitudeHandler.h"

template<typename T>
class WaveformBuilderBase : public WaveformBuilder {
public:
	T& setAmplitudeByValue(const uint64_t value);
	T& setAmplitudeByPercentage(const double percentage);
	T& setDuration(const Duration& duration);
	T& setDurationByNoOfPeriods(const uint32_t noOfPeriods);
	T& setDurationByNoOfSamples(const uint32_t noOfSamples);
	T& setFrequency(const Frequency& frequency);
	T& setPeriod(const Duration& period);

	void appendWaveformToFile(WaveFile& waveFile) const override;

protected:
	const DurationHandler& getDurationHandler() const;
	const FrequencyHandler& getFrequencyHandler() const;
	const AmplitudeHandler& getAmplitudeHandler() const;

private:
	virtual int64_t calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude,
		const uint32_t frequency, const uint32_t sampleRate) const = 0;

	DataBuffer generateWaveform(const FmtSubChunk& fmtSubChunk) const;
	void appendForEveryChannel(DataBuffer& buffer, const int64_t value,
		const int numChannels, const int bytesPerSample) const;

	T& self();

	DurationHandler mDurationHandler;
	FrequencyHandler mFrequencyHandler;
	AmplitudeHandler mAmplitudeHandler;
};

template<typename T>
const DurationHandler& WaveformBuilderBase<T>::getDurationHandler() const {
	return mDurationHandler;
}

template<typename T>
const FrequencyHandler& WaveformBuilderBase<T>::getFrequencyHandler() const {
	return mFrequencyHandler;
}

template<typename T>
const AmplitudeHandler& WaveformBuilderBase<T>::getAmplitudeHandler() const {
	return mAmplitudeHandler;
}

template<typename T>
T& WaveformBuilderBase<T>::setAmplitudeByValue(const uint64_t value) {
	mAmplitudeHandler.setValue(value);
	return self();
}

template<typename T>
T& WaveformBuilderBase<T>::setAmplitudeByPercentage(const double percentage) {
	mAmplitudeHandler.setPercentage(percentage);
	return self();
}

template<typename T>
T& WaveformBuilderBase<T>::setDuration(const Duration& duration) {
	mDurationHandler.setDuration(duration);
	return self();
}

template<typename T>
T& WaveformBuilderBase<T>::setDurationByNoOfPeriods(const uint32_t noOfPeriods) {
	mDurationHandler.setNoOfPeriods(noOfPeriods);
	return self();
}

template<typename T>
T& WaveformBuilderBase<T>::setDurationByNoOfSamples(const uint32_t noOfSamples) {
	mDurationHandler.setNoOfSamples(noOfSamples);
	return self();
}

template<typename T>
T& WaveformBuilderBase<T>::setFrequency(const Frequency& frequency) {
	mFrequencyHandler.setFrequency(frequency);
	return self();
}

template<typename T>
T& WaveformBuilderBase<T>::setPeriod(const Duration& period) {
	mFrequencyHandler.setPeriod(period);
	return self();
}

template<typename T>
void WaveformBuilderBase<T>::appendWaveformToFile(WaveFile& waveFile) const {
	DataBuffer waveform = generateWaveform(waveFile.getFmtSubChunk());
	waveFile.addData(std::move(waveform));
}

template<typename T>
DataBuffer WaveformBuilderBase<T>::generateWaveform(const FmtSubChunk& fmtSubChunk) const {
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
		const int64_t value = offset + calculateSampleValue(timeIndex, amplitude, frequency, sampleRate);
		appendForEveryChannel(buffer, value, numChannels, bytesPerSample);
	}
	return buffer;
}

template<typename T>
void WaveformBuilderBase<T>::appendForEveryChannel(DataBuffer& buffer,
	const int64_t value, const int numChannels, const int bytesPerSample) const {
	constexpr uint8_t BYTE_MASK = 0xff;
	for (int channel = 0; channel < numChannels; ++channel) {
		for (int byteIndex = 0; byteIndex < bytesPerSample; ++byteIndex) {
			buffer.append((value >> (byteIndex * 8)) & BYTE_MASK);
		}
	}
}

template<typename T>
inline T& WaveformBuilderBase<T>::self() {
	return static_cast<T&>(*this);
}
