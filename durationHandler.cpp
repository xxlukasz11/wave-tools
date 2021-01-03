#include "durationHandler.h"

DurationHandler::DurationHandler() : mMode(Mode::DURATION), mDuration(Duration::ZERO), mNoOfPeriods(0), mNoOfSamples(0) {
}

DurationHandler::Mode DurationHandler::getMode() const {
	return mMode;
}

void DurationHandler::setDuration(const Duration& duration) {
	mDuration = duration;
	mMode = Mode::DURATION;
}

void DurationHandler::setNoOfPeriods(const unsigned int noOfPeriods) {
	mNoOfPeriods = noOfPeriods;
	mMode = Mode::PERIODS;
}

void DurationHandler::setNoOfSamples(const unsigned int noOfSamples) {
	mNoOfSamples = noOfSamples;
	mMode = Mode::SAMPLES;
}

Duration DurationHandler::getDuration() const {
	return mDuration;
}

unsigned int DurationHandler::getNoOfPeriods() const {
	return mNoOfPeriods;
}

unsigned int DurationHandler::getNoOfSamples() const {
	return mNoOfSamples;
}
