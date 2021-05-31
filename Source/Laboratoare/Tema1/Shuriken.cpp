#include "Shuriken.h"




Shuriken::Shuriken(float xPoz, float yPoz, float shurikenLenght, float shurikenXVelocity, float shurikenRotVelocity) {
	this->xPoz = xPoz;
	this->yPoz = yPoz;
	this->shurikenLength = shurikenLenght;
	this->angle = 0;
	this->shot = false;
	this->shurikenYVelocity = 0;
	this->shurikenXVelocity = shurikenXVelocity;
	this->shurikenRotVelocity = shurikenRotVelocity;
	this->hitPlayer = false;
}

Shuriken::~Shuriken() {

}

void Shuriken::shurikenUpdate(float deltaTimeSeconds, float gravityConstant) {

	if (!this->shot) {
		this->xPoz -= this->shurikenXVelocity * deltaTimeSeconds;
		this->angle += this->shurikenRotVelocity * deltaTimeSeconds;
	}
	else {
		this->xPoz += this->shurikenXVelocity * deltaTimeSeconds;
		this->shurikenYVelocity -= gravityConstant * deltaTimeSeconds;
		this->yPoz += this->shurikenYVelocity * deltaTimeSeconds;
		this->angle -= this->shurikenRotVelocity * deltaTimeSeconds;

	}
}

bool Shuriken::shurikenCheckBoundries(glm::ivec2 resolution) {

	float safetyOffset = 40;

	if (this->xPoz + this->shurikenLength + safetyOffset < 0) {
		return 0;
	}

	if (this->xPoz - this->shurikenLength - safetyOffset > resolution.x) {

		return 0;
	}

	if (this->yPoz + this->shurikenLength + safetyOffset < 0) {

		return 0;
	}

	if (this->yPoz - this->shurikenLength - safetyOffset > resolution.y) {

		return 0;
	}


	return 1;

}


