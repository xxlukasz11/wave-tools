#pragma once

#include <cstdint>
#include "parameter.h"

class SampleRate : public Parameter<uint32_t> {
public:
	static const SampleRate FREQ_22050Hz;
	static const SampleRate FREQ_44100Hz;
	static const SampleRate FREQ_48000Hz;
	static const SampleRate FREQ_88200Hz;
	static const SampleRate FREQ_96000Hz;
	static const SampleRate FREQ_176400Hz;
	static const SampleRate FREQ_192000Hz;
	static const SampleRate FREQ_384000Hz;

private:
	SampleRate(const uint32_t sampleRate);
};

