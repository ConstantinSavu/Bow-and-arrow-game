#pragma once
#include <Core/Engine.h>

class Shuriken {
public:
	float xPoz;
	float yPoz;

	float angle;
	float shurikenLength;

	bool shot;

	float shurikenYVelocity;
	float shurikenXVelocity;
	float shurikenRotVelocity;

	float hitPlayer;


	Shuriken(float xPoz, float yPoz, float shurikenLenght, float shurikenXVelocity, float shurikenRotVelocity);

	~Shuriken();
	void shurikenUpdate(float deltaTimeSeconds, float gravityConstant);

	bool shurikenCheckBoundries(glm::ivec2 resolution);
};