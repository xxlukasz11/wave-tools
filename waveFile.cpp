#include "waveFile.h"

WaveFile::WaveFile(const RiffHeader& riffHeader, const FmtSubChunk& fmtSubChunk, const DataSubChunk& dataSubChunk) :
	mRiffHeder(riffHeader),
	mFmtSubChunk(fmtSubChunk),
	mDataSubChunk(dataSubChunk) {
}

void WaveFile::addData(const DataBuffer& dataBuffer) {
	mDataSubChunk.addData(dataBuffer);
}

void WaveFile::addData(DataBuffer&& dataBuffer) {
	mDataSubChunk.addData(std::move(dataBuffer));
}
