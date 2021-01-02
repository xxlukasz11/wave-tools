#include "waveFileSaver.h"

WaveFileSaver::WaveFileSaver(const WaveFile& waveFile) : mWaveFile(waveFile) {
}

void WaveFileSaver::save(const std::string& fileName) {
	std::ofstream stream(fileName, std::fstream::binary);
	writeRiffHeader(stream);
	writeFmtSubChunk(stream);
	writeDataSubChunk(stream);
	stream.close();
}

void WaveFileSaver::writeRiffHeader(std::ofstream& stream) {
	const auto& riffHeader = mWaveFile.getRiffHeader();
	writeId(stream, riffHeader.getChunkId());
	writeLE(stream, riffHeader.getChunkSize());
	writeId(stream, riffHeader.getFormat());
}

void WaveFileSaver::writeFmtSubChunk(std::ofstream& stream) {
	const auto& fmt = mWaveFile.getFmtSubChunk();
	writeId(stream, fmt.getSubChunkId());
	writeLE(stream, fmt.getSubChunkSize());
	writeLE(stream, fmt.getAudioFormat());
	writeLE(stream, fmt.getNumChannels());
	writeLE(stream, fmt.getSampleRate());
	writeLE(stream, fmt.getByteRate());
	writeLE(stream, fmt.getBlockAlign());
	writeLE(stream, fmt.getBitsPerSample());
}

void WaveFileSaver::writeDataSubChunk(std::ofstream& stream) {
	const auto& dataSubChunk = mWaveFile.getDataSubChunk();
	writeId(stream, dataSubChunk.getSubChunkId());
	writeLE(stream, dataSubChunk.getSubChunkSize());
	const auto& buffer = dataSubChunk.data().getBuffer();
	stream.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
}

void WaveFileSaver::writeId(std::ofstream& stream, uint32_t value) {
	constexpr uint8_t byteMask = 0xff;
	for (int i = 3; i >= 0; --i) {
		const uint8_t byte = (value >> (8 * i)) & byteMask;
		stream.write(reinterpret_cast<const char*>(&byte), 1);
	}
}
