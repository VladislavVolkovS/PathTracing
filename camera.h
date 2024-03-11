#pragma once
#include "ray.h"
#include "rndlb.h"
#include <vector>

class Camera {
public:
	Camera(glm::vec3 lookfrom, glm::vec3 lookat, glm::vec3 vup, float vfov, float aspect,
           float aperture, float focus_dist);
	Ray get_ray(const float s, const float t) const;

	glm::vec3 origin;
	glm::vec3 lower_left_corner;
	glm::vec3 horizontal;
	glm::vec3 vertical;
	glm::vec3 u, v, w;
	float lens_radius;
};

int generateCameraRays(std::vector<Ray> &rays, std::vector<int> &pixCoord, const Camera &cam,
					   int width, int height, uint32_t pixelSampleIndex, Generator gen_type,
					   uint32_t samplesPerPixel);