//=============================================================================
//
// �n�ʂ̏��� [field.h]
//
//=============================================================================
#ifndef _FIELD_H_
#define _FIELD_H_

#define	MAX_FIELD		(40)		// �n�ʂ̍ő吔

//*************************************
// �n�ʂ̍\����
//*************************************
typedef struct
{
	float posX;			// �n�ʂ̊�ʒu�w���W
	float posY;			// �n�ʂ̊�ʒu�x���W
	float width;		// �n�ʂ̕�
	bool enable;		// �n�ʂ��g�p���Ă��邩�ǂ���
} FIELD;

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
void InitField(void);
void UninitField(void);
void UpdateField(void);
void DrawField(void);

void CreateField(float in_posX, float in_posY, float in_width);
FIELD *GetField(void);

#endif

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
