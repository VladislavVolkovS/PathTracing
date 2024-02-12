#pragma once

#include "externals/glm/glm/glm.hpp"

struct Intersection {
	int shapeId = -1;
	int primitiveId = -1;
	int materialId = -1;
	glm::vec2 uv;
	float t = 1e9f;
};