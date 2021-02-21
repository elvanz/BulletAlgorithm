//=============================================================================
//
// �v���C���[���� [player.cpp]
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "field.h"
#include "bullet.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	VALUE_MOVE_X			(0.75f)		// �n��ł̈ړ��ʂw����
#define	VALUE_MOVE_X_AIR		(0.30f)		// �󒆂ł̈ړ��ʂw����
#define	VALUE_JUMP				(0.80f)		// �W�����v��
#define	VALUE_RESIST_X			(0.50f)		// �n��ł̈ړ����C��R
#define	VALUE_RESIST_X_AIR		(0.35f)		// �󒆂ł̈ړ����C��R
#define	VALUE_GRAVITY			(0.06f)		// �d�͗�

#define	LIMIT_LEFT				(2.0f)		// �ړ��͈͍��[
#define	LIMIT_RIGHT				(78.0f)		// �ړ��͈͉E�[
#define	LIMIT_DOWN				(24.0f)		// �ړ��͈͉��[

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
bool CheckCollisionField(void);

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
PLAYER player;		// �v���C���[�̏��(�\���̕ϐ�)

//=============================================================================
// �v���C���[�̏���������
//=============================================================================
void InitPlayer(void)
{
	// �v���C���[���̏�����
	player.posX = 20.0f;
	player.posY = 24.0f;
	player.oldPosX = 20.0f;
	player.oldPosY = 24.0f;
	player.moveX = 0.0f;
	player.moveY = 0.0f;
	player.jumpFlg = false;
	player.landFlg = false;
	player.moveFlg = false;
	player.shotFlg = false;
	player.direction = 1.0f;
}

//=============================================================================
// �v���C���[�̏I������
//=============================================================================
void UninitPlayer(void)
{
}

//=============================================================================
// �v���C���[�̍X�V����
//=============================================================================
void UpdatePlayer(void)
{
	// ���݂̈ʒu��ۑ�
	player.oldPosX = player.posX;
	player.oldPosY = player.posY;

	// ���L�[��������Ă���ꍇ�͍��ړ�
	if (InputKeyMouse(PK_LEFT))
	{
		// �W�����v�����̔���
		if (player.jumpFlg)
		{
			// �W�����v���ł���΃W�����v���̈ړ��ʂ��Z�b�g
			player.moveX -= VALUE_MOVE_X_AIR;
		}
		else
		{
			// �W�����v���ł͂Ȃ��ꍇ�͈ړ��ʂ��Z�b�g
			player.moveX -= VALUE_MOVE_X;
		}

		// �ړ����ł��邱�Ƃ��t���O�ɃZ�b�g����
		player.moveFlg = true;

		// �v���C���[�̌����̏����}�C�i�X�i�������j�ɂ���
		player.direction = -1.0f;
	}

	// �E�L�[��������Ă���ꍇ�͉E�ړ�
	if (InputKeyMouse(PK_RIGHT))
	{
		// �W�����v�����̔���
		if (player.jumpFlg)
		{
			// �W�����v���ł���΃W�����v���̈ړ��ʂ��Z�b�g
			player.moveX += VALUE_MOVE_X_AIR;
		}
		else
		{
			// �W�����v���ł͂Ȃ��ꍇ�͈ړ��ʂ��Z�b�g
			player.moveX += VALUE_MOVE_X;
		}

		// �ړ����ł��邱�Ƃ��t���O�ɃZ�b�g����
		player.moveFlg = true;

		// �v���C���[�̌����̏����v���X�i�E�����j�ɂ���
		player.direction = 1.0f;
	}

	// ��L�[��������Ă���ꍇ�̓W�����v
	if (InputKeyMouse(PK_UP))
	{
		// ���Ƀt���O���W�����v���̏ꍇ�͏������Ȃ�
		// �����ꂪ�Ȃ��Ƃ����ƃL�[��������Ă����
		// �@�����Ə�Ɉړ����Ă��܂��܂�
		if (!player.jumpFlg)
		{
			// Y�����ɃW�����v���̈ړ��ʂ��Z�b�g����
			player.moveY = -VALUE_JUMP;

			// �W�����v���ł��邱�Ƃ��t���O�ɃZ�b�g����
			player.jumpFlg = true;
		}
	}

	// �X�y�[�X�L�[�������ꂽ��U��
	if (InputKeyMouse(PK_SP))
	{
		// �e�����ɐ�������Ă��Ȃ���
		// �i�L�[���������ł̒e�̘A�����˂�h���j
		if (!player.shotFlg)
		{
			// �e�𐶐�����
			// ���̊֐��̒��Œe�̍ő吔�܂Œe�𐶐����邱�Ƃ��ł���
			SetBullet(player.posX + player.moveX + player.direction * 2.0f,
				player.posY,
				player.direction,
				0.0f,
				BULLETTYPE_PLAYER);
			player.shotFlg = true;
		}
	}
	else
	{
		// �e����������Ă��邩
		if (player.shotFlg)
		{
			// �e����������Ă����疢�����ɂ���
			player.shotFlg = false;
		}
	}

	// �W�����v���̈ړ��v�Z
	if (player.jumpFlg)
	{
		// �W�����v���͈ړ��ƂȂ�̂ňړ��t���O���Z�b�g
		player.moveFlg = true;

		// �W�����v���̓v���C���[�̉������̈ړ��ɋ󒆗p�̒�R��������
		player.moveX += (0.0f - player.moveX) * VALUE_RESIST_X_AIR;
	}
	else
	{
		// �n��ɂ���Ƃ��̓v���C���[�̉������̈ړ��ɒn��p�̒�R��������
		player.moveX += (0.0f - player.moveX) * VALUE_RESIST_X;
	}

	// ���݂̈ʒu���X�V����
	player.posX += player.moveX;

	// �v���C���[�̈ʒu����ʍ��[��菬�����ꍇ
	if (player.posX < LIMIT_LEFT)
	{
		// �v���C���[�̈ʒu����ʍ��[�ɂ���
		player.posX = LIMIT_LEFT;
	}

	// �v���C���[�̈ʒu����ʉE�[���傫���ꍇ
	if (player.posX > LIMIT_RIGHT)
	{
		// �v���C���[�̈ʒu����ʉE�[�ɂ���
		player.posX = LIMIT_RIGHT;
	}

	// �d�͂�������
	player.moveY += VALUE_GRAVITY;
	player.posY += player.moveY;

	// �v���C���[����ʉ������z������
	if (player.posY > LIMIT_DOWN)
	{
		// �n�ʂɂ߂荞�񂾏ꍇ�͉�ʉ�����
		// �ʒu�����킹��
		player.posY = LIMIT_DOWN;
		player.moveY = 0.0f;
		player.jumpFlg = false;
	}

	// �n�ʂƂ̓����蔻��
	if (CheckCollisionField() == true)
	{
		// �n�ʂɓ��������ꍇ
		player.moveY = 0.0f;
		player.moveFlg = true;
		player.jumpFlg = false;
		player.landFlg = true;
	}
	else
	{
		// �n�ʂƓ������Ă��Ȃ��ꍇ
		if (player.landFlg)
		{
			// �n�ʂɐڂ��Ă��Ȃ���΃W�����v���ɂ���
			player.jumpFlg = true;
			player.landFlg = false;
		}
	}
}

