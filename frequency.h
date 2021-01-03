#pragma once

class Frequency {
public:
	static Frequency ZERO;
	static Frequency ofHertz(const unsigned int hertz);
	static Frequency ofKiloHertz(const unsigned int kiloHertz);
	static Frequency ofMegaHertz(const unsigned int megaHertz);

	unsigned int hertz() const;

private:
	Frequency(const unsigned int hertz);

	unsigned int mHertz;
};

