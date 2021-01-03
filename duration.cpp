#include "duration.h"

constexpr unsigned int MICROSECONDS_IN_SECOND = 1'000'000;
constexpr unsigned int MILLISECONDS_IN_SECOND = 1'000;
constexpr unsigned int SECONDS_IN_MINUTE = 60;

Duration::Duration(const unsigned int seconds, const unsigned int microSeconds) :
    mSeconds(seconds),
    mMicroSeconds(microSeconds) {
}

Duration Duration::ZERO = Duration(0, 0);

Duration Duration::ofMicroSeconds(const unsigned int microSeconds) {
    const unsigned int seconds = microSeconds / MICROSECONDS_IN_SECOND;
    return Duration(seconds, microSeconds - seconds * MICROSECONDS_IN_SECOND);
}

Duration Duration::ofMilliSeconds(const unsigned int milliSeconds) {
    const unsigned int seconds = milliSeconds / MILLISECONDS_IN_SECOND;
    return Duration(seconds, milliSeconds - seconds * MILLISECONDS_IN_SECOND);
}

Duration Duration::ofSeconds(const unsigned int seconds) {
    return Duration(seconds, 0);
}

Duration Duration::ofMinutes(const unsigned int minutes) {
    return Duration(minutes * SECONDS_IN_MINUTE, 0);
}

unsigned int Duration::seconds() const {
    return mSeconds;
}

unsigned int Duration::microSeconds() const {
    return mMicroSeconds;
}

double Duration::realSeconds() const {
    return mSeconds + mMicroSeconds * 1.0 / MICROSECONDS_IN_SECOND;
}
