#pragma once

#include <cstdint>
#include "chunk.h"

class RiffHeader : public Chunk {
public:
	RiffHeader();

private:
	uint32_t mFormat;
};

