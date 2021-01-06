#pragma once

#include "waveformBuilderBase.h"

class SineWaveformBuilder : public WaveformBuilderBase<SineWaveformBuilder> {
public:
	static SineWaveformBuilder newBuilder();

private:
	SineWaveformBuilder() = default;
	uint64_t calculateSampleValue(const uint64_t timeIndex, const uint64_t amplitude,
		const uint32_t frequency, const uint32_t sampleRate) const override;
};
