#pragma once

#include <string>

#include <include/glm.h>
#include <Core/GPU/Mesh.h>

constexpr auto MAXNRSEGMENTS = 100;

namespace TemaObject2D
{

	// Create square with given bottom left corner, length and color
	Mesh* CreateSquare(std::string name, glm::vec3 leftBottomCorner, float length, glm::vec3 color, bool fill = false);

	Mesh* CreateBow(std::string name, glm::vec3 gripSpot, float length, int risterSegments, glm::vec3 riserColor, glm::vec3 stringColor);

	Mesh* CreateArrow(std::string name, glm::vec3 middleSpot, float length, float tipGirth, glm::vec3 shaftColor, glm::vec3 tipColor);

	Mesh* CreateShuriken(std::string name, glm::vec3 middleSpot, float shurikenLenght, glm::vec3 shurikenColor);

	Mesh* CreateTriangle(std::string name, glm::vec3 origin, float lenght, glm::vec3 color);

	Mesh* CreateCircle(std::string name, glm::vec3 origin, float radius, float segments, glm::vec3 color);

	Mesh* CreateHeart(std::string name, glm::vec3 origin, float lenght, glm::vec3 color);



}

