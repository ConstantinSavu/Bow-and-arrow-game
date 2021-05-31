#pragma once
#include <Core/Engine.h>

class Baloon {
public:
	float xPoz;
	float yPoz;

	float baloonRadius;
	float baloonYscaleup;

	bool positive;

	float baloonXVelocity;
	float baloonYVelocity;

	float baloonScale;

	bool shot;
	float baloonTime;
	float animationTime;
	float baloonUpTime;
	float boundBox;
	bool goRight;
	float originalXPoz;
	float baloonAngle;
	float baloonAngleSpeed;
	float baloonScaleSpeed;

	Baloon(float xPoz, float yPoz, float baloonRadius, float baloonYscaleup, float baloonYVelocity, bool positive);

	~Baloon();

	void baloonUpdate(float deltaTimeSeconds, float baloonYVelocity);

	bool baloonCheckBoundries(glm::ivec2 resolution);
};