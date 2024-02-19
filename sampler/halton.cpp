#include <cmath>
#include <iostream>
#include "halton.h"
#include "primes.h"

double halton(int index, int base) {
    int d;
    int j;
    double prime_inv = 1.0 / static_cast<double>(base);
    double result = 0.0;
    int t = index;

    while (t > 0) {
        d = (t % base);
        result += static_cast<double>(d) * prime_inv;
        prime_inv = prime_inv / static_cast<double>(base);
        t = (t - d) / base;
    }
    return result;
}