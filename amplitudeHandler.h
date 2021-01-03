#pragma once

#include <cstdint>

class AmplitudeHandler {
public:
	enum class Mode {
		VALUE,
		PERCENTAGE
	};

	AmplitudeHandler();
	Mode getMode() const;
	void setValue(const uint64_t value);
	void setPercentage(const double percentage);

	uint64_t getValue() const;
	double getPercentage() const;

private:
	Mode mMode;
	uint64_t mValue;
	double mPercentage;
};

