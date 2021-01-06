#pragma once

#include "waveFile.h"

class WaveformBuilder {
public:
	virtual void appendWaveformToFile(WaveFile& waveFile) const = 0;
};

