#pragma once


//	�v���C���[�̓����蔻��
//	p���v���C���[��X�AY���W�Ae���G�̒e��X�AY���W�Ar�������蔻��̔��a�I�傫��
#include <iostream>

void PlayerHit(int px, int py, int& Enemy_bullet_x, int& Enemy_bullet_y, int r, int& Player_life)
{


	if (Enemy_bullet_x >= px - r && Enemy_bullet_x <= px + r && Enemy_bullet_y >= py - r && Enemy_bullet_y <= py + r)
	{
		Player_life--;
		Enemy_bullet_x = -10000;
		Enemy_bullet_y = -10000;
	}
}

void EnemyHit(int ex, int ey, int& Player_bullet_x, int& Player_bullet_y, int r, int& Attack_count)
{
//		printf("aa");

		//if (Player_bullet_y >= ex - r / 3 && Player_bullet_y <= ex + r / 3 && Player_bullet_y >= ey - r / 3 && Player_bullet_y <= ey + r / 3)
		//{
		//	Attack_count++;
		//	Player_bullet_y = -100;
		//	Player_bullet_y = -100;
		//}
		if (Player_bullet_x >= ex - r / 2 && Player_bullet_x <= ex + r / 2 && Player_bullet_y >= ey - r / 2 && Player_bullet_y <= ey + r / 2)
		{
			printf("����");
			Attack_count++;

			Player_bullet_y = -10000;
//			Player_bullet_y = -10000;
			ex = -3000;
		}

		//if (Bullet_x[i] >= Enemy_x - Enemy_r && Bullet_x[i] <= Enemy_x + Enemy_r && Bullet_y[i] >= Enemy_y - Enemy_r && Bullet_y[i] <= Enemy_y + Enemy_r)

}