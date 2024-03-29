#include "frequencyHandler.h"

FrequencyHandler::FrequencyHandler() : mFrequency(Frequency::ZERO) {
}

void FrequencyHandler::setFrequency(const Frequency& frequency) {
	mFrequency = frequency;
}

void FrequencyHandler::setPeriod(const Duration& duration) {
	const auto hertz = static_cast<uint32_t>(1.0 / duration.realSeconds());
	mFrequency = Frequency::ofHertz(hertz);
}

Frequency FrequencyHandler::getFrequency() const {
	return mFrequency;
}
