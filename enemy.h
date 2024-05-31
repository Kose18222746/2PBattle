
#pragma once
#include "DxLib.h"
#include "stdlib.h"


const int MAX_ENEMY = 10;

struct Enemy {
	int x_d[MAX_ENEMY], y_d[MAX_ENEMY];

	int bullet_d[MAX_ENEMY];

	int randnum_d[MAX_ENEMY];

	int timer_d[MAX_ENEMY];

	bool mode_d[MAX_ENEMY];

	int enemy_r;

}Enemy;

struct  Enemy enemy;

void enemy_Init() {
	for (int i = 0; i < MAX_ENEMY; i++) {
		enemy.x_d[i] = 50;
		enemy.y_d[i] = 700;

		enemy.bullet_d[i] = 0;

		enemy.mode_d[i] = false;

		enemy.timer_d[i] = 0;

		enemy.randnum_d[i] = rand() % 4;

		enemy.enemy_r = 10;
	}





}


void enemy_Update() {



	for (int i = 0; i < MAX_ENEMY; i++) {
		enemy.timer_d[i]++;

		if (enemy.mode_d[i] == false) {
			enemy.x_d[i] += 3;
		}
		else {
			enemy.x_d[i] -= 3;
		}



		enemy.y_d[i] -= 5 - enemy.randnum_d[i];



		if (enemy.timer_d[i] >= enemy.randnum_d[i] * 10) {
			if (enemy.mode_d[i] == true) {
				enemy.mode_d[i] = false;
			}
			else {
				enemy.mode_d[i] = true;
			}

			enemy.randnum_d[i] = rand() % 4;
			enemy.timer_d[i] = 0;

		}


	if (enemy.x_d[i] <= -2900)
	{
		printf("“]‘—");
	}


		if (enemy.y_d[i] <= -100) {
			enemy.y_d[i] = 700;

			enemy.x_d[i] + i * 50;
		}

	}

}

void enemy_Draw() {
	for (int i = 0; i < MAX_ENEMY; i++) {
		DrawCircle(enemy.x_d[i] + i * 50, enemy.y_d[i] + i * 10, enemy.enemy_r, GetColor(255, 0, 0), TRUE);
	}
}


int Getenemy_x() {
	int now_x;
	for (int i = 0; i < MAX_ENEMY; i++) {
		//now_x = ;
		return enemy.x_d[i];
	}
}

int Getenemy_y() {
	int now_y;
	for (int i = 0; i < MAX_ENEMY; i++) {
		//now_y = enemy.y_d[i];
		return enemy.y_d[i];
	}
}
