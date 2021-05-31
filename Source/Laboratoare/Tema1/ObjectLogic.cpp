#include "Tema1.h"

//check colision between an arrow and a rectangle with dimensions checkXLength and checkYLength, (centered in checkX, checkY)
bool Tema1::arrowColisionCheck(Arrow arrow, float checkX, float checkY, float checkXLength, float checkYLength) {


	//punct de coliziune al sagetii (imediat dupa triunghi)
	float xOriginPoint = arrow.arrowLength / 2;
	float yOriginPoint = 0;

	//rotatie si tranzatie a punctului de coliziune
	float xColisionPoint = xOriginPoint * cos(arrow.angle) - yOriginPoint * sin(arrow.angle) + arrow.xPoz;
	float yColisionPoint = xOriginPoint * sin(arrow.angle) + yOriginPoint * cos(arrow.angle) + arrow.yPoz;

	/*
	
	*/

	
	float distance = sqrt( (xColisionPoint - checkX) * (xColisionPoint - checkX) +
							(yColisionPoint - checkY) * (yColisionPoint - checkY));


	//verifica daca este in interiorul cercului de raza checkXLength / 2
	if (distance < checkXLength / 2) {
		return true;
	}
	else {
		//verifica daca este in interiorul dreptungiului determinat de checkX - checkXLength / 2  si checkX + checkXLength / 2
		//apoi daca este in interiorul cercului de raza checkYLength / 2 
		if (checkX - checkXLength / 2 < xColisionPoint && xColisionPoint < checkX + checkXLength / 2) {
			return distance < checkYLength / 2;
		}

		return false;
	}
	return false;
}


bool Tema1::playerColisionCheck(float checkX, float checkY, float checkXLength, float checkYLength) {



	float xOriginPoint, yOriginPoint;

	xOriginPoint = -bowLength / 2;
	yOriginPoint = 0;

	float xColisionPoint = xOriginPoint * cos(bowAngle) - yOriginPoint * sin(bowAngle) + pozBowX;
	float yColisionPoint = xOriginPoint * sin(bowAngle) + yOriginPoint * cos(bowAngle) + pozBowY;

	float distance = sqrt((xColisionPoint - checkX) * (xColisionPoint - checkX) +
		(yColisionPoint - checkY) * (yColisionPoint - checkY));


	return (distance < checkXLength / 2 + bowLength);
	
	


	/*
	* Varianta asta merge mai bine decat cea de sus
	* Nu este perfecta
	* 
	float aMinX, aMaxX, aMinY, aMaxY;
	float bMinX, bMaxX, bMinY, bMaxY;


	aMinX = -bowLength;
	aMinY = -bowLength * bowYscaleup;


	aMaxX = 0;
	aMaxY = bowLength * bowYscaleup;

	glm::mat3 curentPoz = glm::mat3(
		aMinX, aMinY, 1,
		aMaxX, aMaxY, 1,
		0, 0, 0
	);

	modelMatrix = glm::mat3(1);
	modelMatrix *= TemaTransform2D::Translate(pozBowX, pozBowY);
	modelMatrix *= TemaTransform2D::Rotate(bowAngle);
	modelMatrix *= curentPoz;


	aMinX = modelMatrix[0][0];
	aMaxX = modelMatrix[1][0];

	//se corecteaza pentru aMinX si aMaxX
	if (modelMatrix[0][0] > modelMatrix[1][0]) {
		aMinX = modelMatrix[1][0];
		aMaxX = modelMatrix[0][0];
	}

	aMinY = modelMatrix[0][1];
	aMaxY = modelMatrix[1][1];

	//se corecteaza pentru aMinY si aMaxY
	if (modelMatrix[0][1] > modelMatrix[1][1]) {
		aMinY = modelMatrix[1][1];
		aMaxY = modelMatrix[0][1];
	}



	bMinX = checkX - checkXLength / 2.0f;
	bMaxX = checkX + checkXLength / 2.0f;

	bMinY = checkY - checkYLength / 2.0f;
	bMaxY = checkY + checkYLength / 2.0f;

	return (aMinX <= bMaxX && aMaxX >= bMinX) && (aMinY <= bMaxY && aMaxY >= bMinY);
	*/

}

