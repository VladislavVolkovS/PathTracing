#pragma once

#include "externals/glm/glm/glm.hpp"
#include "ray.h"
#include "intersection.h"

const float EPS = 1e-5f;

struct Triangle {
	static bool intersection(const Ray &r, const glm::vec3 &a, const glm::vec3 &b, const glm::vec3 &c, Intersection &isec);
};