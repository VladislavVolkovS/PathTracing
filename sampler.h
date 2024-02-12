#pragma once
#include <iostream>
#include "sample_dimension.h"

struct SamplerState {
  uint32_t seed;
  uint32_t sampleIdx;
  uint32_t depth;
};

SamplerState initSampler(uint32_t linearPixelIndex, uint32_t pixelSampleIndex,
                                uint32_t seed);