#pragma once

#include "waveFile.h"
#include "riffHeader.h"
#include "fmtSubChunk.h"
#include "dataSubChunk.h"
#include "sampleRate.h"
#include "bitsPerSample.h"
#include "numChannels.h"

class WaveFileBuilder {
public:
	WaveFile build();
	static WaveFileBuilder newBuilder();

	WaveFileBuilder& setSampleRate(SampleRate sampleRate);
	WaveFileBuilder& setBitsPerSample(BitsPerSample bitsPerSample);
	WaveFileBuilder& setNumChannels(NumChannels numChannels);
private:
	WaveFileBuilder();

	SampleRate mSampleRate;
	BitsPerSample mBitsPerSample;
	NumChannels mNumChannels;
};

