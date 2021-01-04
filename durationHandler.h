#pragma once

#include "duration.h"
#include <cstdint>

class DurationHandler {
public:
	DurationHandler();
	void setDuration(const Duration& duration);
	void setNoOfPeriods(const uint32_t noOfPeriods);
	void setNoOfSamples(const uint32_t noOfSamples);

	uint32_t calculateNoOfSamples(const uint32_t sampleRate, const uint32_t signalFrequency) const;

private:
	enum class Mode {
		DURATION,
		PERIODS,
		SAMPLES
	};

	Mode mMode;
	Duration mDuration;
	uint32_t mNoOfPeriods;
	uint32_t mNoOfSamples;
};

