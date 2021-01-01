#include <iostream>

#include "riffHeader.h"
#include "fmtSubChunk.h"
#include "dataSubChunk.h"
#include "sampleRate.h"
#include "numChannels.h"
#include "bitsPerSample.h"

int main() {
	RiffHeader riffHeader;
	FmtSubChunk fmtChunk(riffHeader);
	DataSubChunk dataChunk(riffHeader);
	SampleRate::FREQ_44100kHz;
	NumChannels::CH_2;
	BitsPerSample::BITS_16;
	return 0;
}