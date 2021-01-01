#include "bitsPerSample.h"

BitsPerSample::BitsPerSample(const uint16_t bitsPerSample) : Parameter(bitsPerSample) {
}

const BitsPerSample BitsPerSample::BITS_8{ 8 };
const BitsPerSample BitsPerSample::BITS_16{ 16 };
const BitsPerSample BitsPerSample::BITS_24{ 24 };
const BitsPerSample BitsPerSample::BITS_32{ 32 };