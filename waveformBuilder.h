#pragma once

#include <cstdint>
#include "waveFile.h"
#include "dataBuffer.h"
#include "durationHandler.h"
#include "frequencyHandler.h"
#include "amplitudeHandler.h"

class WaveformBuilder {
public:
	WaveformBuilder& setAmplitudeByValue(const uint64_t value);
	WaveformBuilder& setAmplitudeByPercentage(const double percentage);
	WaveformBuilder& setDuration(const Duration& duration);
	WaveformBuilder& setDurationByNoOfPeriods(const unsigned int noOfPeriods);
	WaveformBuilder& setDurationByNoOfSamples(const unsigned int noOfSamples);
	WaveformBuilder& setFrequency(const Frequency& frequency);
	WaveformBuilder& setPeriod(const Duration& period);

	WaveformBuilder& appendWaveformToFile(WaveFile& waveFile);

protected:
	const DurationHandler& getDurationHandler() const;
	const FrequencyHandler& getFrequencyHandler() const;
	const AmplitudeHandler& getAmplitudeHandler() const;

private:
	virtual DataBuffer generateWaveform(const uint16_t bitsPerSample) const = 0;

	DurationHandler mDurationHandler;
	FrequencyHandler mFrequencyHandler;
	AmplitudeHandler mAmplitudeHandler;
};

