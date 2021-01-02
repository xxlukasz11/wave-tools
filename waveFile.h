#pragma once

#include "riffHeader.h"
#include "fmtSubChunk.h"
#include "dataSubChunk.h"
#include "dataBuffer.h"

class WaveFile {
public:
	WaveFile(const RiffHeader& riffHEeader, const FmtSubChunk& fmtSubChunk, const DataSubChunk& dataSubChunk);
	void addData(const DataBuffer& dataBuffer);
	void addData(DataBuffer&& dataBuffer);

private:
	RiffHeader mRiffHeder;
	FmtSubChunk mFmtSubChunk;
	DataSubChunk mDataSubChunk;
};

