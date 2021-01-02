#pragma once

#include "waveFile.h"
#include <string>
#include <cstdint>
#include <fstream>

class WaveFileSaver {
public:
	WaveFileSaver(const WaveFile& waveFile);
	void save(const std::string& fileName);

private:
	void writeRiffHeader(std::ofstream& stream);
	void writeFmtSubChunk(std::ofstream& stream);
	void writeDataSubChunk(std::ofstream& stream);
	void writeId(std::ofstream& stream, uint32_t value);

	template<typename T>
	void writeLE(std::ofstream& stream, T value);

	const WaveFile& mWaveFile;
};

template<typename T>
inline void WaveFileSaver::writeLE(std::ofstream& stream, T value) {
	constexpr int size = sizeof(T);
	constexpr uint8_t byteMask = 0xff;
	for (int i = 0; i < size; ++i) {
		const uint8_t byte = (value >> (8 * i)) & byteMask;
		stream.write(reinterpret_cast<const char*>(&byte), 1);
	}
}