#include "sampler.h"

SamplerState initSampler(uint32_t linearPixelIndex, uint32_t pixelSampleIndex, uint32_t seed) {
  SamplerState sampler {};
  sampler.seed = seed + linearPixelIndex;
  sampler.sampleIdx = pixelSampleIndex;
  return sampler;
}