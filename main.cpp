#include <iostream>

#include "waveFileBuilder.h"
#include "sineWaveformBuilder.h"
#include "sawtoothWaveformBuilder.h"
#include "triangleWaveformBuilder.h"
#include <cmath>
#include <fstream>

static const std::string FILE_NAME = "file.wav";

void printHeaderInHex() {
	std::ifstream ff(FILE_NAME, std::fstream::binary);
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
		.setBitsPerSample(BitsPerSample::BITS_16)
		.setNumChannels(NumChannels::CH_2)
		.setSampleRate(SampleRate::FREQ_44100Hz)
		.build();

	const WaveformBuilder& sineBuilder = SineWaveformBuilder::newBuilder()
		.setAmplitudeByPercentage(0.3)
		.setFrequency(Frequency::ofHertz(200))
		.setDuration(Duration::ofSeconds(2));

	const WaveformBuilder& sawtoothBuilder = SawtoothWaveformBuilder::newBuilder()
		.setAmplitudeByPercentage(0.2)
		.setFrequency(Frequency::ofHertz(200))
		.setDuration(Duration::ofSeconds(2));

	const WaveformBuilder& triangleBuilder = TriangleWaveformBuilder::newBuilder()
		.setAmplitudeByPercentage(0.2)
		.setFrequency(Frequency::ofHertz(200))
		.setDuration(Duration::ofSeconds(2));

	sineBuilder.appendWaveformToFile(file);
	sawtoothBuilder.appendWaveformToFile(file);
	triangleBuilder.appendWaveformToFile(file);

	file.save(FILE_NAME);
	printHeaderInHex();
	return 0;
}