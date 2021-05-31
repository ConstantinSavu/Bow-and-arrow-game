#include "Tema1.h"



void Tema1::RenderArrow(Arrow arrow) {

	modelMatrix = glm::mat3(1);
	modelMatrix *= TemaTransform2D::Translate(arrow.xPoz, arrow.yPoz);
	modelMatrix *= TemaTransform2D::Rotate(arrow.angle);
	modelMatrix *= TemaTransform2D::Translate(-arrowLength / 2 + bowLength / 2, 0);
	RenderMesh2D(meshes["arrow"], shaders["VertexColor"], modelMatrix);

}


void Tema1::RenderShuriken(Shuriken shuriken) {

	modelMatrix = glm::mat3(1);
	modelMatrix *= TemaTransform2D::Translate(shuriken.xPoz, shuriken.yPoz);
	modelMatrix *= TemaTransform2D::Rotate(shuriken.angle);
	RenderMesh2D(meshes["shuriken"], shaders["VertexColor"], modelMatrix);

}

void Tema1::renderBow() {

	modelMatrix = glm::mat3(1);
	modelMatrix *= TemaTransform2D::Translate(pozBowX, pozBowY);
	modelMatrix *= TemaTransform2D::Rotate(bowAngle);
	modelMatrix *= TemaTransform2D::Scale(1, bowYscaleup);
	RenderMesh2D(meshes["bow"], shaders["VertexColor"], modelMatrix);


	//arrow
	if (canShoot == 1) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= TemaTransform2D::Translate(pozBowX, pozBowY);
		modelMatrix *= TemaTransform2D::Rotate(bowAngle);
		modelMatrix *= TemaTransform2D::Translate(-arrowLength / 2 + bowLength / 2, 0);
		RenderMesh2D(meshes["arrow"], shaders["VertexColor"], modelMatrix);
	}

	for (int i = 0; i < lives; i++) {
		modelMatrix = glm::mat3(1);
		modelMatrix *= TemaTransform2D::Translate(pozBowX - bowLength * 2 , pozBowY - bowLength+ (bowLength / 3 + 20) * i);
		RenderMesh2D(meshes["heart"], shaders["VertexColor"], modelMatrix);
	}

}

void Tema1::renderPower() {

	//powerFrame
	modelMatrix = glm::mat3(1);

	modelMatrix *= TemaTransform2D::Translate(pozBowX - bowLength * 2, pozBowY - bowLength * bowYscaleup - bowLength / 2);


	modelMatrix *= TemaTransform2D::Scale(maxPower, 0.5);
	modelMatrix *= TemaTransform2D::Translate(bowLength / 2, 0);

	RenderMesh2D(meshes["frameSquare"], shaders["VertexColor"], modelMatrix);

	//powerBar

	modelMatrix = glm::mat3(1);
	modelMatrix *= TemaTransform2D::Translate(pozBowX - bowLength * 2, pozBowY - bowLength * bowYscaleup - bowLength / 2);


	modelMatrix *= TemaTransform2D::Scale(power, 0.5);
	modelMatrix *= TemaTransform2D::Translate(bowLength / 2, 0);

	RenderMesh2D(meshes["powerSquare"], shaders["VertexColor"], modelMatrix);

}

void Tema1::RenderBaloon(Baloon baloon) {

	modelMatrix = glm::mat3(1);
	modelMatrix *= TemaTransform2D::Translate(baloon.xPoz, baloon.yPoz);
	modelMatrix *= TemaTransform2D::Rotate(baloon.baloonAngle);
	modelMatrix *= TemaTransform2D::Scale(baloon.baloonScale, baloon.baloonYscaleup * baloon.baloonScale);

	if (baloon.positive) {
		RenderMesh2D(meshes["baloonCirclePositive"], shaders["VertexColor"], modelMatrix);
	}
	else {
		RenderMesh2D(meshes["baloonCircleNegative"], shaders["VertexColor"], modelMatrix);

	}

	modelMatrix = glm::mat3(1);
	modelMatrix *= TemaTransform2D::Translate(baloon.xPoz, baloon.yPoz);
	modelMatrix *= TemaTransform2D::Rotate(baloon.baloonAngle);
	modelMatrix *= TemaTransform2D::Translate(0, (-baloon.baloonRadius * baloon.baloonYscaleup - baloon.baloonRadius / 4) * baloon.baloonScale);
	modelMatrix *= TemaTransform2D::Scale(baloon.baloonScale, baloon.baloonScale);

	if (baloon.positive) {
		RenderMesh2D(meshes["baloonTrianglePositive"], shaders["VertexColor"], modelMatrix);
	}
	else {
		RenderMesh2D(meshes["baloonTriangleNegative"], shaders["VertexColor"], modelMatrix);
	}
}
