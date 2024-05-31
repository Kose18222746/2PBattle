#include "iostream"
#include "enemy.h"
#include "Hit.h"
using namespace std;

void Init()
{
	// DxLib�̏�����
	ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ɐݒ�
	if (DxLib_Init() == -1) { // �������Ɏ��s�����ꍇ�̓G���[��Ԃ�
		exit(-1);
	}
	SetDrawScreen(DX_SCREEN_BACK);
	//  ���W�Ƒ傫��
//  �摜�̓ǂݍ��݂��s��
	Player_image = LoadGraph("data/war_stealth_aircraft.png");
	Player2_image = LoadGraph("data/22302021.png");
	Explosion_image = LoadGraph("data/Effect_preview_0.png");

	Bulet_fire = LoadGraph("data/fire1.png");
	Bulet_fire2 = LoadGraph("data/fire2.png");

	//  �w�i�摜�̓ǂݍ���
	Background_main = LoadGraph("data/Background.jpeg");


	for (int i = 0; i < 60; i++)
	{
		//  �e�U�O������ʊO�ɑҋ@�����Ă���
		Bullet_x[i] = -1000;
		Bullet_y[i] = 0;
	}

	enemy_Init();

}

//  �X�N���[���T�C�Yx=640y=480

void Update()
{

	//  �^�C�g���̕����F��ω�������
	if (Title_Color_Button)
	{
		Title_color_change++;
	}



	bullet_time++;

	//  �ˌ����[�h�ύX�p����

	if (CheckHitKey(KEY_INPUT_E))
	{
		Mode_change = true;
	}
	if (CheckHitKey(KEY_INPUT_R))
	{
		Mode_change = FALSE;
	}


	if (CheckHitKey(KEY_INPUT_J))
	{
		Title_back = true;
	}

	if (Title_back)
	{
		Title_x -= 5;
	}

	if (Title_color_change)
	{
		Title_color_change++;
	}
	else
	{
		Title_color_change--;
	}

	if (Title_color_change >= 355)
	{
		Title_Color_Button = false;
	}
	else if (Title_color_change <= 0)
	{
		Title_Color_Button = true;
	}

	Title_color += Title_color_change;


	//  �v���C���[�̓����̏���
	if (CheckHitKey(KEY_INPUT_A))
	{
		Player_x -= 5;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		Player_x += 5;
	}
	if (CheckHitKey(KEY_INPUT_W))
	{
		Player_y -= 5;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		Player_y += 5;
	}

	//	�v���C���[�Q�̓����̏���
	if (CheckHitKey(KEY_INPUT_J))
	{
		Player2_x -= 5;
	}
	if (CheckHitKey(KEY_INPUT_L))
	{
		Player2_x += 5;
	}
	if (CheckHitKey(KEY_INPUT_I))
	{
		Player2_y -= 5;
	}
	if (CheckHitKey(KEY_INPUT_K))
	{
		Player2_y += 5;
	}



	//  �v���C���[����ʊO�ɍs���Ȃ��悤�ɂ��邽�߂̏���

	if (Player_x <= 20)
	{
		Player_x = 21;
	}
	if (Player_x >= 270)
	{
		Player_x = 269;
	}
	if (Player_y <= 20)
	{
		Player_y = 21;

	}
	if (Player_y >= 460)
	{
		Player_y = 459;
	}

	//	�v���C���[�Q

	if (Player2_x <= 350)
	{
		Player2_x = 351;
	}
	if (Player2_x >= 620)
	{
		Player2_x = 619;
	}
	if (Player2_y <= 20)
	{
		Player2_y = 21;

	}
	if (Player2_y >= 460)
	{
		Player2_y = 459;
	}


	//  �v���C���[���e�𔭎˂��鏈��������Ă���

	if (Player_bullet_time <= 0)
	{
		if (CheckHitKey(KEY_INPUT_V))
		{

			Bulet_x = Player_x;
			Bulet_y = Player_y;
			Player_bullet_time = 300;
			attack_ok1 = 20;

		}
	}
	if (Player2_bullet_time <= 0) {
		if (CheckHitKey(KEY_INPUT_N))
		{
			bulet2_x = Player2_x;
			bulet2_y = Player2_y;
			Player2_bullet_time = 300;
			attack_ok2 = 630;
		}

	}

	if (attack_ok1 <= 320)
	{
		attack_ok1++;
}
else if(attack_ok1 >= 320)
{
	attack_ok1 = 320;
}
	if (attack_ok2 >= 330)
	{
		attack_ok2--;
	}
	else if (attack_ok2 <= 330)
	{
		attack_ok2 = 330;
	}


	Player_bullet_time--;
	Player2_bullet_time--;

	//	�e�̑��x
	Bulet_x += 20;
	bulet2_x -= 20;


	if (Player_x >= bulet2_x - Player_r && Player_x <= bulet2_x + Player_r && Player_y >= bulet2_y - Player_r  && Player_y <= bulet2_y + Player_r )
	{
		Player_life--;
		bulet2_y = -600;
		Player_out = true;
		Out_time = 0;
	}

	if (Player2_x >= Bulet_x - Player_r && Player2_x <= Bulet_x + Player_r && Player2_y >= Bulet_y - Player_r && Player2_y <= Bulet_y + Player_r)
	{
		Player2_life--;
		Bulet_y = -600;
		Player2_out = true;
		Out_time = 0;
	}

	Out_time+=5;
	if (Out_time >= 421)
	{
		Player_out = false;
		Player2_out = false;
	}

	if (Player_out)
	{

			if (Out_time >= 0 && Out_time <= 70 || Out_time >= 141 && Out_time <= 210 || Out_time >= 281 && Out_time <= 350)
			{
				Image_Check = false;
			}
			else
//	else if (i >= 71 && i <= 140 || i >= 211 && i <= 280 || i >= 351 && i <= 420)
			{
				Image_Check = true;
			}

	}

	if (Player2_out)
	{

		if (Out_time >= 0 && Out_time <= 70 || Out_time >= 141 && Out_time <= 210 || Out_time >= 281 && Out_time <= 350)
		{
			Image2_Check = false;
		}
		else
			//	else if (i >= 71 && i <= 140 || i >= 211 && i <= 280 || i >= 351 && i <= 420)
		{
			Image2_Check = true;
		}

	}

	//�@���C�t�����؂����Ƃ��̔���
	if (Player2_life <= 0)
	{
		Player_win = true;
	}
	if (Player_life <= 0)
	{
		Player2_win = true;
	}


	//if (Mode_change) {
	//	for (int i = 0; i < 60; i++) {
	//		Bulet_speed = 15;
	//		Bullet_x[i] += Bulet_speed;
	//	}
	//}
	//else
	//{
	//	for (int i = 0; i < 60; i++) {
	//		if (i % 3 == 0) {
	//			Bulet_speed = 10;
	//			Bullet_y[i] += Bulet_speed;
	//			Bullet_x[i] += 5;
	//			bullet_time += 2;

	//		}
	//		else if (i % 3 == 1)
	//		{
	//			Bullet_y[i] += Bulet_speed;
	//			Bullet_x[i] -= 5;
	//			bullet_time += 2;

	//		}
	//		else if (i % 3 == 2)
	//		{
	//			Bullet_y[i] += Bulet_speed;
	//			bullet_time += 2;
	//		}

	//	}

	//}

	//  Enemy��Bullet���G�ꂽ�������Ƃ�������悤�ɏ�������
	//if ( Bulet_y >= Enemy_y - Enemy_r && Bulet_y <= Enemy_y + Enemy_r )
	//for (int i = 0; i < 60; i++) {
	//    if (Bullet_x[i] >= Enemy_x - Enemy_r && Bullet_x[i] <= Enemy_x + Enemy_r && Bullet_y[i] >= Enemy_y - Enemy_r && Bullet_y[i] <= Enemy_y + Enemy_r)

	//    {
	//        //  �ꏏ�̈ʒu�ɔ�΂��Ă��܂����ꍇ���j���J�E���g�����������Ă��܂����ߊԊu�������Ĕ�΂�
	//        Enemy_x = -1000;
	//        Bulet_x = -1100;
	//        Enemy_y = 500;
	//        Enemy_rand_y=GetRand(300);
	//        Attack_count++;
	//    }
	//}

	//  �G�̓���
	if (Enemy_x >= Enemy_rand_x - 2 && Enemy_x <= Enemy_rand_x + 2)
	{
		Enemy_rand_x = GetRand(500);
	}

	else if (Enemy_x > Enemy_rand_x)
	{
		Enemy_x -= 3;
	}
	else if (Enemy_x < Enemy_rand_x)
	{
		Enemy_x += 3;
	}

	if (Enemy_y >= Enemy_rand_y + 100)
	{
		Enemy_y--;
	}

	Enemy_attack_time++;
	Enemy_bullet_y -= 5;

	// �@�G�̍U���p�̏���
	if (Enemy_attack_time > 180)
	{
		Enemy_bullet_x = Enemy_x;
		Enemy_bullet_y = Enemy_y;
		Enemy_attack_time = 0;
	}
	////  �G�̋ʂ̓����蔻��
	//if (Enemy_bullet_x >= Player_x - Enemy_r - 3 && Enemy_bullet_x <= Player_x + Enemy_r / 3 && Enemy_bullet_y >= Player_y - Enemy_r / 3 && Enemy_bullet_y <= Player_y + Enemy_r / 3)
	//{
	//    Player_life--;
	//    Enemy_bullet_x = -100;
	//    Enemy_bullet_y = -100;
	//}


//	enemy_Update();


	//for (int i = 0; i < 10; i++) {

	//	for (int j = 0; j < 60; j++) {
	//		EnemyHit(enemy.x_d[i], enemy.y_d[i], Bullet_x[j], Bullet_y[j], enemy.enemy_r, Attack_count);
	//	}
	//	PlayerHit(Player_x, Player_y, enemy.x_d[i], enemy.y_d[i], Player_r, Player_life);

	//}



}

