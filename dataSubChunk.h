#pragma once

#include "chunk.h"
#include "subChunk.h"

class DataSubChunk : public SubChunk {
public:
	DataSubChunk(Chunk& parentHeader);

private:
	// TODO: data field
};

