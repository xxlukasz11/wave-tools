#include "sineWaveformBuilder.h"

constexpr double PI = 3.14159265358979323846;
constexpr uint8_t BYTE_MASK = 0xff;

SineWaveformBuilder SineWaveformBuilder::newBuilder() {
    return SineWaveformBuilder();
}

DataBuffer SineWaveformBuilder::generateWaveform(const FmtSubChunk& fmtSubChunk) const {
    const auto bitsPerSample = fmtSubChunk.getBitsPerSample();
    const auto blockAlign = fmtSubChunk.getBlockAlign();
    const auto sampleRate = fmtSubChunk.getSampleRate();
    const auto numChannels = fmtSubChunk.getNumChannels();
    const auto frequency = getFrequencyHandler().getFrequency().hertz();
    const auto noOfSamples = getDurationHandler().calculateNoOfSamples(sampleRate, frequency);
    const auto amplitude = getAmplitudeHandler().calculateAmplitude(bitsPerSample);
    const auto offset = getAmplitudeHandler().calculateOffset(bitsPerSample);
    DataBuffer buffer(noOfSamples*blockAlign);

    const auto bytesPerSample = bitsPerSample / 8;
    for (uint64_t i = 0; i < noOfSamples; ++i) {
        uint64_t value = offset + amplitude * sin(2 * PI * frequency / sampleRate * i);
        for (int channel = 0; channel < numChannels; ++channel) {
            for (int byteIndex = 0; byteIndex < bytesPerSample; ++byteIndex) {
                buffer.append((value >> (byteIndex * 8)) & BYTE_MASK);
            }
        }
    }
    return buffer;
}
