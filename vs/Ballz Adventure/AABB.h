#ifndef AABB_H
#define AABB_H
#include <GLM/glm.hpp>
#include "Sprite.h"

using namespace glm;

namespace Engine {
	class AABB {
	public:
		AABB(float x, float y, float width, float height);
		bool isBallCollide(AABB* other);
		bool isBallInsideRing(AABB* other);
		bool collideWithMouse(float mouseX, float mouseY);
		void SetX(float X);
		void SetY(float Y);
		void SetWidth(float width);
		void SetHeight(float height);
		float GetX();
		float GetY();
		float GetWidth();
		float GetHeight();
	private:
		float x = 0, y = 0, width = 0, height = 0;
		float minX = 0, maxX = 0, minY = 0, maxY = 0;
	};
}

#endif

