#pragma once

#include <Component/SimpleScene.h>
#include <string>
#include <Core/Engine.h>
#include <TextRenderer/TextRenderer.h>

#include "TemaTransform2D.h"
#include "TemaObject2D.h"

#include "Arrow.h"
#include "Shuriken.h"
#include "Baloon.h"

#include <vector>
#include <iostream>

#include <Core/Engine.h>
#include "TemaTransform2D.h"
#include "TemaObject2D.h"

using namespace std;



class Tema1 : public SimpleScene
{
public:
	Tema1();
	~Tema1();

	void Init() override;

private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
	
	void renderBow();
	void renderPower();
	
	void RenderArrow(Arrow arrow);
	void RenderShuriken(Shuriken shuriken);

	bool arrowColisionCheck(Arrow arrow, float checkX, float checkY, float checkXLength, float checkYLength);
	void RenderBaloon(Baloon baloon);
	bool playerColisionCheck(float checkX, float checkY, float checkXLength, float checkYLength);
	void pointColisionLogic();
	void playerColisionLogic();
	void arrowLogic(float deltaTimeSeconds);
	void shurikenLogic(float deltaTimeSeconds);
	void baloonLogic(float deltaTimeSeconds);
	void aliveLoop(float deltaTimeSeconds);

	// Draw the hud
	void drawAliveHud();
	void drawDeadHud();
	void drawPauseHud();
	void drawViewControlsHud();

	void initMeshes();
	void resetValues();
	

protected:
	//resolutia originala de la care plec
	glm::ivec2 res = window->GetResolution();
	glm::mat3 modelMatrix;
	glm::vec3 origin = glm::vec3(0, 0, 0);

	//world properies
	float originGravityConstant = 70;
	float gravityConstant = originGravityConstant;

	//player properies
	int maxLives = 3;
	int lives = maxLives;
	int points = 0;


	//bow properies
	float bowLength = float(res.y / 16);
	glm::vec3 gripSpot = glm::vec3(0, 0, 0);
	int riserSegments = 40;
	glm::vec3 raiserColor = glm::vec3(0.545, 0.271, 0.075);
	glm::vec3 stringColor = glm::vec3(1, 1, 1);
	float bowYscaleup = float(1.6);
	float pozBowX = float(bowLength * 2.5), pozBowY = float(res.y/2);
	float bowVelocity = float(res.y / 4);
	float bowAngle = 0;

	//arrow properies
	float arrowLength = float(bowLength * 1.5);
	float arrowGrith = float(arrowLength / 6);
	glm::vec3 shaftColor = glm::vec3(0.804, 0.522, 0.247);
	glm::vec3 tipColor = glm::vec3(0.502, 0.502, 0.502);
	std::vector<Arrow> arrowData;


	//power bar and shooting properies
	float power = 0;
	float powerSpeed = 1;
	float maxPower = 2;
	float canShoot = 1;
	float waitShoot = 0;
	float waitTimeShoot = 2;
	float arrowPowerModifier = 250;

	//shuriken properies
	float originShurikenXVelocity = 100;
	float originShurikenRotVelocity = 5;
	float originShurikenTimeBewtweenSpawns = 3;

	float shurikenXVelocity = originShurikenXVelocity;
	float shurikenRotVelocity = originShurikenRotVelocity;
	float shurikenLength = bowLength;
	std::vector<Shuriken> shurikenData;

	//shuriken spawn properies
	float shurikenSpawnTimer = 0;
	float shurikenTimeBewtweenSpawns = originShurikenTimeBewtweenSpawns;
	bool canSpawnShuriken = true;

	//baloon properies
	float originBaloonTimeBewtweenSpawns = 5;
	float originBaloonPositiveChance = 70;
	float originBaloonYVelocity = 30;

	float baloonYscaleup = float(1.4);
	float baloonRadius = float(bowLength / 1.5);
	
	float baloonYVelocity = originBaloonYVelocity;
	int baloonCircleSegments = 40;
	std::vector<Baloon> baloonData;

	//baloon spawn properies
	//0-100
	float baloonPositiveChance = originBaloonPositiveChance;
	float baloonSpawnTimer = 0;
	float baloonTimeBewtweenSpawns = originBaloonTimeBewtweenSpawns;
	bool canSpawnBaloon = true;

	

	int baloonPositivePoints = 10;
	int baloonNegativePoints = 5;
	int shurikenPoints = 5;

	//game logic properies
	float deltaModifier = 1;

	bool pause = 1;
	bool viewControls = 1;

	bool invincibleMode = 0;

	bool tripped = false;
	int deltaNextLvl = 20;
	int nextLevel = 1;

	// The text renderer
	TextRenderer* Text;

	
};

