#pragma once

#include <cstdint>
#include <memory>

class Chunk {
public:
	Chunk(const uint32_t id, const uint32_t initialSize);
	void increaseChunkSize(const int noOfBytes);

	uint32_t getChunkId() const;
	uint32_t getChunkSize() const;

private:
	uint32_t mChunkId;
	uint32_t mChunkSize;
};

using ChunkPtr = std::shared_ptr<Chunk>;