//=============================================================================
// �v���C���[�̕`�揈��
//=============================================================================
void DrawPlayer(void)
{
	// �v���C���[���ړ�������
	if (player.moveFlg)
	{
		// �O��̈ʒu�ł̃v���C���[������
		SetCursorPosition((int)player.oldPosX, (int)player.oldPosY);
		PrintString("  ", 2);
		SetCursorPosition((int)player.oldPosX, (int)(player.oldPosY - 1.0f));
		PrintString("  ", 2);

		player.moveFlg = false;
	}

	// �F�ݒ�
	SetConsoleTextColor(YELLOW);

	// ���݂̈ʒu�Ƀv���C���[��\��
	SetCursorPosition((int)player.posX, (int)player.posY);
	PrintString("��", 2);
	SetCursorPosition((int)player.posX, (int)(player.posY - 1.0f));
	PrintString("��", 2);
}

//=============================================================================
// �n�ʂƂ̓����蔻��
//=============================================================================
bool CheckCollisionField(void)
{
	FIELD *field;

	// �n�ʂ̃f�[�^�̐擪�A�h���X���擾����
	field = GetField();

	// �n�ʂ̃f�[�^�����J��Ԃ�
	for (int cntField = 0; cntField < MAX_FIELD; cntField++, field++)
	{
		// �n�ʂ��L����
		if (field->enable)
		{
			// �ォ��n�ʂɓ����������̔���
			// �v���C���[�ƒn�ʂ͈̔͂��d�Ȃ��Ă��邩���`�F�b�N�iX�����j
			if ((player.posX + 0.9f) > field->posX && player.posX < (field->posX + field->width - 0.1f))
			{
				// �v���C���[�ƒn�ʂ͈̔͂��d�Ȃ��Ă��邩���`�F�b�N�iY�����j
				if (player.posY > (field->posY - 1.0f) && player.oldPosY <= (field->posY - 1.0f))
				{
					// X��Y���d�Ȃ��Ă��邽�ߒn�ʂ�Y���W�̏���v���C���[�̍��W�Ƃ���
					player.posY = field->posY - 1.0f;

					return true;
				}
			}

			// ������n�ʂɓ����������̔���
			// �v���C���[�ƒn�ʂ͈̔͂��d�Ȃ��Ă��邩���`�F�b�N�iX�����j
			if ((player.posX + 0.9f) > field->posX && player.posX < (field->posX + field->width - 0.1f))
			{
				// �v���C���[�ƒn�ʂ͈̔͂��d�Ȃ��Ă��邩���`�F�b�N�iY�����j
				if ((player.posY - 2.0f) < field->posY && (player.oldPosY - 1.0f) >= field->posY)
				{
					// X��Y���d�Ȃ��Ă��邽�ߒn�ʂ�Y���W�̏���v���C���[�̍��W�Ƃ���
					player.posY = field->posY + 2.0f;
					player.moveY = 0.0f;
				}
			}
		}
	}

	return false;
}

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
