#include "fmtSubChunk.h"

constexpr uint32_t FMT_SUBCHUNK_ID = 0x666d7420; // "fmt "
constexpr uint32_t FMT_SUBCHUNK_SIZE = 16;
constexpr uint16_t FORMAT_PCM = 1;

FmtSubChunk::FmtSubChunk(Chunk& parentHeader, const uint16_t numChannels,
	const uint32_t sampleRate, const uint32_t byteRate,
	const uint16_t blockAlign, uint16_t bitsPerSample) :
	SubChunk(parentHeader, FMT_SUBCHUNK_ID, FMT_SUBCHUNK_SIZE),
	mAudioFormat(FORMAT_PCM),
	mNumChannels(numChannels),
	mSampleRate(sampleRate),
	mByteRate(byteRate),
	mBlockAlign(blockAlign),
	mBitsPerSample(bitsPerSample) {
}