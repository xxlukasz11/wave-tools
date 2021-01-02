#include "subChunk.h"

SubChunk::SubChunk(const ChunkPtr& masterChunk, const uint32_t subChunkId, const uint32_t initialSubChunkSize) :
	mMasterChunk(masterChunk),
	mSubChunkId(subChunkId),
	mSubChunkSize(initialSubChunkSize) {
	mMasterChunk->increaseChunkSize(mSubChunkSize);
}

uint32_t SubChunk::getSubChunkId() const {
	return mSubChunkId;
}

uint32_t SubChunk::getSubChunkSize() const {
	return mSubChunkSize;
}

void SubChunk::increaseSubChunkSize(const int noOfBytes) {
	mSubChunkSize += noOfBytes;
	mMasterChunk->increaseChunkSize(noOfBytes);
}
