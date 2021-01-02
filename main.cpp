#include <iostream>

#include "riffHeader.h"
#include "fmtSubChunk.h"
#include "dataSubChunk.h"
#include "sampleRate.h"
#include "numChannels.h"
#include "bitsPerSample.h"
#include "dataBuffer.h"

int main() {
	RiffHeader riffHeader;
	FmtSubChunk fmtChunk(riffHeader);
	DataSubChunk dataChunk(riffHeader);
	SampleRate::FREQ_44100kHz;
	NumChannels::CH_2;
	BitsPerSample::BITS_16;

	DataBuffer buffer;
	buffer.append(1);
	DataBuffer::DataType b{ 2,3,4 };
	buffer.append(b);
	buffer.append(std::move(b));

	dataChunk.addData(buffer);
	return 0;
}