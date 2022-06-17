#include "AABB.h"
#include <GLM/glm.hpp>
#include <iostream>

using namespace Engine;
using namespace std;

AABB::AABB(float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

bool AABB::isBallCollide(AABB* other) {
	float realWidth = width / 16;
	return (x < other->GetX() + other->GetWidth() && x + realWidth > other->GetX() && y < other->GetY() + other->GetHeight() && y + height > other->GetY());
}

bool AABB::isBallInsideRing(AABB* other) {
	float realWidth = width / 16;
	return (x + realWidth < other->GetX() + other->GetWidth() && x > other->GetX() && y + height < other->GetY() + other->GetHeight() && y + height > other->GetY());
}

bool AABB::collideWithMouse(float mouseX, float mouseY) {
	float realY = 600 - y - height;
	return (x < mouseX && x + width > mouseX && realY < mouseY && realY + height > mouseY);
}

void Engine::AABB::SetX(float X)
{
	this->x = X;
}

void Engine::AABB::SetY(float Y)
{
	this->y = Y;
}

void Engine::AABB::SetWidth(float width)
{
	this->width = width;
}

void Engine::AABB::SetHeight(float height)
{
	this->height = height;
}

float Engine::AABB::GetX()
{
	return this->x;
}

float Engine::AABB::GetY()
{
	return this->y;
}

float Engine::AABB::GetWidth()
{
	return this->width;
}

float Engine::AABB::GetHeight()
{
	return this->height;
}


