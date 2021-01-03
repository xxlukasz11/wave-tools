#pragma once

#include <cstdint>
#include <vector>

class DataBuffer {
public:
	using ByteType = uint8_t;
	using DataType = std::vector<ByteType>;

	DataBuffer() = default;
	DataBuffer(const size_t initialSize);
	const DataType& getBuffer() const;
	size_t size() const;
	
	void append(ByteType byte);
	void append(const DataBuffer& buffer);
	void append(DataBuffer&& buffer);
	
	template<typename T, typename = std::enable_if_t<!std::is_fundamental_v<T>>>
	void append(T&& iterable);

private:
	DataType mBuffer;
};

template<typename T, typename>
inline void DataBuffer::append(T&& iterable) {
	if constexpr (std::is_lvalue_reference_v<T>) {
		mBuffer.insert(mBuffer.end(), iterable.begin(), iterable.end());
	} else {
		mBuffer.insert(mBuffer.end(), std::make_move_iterator(iterable.begin()), std::make_move_iterator(iterable.end()));
		iterable.erase(iterable.begin(), iterable.end());
	}
}
