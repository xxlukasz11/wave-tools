#include "sineWaveformBuilder.h"

constexpr double PI = 3.14159265358979323846;

SineWaveformBuilder SineWaveformBuilder::newBuilder() {
    return SineWaveformBuilder();
}

int64_t SineWaveformBuilder::calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude,
    const uint32_t frequency, const uint32_t sampleRate) const {
    return static_cast<uint64_t>(amplitude * sin(2 * PI * frequency / sampleRate * timeIndex));
}
