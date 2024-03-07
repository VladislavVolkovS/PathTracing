#pragma once

#include "sampler/primes.h"
#include "sampler/halton.h"
#include "sampler/sobol.h"
#include "sampler/sample_dimension.h"
#include "sampler/sampler.h"
#include "externals/glm/glm/glm.hpp"
#include <fstream>

float GetRandomFromStd();

template <SampleDimension Dim>
float getRandom(SamplerState& state, Generator gen_type, bool scrambling) {
    uint32_t dimension = uint32_t(Dim) + state.depth * uint32_t(SampleDimension::eNUM_DIMENSIONS);
    if (gen_type == HALTON) {
        const uint32_t base = Primes[dimension & 31u];
        return scrambling ? halton_scramble(state.seed + state.sampleIdx, base)
                            : halton(state.seed + state.sampleIdx, base);
    } else if (gen_type == SOBOL) {
        return scrambling ? sobol_scramble(state.sampleIdx, dimension, state.seed)
                            : sobol(state.sampleIdx, dimension);
    } else {
        return GetRandomFromStd();
    }
}
glm::vec3 random_in_unit_disk();
glm::vec3 random_in_unit_disk(SamplerState& state, Generator gen_type, bool scrambling);