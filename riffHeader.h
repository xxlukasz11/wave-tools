#pragma once

#include <cstdint>
#include "chunk.h"

class RiffHeader : public Chunk {
public:
	RiffHeader();
	uint32_t getFormat() const;

private:
	uint32_t mFormat;
};

