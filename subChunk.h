#pragma once

#include <cstdlib>
#include "chunk.h"

class SubChunk {
public:
	SubChunk(const ChunkPtr& masterChunk, const uint32_t subChunkId, const uint32_t initialSubChunkSize);
	uint32_t getSubChunkId() const;
	uint32_t getSubChunkSize() const;

protected:
	void increaseSubChunkSize(const int noOfBytes);

private:
	ChunkPtr mMasterChunk;
	uint32_t mSubChunkId;
	uint32_t mSubChunkSize;
};

