#include "sampler.h"

SamplerState initSampler(uint32_t linearPixelIndex, uint32_t pixelSampleIndex, uint32_t seed,
                         uint32_t depth) {
  SamplerState sampler {};
  sampler.seed = seed + linearPixelIndex;
  sampler.sampleIdx = pixelSampleIndex;
  sampler.depth = depth;
  return sampler;
}