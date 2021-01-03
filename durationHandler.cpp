#include "durationHandler.h"

DurationHandler::DurationHandler() : mMode(Mode::DURATION), mDuration(Duration::ZERO), mNoOfPeriods(0), mNoOfSamples(0) {
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

uint64_t DurationHandler::calculateNoOfSamples(const uint32_t sampleRate, const uint32_t signalFrequency) const {
	if (mMode == Mode::PERIODS) {
		return static_cast<uint64_t>(mNoOfPeriods) * sampleRate / signalFrequency;
	}
	if (mMode == Mode::DURATION) {
		return mDuration.realSeconds() * sampleRate;
	}
	return mNoOfSamples;
}
