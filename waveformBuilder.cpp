#include "waveformBuilder.h"

WaveformBuilder& WaveformBuilder::appendWaveformToFile(WaveFile& waveFile) {
	DataBuffer data = generateWaveform(waveFile.getFmtSubChunk().getBitsPerSample());
	// TODO swap endianess
	return *this;
}

const DurationHandler& WaveformBuilder::getDurationHandler() const {
	return mDurationHandler;
}

const FrequencyHandler& WaveformBuilder::getFrequencyHandler() const {
	return mFrequencyHandler;
}

const AmplitudeHandler& WaveformBuilder::getAmplitudeHandler() const {
	return mAmplitudeHandler;
}

WaveformBuilder& WaveformBuilder::setAmplitudeByValue(const uint64_t value) {
	mAmplitudeHandler.setValue(value);
	return *this;
}

WaveformBuilder& WaveformBuilder::setAmplitudeByPercentage(const double percentage) {
	mAmplitudeHandler.setPercentage(percentage);
	return *this;
}

WaveformBuilder& WaveformBuilder::setDuration(const Duration& duration) {
	mDurationHandler.setDuration(duration);
	return *this;
}

WaveformBuilder& WaveformBuilder::setDurationByNoOfPeriods(const unsigned int noOfPeriods) {
	mDurationHandler.setNoOfPeriods(noOfPeriods);
	return *this;
}

WaveformBuilder& WaveformBuilder::setDurationByNoOfSamples(const unsigned int noOfSamples) {
	mDurationHandler.setNoOfSamples(noOfSamples);
	return *this;
}

WaveformBuilder& WaveformBuilder::setFrequency(const Frequency& frequency) {
	mFrequencyHandler.setFrequency(frequency);
	return *this;
}

WaveformBuilder& WaveformBuilder::setPeriod(const Duration& period) {
	mFrequencyHandler.setPeriod(period);
	return *this;
}
