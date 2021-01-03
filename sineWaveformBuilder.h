#pragma once

#include "waveformBuilder.h"

class SineWaveformBuilder : public WaveformBuilder<SineWaveformBuilder> {
public:
	static SineWaveformBuilder newBuilder();

private:
	SineWaveformBuilder() = default;
	DataBuffer generateWaveform(const FmtSubChunk& fmtSubChunk) const override;
};

