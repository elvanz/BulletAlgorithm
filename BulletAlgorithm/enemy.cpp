//=============================================================================
//
// �G�̏��� [enemy.cpp]
//
//=============================================================================
#include "main.h"
#include "enemy.h"
#include "bullet.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	MAX_ENEMY		(100)	// �G�̍ő吔

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
ENEMY enemy[MAX_ENEMY];			// �G�̃��[�N

//=============================================================================
// �G�̏���������
//=============================================================================
void InitEnemy(void)
{
	// �G�̍ő吔���J��Ԃ�
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// �G�̏��̏�����
		enemy[countEnemy].posX = 0.0f;
		enemy[countEnemy].posY = 0.0f;
		enemy[countEnemy].oldPosX = 0.0f;
		enemy[countEnemy].oldPosY = 0.0f;
		enemy[countEnemy].moveX = 0.0f;
		enemy[countEnemy].moveY = 0.0f;
		enemy[countEnemy].type = 0;
		enemy[countEnemy].enable = false;
	}

	// �G�̐���
	SetEnemy(40.0f, 24.0f, 0);
}

//=============================================================================
// �G�̏I������
//=============================================================================
void UninitEnemy(void)
{
}

//=============================================================================
// �G�̍X�V����
//=============================================================================
void UpdateEnemy(void)
{
	// �G�̍ő吔���J��Ԃ�
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// �G���������Ă��邩
		if (enemy[countEnemy].enable)
		{
			// �G���e�𔭎˂���^�C�~���O�𗐐��Ō��߂�
			if ((rand() % 100) == 0)
			{
				// �G�̒e����
				SetBullet(enemy[countEnemy].posX + enemy[countEnemy].moveX + enemy[countEnemy].direction * 2.0f,
					enemy[countEnemy].posY,
					enemy[countEnemy].direction * 0.5f, 0.0f,
					BULLETTYPE_ENEMY);
			}
		}
	}
}

//=============================================================================
// �G�̕`�揈��
//=============================================================================
void DrawEnemy(void)
{
	// �G�̍ő吔���J��Ԃ�
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		//	�G���������Ă��邩
		if (enemy[countEnemy].enable)
		{
			// �F�ݒ�
			SetConsoleTextColor(LIGHTBLUE);

			// �O��̈ʒu�ł̓G������
			SetCursorPosition((int)(enemy[countEnemy].oldPosX), (int)(enemy[countEnemy].oldPosY - 1.0f));
			printf("�@");
			SetCursorPosition((int)(enemy[countEnemy].oldPosX), (int)(enemy[countEnemy].oldPosY));
			printf("�@");

			// ���݂̈ʒu�ɓG��\��
			SetCursorPosition((int)(enemy[countEnemy].posX), (int)(enemy[countEnemy].posY - 1.0f));
			printf("��");
			SetCursorPosition((int)(enemy[countEnemy].posX), (int)(enemy[countEnemy].posY));
			printf("��");
		}
	}
}

//=============================================================================
// �G�̐���
//=============================================================================
void SetEnemy(float posX, float posY, int type)
{
	// �G�̍ő吔���J��Ԃ�
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// �G���������Ă��Ȃ���
		if (!enemy[countEnemy].enable)
		{
			enemy[countEnemy].posX = posX;
			enemy[countEnemy].posY = posY;
			enemy[countEnemy].oldPosX = posX;
			enemy[countEnemy].oldPosY = posY;
			enemy[countEnemy].moveX = 0.0f;
			enemy[countEnemy].moveY = 0.0f;
			enemy[countEnemy].direction = -1.0f;
			enemy[countEnemy].type = type;
			enemy[countEnemy].enable = true;	// �G�𐶑���Ԃ�

			break;
		}
	}
}

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
