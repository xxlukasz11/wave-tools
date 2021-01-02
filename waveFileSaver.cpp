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
	write(stream, riffHeader.getChunkId());
	writeLE(stream, riffHeader.getChunkSize());
	write(stream, riffHeader.getFormat());
}

void WaveFileSaver::writeFmtSubChunk(std::ofstream& stream) {
	const auto& fmt = mWaveFile.getFmtSubChunk();
	write(stream, fmt.getSubChunkId());
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
	write(stream, dataSubChunk.getSubChunkId());
	writeLE(stream, dataSubChunk.getSubChunkSize());
	const auto& buffer = dataSubChunk.data().getBuffer();
	stream.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
}
