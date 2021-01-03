#pragma once

#include <cstdint>

class AmplitudeHandler {
public:
	AmplitudeHandler();
	void setValue(const uint64_t value);
	void setPercentage(const double percentage);
	uint64_t calculateAmplitude(const uint32_t bitsPerSample) const;
	uint32_t calculateOffset(const uint32_t bitsPerSample) const;

private:
	enum class Mode {
		VALUE,
		PERCENTAGE
	};

	Mode mMode;
	uint64_t mValue;
	double mPercentage;
};

