#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <iostream>
#include <random>
#include "camera.h"
#include "intersection.h"
#include "triangle.h"
#include "sampler/sampler.h"

#include "sampler/halton.h"
#include "consol_reader.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <fstream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "externals/stb_image_write.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include "externals/tiny_obj_loader.h"