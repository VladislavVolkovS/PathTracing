#include <random>
#include "rndlb.h"
#include "rng.h"
#include "sbprimes.h"

float GetRandomFromStd() {
	static std::default_random_engine generator;

	// static std::mt19937 generator; // std::mersenne_twister_engine<std::uint_fast32_t, 32, 624, 397, 31,
    //                         			 0x9908b0df, 11,
    //                         			 0xffffffff, 7,
    //                          		 0x9d2c5680, 15,
    //                         			 0xefc60000, 18, 1812433253>

	// static std::minstd_rand0 generator; // std::linear_congruential_engine<std::uint_fast32_t, 16807, 0, 2147483647>

	// static std::ranlux24_base generator; // std::subtract_with_carry_engine<std::uint_fast32_t, 24, 10, 24>

	// static std::ranlux48_base generator; // std::subtract_with_carry_engine<std::uint_fast64_t, 48, 5, 12>

	// static std::knuth_b generator; // std::shuffle_order_engine<std::minstd_rand0, 256>

	static std::uniform_real_distribution<float> distribution(0.0, 1.0);

	return distribution(generator);
}

float halton(uint32_t value, uint32_t base) {
    const float invBase = (float)1 / (float)base;
    uint64_t reversedDigits = 0;
    float invBaseN = 1;

    while (value) {
        uint64_t next  = value / base;
        uint64_t digit = value - next * base;
        reversedDigits = reversedDigits * base + digit;
        invBaseN *= invBase;
        value = next;
    }

    return std::min(reversedDigits * invBaseN, FloatOneMinusEpsilon);
}

float ScrambledHalton(uint32_t index, uint32_t base, const uint16_t *perm) {
    static std::vector<uint16_t> radicalInversePermutations;
    RNG rng;
    radicalInversePermutations = ComputeRadicalInversePermutations(rng);
    return ScrambledRadicalInverse(base, index, &radicalInversePermutations[PrimeSums[base]]);
}

float sobol(uint32_t index, uint32_t dimension, const unsigned long long scramble) {
    unsigned long long result = scramble & ~-(1ULL << sobol_matrices_size);
    for (unsigned i = dimension * sobol_matrices_size; index; index >>= 1, ++i)
    {
        if (index & 1)
            result ^= matrices[i];
    }

    return result * (1.0 / (1ULL << sobol_matrices_size));
}


glm::vec3 random_in_unit_disk() {
	glm::vec3 p;
	do
	{
		p = 2.0f * glm::vec3(GetRandomFromStd(), GetRandomFromStd(), 0) - glm::vec3(1, 1, 0);
	} while (dot(p, p) >= 1.0);
	return p;
}

glm::vec3 random_in_unit_disk(SamplerState& state, Generator gen_type) {
	glm::vec3 p;
	do
	{
		p = 2.0f * glm::vec3(getRandom<SampleDimension::eRussianRoulette>(state, gen_type),
                             getRandom<SampleDimension::eRussianRoulette>(state, gen_type), 0)
                             - glm::vec3(1, 1, 0);
	} while (dot(p, p) >= 1.0);
	return p;
}