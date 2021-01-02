#include "waveFile.h"
#include "waveFileSaver.h"

WaveFile::WaveFile(const RiffHeaderPtr& riffHeader, const FmtSubChunk& fmtSubChunk, const DataSubChunk& dataSubChunk) :
	mRiffHeader(riffHeader),
	mFmtSubChunk(fmtSubChunk),
	mDataSubChunk(dataSubChunk) {
}

void WaveFile::addData(const DataBuffer& dataBuffer) {
	mDataSubChunk.addData(dataBuffer);
}

void WaveFile::addData(DataBuffer&& dataBuffer) {
	mDataSubChunk.addData(std::move(dataBuffer));
}

const RiffHeader& WaveFile::getRiffHeader() const {
	return *mRiffHeader;
}

const FmtSubChunk& WaveFile::getFmtSubChunk() const {
	return mFmtSubChunk;
}

const DataSubChunk& WaveFile::getDataSubChunk() const {
	return mDataSubChunk;
}

void WaveFile::save(const std::string& fileName) const {
	WaveFileSaver saver(*this);
	saver.save(fileName);
}
