#include "sampleRate.h"

SampleRate::SampleRate(const uint32_t sampleRate) : Parameter(sampleRate) {
}

const SampleRate SampleRate::FREQ_44100kHz{ 44100 };
const SampleRate SampleRate::FREQ_96000kHz{ 96000 };