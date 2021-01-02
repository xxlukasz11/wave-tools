#pragma once

#include "chunk.h"
#include "subChunk.h"
#include "dataBuffer.h"

class DataSubChunk : public SubChunk {
public:
	DataSubChunk(const ChunkPtr& parentHeader);

	void addData(const DataBuffer& data);
	void addData(DataBuffer&& data);

	DataBuffer& data();
	const DataBuffer& data() const;

private:
	DataBuffer mData;
};

