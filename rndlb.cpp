#include <random>
#include "rndlb.h"
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

double sobol(uint32_t index, uint32_t base) {
    uint32_t result = 0;

    for(uint32_t j = base * sobol_matrices_size; index; index >>= 1, j++)
        if(index & 1)
            result ^= matrices[j];

    return result * (1.0 / static_cast<double>(1ULL << 32));
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