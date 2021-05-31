#pragma once

#include <Core/Engine.h>


class Arrow {
public:
	float xPoz;
	float yPoz;

	float angle;

	float xVelocity;
	float yVelocity;
	float arrowLength;

	Arrow(float xPoz, float yPoz, float angle, float xVelocity, float yVelocity, float arrowLength);

	~Arrow();

	void arrowUpdate(float deltaTimeSeconds);

	void arrowUpdate(float deltaTimeSeconds, float gravityConstant);

	bool arrowCheckBoundries(glm::ivec2 resolution);
};
