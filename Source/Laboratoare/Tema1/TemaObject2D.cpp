#include "TemaObject2D.h"

#include <Core/Engine.h>

Mesh* TemaObject2D::CreateSquare(std::string name, glm::vec3 center, float length, glm::vec3 color, bool fill)
{
	glm::vec3 origin = center;

	std::vector<VertexFormat> vertices =
	{
		VertexFormat(origin + glm::vec3(-length/2, -length/2, 0), color), //0
		VertexFormat(origin + glm::vec3(length/2, -length/2, 0), color), //1
		VertexFormat(origin + glm::vec3(length/2, length/2, 0), color), //2
		VertexFormat(origin + glm::vec3(-length/2, length/2, 0), color) //3
	};

	Mesh* square = new Mesh(name);
	std::vector<unsigned short> indices = { 0, 1, 2, 3 };
	
	if (!fill) {
		square->SetDrawMode(GL_LINE_LOOP);
	}
	else {
		// draw 2 triangles. Add the remaining 2 indices
		indices.push_back(0);
		indices.push_back(2);
	}

	square->InitFromData(vertices, indices);
	return square;
}

Mesh* TemaObject2D::CreateBow(std::string name, glm::vec3 gripSpot, float length, int risterSegments ,glm::vec3 riserColor, glm::vec3 stringColor)
{
	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;
	
	if (risterSegments > MAXNRSEGMENTS) {
		
		risterSegments = MAXNRSEGMENTS;
	}

	float r = length;
	Mesh* bow = new Mesh(name);
	bow -> SetDrawMode(GL_LINE_STRIP);

	
	int i;
	for (i = 0; i <= risterSegments; i++) {
		float theta = 3.1415926f * float(i) / float(risterSegments) - 3.1415926f / 2.0f;
		
		vertices.push_back(VertexFormat(gripSpot - glm::vec3(r, 0, 0) + glm::vec3(r * cosf(theta), r * sinf(theta), 0), riserColor));
		
		indices.push_back(i);
	}

	vertices.push_back(VertexFormat(gripSpot - glm::vec3(r,0,0) + glm::vec3(0, r, 0), stringColor));
	indices.push_back(i);

	vertices.push_back(VertexFormat(gripSpot - glm::vec3(r, 0, 0) + glm::vec3(0, -r, 0), stringColor));
	indices.push_back(i + 1);

	bow->InitFromData(vertices, indices);

	return bow;

}

Mesh* TemaObject2D::CreateArrow(std::string name, glm::vec3 middleSpot, float shaftLength, float tipGirth, glm::vec3 shaftColor, glm::vec3 tipColor) {

	std::vector<VertexFormat> vertices = {

		VertexFormat(middleSpot - glm::vec3(shaftLength / 2 , 1, 0), shaftColor), //0
		VertexFormat(middleSpot - glm::vec3(shaftLength / 2 , -1, 0), shaftColor), //1

		VertexFormat(middleSpot + glm::vec3(shaftLength / 2 , 1, 0), shaftColor), //2
		VertexFormat(middleSpot + glm::vec3(shaftLength / 2 , -1, 0), shaftColor), //3

		VertexFormat(middleSpot + glm::vec3(shaftLength / 2 + tipGirth, 0, 0), tipColor), //4
		VertexFormat(middleSpot + glm::vec3(shaftLength / 2, -tipGirth / 2, 0), tipColor), //5
		VertexFormat(middleSpot + glm::vec3(shaftLength / 2, tipGirth / 2, 0), tipColor), //5



		
	};

	Mesh* arrow = new Mesh(name);
	arrow -> SetDrawMode(GL_TRIANGLE_STRIP);

	std::vector<unsigned short> indices = {
	
		0, 3, 1,
		3, 1, 2,
		2, 3, 4,
		6, 4, 2,
		3, 4, 5
	};


	arrow -> InitFromData(vertices, indices);

	return arrow;

}

