#pragma once

#include "chunk.h"
#include "subChunk.h"
#include <cstdlib>

class FmtSubChunk : public SubChunk {
public:
	FmtSubChunk(Chunk& parentHeader);

private:
	const uint16_t mAudioFormat;
	uint16_t mNumChannels;
	uint32_t mSampleRate;
	uint32_t mByteRate;
	uint16_t mBlockAlign;
	uint16_t mBitsPerSample;
};

