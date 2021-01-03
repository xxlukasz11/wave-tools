#include <iostream>

#include "waveFileBuilder.h"
#include "sampleRate.h"
#include "numChannels.h"
#include "bitsPerSample.h"
#include "dataBuffer.h"
#include <fstream>
#include "sineWaveformBuilder.h"
#include <cmath>

void printHex() {
	std::ifstream ff("file.wav", std::fstream::binary);
	for (int i = 0; i < 40; ++i) {
		if (i % 4 == 0 && i != 0) {
			std::cout << std::endl;
		}
		unsigned char byte;
		ff.read(reinterpret_cast<char*>(&byte), 1);
		std::cout << std::hex << (unsigned int)byte << " ";
	}
}

int main() {
	WaveFile file = WaveFileBuilder::newBuilder()
		.setBitsPerSample(BitsPerSample::BITS_8)
		.setNumChannels(NumChannels::CH_1)
		.setSampleRate(SampleRate::FREQ_44100Hz)
		.build();

	DataBuffer buffer;
	int freq = 400;
	for (int i = 0; i < 88200; ++i) {
		buffer.append(127 + 127 * sin(i * 2 * 3.14 * freq / 44100.0));
	}

	file.addData(buffer);
	file.save("file.wav");

	printHex();

	SineWaveformBuilder().set().set().setAmplitudeByPercentage(0.2).set();
	return 0;
}