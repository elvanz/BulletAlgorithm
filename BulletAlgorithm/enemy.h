//=============================================================================
//
// �G�̏��� [enemy.h]
//
//=============================================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//*************************************
// �G�̍\����
//*************************************
typedef struct
{
	float posX;			// ���݂�X���W
	float posY;			// ���݂�Y���W
	float oldPosX;		// �O���X���W
	float oldPosY;		// �O���Y���W
	float moveX;		// X�����̈ړ���
	float moveY;		// Y�����̈ړ���
	float direction;	// ����
	int type;			// �^�C�v	
	bool enable;		// �g�p�����ǂ���
} ENEMY;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
void InitEnemy(void);
void UninitEnemy(void);
void UpdateEnemy(void);
void DrawEnemy(void);

void SetEnemy(float posX, float posY, int type);

#endif

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
