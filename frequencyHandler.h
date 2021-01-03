#pragma once

#include "frequency.h"
#include "duration.h"

class FrequencyHandler {
public:
	FrequencyHandler();
	void setFrequency(const Frequency& frequency);
	void setPeriod(const Duration& duration);

private:
	Frequency mFrequency;
};

