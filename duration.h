#pragma once

class Duration {
public:
	static Duration ZERO;
	static Duration ofMicroSeconds(const unsigned int microSeconds);
	static Duration ofMilliSeconds(const unsigned int milliSeconds);
	static Duration ofSeconds(const unsigned int seconds);
	static Duration ofMinutes(const unsigned int minutes);

	unsigned int seconds() const;
	unsigned int microSeconds() const;
	double realSeconds() const;

private:
	Duration(const unsigned int seconds, const unsigned int microSeconds);

	unsigned int mSeconds;
	unsigned int mMicroSeconds;
};

