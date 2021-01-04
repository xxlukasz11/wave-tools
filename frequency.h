#pragma once

#include <cstdint>

class Frequency {
public:
	static Frequency ZERO;
	static Frequency ofHertz(const uint32_t hertz);
	static Frequency ofKiloHertz(const uint32_t kiloHertz);
	static Frequency ofMegaHertz(const uint32_t megaHertz);

	uint32_t hertz() const;

private:
	Frequency(const uint32_t hertz);

	uint32_t mHertz;
};
