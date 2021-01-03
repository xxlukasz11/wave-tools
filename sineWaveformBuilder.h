#pragma once

#include "waveformBuilder.h"

class SineWaveformBuilder : public WaveformBuilder<SineWaveformBuilder> {
public:
	SineWaveformBuilder& set() { return *this;  }

private:
	DataBuffer generateWaveform(const uint16_t bitsPerSample) const override;
};

