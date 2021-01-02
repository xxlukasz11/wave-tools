#include <iostream>

#include "waveFileBuilder.h"
#include "sampleRate.h"
#include "numChannels.h"
#include "bitsPerSample.h"
#include "dataBuffer.h"

int main() {
	WaveFile file = WaveFileBuilder::newBuilder()
		.setBitsPerSample(BitsPerSample::BITS_16)
		.setNumChannels(NumChannels::CH_2)
		.setSampleRate(SampleRate::FREQ_44100kHz)
		.build();

	DataBuffer buffer;
	buffer.append(1);
	DataBuffer::DataType b{ 2,3,4 };
	buffer.append(b);
	buffer.append(std::move(b));

	return 0;
}