#include "dataBuffer.h"

DataBuffer::DataBuffer(const size_t initialSize) {
    mBuffer.reserve(initialSize);
}

const DataBuffer::DataType& DataBuffer::getBuffer() const {
    return mBuffer;
}

size_t DataBuffer::size() const {
    return mBuffer.size();
}

void DataBuffer::append(ByteType byte) {
    mBuffer.push_back(byte);
}

void DataBuffer::append(const DataBuffer& buffer) {
    append(buffer.mBuffer);
}

void DataBuffer::append(DataBuffer&& buffer) {
    append(std::move(buffer.mBuffer));
}
