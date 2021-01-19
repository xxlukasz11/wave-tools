#include "triangleWaveformBuilder.h"

constexpr double PERIOD_2 = 0.5;

TriangleWaveformBuilder TriangleWaveformBuilder::newBuilder() {
    return TriangleWaveformBuilder();
}

int64_t TriangleWaveformBuilder::calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude, const uint32_t frequency, const uint32_t sampleRate) const {
    const double arg = static_cast<double>(frequency) / sampleRate * timeIndex;
    return amplitude * triangleFunction(arg);
}

double TriangleWaveformBuilder::triangleFunction(const double arg) const {
    const auto value = static_cast<uint64_t>(arg);
    const double fraction = arg - value;
    if (fraction < PERIOD_2) {
        return 4 * fraction - 1;
    }
    return 1 - 4 * (fraction - PERIOD_2);
}
