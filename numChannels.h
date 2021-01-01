#pragma once

#include "parameter.h"
#include <cstdint>

class NumChannels : public Parameter<uint16_t> {
public:
	static const NumChannels CH_1;
	static const NumChannels CH_2;
	static const NumChannels CH_3;
	static const NumChannels CH_4;
	static const NumChannels CH_5;
	static const NumChannels CH_6;
	static const NumChannels CH_7;
	static const NumChannels CH_8;
	static const NumChannels CH_9;
	static const NumChannels CH_10;

private:
	NumChannels(const uint16_t numChannels);
};

