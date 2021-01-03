#include "amplitudeHandler.h"

AmplitudeHandler::AmplitudeHandler() : mMode(Mode::PERCENTAGE), mValue(0), mPercentage(0) {
}

AmplitudeHandler::Mode AmplitudeHandler::getMode() const {
	return mMode;
}

void AmplitudeHandler::setValue(const uint64_t value) {
	mValue = value;
	mMode = Mode::VALUE;
}

void AmplitudeHandler::setPercentage(const double percentage) {
	mPercentage = percentage;
}

uint64_t AmplitudeHandler::getValue() const {
	return mValue;
}

double AmplitudeHandler::getPercentage() const {
	return mPercentage;
}
