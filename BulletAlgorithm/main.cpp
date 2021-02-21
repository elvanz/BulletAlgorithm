//=============================================================================
//
// �A�N�V�����Q�[���T���v�� [main.cpp]
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "field.h"
#include "enemy.h"
#include "bullet.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
#ifdef _DEBUG
void DispFPS(void);
#endif

//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
int countFps;				// FPS�J�E���^

//=============================================================================
// ���C���֐�
//=============================================================================
int main(void)
{
	int execLastTime;
	int fpsLastTime;
	int currentTime;
	int frameCount;

	// ����\��ݒ�
	timeBeginPeriod(1);

	execLastTime = fpsLastTime = timeGetTime();
	currentTime = frameCount = 0;

	InitConio(80, 40);

	// �n�ʂ̏���������
	InitField();

	// �v���C���[�̏���������
	InitPlayer();

	// �G�̏���������
	InitEnemy();

	// �e�̏���������
	InitBullet();

	// �Q�[�����C������
	while(1)
	{
		currentTime = timeGetTime();
		if((currentTime - fpsLastTime) >= 500)	// 0.5�b���ƂɎ��s
		{
			countFps = frameCount * 1000 / (currentTime - fpsLastTime);
			fpsLastTime = currentTime;
			frameCount = 0;
		}

		if((currentTime - execLastTime) >= (1000 / 60))
		{
			execLastTime = currentTime;

			// �n�ʂ̍X�V����
			UpdateField();

			// �v���C���[�̍X�V����
			UpdatePlayer();

			// �G�̍X�V����
			UpdateEnemy();

			// �e�̍X�V����
			UpdateBullet();


			// �n�ʂ̕`�揈��
			DrawField();

			// �v���C���[�̕`�揈��
			DrawPlayer();

			// �G�̕`�揈��
			DrawEnemy();

			// �e�̕`�揈��
			DrawBullet();

#ifdef _DEBUG
			// FPS�\��
			DispFPS();
#endif
			frameCount++;
		}
	}

	// �v���C���[�̏I������
	UninitPlayer();

	// �n�ʂ̏I������
	UninitField();

	// ����\��߂�
	timeEndPeriod(1);
}

#ifdef _DEBUG
//=============================================================================
// FPS�\��
//=============================================================================
void DispFPS(void)
{
	char fps[10];
	int len;
	sprintf_s(fps, "FPS:%d", countFps);
	len = (int)strlen(fps);

	SetConsoleTextColor(YELLOW);
	SetCursorPosition(1, 1);
	PrintString(fps, len);
}
#endif

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
