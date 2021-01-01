#include "chunk.h"

Chunk::Chunk(const uint32_t id, const uint32_t initialSize) :
	mChunkId(id),
	mChunkSize(initialSize) {
}

void Chunk::increaseChunkSize(const int noOfBytes) {
	mChunkSize += noOfBytes;
}
