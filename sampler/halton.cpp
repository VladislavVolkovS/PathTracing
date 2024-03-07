#include <cmath>
#include <iostream>
#include "halton.h"
#include "primes.h"

float halton(uint32_t index, uint32_t base) {
    uint32_t d;
    uint32_t j;
    float prime_inv = 1.0f / static_cast<float>(base);
    float result = 0.0f;
    uint32_t t = index;

    while (t > 0) {
        d = (t % base);
        result += static_cast<float>(d) * prime_inv;
        prime_inv = prime_inv / static_cast<float>(base);
        t = (t - d) / base;
    }
    return result;
}


// need to implement!!!
float halton_scramble(uint32_t index, uint32_t base) {
    // float result = 0.0f;
    // int d;
    // int j;
    // float prime_inv = 1.0f / static_cast<float>(base);
    // int t = index;

    // while (t > 0) {
    //     d = (t % base);
    //     result += static_cast<float>(d) * prime_inv;
    //     prime_inv = prime_inv / static_cast<float>(base);
    //     t = (t - d) / base;
    // }
    return halton(index, base);
}