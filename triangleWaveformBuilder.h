#pragma once

#include "waveformBuilderBase.h"

class TriangleWaveformBuilder : public WaveformBuilderBase<TriangleWaveformBuilder> {
public:
	static TriangleWaveformBuilder newBuilder();

private:
	TriangleWaveformBuilder() = default;
	int64_t calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude,
		const uint32_t frequency, const uint32_t sampleRate) const override;
	double triangleFunction(const double arg) const;
};

