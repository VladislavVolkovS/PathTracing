#pragma once

#include "halton.h"
#include "sample_dimension.h"
#include "sampler.h"
#include "externals/glm/glm/glm.hpp"
#include "primes.h"

enum Generator {
    HALTON, SOBOL, STL
};

float GetRandomFromStd();
float halton(uint32_t value, uint32_t base);
float sobol(uint32_t index, uint32_t dimension, const unsigned long long scramble = 0ULL);
float ScrambledHalton(uint32_t index, uint32_t base, const uint16_t *perm);

template <SampleDimension Dim>
float getRandom(SamplerState& state, Generator gen_type) {
    const uint32_t dimension = uint32_t(Dim) + state.depth * uint32_t(SampleDimension::eNUM_DIMENSIONS);
    const uint32_t base = Primes[dimension & 31u];
    if (gen_type == HALTON) {
        return halton(state.seed + state.sampleIdx, base);
        // static std::vector<uint16_t> radicalInversePermutations;
        // RNG rng;
        // radicalInversePermutations = ComputeRadicalInversePermutations(rng);
        // return ScrambledHalton(state.seed + state.sampleIdx, base, &radicalInversePermutations[PrimeSums[base]]);
    }
    if (gen_type == SOBOL) {
        return sobol(state.seed + state.sampleIdx, base);
    }
    return GetRandomFromStd();
}
glm::vec3 random_in_unit_disk();
glm::vec3 random_in_unit_disk(SamplerState& state, Generator gen_type);