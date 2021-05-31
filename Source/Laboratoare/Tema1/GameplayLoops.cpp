#include "Tema1.h"

void Tema1::aliveLoop(float deltaTimeSeconds) {



	if (canShoot == 0) {
		waitShoot += deltaTimeSeconds;
	}

	if (waitShoot >= waitTimeShoot) {
		waitShoot = 0;
		canShoot = 1;
	}

	if (points >= deltaNextLvl * nextLevel) {

		nextLevel = points / deltaNextLvl + 1;

		cout << "Level up! Curent level: " << nextLevel - 1 << endl;
		//happens every level up


		if (rand() % 2) {
			if (shurikenTimeBewtweenSpawns > 0.5) {
				cout << "Shuriken spawn time decreased" << endl;
				shurikenTimeBewtweenSpawns -= 0.1;
			}
		}
		else {
			if (baloonYVelocity < 80) {
				cout << "Baloon velocity increased" << endl;
				baloonYVelocity += 5;
			}
		}




		//happens every 2 level ups
		if ((nextLevel - 1) % 2 == 0) {

			if (rand() % 2) {

				if (baloonPositiveChance > 20) {
					cout << "Positive baloon spawn chance decreased" << endl;
					baloonPositiveChance -= 2;
				}
			}
			else {
				if (shurikenXVelocity < 300) {
					cout << "Shuriken velocity increased" << endl;
					shurikenXVelocity += 20;
					shurikenRotVelocity += 1;
				}
			}
		}

		//happens every 4 level ups
		if ((nextLevel - 1) % 4 == 0) {
			if (baloonTimeBewtweenSpawns < 1) {
				cout << "Baloon spawn time decreased" << endl;
				baloonTimeBewtweenSpawns -= 0.5;
			}
		}
		//happens every 8 level ups
		if ((nextLevel - 1) % 8 == 0) {
			if (deltaModifier < 3) {
				cout << "EVERYTHING INCREASED" << endl;
				deltaModifier += 0.2;
			}
		}

		//happens every 16 level ups
		if ((nextLevel - 1) % 16 == 0) {

			if (rand() % 2) {
				if (lives < maxLives) {
					cout << "Life restored" << endl;
					lives += 1;
				}
			}
		}

		cout << "-----------------------------" << endl << endl;
	}



	renderBow();

	renderPower();

	pointColisionLogic();

	playerColisionLogic();


	arrowLogic(deltaTimeSeconds);

	shurikenLogic(deltaTimeSeconds);

	baloonLogic(deltaTimeSeconds);

}
