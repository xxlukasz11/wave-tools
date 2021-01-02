#include "dataSubChunk.h"

constexpr uint32_t DATA_SUBCHUNK_ID = 0x64617461; // "data"
constexpr uint32_t INITIAL_DATA_SUBCHUNK_SIZE = 0;

DataSubChunk::DataSubChunk(Chunk& parentHeader) :
	SubChunk(parentHeader, DATA_SUBCHUNK_ID, INITIAL_DATA_SUBCHUNK_SIZE) {
}

void DataSubChunk::addData(const DataBuffer& data) {
	increaseSubChunkSize(data.size());
	mData.append(data);
}

void DataSubChunk::addData(DataBuffer&& data) {
	increaseSubChunkSize(data.size());
	mData.append(std::move(data));
}

DataBuffer& DataSubChunk::data() {
	return mData;
}

const DataBuffer& DataSubChunk::data() const {
	return mData;
}
