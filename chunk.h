#pragma once

#include <cstdint>

class Chunk {
public:
	Chunk(const uint32_t id, const uint32_t initialSize);
	void increaseChunkSize(const int noOfBytes);

private:
	uint32_t mChunkId;
	uint32_t mChunkSize;
};

