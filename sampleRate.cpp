#include "sampleRate.h"

SampleRate::SampleRate(const uint32_t sampleRate) : Parameter(sampleRate) {
}

const SampleRate SampleRate::FREQ_22050Hz{ 22050 };
const SampleRate SampleRate::FREQ_44100Hz{ 44100 };
const SampleRate SampleRate::FREQ_48000Hz{ 48000 };
const SampleRate SampleRate::FREQ_88200Hz{ 88200 };
const SampleRate SampleRate::FREQ_96000Hz{ 96000 };
const SampleRate SampleRate::FREQ_176400Hz{ 176400 };
const SampleRate SampleRate::FREQ_192000Hz{ 192000 };
const SampleRate SampleRate::FREQ_384000Hz{ 384000 };