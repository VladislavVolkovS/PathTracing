#pragma once

#include <iostream>

uint32_t hash_combine(uint32_t seed, uint32_t v);

uint32_t hash(uint32_t x);
uint32_t ReverseBits(uint32_t value);

uint32_t ReverseBitsOwen(uint32_t value, uint32_t seed);

uint32_t laine_karras_permutation(uint32_t x, uint32_t seed);

uint32_t nested_uniform_scramble(uint32_t x, uint32_t seed);