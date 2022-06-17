#ifndef SPRITE_H
#define SPRITE_H

#include "Shader.h"
#include "Texture.h"
#include "Quad.h"
#include <GLM/gtc/matrix_transform.hpp>

namespace Engine {
	class Sprite
	{
	public:
		Sprite(Texture* texture, Shader* shader, Quad* quad);
		~Sprite();
		void Draw();
		void Update(float deltaTime);
		void SetFlipHorizontal(bool flipHorizontal);
		void SetFlipVertical(bool flipVertical);
		void SetAnimationDuration(int maxFrameDuration);
		void SetEnableAnimation(bool enableAnimation);
		void SetPosition(float x, float y);
		vec2 GetPosition();
		void SetRotation(float degree);
		void SetNumFrames(int numFrames);
		float GetRotation();
		void SetScale(float s);
		float GetScale();
		void SetSize(float width, float height);
		float GetScaleWidth();
		float GetScaleHeight();
		float GetX();
		float GetY();
	private:
		vec4 min;
		Shader* shader;
		Quad* quad;
		Texture* texture;
		float x = 0, y = 0, width = 0, height = 0, s = 1, degree = 0, frameDuration = 0, maxFrameDuration = 80;
		bool flipHorizontal = false, flipVertical = false, enableAnimation = false;
		int numFrames = 1, frameIndex = 0;
		mat4 CreateTransform();
		void UpdateTransform();
	};
}

#endif

