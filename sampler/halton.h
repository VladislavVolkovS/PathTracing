#pragma once
#include <iostream>
#include <string>
#include <memory>

float halton(uint32_t index, uint32_t base);

float halton_scramble(uint32_t index, uint32_t base);