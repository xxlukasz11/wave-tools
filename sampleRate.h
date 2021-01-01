#pragma once

#include <cstdint>
#include "parameter.h"

class SampleRate : public Parameter<uint32_t> {
public:
	static const SampleRate FREQ_44100kHz;
	static const SampleRate FREQ_96000kHz;

private:
	SampleRate(const uint32_t sampleRate);
};

