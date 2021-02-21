//=============================================================================
//
// �v���C���[���� [player.h]
//
//=============================================================================
#pragma once

//*************************************
// �v���C���[�\����
//*************************************
typedef struct
{
	float posX;			// ���݂�X���W
	float posY;			// ���݂�Y���W
	float oldPosX;		// �O���X���W
	float oldPosY;		// �O���Y���W
	float moveX;		// X�����̈ړ���
	float moveY;		// Y�����̈ړ���
	bool jumpFlg;		// �W�����v���Ȃ�true
	bool landFlg;		// ���n���Ȃ�true
	bool moveFlg;		// �ړ����Ă���Ȃ�true
	bool shotFlg;		// �V���b�g���Ȃ�true
	float direction;	// ����
} PLAYER;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
