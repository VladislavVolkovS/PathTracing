#include "camera.h"

Camera::Camera(glm::vec3 lookfrom, glm::vec3 lookat, glm::vec3 vup, float vfov, float aspect, float aperture, float focus_dist) {
    // vfov is top to bottom in degrees
    lens_radius = aperture * 0.5f;
    float theta = vfov * float(M_PI) * (1.0f / 180.0f);
    float half_height = tan(theta * 0.5f);
    float half_width = aspect * half_height;
    origin = lookfrom;
    w = glm::normalize(lookfrom - lookat);
    u = glm::normalize(glm::cross(vup, w));
    v = glm::cross(w, u);
    lower_left_corner = origin - half_width * focus_dist * u - half_height * focus_dist * v - focus_dist * w;
    horizontal = 2 * half_width * focus_dist * u;
    vertical = 2 * half_height * focus_dist * v;
}

Ray Camera::get_ray(const float s, const float t) const {
    glm::vec3 rd = lens_radius * random_in_unit_disk();
    glm::vec3 offset = u * rd.x + v * rd.y;
    Ray ray;
    ray.origin = glm::vec4(origin + offset, 1.0);
    ray.direction = glm::normalize(glm::vec4(lower_left_corner + s * horizontal + t * vertical - origin - offset, 0.0));
    return ray;
}

int generateCameraRays(std::vector<Ray> &rays, std::vector<int> &pixCoord, const Camera &cam,
                       int width, int height, uint32_t pixelSampleIndex, Generator gen_type,
                       uint32_t samplesPerPixel) {
	const int numRays = width * height;
	rays.reserve(numRays);
	pixCoord.reserve(numRays);
	// Y
	// ^
	// |
	// O---> X
	for (int h = height - 1; h >= 0; --h) {
		for (int w = 0; w < width; ++w) {
            auto sampler = initSampler(h * width + w, pixelSampleIndex, 1, 0, samplesPerPixel);
            auto scrambling = true;
			float u = float(w + getRandom<SampleDimension::ePixelX>(sampler, gen_type, scrambling)) / float(width);
			float v = float(h + getRandom<SampleDimension::ePixelY>(sampler, gen_type, scrambling)) / float(height);
			// float u = float(w) / float(width);
			// float v = float(h) / float(height);

			Ray r = cam.get_ray(u, v);
			rays.push_back(r);
			pixCoord.push_back(h * width + w);
		}
	}
	return numRays;
}