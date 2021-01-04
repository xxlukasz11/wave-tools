#pragma once

#include <cstdint>

class Duration {
public:
	static Duration ZERO;
	static Duration ofMicroSeconds(const uint32_t microSeconds);
	static Duration ofMilliSeconds(const uint32_t milliSeconds);
	static Duration ofSeconds(const uint32_t seconds);
	static Duration ofMinutes(const uint32_t minutes);

	uint32_t seconds() const;
	uint32_t microSeconds() const;
	double realSeconds() const;

private:
	Duration(const uint32_t seconds, const uint32_t microSeconds);

	uint32_t mSeconds;
	uint32_t mMicroSeconds;
};

