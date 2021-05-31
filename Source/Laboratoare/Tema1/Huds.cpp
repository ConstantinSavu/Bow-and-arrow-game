#include "Tema1.h"

void Tema1::drawDeadHud() {
	Text->RenderText("Reached level " + std::to_string(nextLevel - 1), res.x / 2 - 500, res.y / 2 - 100, 5.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Total points " + std::to_string(points), res.x / 2 - 400, res.y / 2, 5.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Press R to restart", res.x / 2 - 300, res.y / 2 + 100, 2.0f, glm::vec3(1.0, 1.0, 1.0));

}

void Tema1::drawAliveHud() {


	Text->RenderText("Points: " + std::to_string(points), 5.0f, 5.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Curent level: " + std::to_string(nextLevel - 1), 150.0f, 5.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Press R to restart", 350.0f, 5.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Press P to pause", 550.0f, 5.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));

}

void Tema1::drawPauseHud() {
	Text->RenderText("Game Paused", res.x / 2 - 400, res.y / 2, 5.0f, glm::vec3(1.0, 1.0, 1.0));
}

void Tema1::drawViewControlsHud() {

	std::string deltaModifierString = std::to_string(deltaModifier).substr(0, 4);
	std::string gravityModifier = std::to_string( gravityConstant/originGravityConstant ).substr(0, 4);


	Text->RenderText("LCtrl - Hide/Reveal this HUD", res.x - 300, 5.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("W - up", res.x - 300, 30.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("S - down", res.x - 300, 55.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("L_Click - charge/shoot", res.x - 300, 80.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("R_Click - reset charge", res.x - 300, 105.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Space - speed up time", res.x - 300, 130.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("LShift - slow down time", res.x - 300, 155.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("I - toggle Invicible Mode", res.x - 300, 180.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("L - manually increase level", res.x - 300, 205.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("K - manually decrease lives", res.x - 300, 230.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Time speedup:" + deltaModifierString, res.x - 300, 255.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));
	Text->RenderText("Gravity modifier: " + gravityModifier, res.x - 300, 280.0f, 1.0f, glm::vec3(1.0, 1.0, 1.0));




}
