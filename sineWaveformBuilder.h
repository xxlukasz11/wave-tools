#pragma once

#include "waveformBuilder.h"

class SineWaveformBuilder : public WaveformBuilder<SineWaveformBuilder> {
public:
	static SineWaveformBuilder newBuilder();

private:
	SineWaveformBuilder() = default;
	DataBuffer generateWaveform(const FmtSubChunk& fmtSubChunk) const override;
	void appendForEveryChannel(DataBuffer& buffer, const uint64_t value,
		const int numChannels, const int bytesPerSample) const;
};

