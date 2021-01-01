#include "fmtSubChunk.h"

constexpr uint32_t FMT_SUBCHUNK_ID = 0x666d7420; // "fmt "
constexpr uint32_t FMT_SUBCHUNK_SIZE = 16;
constexpr uint16_t FORMAT_PCM = 1;
constexpr int16_t INITIAL_NUM_CHANNELS = 2;
constexpr uint32_t INITIAL_SAMPLE_RATE = 44100;
constexpr uint16_t INITIAL_BITS_PER_SAMPLE = 16;
constexpr uint16_t INITIAL_BLOCK_ALIGN = INITIAL_NUM_CHANNELS * INITIAL_BITS_PER_SAMPLE / 8;
constexpr uint32_t INITIAL_BYTE_RATE = INITIAL_SAMPLE_RATE * INITIAL_BLOCK_ALIGN;

FmtSubChunk::FmtSubChunk(Chunk& parentHeader) :
	SubChunk(parentHeader, FMT_SUBCHUNK_ID, FMT_SUBCHUNK_SIZE),
	mAudioFormat(FORMAT_PCM),
	mNumChannels(INITIAL_NUM_CHANNELS),
	mSampleRate(INITIAL_SAMPLE_RATE),
	mByteRate(INITIAL_BYTE_RATE),
	mBlockAlign(INITIAL_BLOCK_ALIGN),
	mBitsPerSample(INITIAL_BITS_PER_SAMPLE) {
}
