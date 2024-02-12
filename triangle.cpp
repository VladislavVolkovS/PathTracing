#include "triangle.h"

bool Triangle::intersection(const Ray &r, const glm::vec3 &a, const glm::vec3 &b,
                            const glm::vec3 &c, Intersection &isec) {
		// O + t * D = (1 - u - v) * A + u * B + v * C
		// O + t * D = A - u * A - v * A + u * B + v * C
		// O + t * D = A + u * (B - A) + v * (C - A)
		// O - A = -t * D + u * (B - A) + v * (C - A)
		// T = O - A
		// E1 = B - A
		// E2 = C - A
		// T = -t * D + u * E1 + v * E2
		//                [t]
		// [-D, E1, E2] x [u] = T
		//                [v]
		// M = [-D, E1, E2]
		// det(M) = -D * (E1 x E2) = D * (E2 x E1) = E1 * (D x E2)
		// [t]        1          | | T, E1, E2| |
		// [u] = ------------- * | |-D, T, E2 | |
		// [v]   E1 * (D x E2)   | |-D, E1, T | |
		// regroup
		// [t]        1          | | T * (E1 x E2)| |
		// [u] = ------------- * | |-D * (T x E2) | |
		// [v]   E1 * (D x E2)   | |-D * (E1 x T) | |
		// regroup
		// [t]        1          | | E2 * (T x E1)| |
		// [u] = ------------- * | | T * (D x E2) | |
		// [v]   E1 * (D x E2)   | | D * (T x E1) | |
		// P = D x E2, Q = T x E1
		// [t]     1      | | E2 * Q| |
		// [u] = ------ * | | T * P | |
		// [v]   E1 * P   | | D * Q | |
		glm::vec3 e1 = b - a;
		glm::vec3 e2 = c - a;
		glm::vec3 p = glm::cross(glm::vec3(r.direction), e2);
		float det = glm::dot(e1, p);
		// culling
		if (det < EPS)
		{
			return false;
		}
		// if (abs(det) < EPS)
		// {
		// return false;
		// }
		float invDet = 1.0f / det;
		glm::vec3 T = glm::vec3(r.origin) - a;
		float u = glm::dot(T, p) * invDet;
		if (u < 0.0f || u > 1.0f)
		{
			return false;
		}
		glm::vec3 Q = cross(T, e1);
		float v = glm::dot(glm::vec3(r.direction), Q) * invDet;
		if (v < 0.0f || (u + v) > 1.0f)
		{
			return false;
		}
		float t = dot(e2, Q) * invDet;
		// if (t < 0.0f || t > isec.t)
		if (t < EPS || t > isec.t)
		{
			return false;
		}

		isec.shapeId = 1;
		isec.uv.x = u;
		isec.uv.y = v;
		isec.t = t;

		return true;
	}