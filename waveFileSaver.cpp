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
	write(stream, riffHeader.getChunkSize());
	write(stream, riffHeader.getFormat());
}

void WaveFileSaver::writeFmtSubChunk(std::ofstream& stream) {
	const auto& fmt = mWaveFile.getFmtSubChunk();
	write(stream, fmt.getSubChunkId());
	write(stream, fmt.getSubChunkSize());
	write(stream, fmt.getAudioFormat());
	write(stream, fmt.getNumChannels());
	write(stream, fmt.getSampleRate());
	write(stream, fmt.getByteRate());
	write(stream, fmt.getBlockAlign());
	write(stream, fmt.getBitsPerSample());
}

void WaveFileSaver::writeDataSubChunk(std::ofstream& stream) {
	const auto& dataSubChunk = mWaveFile.getDataSubChunk();
	write(stream, dataSubChunk.getSubChunkId());
	write(stream, dataSubChunk.getSubChunkSize());
	const auto& buffer = dataSubChunk.data().getBuffer();
	stream.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());
}
