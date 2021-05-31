#include "Tema1.h"


void Tema1::initMeshes() {

	Mesh* bow = TemaObject2D::CreateBow("bow", gripSpot, bowLength, riserSegments, raiserColor, stringColor);
	AddMeshToList(bow);

	Mesh* arrow = TemaObject2D::CreateArrow("arrow", origin, arrowLength, arrowGrith, shaftColor, tipColor);
	AddMeshToList(arrow);

	Mesh* square1 = TemaObject2D::CreateSquare("frameSquare", origin, bowLength, glm::vec3(1, 0, 0), false);
	AddMeshToList(square1);

	Mesh* square2 = TemaObject2D::CreateSquare("powerSquare", origin, bowLength, glm::vec3(0.855, 0.647, 0.125), true);
	AddMeshToList(square2);

	Mesh* shuriken = TemaObject2D::CreateShuriken("shuriken", origin, bowLength, glm::vec3(0.412, 0.412, 0.412));
	AddMeshToList(shuriken);

	Mesh* baloonCirclePositive = TemaObject2D::CreateCircle("baloonCirclePositive", origin, baloonRadius, baloonCircleSegments, glm::vec3(1, 0, 0));
	AddMeshToList(baloonCirclePositive);

	Mesh* baloonTrianglePositive = TemaObject2D::CreateTriangle("baloonTrianglePositive", origin, baloonRadius / 2, glm::vec3(1, 0, 0));
	AddMeshToList(baloonTrianglePositive);

	Mesh* baloonCircleNegative = TemaObject2D::CreateCircle("baloonCircleNegative", origin, baloonRadius, baloonCircleSegments, glm::vec3(1.000, 1.000, 0.000));
	AddMeshToList(baloonCircleNegative);

	Mesh* baloonTriangleNegative = TemaObject2D::CreateTriangle("baloonTriangleNegative", origin, baloonRadius / 2, glm::vec3(1.000, 1.000, 0.000));
	AddMeshToList(baloonTriangleNegative);

	Mesh* heart = TemaObject2D::CreateHeart("heart", origin, bowLength / 3, glm::vec3(1.000, 0.412, 0.706));
	AddMeshToList(heart);

}

void Tema1::resetValues() {

	lives = maxLives;
	shurikenData.clear();
	baloonData.clear();
	arrowData.clear();
	points = 0;
	pozBowX = float(bowLength * 2.5);
	pozBowY = float(res.y / 2);
	bowAngle = 0;
	power = 0;
	canShoot = 1;
	waitShoot = 0;

	shurikenSpawnTimer = 0;
	canSpawnShuriken = true;
	shurikenRotVelocity = originShurikenRotVelocity;
	shurikenXVelocity = originShurikenXVelocity;
	shurikenTimeBewtweenSpawns = originShurikenTimeBewtweenSpawns;

	baloonSpawnTimer = 0;
	canSpawnBaloon = true;
	baloonTimeBewtweenSpawns = originBaloonTimeBewtweenSpawns;
	baloonYVelocity = originBaloonYVelocity;
	baloonPositiveChance = originBaloonPositiveChance;

	deltaModifier = 1;
	nextLevel = 1;

	invincibleMode = false;

	gravityConstant = originGravityConstant;

}
