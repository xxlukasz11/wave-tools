#include <iostream>

#include "riffHeader.h"
#include "fmtSubChunk.h"
#include "dataSubChunk.h"

int main() {
	RiffHeader riffHeader;
	FmtSubChunk fmtChunk(riffHeader);
	DataSubChunk dataChunk(riffHeader);
	return 0;
}