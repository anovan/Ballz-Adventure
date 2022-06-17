#ifndef DEMO_H
#define DEMO_H

#include "Game.h"
#include "Setting.h"
#include "Texture.h"
#include "Sprite.h"
#include "Music.h"
#include "Sound.h"
#include "Text.h"
#include "AABB.h"

namespace Engine {
	class Demo :
		public Engine::Game
	{
	public:
		Demo(Setting* setting);
		~Demo();
		virtual void Init();
		virtual void Update();
		virtual void Render();
	private:
		Texture* ballTexture = NULL;
		Texture* backgroundTexture = NULL;
		Texture* buttonTexture = NULL;
		Texture* logoTexture = NULL;
		Texture* arena1LeftTexture = NULL;
		Texture* arena1BottomTexture = NULL;
		Texture* arena2_1Texture = NULL;
		Texture* arena2_2Texture = NULL;
		Texture* arena2_3Texture = NULL;
		Texture* arena3_1Texture = NULL;
		Texture* arena3_2Texture = NULL;
		Texture* arena3_3Texture = NULL;
		Texture* arena4_1Texture = NULL;
		Texture* arena4_2Texture = NULL;
		Texture* arena5_1Texture = NULL;
		Texture* arena5_2Texture = NULL;
		Texture* barrelTexture = NULL;
		Texture* flagTexture = NULL;
		Texture* ringTexture = NULL;
		Sprite* backgroundSprite = NULL;
		Sprite* ballSprite = NULL;
		Sprite* buttonSprite = NULL;
		Sprite* logoSprite = NULL;
		Sprite* arena1LeftSprite = NULL;
		Sprite* arena1BottomSprite = NULL;
		Sprite* arena2_1Sprite = NULL;
		Sprite* arena2_2Sprite = NULL;
		Sprite* arena2_3Sprite = NULL;
		Sprite* arena3_1Sprite = NULL;
		Sprite* arena3_2Sprite = NULL;
		Sprite* arena3_3Sprite = NULL;
		Sprite* arena4_1Sprite = NULL;
		Sprite* arena4_2Sprite = NULL;
		Sprite* arena5_1Sprite = NULL;
		Sprite* arena5_2Sprite = NULL;
		Sprite* barrelSprite = NULL;
		Sprite* flagSprite = NULL;
		Sprite* ringSprite = NULL;
		Music* startMusic = NULL;
		Music* mainMusic = NULL;
		Sound* soundTransition = NULL;
		Sound* soundFinish = NULL;
		Sound* soundFall = NULL;
		Sound* soundRing = NULL;
		Sound* soundTrap = NULL;
		Text* livesText = NULL;
		Text* ringText = NULL;
		Text* finishText = NULL;
		AABB* ballAABB;
		AABB* arena1BottomAABB;
		AABB* arena1LeftAABB;
		AABB* arena2_1AABB;
		AABB* arena2_2AABB;
		AABB* arena2_3AABB;
		AABB* arena3_1AABB;
		AABB* arena3_2AABB;
		AABB* arena3_3AABB;
		AABB* arena4_1AABB;
		AABB* arena4_2AABB;
		AABB* arena5_1AABB;
		AABB* arena5_2AABB;
		AABB* barrelAABB;
		AABB* flagAABB;
		AABB* buttonAABB;
		AABB* ringAABB;
		int round = 0, currentRing = 0, targetRing = 3, lives = 3;
		float xpos = 0.0f, ypos = 0.0f;
		bool isRing1Completed = false, isRing2Completed = false, isRing3Completed = false, isFinished = false;
	};
}
#endif

