#include "Arrow.h"

Arrow::Arrow(float xPoz, float yPoz, float angle, float xVelocity, float yVelocity, float arrowLength) {
	this->xPoz = xPoz;
	this->yPoz = yPoz;
	this->angle = angle;
	this->xVelocity = xVelocity;
	this->yVelocity = yVelocity;
	this->arrowLength = arrowLength;
}

Arrow::~Arrow() {

}

void Arrow::arrowUpdate(float deltaTimeSeconds) {
	this->xPoz += this->xVelocity * deltaTimeSeconds;

	this->yPoz += this->yVelocity * deltaTimeSeconds;
}

void Arrow::arrowUpdate(float deltaTimeSeconds, float gravityConstant) {
	this->xPoz += this->xVelocity * deltaTimeSeconds;

	this->yVelocity -= gravityConstant * deltaTimeSeconds;
	this->yPoz += this->yVelocity * deltaTimeSeconds;

	this->angle = atan2(this->yVelocity, this->xVelocity);
	}

bool Arrow::arrowCheckBoundries(glm::ivec2 resolution) {

	float safetyOffset = 10;

	if (this->xPoz + this->arrowLength + safetyOffset < 0) {
		return 0;
	}

	if (this->xPoz - this->arrowLength - safetyOffset > resolution.x) {
		return 0;
	}

	if (this->yPoz + this->arrowLength + safetyOffset < 0) {
		return 0;
	}


	return 1;

}

