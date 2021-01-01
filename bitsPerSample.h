#pragma once

#include "parameter.h"
#include <cstdint>

class BitsPerSample : public Parameter<uint16_t> {
public:
	static const BitsPerSample BITS_8;
	static const BitsPerSample BITS_16;
	static const BitsPerSample BITS_24;
	static const BitsPerSample BITS_32;

private:
	BitsPerSample(const uint16_t bitsPerSample);
};

