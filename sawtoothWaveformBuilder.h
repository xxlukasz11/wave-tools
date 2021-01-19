#pragma once

#include "waveformBuilderBase.h"

class SawtoothWaveformBuilder : public WaveformBuilderBase<SawtoothWaveformBuilder> {
public:
	static SawtoothWaveformBuilder newBuilder();

private:
	SawtoothWaveformBuilder() = default;
	int64_t calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude,
		const uint32_t frequency, const uint32_t sampleRate) const override;
	double sawtoothFunction(const double arg) const;
};

