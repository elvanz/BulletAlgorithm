//=============================================================================
//
// �e�̏��� [bullet.h]
//
//=============================================================================
#ifndef _BULLET_H_
#define _BULLET_H_

//*************************************
// �e�̎��
//*************************************
typedef enum
{
	BULLETTYPE_PLAYER = 0,		// �v���C���[�̒e
	BULLETTYPE_ENEMY,			// �G�̒e
	BULLETTYPE_MAX
} BULLETTYPE;

//*************************************
// �e�̍\����
//*************************************
typedef struct
{
	float posX;			// ���݂�X���W
	float posY;			// ���݂�Y���W
	float oldPosX;		// �O���X���W
	float oldPosY;		// �O���Y���W
	float moveX;		// X�����̈ړ���
	float moveY;		// Y�����̈ړ���
	BULLETTYPE type;	// �e�̎��
	bool enable;		// �g�p�����ǂ���
} BULLET;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
void InitBullet(void);
void UninitBullet(void);
void UpdateBullet(void);
void DrawBullet(void);

void SetBullet(float posX, float posY, float moveX, float moveY, BULLETTYPE type);

#endif

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
