#include "waveFileBuilder.h"

WaveFile WaveFileBuilder::build() {
    const uint32_t sampleRate = mSampleRate.getValue();
    const uint16_t bitsPerSample = mBitsPerSample.getValue();
    const uint16_t numChannels = mNumChannels.getValue();
    const uint16_t blockAlign = numChannels * bitsPerSample / 8;
    const uint32_t byteRate = blockAlign * sampleRate;

    RiffHeader riffHeader;
    FmtSubChunk fmtSubChunk(riffHeader, numChannels, sampleRate, byteRate, blockAlign, bitsPerSample);
    DataSubChunk dataSubChunk(riffHeader);
    return WaveFile(riffHeader, fmtSubChunk, dataSubChunk);
}

WaveFileBuilder::WaveFileBuilder() :
    mSampleRate(SampleRate::FREQ_44100kHz),
    mBitsPerSample(BitsPerSample::BITS_16),
    mNumChannels(NumChannels::CH_2) {
}

WaveFileBuilder WaveFileBuilder::newBuilder() {
    return WaveFileBuilder{};
}

WaveFileBuilder& WaveFileBuilder::setSampleRate(SampleRate sampleRate) {
    mSampleRate = sampleRate;
    return *this;
}

WaveFileBuilder& WaveFileBuilder::setBitsPerSample(BitsPerSample bitsPerSample) {
    mBitsPerSample = bitsPerSample;
    return *this;
}

WaveFileBuilder& WaveFileBuilder::setNumChannels(NumChannels numChannels) {
    mNumChannels = numChannels;
    return *this;
}
