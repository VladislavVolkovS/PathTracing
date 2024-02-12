#pragma once

#include <iostream>
#include <vector>
#include "primes.h"
#include "rng.h"

template <typename T>
void Shuffle(T *samp, int count, int nDimensions, RNG &rng) {
    for (int i = 0; i < count; ++i) {
        int other = i + rng.UniformUInt32(count - i);
        for (int j = 0; j < nDimensions; ++j)
            std::swap(samp[nDimensions * i + j],
                      samp[nDimensions * other + j]);
    }
}

std::vector<uint16_t> ComputeRadicalInversePermutations(RNG &rng);

template <int base>
float ScrambledRadicalInverseSpecialized(const uint16_t *perm, uint64_t a) {
    const float invBase = (float)1 / (float)base;
    uint64_t reversedDigits = 0;
    float invBaseN = 1;
    while (a) {
        uint64_t next = a * invBase;
        uint64_t digit = a - next * base;
        reversedDigits = reversedDigits * base + perm[digit];
        invBaseN *= invBase;
        a = next;
    }
    return std::min(invBaseN * (reversedDigits + invBase * perm[0] / (1 - invBase)),
                    OneMinusEpsilon);
}

float ScrambledRadicalInverse(int baseIndex, uint64_t a, const uint16_t *perm);

uint32_t ReverseBits32(uint32_t n);

uint64_t ReverseBits64(uint64_t n);