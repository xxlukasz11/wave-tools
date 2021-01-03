#include "frequency.h"

constexpr unsigned int KILO = 1'000;
constexpr unsigned int MEGA = 1'000'000;

Frequency Frequency::ZERO = Frequency(0);

Frequency Frequency::ofHertz(const unsigned int hertz) {
	return Frequency(hertz);
}

Frequency Frequency::ofKiloHertz(const unsigned int kiloHertz) {
	return Frequency(KILO * kiloHertz);
}

Frequency Frequency::ofMegaHertz(const unsigned int megaHertz) {
	return Frequency(MEGA * megaHertz);
}

unsigned int Frequency::hertz() const {
	return mHertz;
}

Frequency::Frequency(const unsigned int hertz) : mHertz(hertz) {
}