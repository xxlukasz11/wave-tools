#include "riffHeader.h"

constexpr uint32_t CHUNK_ID = 0x52494646; // RIFF
constexpr uint32_t FORMAT_WAVE = 0x57415645; // WAVE
constexpr uint32_t INITIAL_CHUNK_SZE = 4;

RiffHeader::RiffHeader() : Chunk(CHUNK_ID, INITIAL_CHUNK_SZE), mFormat(FORMAT_WAVE) {
}