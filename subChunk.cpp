#include "subChunk.h"

SubChunk::SubChunk(Chunk& masterChunk, const uint32_t subChunkId, const uint32_t initialSubChunkSize) :
	mMasterChunk(masterChunk),
	mSubChunkId(subChunkId),
	mSubChunkSize(initialSubChunkSize) {
}

void SubChunk::increaseSubChunkSize(const int noOfBytes) {
	mSubChunkSize += noOfBytes;
	mMasterChunk.increaseChunkSize(noOfBytes);
}
