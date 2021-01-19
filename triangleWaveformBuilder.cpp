#include "triangleWaveformBuilder.h"

constexpr double DEFAULT_PEAK_POSITION = 0.5;

TriangleWaveformBuilder TriangleWaveformBuilder::newBuilder() {
    return TriangleWaveformBuilder();
}

TriangleWaveformBuilder::TriangleWaveformBuilder() : mPeakPosition(DEFAULT_PEAK_POSITION) {}

TriangleWaveformBuilder& TriangleWaveformBuilder::setRelativePeakPosition(const double ratio) {
    if (ratio >= 0.0 && ratio <= 1.0) {
        mPeakPosition = ratio;
    }
    return *this;
}

int64_t TriangleWaveformBuilder::calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude, const uint32_t frequency, const uint32_t sampleRate) const {
    const double arg = static_cast<double>(frequency) / sampleRate * timeIndex;
    return amplitude * triangleFunction(arg);
}

double TriangleWaveformBuilder::triangleFunction(const double arg) const {
    const auto value = static_cast<uint64_t>(arg);
    const double fraction = arg - value;
    if (fraction < mPeakPosition) {
        return 4 * fraction - 1;
    }
    return 1 - 4 * (fraction - mPeakPosition);
}
