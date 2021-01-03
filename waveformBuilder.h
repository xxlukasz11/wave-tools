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
	virtual DataBuffer generateWaveform(const FmtSubChunk& fmtSubChunk) const = 0;
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
inline T& WaveformBuilder<T>::self() {
	return static_cast<T&>(*this);
}