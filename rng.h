#pragma once
#include <iostream>

// Random Number Declarations
#ifndef PBRT_HAVE_HEX_FP_CONSTANTS
static const double DoubleOneMinusEpsilon = 0.99999999999999989;
static const float FloatOneMinusEpsilon = 0.99999994;
#else
static const double DoubleOneMinusEpsilon = 0x1.fffffffffffffp-1;
static const float FloatOneMinusEpsilon = 0x1.fffffep-1;
#endif

#ifdef PBRT_FLOAT_AS_DOUBLE
static const float OneMinusEpsilon = DoubleOneMinusEpsilon;
#else
static const float OneMinusEpsilon = FloatOneMinusEpsilon;
#endif

#define PCG32_DEFAULT_STATE 0x853c49e6748fea9bULL
#define PCG32_DEFAULT_STREAM 0xda3e39cb94b95bdbULL
#define PCG32_MULT 0x5851f42d4c957f2dULL

class RNG{
public:
    RNG() : state_(PCG32_DEFAULT_STATE), inc_(PCG32_DEFAULT_STREAM) {
    }
    RNG(uint64_t sequenceIndex) {
        SetSequence(sequenceIndex);
    }

    void SetSequence(uint64_t sequenceIndex) {
        state_ = 0u;
        inc_ = (sequenceIndex << 1u) | 1u;
        UniformUInt32();
        state_ += PCG32_DEFAULT_STATE;
        UniformUInt32();
    }

    float UniformFloat() {
        return std::min(OneMinusEpsilon, UniformUInt32() * 0x1p-32f);
    }

    uint32_t UniformUInt32() {
        uint64_t oldstate = state_;
        state_ = oldstate * PCG32_MULT + inc_;
        uint32_t xorshifted = (uint32_t)(((oldstate >> 18u) ^ oldstate) >> 27u);
        uint32_t rot = (uint32_t)(oldstate >> 59u);
        return (xorshifted >> rot) | (xorshifted << ((~rot + 1u) & 31));
    }

    uint32_t UniformUInt32(uint32_t b) {
        uint32_t threshold = (~b + 1u) % b;
        while (true) {
            uint32_t r = UniformUInt32();
            if (r >= threshold)
                return r % b;
        }
    }

    // template <typename Iterator>
    // void shuffle(Iterator begin, Iterator end) {
    //     for (Iterator it = end - 1; it > begin; --it) {
    //         std::iter_swap(it, begin + uniformUInt32((uint32_t)(it - begin + 1)));
    //     }
    // }
    
    // void advance(int64_t idelta) {
    //     uint64_t cur_mult = PCG32_MULT, cur_plus = inc_, acc_mult = 1u,
    //     acc_plus = 0u, delta = (uint64_t)idelta;
    //     while (delta > 0) {
    //         if (delta & 1) {
    //             acc_mult *= cur_mult;
    //             acc_plus = acc_plus * cur_mult + cur_plus;
    //         }
    //         cur_plus = (cur_mult + 1) * cur_plus;
    //         cur_mult *= cur_mult;
    //         delta /= 2;
    //     }
    //     state_ = acc_mult * state_ + acc_plus;
    // }
    
    // int64_t operator-(const RNG &other) const {
    //     uint64_t cur_mult = PCG32_MULT, cur_plus = inc_, cur_state = other.state_,
    //     the_bit = 1u, distance = 0u;
    //     while (state_ != cur_state) {
    //         if ((state_ & the_bit) != (cur_state & the_bit)) {
    //             cur_state = cur_state * cur_mult + cur_plus;
    //             distance |= the_bit;
    //         }
    //         the_bit <<= 1;
    //         cur_plus = (cur_mult + 1ULL) * cur_plus;
    //         cur_mult *= cur_mult;
    //     }
    //     return (int64_t)distance;
    // }

private:
    uint64_t state_, inc_;
};