#include "Tema1.h"



Tema1::Tema1()
{
}

Tema1::~Tema1()
{
}


void Tema1::Init()
{
	glm::ivec2 resolution = window->GetResolution();
	auto camera = GetSceneCamera();
	camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
	camera->SetPosition(glm::vec3(0, 0, 50));
	camera->SetRotation(glm::vec3(0, 0, 0));
	camera->Update();
	GetCameraInput()->SetActive(false);

	Text = new TextRenderer(resolution.x, resolution.y);

	Text->Load("Source/TextRenderer/Fonts/Arial.ttf", 18);

	resetValues();
	initMeshes();

}

void Tema1::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);

	
}



void Tema1::Update(float deltaTimeSeconds)
{

	deltaTimeSeconds *= deltaModifier * pause;

	if (lives > 0) {
		aliveLoop(deltaTimeSeconds);
	}

}

void Tema1::FrameEnd()
{
	if (lives > 0) {
		drawAliveHud();
		if (pause == 0) {
			drawPauseHud();
		}
	}
	else {
		drawDeadHud();
	}

	if (viewControls) {
		drawViewControlsHud();
	}
	
}


void Tema1::OnInputUpdate(float deltaTime, int mods)
{	
	float safetyOffset = 10;

	deltaTime *= deltaModifier;

	if (window->KeyHold(GLFW_KEY_W) && pause == 1) {

		if (pozBowY + bowLength * bowYscaleup + bowLength * bowYscaleup / 3.0f + safetyOffset < res.y) {
			pozBowY += deltaTime * bowVelocity;
		}
	}
	
	if (window->KeyHold(GLFW_KEY_S) && pause == 1) {

		if (pozBowY - bowLength * bowYscaleup - bowLength * bowYscaleup / 3.0f - safetyOffset > 0) {
			pozBowY -= deltaTime * bowVelocity;
		}
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_1) && pause == 1) {

		if (canShoot == 1 && pause == 1) {
			if (power < maxPower) {
				power += deltaTime * powerSpeed;
			}

			else {
				power = maxPower;
			}
		}
	}

	if (window->KeyHold(GLFW_KEY_SPACE)) {
		deltaModifier += 0.01f;
	}

	if (window->KeyHold(GLFW_KEY_LEFT_SHIFT)) {
		if (deltaModifier >= 0) {
			deltaModifier -= 0.01f;
		}
		else {
			deltaModifier = 0;
		}
	}

	if (window->KeyHold(GLFW_KEY_UP)) {
		gravityConstant += 0.1f;
	}

	if (window->KeyHold(GLFW_KEY_DOWN)) {
		gravityConstant -= 0.1f;
	}
}

void Tema1::OnKeyPress(int key, int mods)
{
	if (key == GLFW_KEY_R) {

		resetValues();
	}

	if (key == GLFW_KEY_P) {
		if (lives > 0) {
			pause = !pause;
		}
	}

	if (key == GLFW_KEY_LEFT_CONTROL ) {
		viewControls = !viewControls;
	}

	if (key == GLFW_KEY_I) {
		invincibleMode = !invincibleMode;
	}

	if (key == GLFW_KEY_L) {
		points += deltaNextLvl;
	}

	if (key == GLFW_KEY_K) {
		lives --;
	}

}

void Tema1::OnKeyRelease(int key, int mods)
{
}

void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{	
	glm::ivec2 resolution = window->GetResolution();

	if (mouseX * res.x / resolution.x >= pozBowX && pause == 1) {
		float delta_X = mouseX * res.x / resolution.x - pozBowX;
		float delta_Y = (res.y - mouseY * res.y / resolution.y) - pozBowY;
		bowAngle = atan2(delta_Y, delta_X);
	}
	

}

void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event

	if (button == GLFW_MOUSE_BUTTON_3) {
		power = 0;
	} 
}

void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button release event
	if (button == GLFW_MOUSE_BUTTON_2) {

		if (canShoot == 1 && pause == 1) {
			
			if (power != 0) {
				Arrow newArrow(pozBowX, pozBowY, bowAngle, power * cos(bowAngle) * arrowPowerModifier, power * sin(bowAngle) * arrowPowerModifier, arrowLength);
				arrowData.push_back(newArrow);
			}

			power = 0;
			canShoot = 0;
		}

	}
}

void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void Tema1::OnWindowResize(int width, int height)
{
	
}
