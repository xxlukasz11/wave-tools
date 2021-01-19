#include "sawtoothWaveformBuilder.h"

SawtoothWaveformBuilder SawtoothWaveformBuilder::newBuilder() {
    return SawtoothWaveformBuilder();
}

int64_t SawtoothWaveformBuilder::calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude, const uint32_t frequency, const uint32_t sampleRate) const {
    const double arg = static_cast<double>(frequency) / sampleRate * timeIndex;
    return amplitude * sawtoothFunction(arg);
}

double SawtoothWaveformBuilder::sawtoothFunction(const double arg) const {
    const auto value = static_cast<uint64_t>(arg);
    return 2 * (arg - value) - 1.0;
}

