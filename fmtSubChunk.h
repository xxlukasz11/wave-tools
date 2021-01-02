#pragma once

#include "chunk.h"
#include "subChunk.h"
#include <cstdlib>

class FmtSubChunk : public SubChunk {
public:
	FmtSubChunk(Chunk& parentHeader, const uint16_t numChannels,
		const uint32_t sampleRate, const uint32_t byteRate,
		const uint16_t blockAlign, uint16_t bitsPerSample);
	uint16_t getAudioFormat() const;
	uint16_t getNumChannels() const;
	uint32_t getSampleRate() const;
	uint32_t getByteRate() const;
	uint16_t getBlockAlign() const;
	uint16_t getBitsPerSample() const;

private:
	const uint16_t mAudioFormat;
	uint16_t mNumChannels;
	uint32_t mSampleRate;
	uint32_t mByteRate;
	uint16_t mBlockAlign;
	uint16_t mBitsPerSample;
};

