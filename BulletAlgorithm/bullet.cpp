//=============================================================================
//
// �e�̏��� [bullet.cpp]
//
//=============================================================================
#include "main.h"
#include "bullet.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	MAX_BULLET		(100)	// �e�̍ő吔

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
BULLET bullet[MAX_BULLET];		// �e�̃��[�N

//=============================================================================
// �e�̏���������
//=============================================================================
void InitBullet(void)
{
	// �e�̍ő吔���J��Ԃ�
	for (int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// �e�̏��̏�����
		bullet[countBullet].posX = 0.0f;
		bullet[countBullet].posY = 0.0f;
		bullet[countBullet].oldPosX = 0.0f;
		bullet[countBullet].oldPosY = 0.0f;
		bullet[countBullet].moveX = 0.0f;
		bullet[countBullet].moveY = 0.0f;
		bullet[countBullet].type = BULLETTYPE_PLAYER;
		bullet[countBullet].enable = false;
	}
}

//=============================================================================
// �e�̏I������
//=============================================================================
void UninitBullet(void)
{
}

//=============================================================================
// �e�̍X�V����
//=============================================================================
void UpdateBullet(void)
{
	// �e�̍ő吔���J��Ԃ�
	for (int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// �e���g�p��Ԃ�
		if (bullet[countBullet].enable)
		{
			// ���݂̈ʒu��ۑ�
			bullet[countBullet].oldPosX = bullet[countBullet].posX;
			bullet[countBullet].oldPosY = bullet[countBullet].posY;

			// �ʒu���X�V
			bullet[countBullet].posX += bullet[countBullet].moveX;
			bullet[countBullet].posY += bullet[countBullet].moveY;

			// �e����ʊO�ɏo�����H
			if (bullet[countBullet].posX < 2.0f
				|| bullet[countBullet].posX > 78.0f
				|| bullet[countBullet].posY < 2.0f
				|| bullet[countBullet].posY > 24.0f)
			{
				// �O��̈ʒu�ł̒e������
				SetCursorPosition((int)(bullet[countBullet].oldPosX), (int)(bullet[countBullet].oldPosY));
				printf("�@");

				bullet[countBullet].enable = false;	// �e�𖢎g�p��Ԃ�
			}
		}
	}
}

//=============================================================================
// �e�̕`�揈��
//=============================================================================
void DrawBullet(void)
{
	// �e�̍ő吔���J��Ԃ�
	for(int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// �e���g�p��Ԃ�
		if(bullet[countBullet].enable)
		{
			 // �F�ݒ�
			if(bullet[countBullet].type == BULLETTYPE_PLAYER)
			{
				// �v���C���[�̒e�̐F���w��
				SetConsoleTextColor(LIGHTGREEN);
			}
			else
			{
				// �G�̒e�̐F���w��
				SetConsoleTextColor(LIGHTCYAN);
			}

			// �O��̈ʒu�ł̒e������
			SetCursorPosition((int)(bullet[countBullet].oldPosX), (int)(bullet[countBullet].oldPosY));
			printf("�@");

			// ���݂̈ʒu�ɋʂ�\��
			SetCursorPosition((int)(bullet[countBullet].posX), (int)(bullet[countBullet].posY));
			printf("��");
		}
	}
}

//=============================================================================
// �e�̐���
//=============================================================================
void SetBullet(float posX, float posY, float moveX, float moveY, BULLETTYPE type)
{
	// �e�̍ő吔���J��Ԃ�
	for(int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// �e�����g�p��Ԃ�
		if(!bullet[countBullet].enable)
		{
			bullet[countBullet].posX = posX;
			bullet[countBullet].posY = posY;
			bullet[countBullet].oldPosX = posX;
			bullet[countBullet].oldPosY = posY;
			bullet[countBullet].moveX = moveX;
			bullet[countBullet].moveY = moveY;
			bullet[countBullet].type = type;
			bullet[countBullet].enable = true;	// �e���g�p��Ԃ�

			break;
		}
	}
}


/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