void Tema1::pointColisionLogic() {

	for (int i = 0; i < arrowData.size(); i++) {

		bool destroyArrow = false;

		for (int j = 0; j < shurikenData.size(); j++) {

			if (arrowColisionCheck(arrowData[i], shurikenData[j].xPoz, shurikenData[j].yPoz, shurikenData[j].shurikenLength, shurikenData[j].shurikenLength)) {

				if (!shurikenData[j].shot) {

					shurikenData[j].shot = true;
					shurikenData[j].shurikenRotVelocity /= 2.0f;
					shurikenData[j].shurikenXVelocity = arrowData[i].xVelocity / 6.0f;
					shurikenData[j].shurikenYVelocity = arrowData[i].yVelocity / 8.0f;
					destroyArrow = true;
					points += shurikenPoints;

				}
			}

		}

		for (int j = 0; j < baloonData.size(); j++) {

			if (arrowColisionCheck(arrowData[i], baloonData[j].xPoz, baloonData[j].yPoz, baloonData[j].baloonRadius * 2, baloonData[j].baloonRadius * baloonData[j].baloonYscaleup * 2)) {

				if (!baloonData[j].shot) {
					if (baloonData[j].positive) {
						points += baloonPositivePoints;
					}
					else {
						points -= baloonNegativePoints;
					}

					baloonData[j].shot = true;
					baloonData[j].baloonXVelocity = arrowData[i].xVelocity / 2.0f;
					baloonData[j].baloonYVelocity = arrowData[i].yVelocity;


					destroyArrow = true;
				}

			}

		}

		if (destroyArrow) {
			arrowData.erase(arrowData.begin() + i);
			i--;
		}

	}
}

void Tema1::playerColisionLogic() {

	for (int i = 0; i < shurikenData.size(); i++) {
		if (playerColisionCheck(shurikenData[i].xPoz, shurikenData[i].yPoz, shurikenData[i].shurikenLength, shurikenData[i].shurikenLength)) {
			
			if (!shurikenData[i].hitPlayer) {
				shurikenData[i].shot = true;
				shurikenData[i].hitPlayer = true;
				shurikenData[i].shurikenXVelocity /= 4.0f;

				if (!invincibleMode) {
					lives--;
				}
			}
		}
	}


}

void Tema1::arrowLogic(float deltaTimeSeconds) {

	for (int i = 0; i < arrowData.size(); i++) {
		arrowData[i].arrowUpdate(deltaTimeSeconds, gravityConstant);
		if (arrowData[i].arrowCheckBoundries(res)) {
			RenderArrow(arrowData[i]);
		}
		else {
			arrowData.erase(arrowData.begin() + i);
			i--;
		}
	}

}

void Tema1::shurikenLogic(float deltaTimeSeconds) {
	if (canSpawnShuriken) {

		float randomY;
		float safetyOffset = shurikenLength;
		randomY = rand() % int((res.y - safetyOffset * 2)) + safetyOffset;

		Shuriken newShuriken(float(res.x), randomY, shurikenLength, shurikenXVelocity, shurikenRotVelocity);
		shurikenData.push_back(newShuriken);

		canSpawnShuriken = false;
	}
	else {
		shurikenSpawnTimer += deltaTimeSeconds;
	}

	if (shurikenSpawnTimer >= shurikenTimeBewtweenSpawns) {
		shurikenSpawnTimer = 0;
		canSpawnShuriken = true;
	}

	for (int i = 0; i < shurikenData.size(); i++) {
		shurikenData[i].shurikenUpdate(deltaTimeSeconds, gravityConstant);
		if (shurikenData[i].shurikenCheckBoundries(res)) {
			RenderShuriken(shurikenData[i]);
		}
		else {
			shurikenData.erase(shurikenData.begin() + i);
		}
	}
}

void Tema1::baloonLogic(float deltaTimeSeconds) {
	if (canSpawnBaloon) {

		float randomX;
		float safetyOffset = baloonRadius * 2 + bowLength * 4;
		randomX = rand() % int((res.x - baloonRadius * 4 - +bowLength * 8)) + safetyOffset;

		bool positiveBaloon = false;

		if (baloonPositiveChance >= (rand() % 100)) {

			positiveBaloon = true;

		}


		Baloon newBaloon(randomX, -baloonRadius * baloonYscaleup, baloonRadius, baloonYscaleup, baloonYVelocity, positiveBaloon);


		baloonData.push_back(newBaloon);

		canSpawnBaloon = false;
	}
	else {
		baloonSpawnTimer += deltaTimeSeconds;
	}

	if (baloonSpawnTimer >= baloonTimeBewtweenSpawns) {
		baloonSpawnTimer = 0;
		canSpawnBaloon = true;
	}

	for (int i = 0; i < baloonData.size(); i++) {
		baloonData[i].baloonUpdate(deltaTimeSeconds, baloonYVelocity);
		if (baloonData[i].baloonCheckBoundries(res)) {
			RenderBaloon(baloonData[i]);
		}
		else {
			baloonData.erase(baloonData.begin() + i);
		}
	}
}
