#pragma once

#include "duration.h"
#include <cstdint>

class DurationHandler {
public:
	DurationHandler();
	void setDuration(const Duration& duration);
	void setNoOfPeriods(const unsigned int noOfPeriods);
	void setNoOfSamples(const unsigned int noOfSamples);

	uint64_t calculateNoOfSamples(const uint32_t sampleRate, const uint32_t signalFrequency) const;

private:
	enum class Mode {
		DURATION,
		PERIODS,
		SAMPLES
	};

	Mode mMode;
	Duration mDuration;
	unsigned int mNoOfPeriods;
	unsigned int mNoOfSamples;
};

