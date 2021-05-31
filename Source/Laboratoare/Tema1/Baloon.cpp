#include "Baloon.h"
#include <stdlib.h>



Baloon::Baloon(float xPoz, float yPoz, float baloonRadius, float baloonYscaleup, float baloonYVelocity, bool positive) {
	this->xPoz = xPoz;
	this->yPoz = yPoz;
	this->baloonRadius = baloonRadius;
	this->baloonYscaleup = baloonYscaleup;
	this->positive = positive;
	this->shot = false;
	this->baloonXVelocity = 10;
	this->baloonYVelocity = baloonYVelocity;
	this->baloonScale = 1;
	this->baloonTime = 0;
	this->animationTime = 7;
	this->baloonUpTime = 6;
	this->boundBox = 10;
	this->goRight = rand() % 2;
	this->originalXPoz = xPoz;
	this->baloonAngle = 0;
	this->baloonAngleSpeed = float((rand() % 2000 + 1)) / 100.0f;
	this->baloonScaleSpeed = float((rand() % 200 + 1)) / 100.0f;
}

Baloon::~Baloon() {
}

void Baloon::baloonUpdate(float deltaTimeSeconds, float baloonYVelocity) {
	this->baloonTime += deltaTimeSeconds;

	if (this->baloonTime >= this->animationTime) {
		this->baloonTime = 0;
	}

	if (!this->shot) {

		if (this->baloonTime <= this->baloonUpTime) {
			this->yPoz += baloonYVelocity * deltaTimeSeconds;
		}
		else {
			this->yPoz -= baloonYVelocity / 10.0f * deltaTimeSeconds;
		}

		if (this->goRight) {
			this->xPoz += this->baloonXVelocity * deltaTimeSeconds;
		}
		else {
			this->xPoz -= this->baloonXVelocity * deltaTimeSeconds;
		}

		if (this->originalXPoz + boundBox <= xPoz) {
			this->goRight = false;
		}

		if (this->originalXPoz - boundBox >= xPoz) {
			this->goRight = true;
		}

	}
	else {
		this->xPoz += this->baloonXVelocity * deltaTimeSeconds;
		this->yPoz += this->baloonYVelocity * deltaTimeSeconds;
		this->baloonAngle += this->baloonAngleSpeed * deltaTimeSeconds;
		this->baloonScale -= this->baloonScaleSpeed * deltaTimeSeconds;
	}



}

bool Baloon::baloonCheckBoundries(glm::ivec2 resolution) {

	float safetyOffset = 40;

	if (this->baloonScale <= 0) {
		return 0;
	}

	if (this->xPoz + this->baloonRadius + safetyOffset < 0) {
		return 0;
	}

	if (this->xPoz - this->baloonRadius - safetyOffset > resolution.x) {
		return 0;
	}

	if (this->yPoz + this->baloonRadius * this->baloonYscaleup + safetyOffset < 0) {

		return 0;
	}

	if (this->yPoz - this->baloonRadius * this->baloonYscaleup - safetyOffset > resolution.y) {

		return 0;
	}


	return 1;

 }