Mesh* TemaObject2D::CreateShuriken(std::string name, glm::vec3 middleSpot, float shurikenLenght, glm::vec3 shurikenColor) {
	std::vector<VertexFormat> vertices = {
		VertexFormat(middleSpot, shurikenColor), //0
		VertexFormat(middleSpot + glm::vec3(-shurikenLenght / 2 , shurikenLenght / 2 , 0), shurikenColor), //1
		VertexFormat(middleSpot + glm::vec3(0 , shurikenLenght / 2 , 0), shurikenColor), //2
		VertexFormat(middleSpot + glm::vec3(shurikenLenght / 2 , shurikenLenght / 2 , 0), shurikenColor), //3
		VertexFormat(middleSpot + glm::vec3(shurikenLenght / 2 , 0 , 0), shurikenColor), //4
		VertexFormat(middleSpot + glm::vec3(shurikenLenght / 2 , -shurikenLenght / 2 , 0), shurikenColor), //5
		VertexFormat(middleSpot + glm::vec3(0 , -shurikenLenght / 2 , 0), shurikenColor), //6
		VertexFormat(middleSpot + glm::vec3(-shurikenLenght / 2 , -shurikenLenght / 2 , 0), shurikenColor), //7
		VertexFormat(middleSpot + glm::vec3(-shurikenLenght / 2 , 0 , 0), shurikenColor), //8
	};
	Mesh* shuriken = new Mesh(name);
	shuriken->SetDrawMode(GL_TRIANGLE_FAN);
	std::vector<unsigned short> indices = {
		0,1,2,
		0,3,4,
		0,5,6,
		0,7,8
	};

	shuriken->InitFromData(vertices, indices);

	return shuriken;
}

Mesh* TemaObject2D::CreateTriangle(std::string name, glm::vec3 origin, float lenght, glm::vec3 color) {
	
	float x = lenght * sin(M_PI / 4);

	std::vector<VertexFormat> vertices = {
		VertexFormat(origin + glm::vec3(-x, 0, 0), color), //0
		VertexFormat(origin + glm::vec3(0, x, 0), color), //1
		VertexFormat(origin + glm::vec3(x, 0, 0), color), //1
	};
	Mesh* triangle = new Mesh(name);
	std::vector<unsigned short> indices = {
		0,1,2
	};

	triangle->InitFromData(vertices, indices);

	return triangle;
}

Mesh* TemaObject2D::CreateCircle(std::string name, glm::vec3 origin, float radius, float segments, glm::vec3 color) {

	std::vector<VertexFormat> vertices;
	std::vector<unsigned short> indices;

	if (segments > MAXNRSEGMENTS) {

		segments = MAXNRSEGMENTS;
	}

	Mesh* circle = new Mesh(name);

	circle->SetDrawMode(GL_TRIANGLE_FAN);



	for (int i = 0; i <= segments; i++) {
		float theta = 2.0f * 3.1415926f * float(i) / float(segments);

		vertices.push_back(VertexFormat(origin + glm::vec3(radius * cosf(theta), radius * sinf(theta), 0), color));

		indices.push_back(i);
	}

	

	circle->InitFromData(vertices, indices);
	return circle;

}

Mesh* TemaObject2D::CreateHeart(std::string name, glm::vec3 origin, float length, glm::vec3 color) {

	float l = length;

	std::vector<VertexFormat> vertices = {
		VertexFormat(origin + glm::vec3(0, 0, 0), color), //0
		VertexFormat(origin + glm::vec3(l, 2.0f/3.0f * l, 0),  glm::vec3(1.000, 1.000, 0.000)), //1
		VertexFormat(origin + glm::vec3(2.0f/3.0f * l, l, 0), glm::vec3(1.000, 1.000, 0.000)), //2
		VertexFormat(origin + glm::vec3(1.0f/3.0f * l, l, 0),  glm::vec3(1.000, 1.000, 0.000)), //3
		VertexFormat(origin + glm::vec3(0, 5.0f/6.0f * l, 0), color), //4
		VertexFormat(origin + glm::vec3(-1.0f/3.0f * l, l, 0), color), //5
		VertexFormat(origin + glm::vec3(-2.0f/3.0f * l, l, 0), color), //6
		VertexFormat(origin + glm::vec3(-l, 2.0f/3.0f * l , 0), color), //7


	};

	std::vector<unsigned short> indices = {
		0,1,2,3,4,5,6,7

	};

	Mesh* circle = new Mesh(name);

	circle->SetDrawMode(GL_TRIANGLE_FAN);

	circle->InitFromData(vertices, indices);
	return circle;
}