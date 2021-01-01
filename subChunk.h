#pragma once

#include <cstdlib>
#include "chunk.h"

class SubChunk {
public:
	SubChunk(Chunk& masterChunk, const uint32_t subChunkId, const uint32_t initialSubChunkSize);

protected:
	void increaseSubChunkSize(const int noOfBytes);

private:
	Chunk& mMasterChunk;
	uint32_t mSubChunkId;
	uint32_t mSubChunkSize;
};

