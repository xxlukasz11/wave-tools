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

	template<typename T>
	void write(std::ofstream& stream, T value);

	const WaveFile& mWaveFile;
};

template<typename T>
inline void WaveFileSaver::write(std::ofstream& stream, T value) {
	constexpr int size = sizeof(T);
	constexpr uint8_t byteMask = 0xff;
	for (int i = size - 1; i >= 0; --i) {
		const auto byte = (value >> (8 * i)) & byteMask;
		stream.write(reinterpret_cast<const char*>(&byte), 1);
	}
}
