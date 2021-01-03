#include "amplitudeHandler.h"
#include <algorithm>

constexpr uint64_t ONE = 1;
constexpr uint32_t BITS_8 = 8;
constexpr uint32_t BITS_8_OFFSET = 127;

AmplitudeHandler::AmplitudeHandler() : mMode(Mode::PERCENTAGE), mValue(0), mPercentage(0) {
}

void AmplitudeHandler::setValue(const uint64_t value) {
	mValue = value;
	mMode = Mode::VALUE;
}

void AmplitudeHandler::setPercentage(const double percentage) {
	mPercentage = percentage;
}

uint64_t AmplitudeHandler::calculateAmplitude(const uint32_t bitsPerSample) const {
	const uint64_t maxValue = (ONE << (bitsPerSample - ONE)) - ONE;
	if (mMode == Mode::VALUE) {
		return std::min(mValue, maxValue);
	}
	return mPercentage * maxValue;
}

uint32_t AmplitudeHandler::calculateOffset(const uint32_t bitsPerSample) const {
	if (bitsPerSample == BITS_8) {
		return BITS_8_OFFSET;
	}
	return 0;
}
