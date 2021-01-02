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

using RiffHeaderPtr = std::shared_ptr<RiffHeader>;