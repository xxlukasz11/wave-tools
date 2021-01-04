#include "frequency.h"

constexpr uint32_t KILO = 1'000;
constexpr uint32_t MEGA = 1'000'000;

Frequency Frequency::ZERO = Frequency(0);

Frequency Frequency::ofHertz(const uint32_t hertz) {
	return Frequency(hertz);
}

Frequency Frequency::ofKiloHertz(const uint32_t kiloHertz) {
	return Frequency(KILO * kiloHertz);
}

Frequency Frequency::ofMegaHertz(const uint32_t megaHertz) {
	return Frequency(MEGA * megaHertz);
}

uint32_t Frequency::hertz() const {
	return mHertz;
}

Frequency::Frequency(const uint32_t hertz) : mHertz(hertz) {
}