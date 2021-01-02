#include "chunk.h"

Chunk::Chunk(const uint32_t id, const uint32_t initialSize) :
	mChunkId(id),
	mChunkSize(initialSize) {
}

void Chunk::increaseChunkSize(const int noOfBytes) {
	mChunkSize += noOfBytes;
}

uint32_t Chunk::getChunkId() const {
	return mChunkId;
}

uint32_t Chunk::getChunkSize() const {
	return mChunkSize;
}
