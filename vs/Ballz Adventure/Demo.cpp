#include "Demo.h"

using namespace Engine;

Demo::Demo(Setting* setting) :Game(setting)
{

}


Demo::~Demo()
{
	delete ballTexture;
	delete backgroundTexture;
	delete buttonTexture;
	delete logoTexture;
	delete backgroundSprite;
	delete ballSprite;
	delete buttonSprite;
	delete logoSprite;
	delete startMusic;
	delete mainMusic;
	delete soundTransition;
	delete livesText;
	delete ringText;
}

void Demo::Init()
{
	backgroundTexture = new Texture("background.jpg");
	backgroundSprite = new Sprite(backgroundTexture, defaultSpriteShader, defaultQuad);
	backgroundSprite->SetScale(0.25);
	backgroundSprite->SetPosition((setting->screenWidth) - (backgroundSprite->GetScaleWidth()),
		(setting->screenHeight) - (backgroundSprite->GetScaleHeight()));

	buttonTexture = new Texture("button_start.png");
	buttonSprite = new Sprite(buttonTexture, defaultSpriteShader, defaultQuad);
	buttonSprite->SetScale(0.4);
	buttonSprite->SetPosition((setting->screenWidth * 0.5f) - (buttonSprite->GetScaleWidth() * 0.5f),
		(setting->screenHeight * 0.3f) - (buttonSprite->GetScaleHeight() * 0.5f));

	buttonAABB = new AABB(buttonSprite->GetX(), buttonSprite->GetY(), buttonSprite->GetScaleWidth(), buttonSprite->GetScaleHeight());

	logoTexture = new Texture("logo.png");
	logoSprite = new Sprite(logoTexture, defaultSpriteShader, defaultQuad);
	logoSprite->SetScale(0.2);
	logoSprite->SetPosition((setting->screenWidth * 0.5f) - (logoSprite->GetScaleWidth() * 0.5f), 
		(setting->screenHeight * 0.6f) - (logoSprite->GetScaleHeight() * 0.5f));

	arena1LeftTexture = new Texture("arena1left.png");
	arena1LeftSprite = new Sprite(arena1LeftTexture, defaultSpriteShader, defaultQuad);
	arena1LeftSprite->SetScale(0.24);
	arena1LeftSprite->SetPosition(0, 0);
	arena1LeftSprite->SetFlipHorizontal(true);

	arena1LeftAABB = new AABB(arena1LeftSprite->GetX(), arena1LeftSprite->GetY(), arena1LeftSprite->GetScaleWidth(), arena1LeftSprite->GetScaleHeight());

	arena1BottomTexture = new Texture("arena1bottom.png");
	arena1BottomSprite = new Sprite(arena1BottomTexture, defaultSpriteShader, defaultQuad);
	arena1BottomSprite->SetScale(0.24);
	arena1BottomSprite->SetPosition(0, 0);
	arena1BottomSprite->SetFlipHorizontal(true);

	arena1BottomAABB = new AABB(arena1BottomSprite->GetX(), arena1BottomSprite->GetY(), arena1BottomSprite->GetScaleWidth(), arena1BottomSprite->GetScaleHeight());

	arena2_1Texture = new Texture("arena2-1.png");
	arena2_1Sprite = new Sprite(arena2_1Texture, defaultSpriteShader, defaultQuad);
	arena2_1Sprite->SetScale(0.24);
	arena2_1Sprite->SetPosition(0, 0);
	arena2_1Sprite->SetFlipHorizontal(true);

	arena2_1AABB = new AABB(arena2_1Sprite->GetX(), arena2_1Sprite->GetY(), arena2_1Sprite->GetScaleWidth(), arena2_1Sprite->GetScaleHeight());

	arena2_2Texture = new Texture("arena2-2.png");
	arena2_2Sprite = new Sprite(arena2_2Texture, defaultSpriteShader, defaultQuad);
	arena2_2Sprite->SetScale(0.24);
	arena2_2Sprite->SetPosition(0, 0);
	arena2_2Sprite->SetFlipHorizontal(true);

	arena2_2AABB = new AABB(arena2_2Sprite->GetX(), arena2_2Sprite->GetY(), arena2_2Sprite->GetScaleWidth(), arena2_2Sprite->GetScaleHeight());

	arena2_3Texture = new Texture("arena2-3.png");
	arena2_3Sprite = new Sprite(arena2_3Texture, defaultSpriteShader, defaultQuad);
	arena2_3Sprite->SetScale(0.24);
	arena2_3Sprite->SetPosition(0, 0);
	arena2_3Sprite->SetFlipHorizontal(true);

	arena2_3AABB = new AABB(arena2_3Sprite->GetX(), arena2_3Sprite->GetY(), arena2_3Sprite->GetScaleWidth(), arena2_3Sprite->GetScaleHeight());

	arena3_2Texture = new Texture("arena3-2.png");
	arena3_2Sprite = new Sprite(arena3_2Texture, defaultSpriteShader, defaultQuad);
	arena3_2Sprite->SetScale(0.24);
	arena3_2Sprite->SetPosition(setting->screenWidth - arena3_2Sprite->GetScaleWidth(), 0);
	arena3_2Sprite->SetFlipHorizontal(true);

	arena3_2AABB = new AABB(arena3_2Sprite->GetX(), arena3_2Sprite->GetY(), arena3_2Sprite->GetScaleWidth(), arena3_2Sprite->GetScaleHeight());

	arena3_1Texture = new Texture("arena3-1.png");
	arena3_1Sprite = new Sprite(arena3_1Texture, defaultSpriteShader, defaultQuad);
	arena3_1Sprite->SetScale(0.24);
	arena3_1Sprite->SetPosition(setting->screenWidth * 0.546, arena3_2Sprite->GetScaleHeight());
	arena3_1Sprite->SetFlipHorizontal(true);

	arena3_1AABB = new AABB(arena3_1Sprite->GetX(), arena3_1Sprite->GetY(), arena3_1Sprite->GetScaleWidth(), arena3_1Sprite->GetScaleHeight());

	arena3_3Texture = new Texture("arena3-3.png");
	arena3_3Sprite = new Sprite(arena3_3Texture, defaultSpriteShader, defaultQuad);
	arena3_3Sprite->SetScale(0.24);
	arena3_3Sprite->SetPosition(0, 0);
	arena3_3Sprite->SetFlipHorizontal(true);

	arena3_3AABB = new AABB(arena3_3Sprite->GetX(), arena3_3Sprite->GetY(), arena3_3Sprite->GetScaleWidth(), arena3_3Sprite->GetScaleHeight());

	arena4_1Texture = new Texture("arena4-1.png");
	arena4_1Sprite = new Sprite(arena4_1Texture, defaultSpriteShader, defaultQuad);
	arena4_1Sprite->SetScale(0.24);
	arena4_1Sprite->SetPosition(setting->screenWidth - arena4_1Sprite->GetScaleWidth(), 0);
	arena4_1Sprite->SetFlipHorizontal(true);

	arena4_1AABB = new AABB(arena4_1Sprite->GetX(), arena4_1Sprite->GetY(), arena4_1Sprite->GetScaleWidth(), arena4_1Sprite->GetScaleHeight());

	arena4_2Texture = new Texture("arena4-2.png");
	arena4_2Sprite = new Sprite(arena4_2Texture, defaultSpriteShader, defaultQuad);
	arena4_2Sprite->SetScale(0.24);
	arena4_2Sprite->SetPosition(0, 0);
	arena4_2Sprite->SetFlipHorizontal(true);

	arena4_2AABB = new AABB(arena4_2Sprite->GetX(), arena4_2Sprite->GetY(), arena4_2Sprite->GetScaleWidth(), arena4_2Sprite->GetScaleHeight());

	arena5_1Texture = new Texture("arena5-1.png");
	arena5_1Sprite = new Sprite(arena5_1Texture, defaultSpriteShader, defaultQuad);
	arena5_1Sprite->SetScale(0.24);
	arena5_1Sprite->SetPosition(setting->screenWidth - arena5_1Sprite->GetScaleWidth(), 0);
	arena5_1Sprite->SetFlipHorizontal(true);

	arena5_1AABB = new AABB(arena5_1Sprite->GetX(), arena5_1Sprite->GetY(), arena5_1Sprite->GetScaleWidth(), arena5_1Sprite->GetScaleHeight());

	arena5_2Texture = new Texture("arena5-2.png");
	arena5_2Sprite = new Sprite(arena5_2Texture, defaultSpriteShader, defaultQuad);
	arena5_2Sprite->SetScale(0.24);
	arena5_2Sprite->SetPosition(0, 0);
	arena5_2Sprite->SetFlipHorizontal(true);

	arena5_2AABB = new AABB(arena5_2Sprite->GetX(), arena5_2Sprite->GetY(), arena5_2Sprite->GetScaleWidth(), arena5_2Sprite->GetScaleHeight());

	ballTexture = new Texture("ball.png");
	ballSprite = new Sprite(ballTexture, defaultSpriteShader, defaultQuad);
	ballSprite->SetScale(0.1);
	ballSprite->SetPosition(arena1LeftSprite->GetScaleWidth(), arena1BottomSprite->GetScaleHeight());
	ballSprite->SetNumFrames(16);
	ballSprite->SetAnimationDuration(100);

	ballAABB = new AABB(ballSprite->GetX(), ballSprite->GetY(), ballSprite->GetScaleWidth(), ballSprite->GetScaleHeight());

	ringTexture = new Texture("ring.png");
	ringSprite = new Sprite(ringTexture, defaultSpriteShader, defaultQuad);
	ringSprite->SetScale(0.5);
	ringSprite->SetPosition((setting->screenWidth * 0.5f),
		(arena1BottomSprite->GetScaleHeight()));

	ringAABB = new AABB(ringSprite->GetX(), ringSprite->GetY(), ringSprite->GetScaleWidth(), ringSprite->GetScaleHeight());

	barrelTexture = new Texture("barrel.png");
	barrelSprite = new Sprite(barrelTexture, defaultSpriteShader, defaultQuad);
	barrelSprite->SetScale(0.3);
	barrelSprite->SetPosition((arena5_1Sprite->GetX() + 100),
		(arena5_1Sprite->GetScaleHeight()));

	barrelAABB = new AABB(barrelSprite->GetX(), barrelSprite->GetY(), barrelSprite->GetScaleWidth(), barrelSprite->GetScaleHeight());

	flagTexture = new Texture("bendera.png");
	flagSprite = new Sprite(flagTexture, defaultSpriteShader, defaultQuad);
	flagSprite->SetScale(0.05);
	flagSprite->SetPosition((setting->screenWidth - flagSprite->GetScaleWidth() - 100),
		(arena5_1Sprite->GetScaleHeight()));

	flagAABB = new AABB(flagSprite->GetX(), flagSprite->GetY(), flagSprite->GetScaleWidth(), flagSprite->GetScaleHeight());

	inputManager->AddInputMapping("Move Up", SDLK_w);
	inputManager->AddInputMapping("Move Down", SDLK_s);
	inputManager->AddInputMapping("Move Right", SDLK_d);
	inputManager->AddInputMapping("Move Left", SDLK_a);
	inputManager->AddInputMapping("Quit", SDLK_ESCAPE);
	inputManager->AddInputMapping("Mouse Click", SDL_BUTTON_LEFT);

	startMusic = new Music("bgm_start.ogg");
	startMusic->SetVolume(40);
	startMusic->Play(true);

	mainMusic = new Music("bgm_main.ogg");
	mainMusic->SetVolume(40);

	soundTransition = new Sound("sfx_transition.wav");
	soundTransition->SetVolume(80);

	soundFinish = new Sound("sfx_finish.wav");
	soundFinish->SetVolume(80);

	soundFall = new Sound("sfx_fall.wav");
	soundFall->SetVolume(80);

	soundRing = new Sound("sfx_ring.wav");
	soundRing->SetVolume(80);

	soundTrap = new Sound("sfx_trap.wav");
	soundTrap->SetVolume(80);

	livesText = new Text("hongkonghustle.ttf", 20, defaultTextShader);
	livesText->SetColor(255, 255, 255);
	livesText->SetPosition(0, 20);

	ringText = new Text("hongkonghustle.ttf", 20, defaultTextShader);
	ringText->SetColor(255, 255, 255);
	ringText->SetPosition(0, 0);

	finishText = new Text("hongkonghustle.ttf", 30, defaultTextShader);
	finishText->SetColor(255, 255, 255);
	finishText->SetPosition(setting->screenWidth * 0.45, setting->screenHeight * 0.5);
	finishText->SetText("TAMAT");
}

