#pragma once

#include <iostream>
#include <vector>
#include "scramble.h"

#ifdef FLOAT_IS_DOUBLE
static const float one_minus_epsilon = 0x1.fffffffffffffp-1;
#else
static const float one_minus_epsilon = 0x1.fffffep-1;
#endif

uint32_t sobol_uint(uint32_t index, uint32_t dim);

float sobol(uint32_t index, uint32_t dim);

float sobol_scramble(uint32_t index, uint32_t dim, uint32_t seed);