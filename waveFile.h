#pragma once

#include "riffHeader.h"
#include "fmtSubChunk.h"
#include "dataSubChunk.h"
#include "dataBuffer.h"
#include <string>

class WaveFile {
public:
	WaveFile(const RiffHeaderPtr& riffHEeader, const FmtSubChunk& fmtSubChunk, const DataSubChunk& dataSubChunk);
	void addData(const DataBuffer& dataBuffer);
	void addData(DataBuffer&& dataBuffer);

	const RiffHeader& getRiffHeader() const;
	const FmtSubChunk& getFmtSubChunk() const;
	const DataSubChunk& getDataSubChunk() const;
	void save(const std::string& fileName) const;

private:
	RiffHeaderPtr mRiffHeader;
	FmtSubChunk mFmtSubChunk;
	DataSubChunk mDataSubChunk;
};

