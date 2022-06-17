#include "Sprite.h"


using namespace Engine;


Sprite::Sprite(Texture* texture, Shader* shader, Quad* quad)
{
	this->texture = texture;
	this->quad = quad;
	this->shader = shader;
	this->width = texture->GetWidth();
	this->height = texture->GetHeight();
}

Sprite::~Sprite()
{
}

void Sprite::Draw()
{
	// Enable transparency
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Bind texture
	texture->Bind();
	// Activate shader
	shader->Use();
	shader->setInt(numFrames, "n");
	shader->setInt(frameIndex, "frameIndex");
	shader->setInt(flipHorizontal ? 1 : 0, "flipHorizontal");
	shader->setInt(flipVertical ? 1 : 0, "flipVertical");
	// Update sprite's and bounding box's transform
	UpdateTransform();
	// Draw Quad
	quad->Draw();
	// Unbind texture
	texture->UnBind();
	// Disable transparency
	glDisable(GL_BLEND);
}


void Engine::Sprite::Update(float deltaTime)
{
	if (!enableAnimation || numFrames == 1)
		return;


	frameDuration += deltaTime;

	if (frameDuration >= maxFrameDuration) {
		frameDuration = 0;
		frameIndex = frameDuration == numFrames - 1 ? 0 : frameIndex + 1;
	}
}

void Engine::Sprite::SetFlipHorizontal(bool flipHorizontal)
{
	this->flipHorizontal = flipHorizontal;
}

void Engine::Sprite::SetFlipVertical(bool flipVertical)
{
	this->flipVertical = flipVertical;
}


void Engine::Sprite::SetAnimationDuration(int maxFrameDuration)
{
	this->maxFrameDuration = maxFrameDuration;
}

void Engine::Sprite::SetEnableAnimation(bool enableAnimation)
{
	this->enableAnimation = enableAnimation;
}

void Sprite::SetPosition(float x, float y)
{
	this->x = x;
	this->y = y;
}

vec2 Engine::Sprite::GetPosition()
{
	vec2 position;
	position.x = x;
	position.y = y;
	return position;
}

void Sprite::SetRotation(float degree)
{
	this->degree = degree;
}

void Engine::Sprite::SetNumFrames(int numFrames)
{
	this->numFrames = numFrames;
}

float Sprite::GetRotation()
{
	return this->degree;
}

void Sprite::SetScale(float s)
{
	this->s = abs(s);
}

float Engine::Sprite::GetScale()
{
	return this->s;
}

void Sprite::SetSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

float Sprite::GetScaleWidth()
{
	return s * width;
}

float Sprite::GetScaleHeight()
{
	return s * height;
}

float Sprite::GetX()
{
	return this->x;
}

float Sprite::GetY()
{
	return this->y;
}

mat4 Sprite::CreateTransform()
{
	mat4 transform = mat4();
	// Translate Sprite
	transform = translate(transform, vec3(x, y, 0.0f));
	// Rotate sprite at center
	float w = GetScaleWidth() / numFrames, h = GetScaleHeight();
	transform = translate(transform, vec3(0.5f * w, 0.5f * h, 0.0f));
	transform = rotate(transform, radians(degree), vec3(0.0f, 0.0f, -1.0f));
	transform = translate(transform, vec3(-0.5f * w, -0.5f * h, 0.0f));
	// Scale sprite
	transform = scale(transform, vec3(w, h, 1));
	return transform;
}

void Engine::Sprite::UpdateTransform()
{
	mat4 transform = CreateTransform();
	shader->setMat4(transform, "model");

	transform = mat4();
	// Translate Sprite
	transform = translate(transform, vec3(x + width, y + height, 0.0f));
	// Rotate sprite at center
	float w = GetScaleWidth(), h = GetScaleHeight();
	transform = translate(transform, vec3(0.5f * w, 0.5f * h, 0.0f));
	transform = rotate(transform, radians(degree), vec3(0.0f, 0.0f, -1.0f));
	transform = translate(transform, vec3(-0.5f * w, -0.5f * h, 0.0f));
	// Scale sprite
	transform = scale(transform, vec3(w, h, 1));
}


