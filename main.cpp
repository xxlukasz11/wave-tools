#include <iostream>

#include "waveFileBuilder.h"
#include "sineWaveformBuilder.h"
#include <cmath>
#include <fstream>

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
		.setBitsPerSample(BitsPerSample::BITS_16)
		.setNumChannels(NumChannels::CH_2)
		.setSampleRate(SampleRate::FREQ_44100Hz)
		.build();

	printHex();

	const WaveformBuilder& builder = SineWaveformBuilder::newBuilder()
		.setAmplitudeByPercentage(0.3)
		.setFrequency(Frequency::ofHertz(200))
		.setDuration(Duration::ofSeconds(3));

	builder.appendWaveformToFile(file);

	file.save("file.wav");
	return 0;
}