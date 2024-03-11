#include "sampler.h"

uint32_t sampler_hash(uint32_t a) {
    a = (a + 0x7ED55D16) + (a << 12);
    a = (a ^ 0xC761C23C) ^ (a >> 19);
    a = (a + 0x165667B1) + (a << 5);
    a = (a + 0xD3A2646C) ^ (a << 9);
    a = (a + 0xFD7046C5) + (a << 3);
    a = (a ^ 0xB55A4F09) ^ (a >> 16);
    return a;
}

SamplerState initSampler(uint32_t linearPixelIndex, uint32_t pixelSampleIndex, uint32_t seed,
                         uint32_t depth, uint32_t samplesPerPixel) {
    SamplerState sampler {};
    sampler.seed = pixelSampleIndex + linearPixelIndex * samplesPerPixel;
    // sampler.seed = sampler_hash(linearPixelIndex) + pixelSampleIndex;
    // sampler.seed = seed + pixelSampleIndex;
    sampler.sampleIdx = pixelSampleIndex;
    sampler.depth = depth;
    return sampler;
}