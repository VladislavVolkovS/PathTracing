#pragma once

#include "cxxopts.hpp"
#include "sampler/sampler.h"

struct Parameters {
    uint32_t samples_per_pixel;
    Generator gen_type;
    uint32_t width;
    uint32_t height;
};

Parameters ReadParams(int argc, const char* argv[]) {
    cxxopts::Options options("sampler <params>", "commands");
    options.add_options()

        ("w, width", "screen width", cxxopts::value<uint32_t>()->default_value("800"))
        ("h, height", "screen height", cxxopts::value<uint32_t>()->default_value("800"))

        ("spp", "samples per pixel", cxxopts::value<uint32_t>()->default_value("256"))

        ("gen_type", "type of random generator", cxxopts::value<uint32_t>()->default_value("0"))

        //("asset", "CornellBox-Original", cxxopts::value<uint32_t>()->default_value("0"))

    ;

    auto result = options.parse(argc, argv);

    auto screenWidth = result["width"].as<uint32_t>();
    auto screenHeight = result["height"].as<uint32_t>();

    auto spp = result["spp"].as<uint32_t>();

    auto gen_type = static_cast<Generator>(result["gen_type"].as<uint32_t>());


    return Parameters{spp, gen_type, screenWidth, screenHeight};
}