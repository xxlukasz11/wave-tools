#include "durationHandler.h"

DurationHandler::DurationHandler() : mMode(Mode::DURATION), mDuration(Duration::ZERO), mNoOfPeriods(0), mNoOfSamples(0) {
}

void DurationHandler::setDuration(const Duration& duration) {
	mDuration = duration;
	mMode = Mode::DURATION;
}

void DurationHandler::setNoOfPeriods(const uint32_t noOfPeriods) {
	mNoOfPeriods = noOfPeriods;
	mMode = Mode::PERIODS;
}

void DurationHandler::setNoOfSamples(const uint32_t noOfSamples) {
	mNoOfSamples = noOfSamples;
	mMode = Mode::SAMPLES;
}

uint32_t DurationHandler::calculateNoOfSamples(const uint32_t sampleRate, const uint32_t signalFrequency) const {
	if (mMode == Mode::PERIODS) {
		return mNoOfPeriods * sampleRate / signalFrequency;
	}
	if (mMode == Mode::DURATION) {
		return static_cast<uint32_t>(mDuration.realSeconds() * sampleRate);
	}
	return mNoOfSamples;
}
