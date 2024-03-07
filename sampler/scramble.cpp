#include "scramble.h"

uint32_t hash_combine(uint32_t seed, uint32_t v) {
  return seed ^ (v + (seed << 6) + (seed >> 2));
}

uint32_t hash(uint32_t x) {
    // finalizer from murmurhash3
    x ^= x >> 16;
    x *= 0x85ebca6bu;
    x ^= x >> 13;
    x *= 0xc2b2ae35u;
    x ^= x >> 16;
    return x;
}

uint32_t ReverseBits(uint32_t value) {

    value = (((value & 0xaaaaaaaa) >> 1) | ((value & 0x55555555) << 1));
    value = (((value & 0xcccccccc) >> 2) | ((value & 0x33333333) << 2));
    value = (((value & 0xf0f0f0f0) >> 4) | ((value & 0x0f0f0f0f) << 4));
    value = (((value & 0xff00ff00) >> 8) | ((value & 0x00ff00ff) << 8));
    return ((value >> 16) | (value << 16));

}

uint32_t ReverseBitsOwen(uint32_t value, uint32_t seed) {

    value ^= value * 0x3d20adea;
    value += seed;
    value *= (seed >> 16) | 1;
    value ^= value * 0x05526c56;
    value ^= value * 0x53a22864;

    return value;
}

uint32_t laine_karras_permutation(uint32_t value, uint32_t seed) {
    value += seed;
    value ^= value * 0x6c50b47cu;
    value ^= value * 0xb82f1e52u;
    value ^= value * 0xc7afe638u;
    value ^= value * 0x8d22f6e6u;
    return value;
}

uint32_t nested_uniform_scramble(uint32_t value, uint32_t seed) {
    //value = __builtin_bitreverse32(value);
    value = ReverseBits(value);
    value = laine_karras_permutation(value, seed);
    value = ReverseBits(value);
    return value;
}
