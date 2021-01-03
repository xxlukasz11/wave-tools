#pragma once

#include "duration.h"

class DurationHandler {
public:
	enum class Mode {
		DURATION,
		PERIODS,
		SAMPLES
	};
	
	DurationHandler();
	Mode getMode() const;
	void setDuration(const Duration& duration);
	void setNoOfPeriods(const unsigned int noOfPeriods);
	void setNoOfSamples(const unsigned int noOfSamples);

	Duration getDuration() const;
	unsigned int getNoOfPeriods() const;
	unsigned int getNoOfSamples() const;

private:
	Mode mMode;
	Duration mDuration;
	unsigned int mNoOfPeriods;
	unsigned int mNoOfSamples;
};

