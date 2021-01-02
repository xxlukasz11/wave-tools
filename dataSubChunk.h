#pragma once

#include "chunk.h"
#include "subChunk.h"
#include "dataBuffer.h"

class DataSubChunk : public SubChunk {
public:
	DataSubChunk(Chunk& parentHeader);

	void addData(const DataBuffer& data);
	void setData(DataBuffer&& data);

	DataBuffer& data();
	const DataBuffer& data() const;

private:
	DataBuffer mData;
};