void Demo::Update()
{
	if (inputManager->IsKeyReleased("Quit")) {
		state = State::EXIT;
		return;
	}

	if (inputManager->IsKeyReleased("Mouse Click")) {
		float mouseX = inputManager->GetMouseCoords().x;
		float mouseY = inputManager->GetMouseCoords().y;
		if (round == 0 && (buttonAABB->collideWithMouse(mouseX, mouseY))) {
			round++;
			soundTransition->Play(false);
			startMusic->Stop();
			mainMusic->Play(true);
		}
	}

	float xspeed = 0, yspeed = 0;
	xpos = ballSprite->GetX();
	ypos = ballSprite->GetY();

	float oldxpos = xpos;
	float oldypos = ypos;

	if (round > 0 && !isFinished) {
		if (inputManager->IsKeyPressed("Move Up")) {
			yspeed = 0.08f;
		}

		if (inputManager->IsKeyPressed("Move Down")) {
			yspeed = -0.08f;
		}

		ypos += GetGameTime() * yspeed;

		if (inputManager->IsKeyPressed("Move Right")) {
			xspeed = 0.08f;
			ballSprite->SetFlipHorizontal(false);
		}

		if (inputManager->IsKeyPressed("Move Left")) {
			xspeed = -0.08f;
			ballSprite->SetFlipHorizontal(true);
		}

		xpos += GetGameTime() * xspeed;
		ballAABB->SetX(xpos);
		ballAABB->SetY(ypos);

		if (round == 1 && ballAABB->isBallCollide(arena1LeftAABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 1 && ballAABB->isBallCollide(arena1BottomAABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 2 && ballAABB->isBallCollide(arena2_1AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 2 && ballAABB->isBallCollide(arena2_2AABB)) {
			xpos = oldxpos;
			ypos = oldypos;			
		}

		if (round == 2 && ballAABB->isBallCollide(arena2_3AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 3 && ballAABB->isBallCollide(arena3_1AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 3 && ballAABB->isBallCollide(arena3_2AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 3 && ballAABB->isBallCollide(arena3_3AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 4 && ballAABB->isBallCollide(arena4_1AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 4 && ballAABB->isBallCollide(arena4_2AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 5 && ballAABB->isBallCollide(arena5_1AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 5 && ballAABB->isBallCollide(arena5_2AABB)) {
			xpos = oldxpos;
			ypos = oldypos;
		}

		if (round == 5 && ballAABB->isBallCollide(barrelAABB)) {
			soundTrap->Play(false);
			lives--;
			xpos = oldxpos - 50;
			ypos = oldypos + 50;
		}

		if ((round == 1 || round == 3 || round == 4) && ballAABB->isBallCollide(ringAABB)) {
			if (!ballAABB->isBallInsideRing(ringAABB)) {
				ypos = oldypos;
			}
			else {
				if (round == 1 && !isRing1Completed) {
					soundRing->Play(false);
					currentRing++;
					isRing1Completed = true;
				} else if (round == 3 && !isRing2Completed) {
					soundRing->Play(false);
					currentRing++;
					isRing2Completed = true;
				} else if (round == 4 && !isRing3Completed) {
					soundRing->Play(false);
					currentRing++;
					isRing3Completed = true;
				}
			}
		}

		if ((ypos + ballSprite->GetScaleHeight()) > setting->screenHeight) {
			ypos = oldypos;
		}
		else if ((ypos + ballSprite->GetScaleHeight()) / 2 < 0) {
			soundFall->Play(false);
			lives--;
			ypos += 100;
		}

		if (round == 5) {
			if (xpos + ballSprite->GetScaleWidth() / 16 > setting->screenWidth) {
				xpos = oldxpos;
			}
			if (ballAABB->isBallCollide(flagAABB)) {
				if (currentRing == targetRing) {
					soundFinish->Play(true);
					isFinished = true;
				}
			}
		}

		ballSprite->SetPosition(xpos, ypos);
		ballAABB->SetX(xpos);
		ballAABB->SetY(ypos);
		ballSprite->Update(GetGameTime());
		ballSprite->SetEnableAnimation(xspeed == 0 ? false : true);

		if (((xpos + (xpos + (ballSprite->GetScaleWidth() / 16))) / 2) > setting->screenWidth) {
			round++;
			if (ypos + ballSprite->GetScaleHeight() == setting->screenHeight) {
				ballSprite->SetPosition(0, ballSprite->GetY());
			}
			else {
				ballSprite->SetPosition(0, ballSprite->GetY() + 1);
			}
			ballAABB->SetX(xpos);
			ballAABB->SetY(ypos);
			if (round == 3) {
				ringSprite->SetPosition((arena3_1Sprite->GetX() + (arena3_1Sprite->GetX() + arena3_1Sprite->GetScaleWidth())) / 2 - ringSprite->GetScaleWidth() * 0.5, (arena3_1Sprite->GetY() + arena3_1Sprite->GetScaleHeight()));
				ringAABB->SetX(ringSprite->GetX());
				ringAABB->SetY(ringSprite->GetY());
			}
			else if (round == 4) {
				ringSprite->SetPosition(setting->screenWidth * 0.7, (arena4_1Sprite->GetY() + arena4_1Sprite->GetScaleHeight()));
				ringAABB->SetX(ringSprite->GetX());
				ringAABB->SetY(ringSprite->GetY());
			}
		}

		if (((xpos + (xpos + (ballSprite->GetScaleWidth() / 16))) / 2) < 0) {
			if (round > 1) {
				round--;
				if (ypos + ballSprite->GetScaleHeight() == setting->screenHeight) {
					ballSprite->SetPosition(setting->screenWidth - (ballSprite->GetScaleWidth() / 16), ballSprite->GetY());
				}
				else {
					ballSprite->SetPosition(setting->screenWidth - (ballSprite->GetScaleWidth() / 16), ballSprite->GetY() + 1);
				}
				ballAABB->SetX(xpos);
				ballAABB->SetY(ypos);
				if (round == 1) {
					ringSprite->SetPosition((setting->screenWidth * 0.5f),
						(arena1BottomSprite->GetScaleHeight()));
					ringAABB->SetX(ringSprite->GetX());
					ringAABB->SetY(ringSprite->GetY());
				}
				else if (round == 3) {
					ringSprite->SetPosition((arena3_1Sprite->GetX() + (arena3_1Sprite->GetX() + arena3_1Sprite->GetScaleWidth())) / 2 - ringSprite->GetScaleWidth() * 0.5, (arena3_1Sprite->GetY() + arena3_1Sprite->GetScaleHeight()));
					ringAABB->SetX(ringSprite->GetX());
					ringAABB->SetY(ringSprite->GetY());
				}
				else if (round == 4) {
					ringSprite->SetPosition(setting->screenWidth * 0.7, (arena4_1Sprite->GetY() + arena4_1Sprite->GetScaleHeight()));
					ringAABB->SetX(ringSprite->GetX());
					ringAABB->SetY(ringSprite->GetY());
				}
			}
		}

		livesText->SetText("Life: " + to_string(lives));
		ringText->SetText("Ring: " + to_string(currentRing) + " / " + to_string(targetRing));

		if (lives == 0) {
			finishText->SetText("KALAH");
			isFinished = true;
		}
	}
	
}

void Demo::Render()
{
	//Set the background color
	SetBackgroundColor(0, 255, 255);
	backgroundSprite->Draw();
	if (round == 0) {
		buttonSprite->Draw();
		logoSprite->Draw();
	}
	else {
		ballSprite->Draw();
		if (round == 1) {
			arena1LeftSprite->Draw();
			arena1BottomSprite->Draw();
			ringSprite->Draw();
		}
		else if (round == 2) {
			arena2_1Sprite->Draw();
			arena2_2Sprite->Draw();
			arena2_3Sprite->Draw();
		}
		else if (round == 3) {
			arena3_1Sprite->Draw();
			arena3_2Sprite->Draw();
			arena3_3Sprite->Draw();
			ringSprite->Draw();
		}
		else if (round == 4) {
			arena4_1Sprite->Draw();
			arena4_2Sprite->Draw();
			ringSprite->Draw();
		}
		else if (round == 5) {
			arena5_1Sprite->Draw();
			arena5_2Sprite->Draw();
			barrelSprite->Draw();
			flagSprite->Draw();
		}
		livesText->Draw();
		ringText->Draw();
	}
	if (isFinished) {
		finishText->Draw();
	}
	
}

int main(int argc, char** argv) {
	Setting* setting = new Setting();
	Game* game = new Demo(setting);
	game->Run();
	delete setting;
	delete game;

	return 0;
}
