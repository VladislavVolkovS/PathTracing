#pragma once
#include <iostream>
#include "sample_dimension.h"

enum Generator {
    STL, HALTON, SOBOL
};

struct SamplerState {
  uint32_t seed;
  uint32_t sampleIdx;
  uint32_t depth = 0;
};

uint32_t sampler_hash(uint32_t a);

SamplerState initSampler(uint32_t linearPixelIndex, uint32_t pixelSampleIndex, uint32_t seed,
                         uint32_t depth, uint32_t samplesPerPixel);