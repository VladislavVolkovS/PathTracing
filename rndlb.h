#pragma once

#include "sampler/primes.h"
#include "sampler/halton.h"
#include "sample_dimension.h"
#include "sampler.h"
#include "externals/glm/glm/glm.hpp"
#include <fstream>

enum Generator {
    HALTON, SOBOL, STL
};

float GetRandomFromStd();
double sobol(uint32_t index, uint32_t base);

template <SampleDimension Dim>
double getRandom(SamplerState& state, Generator gen_type) {
    const uint32_t dimension = uint32_t(Dim) + state.depth * uint32_t(SampleDimension::eNUM_DIMENSIONS);
    const uint32_t base = Primes[dimension & 31u];
    if (gen_type == HALTON) {
        return halton(state.seed + state.sampleIdx, base);
    }
    if (gen_type == SOBOL) {
        return sobol(state.seed + state.sampleIdx, base);
    }
    return GetRandomFromStd();
}
glm::vec3 random_in_unit_disk();
glm::vec3 random_in_unit_disk(SamplerState& state, Generator gen_type);