void Draw()
{


	// ��ʃN���A
	ClearDrawScreen();

	//  �w�i
	DrawBox(0, 0, 680, 480, GetColor(255, 255, 255), true);

	//  �{�҂̔w�i
	DrawExtendGraph(0, 0, DEFAULT_SCREEN_SIZE_X, DEFAULT_SCREEN_SIZE_Y, Background_main, true);

	DrawBox(20, 20, 320, 50, GetColor(255, 255, 255),true);
	DrawBox(20, 20, attack_ok1 , 50, GetColor(255, 0,0), true);

	DrawBox(330, 20, 630, 50, GetColor(255, 255, 255),true);
	DrawBox(attack_ok2, 20, 630, 50, GetColor(0, 0, 255), true);


	// �v���C���[��`��i�h��Ԃ��A���a���������j
	//DrawCircle(Player_x, Player_y, Player_r, GetColor(0, 255, 0), TRUE);
//    LoadGraphScreen(Player_x, Player_y, "data/war_stealth_aircraft.png", true);
	//DrawGraph(Player_x, Player_y, Player_image, true);

	//  �摜�̑傫���𒲐�
	//DrawExtendGraph(100, 100, Player_x, Player_y, Player_image, true);

	//  �v���C���[�̕`��
	if (Image_Check) {
		DrawExtendGraph(Player_x - 40, Player_y - 40, Player_x + 40, Player_y + 40, Player_image, true);
	}

	if (Image2_Check)
	{
		DrawExtendGraph(Player2_x - 40, Player2_y - 40, Player2_x + 40, Player2_y + 40, Player2_image, true);
	}
	//	�v���C���[�ƃv���C���[�Q�̒e�̕`��

	//	DrawCircle(Bulet_x, Bulet_y, Player_r, GetColor(0, 0, 255), TRUE);
		DrawExtendGraph(Bulet_x - 20, Bulet_y -20, Bulet_x + 20, Bulet_y + 20, Bulet_fire, true);

		DrawCircle(bulet2_x, bulet2_y, Player_r, GetColor(0, 255, 0), TRUE);
		DrawExtendGraph(bulet2_x - 20, bulet2_y - 20, bulet2_x + 20, bulet2_y + 20, Bulet_fire2, true);


	// �e�̕`��
	//for (int i = 0; i < 60; i++) {
	//	DrawCircle(Bullet_x[i], Bullet_y[i], Bulet_r, GetColor(0, 0, 255), TRUE);
	//}
	//  Enemy�̕`��
   // DrawCircle(Enemy_x, Enemy_y, Enemy_r, GetColor(255, 0, 0), TRUE);

	//  �G�̒e�̕`��
   // DrawCircle(Enemy_bullet_x, Enemy_bullet_y, Enemy_r / 3, GetColor(255, 0, 0), TRUE);

	if (Player_bullet_time >= 0) {
		DrawFormatString(60, 50, GetColor(255, 0, 0), "��[�����܂�%d", Player_bullet_time / 60);
	}
	else
	{
		DrawString(60, 50, "���ˏ�������", GetColor(255, 0, 0));
	}
	if (Player2_bullet_time >= 0) {

		DrawFormatString(400, 50, GetColor(255, 0, 0), "��[�����܂�%d", Player2_bullet_time / 60);
	}
	else
	{
		DrawString(400, 50, "���ˏ�������", GetColor(255, 0, 0));
	}

	//	DrawString(60, 70, "R�L�[��E�L�[�Ŏˌ����[�h�ύX", GetColor(0, 255, 0));

	//	  �v���C���[�̃��C�t��`��
	if (Player_life >= 3) {
		DrawExtendGraph(55, 85, 85, 115, Player_image, true);
		DrawExtendGraph(90, 85, 120, 115, Player_image, true);
		DrawExtendGraph(125, 85, 155, 115, Player_image, true);

	}
	else if (Player_life >= 2)
	{
		DrawExtendGraph(55, 85, 85, 115, Player_image, true);
		DrawExtendGraph(90, 85, 120, 115, Player_image, true);
		DrawExtendGraph(125, 85, 155, 115, Explosion_image, true);

	}
	else if (Player_life >= 1)
	{
		DrawExtendGraph(55, 85, 85, 115, Player_image, true);
		DrawExtendGraph(90, 85, 120, 115, Explosion_image, true);
		DrawExtendGraph(125, 85, 155, 115, Explosion_image, true);

	}

	//	�v���C���[�Q�̃��C�t
	if (Player2_life >= 3) {
		DrawExtendGraph(405, 85, 430, 115, Player2_image, true);
		DrawExtendGraph(440, 85, 470, 115, Player2_image, true);
		DrawExtendGraph(475, 85, 505, 115, Player2_image, true);

	}
	else if (Player2_life >= 2)
	{
		DrawExtendGraph(405, 85, 435, 115, Player2_image, true);
		DrawExtendGraph(440, 85, 470, 115, Player2_image, true);
		DrawExtendGraph(475, 85, 505, 115, Explosion_image, true);

	}
	else if (Player2_life >= 1)
	{
		DrawExtendGraph(405, 85, 430, 115, Player2_image, true);
		DrawExtendGraph(440, 85, 470, 115, Explosion_image, true);
		DrawExtendGraph(475, 85, 505, 115, Explosion_image, true);

	}



	//enemy_Draw();


	/*  DrawString(120, 80, "���j��%d", Attack_count, GetColor(0, 0, 0));

	  DrawString(120, 80, "���j��", GetColor(0, 0, 0));*/

	//	���U���g��ʂ̏o��
	//	�v���C���[�P���������ꍇ
	if (Player_win)
	{
		DrawBox(0, 0, 320, 600, GetColor(255, 0, 0), true);
		DrawBox(321, 0, 640, 600, GetColor(0, 0, 255),true);

		DrawString(160, 180, "Winer", true);
		DrawString(480, 180, "Loser", true);


	}

	if (Player2_win)
	{
		DrawBox(0, 0, 320, 600, GetColor(0, 0, 255), true);
		DrawBox(321, 0, 640, 600, GetColor(255, 0, 0), true);

		DrawString(160, 180, "Loser", true);
		DrawString(480, 180, "Winer", true);


	}


	DrawBox(0, 0, Title_x, Title_y, GetColor(0, 255, 0), true);
	DrawString(Title_x - 400, 200, "�V���[�e�B���O�Q�[��", GetColor(Title_color, Title_color - 100, Title_color - 50), true);
	DrawString(Title_x - 400, 260, "J�L�[�������ăX�^�[�g", GetColor(255, 0, 0), true);




	// ��ʂ̍X�V
	ScreenFlip();
}

void Exit()
{
	// DxLib�̏I������
	DxLib_End();
}

int main()
{
	Init();
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		Update(); // �X�V����
		Draw();   // �`�揈��
	}

	Exit(); // �I������

	return 0;
}
