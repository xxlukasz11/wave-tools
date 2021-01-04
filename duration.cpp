#include "duration.h"

constexpr uint32_t MICROSECONDS_IN_SECOND = 1'000'000;
constexpr uint32_t MILLISECONDS_IN_SECOND = 1'000;
constexpr uint32_t SECONDS_IN_MINUTE = 60;

Duration::Duration(const uint32_t seconds, const uint32_t microSeconds) :
    mSeconds(seconds),
    mMicroSeconds(microSeconds) {
}

Duration Duration::ZERO = Duration(0, 0);

Duration Duration::ofMicroSeconds(const uint32_t microSeconds) {
    const uint32_t seconds = microSeconds / MICROSECONDS_IN_SECOND;
    return Duration(seconds, microSeconds - seconds * MICROSECONDS_IN_SECOND);
}

Duration Duration::ofMilliSeconds(const uint32_t milliSeconds) {
    const uint32_t seconds = milliSeconds / MILLISECONDS_IN_SECOND;
    return Duration(seconds, milliSeconds - seconds * MILLISECONDS_IN_SECOND);
}

Duration Duration::ofSeconds(const uint32_t seconds) {
    return Duration(seconds, 0);
}

Duration Duration::ofMinutes(const uint32_t minutes) {
    return Duration(minutes * SECONDS_IN_MINUTE, 0);
}

uint32_t Duration::seconds() const {
    return mSeconds;
}

uint32_t Duration::microSeconds() const {
    return mMicroSeconds;
}

double Duration::realSeconds() const {
    return mSeconds + mMicroSeconds * 1.0 / MICROSECONDS_IN_SECOND;
}
