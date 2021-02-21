//=============================================================================
//
// “G‚Ìˆ— [enemy.cpp]
//
//=============================================================================
#include "main.h"
#include "enemy.h"
#include "bullet.h"

//*****************************************************************************
// ƒ}ƒNƒ’è‹`
//*****************************************************************************
#define	MAX_ENEMY		(100)	// “G‚ÌÅ‘å”

//*****************************************************************************
// ƒvƒƒgƒ^ƒCƒvéŒ¾
//*****************************************************************************

//*****************************************************************************
// ƒOƒ[ƒoƒ‹•Ï”
//*****************************************************************************
ENEMY enemy[MAX_ENEMY];			// “G‚Ìƒ[ƒN

//=============================================================================
// “G‚Ì‰Šú‰»ˆ—
//=============================================================================
void InitEnemy(void)
{
	// “G‚ÌÅ‘å”•ªŒJ‚è•Ô‚µ
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// “G‚Ìî•ñ‚Ì‰Šú‰»
		enemy[countEnemy].posX = 0.0f;
		enemy[countEnemy].posY = 0.0f;
		enemy[countEnemy].oldPosX = 0.0f;
		enemy[countEnemy].oldPosY = 0.0f;
		enemy[countEnemy].moveX = 0.0f;
		enemy[countEnemy].moveY = 0.0f;
		enemy[countEnemy].type = 0;
		enemy[countEnemy].enable = false;
	}

	// “G‚Ì¶¬
	SetEnemy(40.0f, 24.0f, 0);
}

//=============================================================================
// “G‚ÌI—¹ˆ—
//=============================================================================
void UninitEnemy(void)
{
}

//=============================================================================
// “G‚ÌXVˆ—
//=============================================================================
void UpdateEnemy(void)
{
	// “G‚ÌÅ‘å”•ªŒJ‚è•Ô‚µ
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// “G‚ª¶‘¶‚µ‚Ä‚¢‚é‚©
		if (enemy[countEnemy].enable)
		{
			// “G‚ª’e‚ğ”­Ë‚·‚éƒ^ƒCƒ~ƒ“ƒO‚ğ—”‚ÅŒˆ‚ß‚é
			if ((rand() % 100) == 0)
			{
				// “G‚Ì’e”­Ë
				SetBullet(enemy[countEnemy].posX + enemy[countEnemy].moveX + enemy[countEnemy].direction * 2.0f,
					enemy[countEnemy].posY,
					enemy[countEnemy].direction * 0.5f, 0.0f,
					BULLETTYPE_ENEMY);
			}
		}
	}
}

//=============================================================================
// “G‚Ì•`‰æˆ—
//=============================================================================
void DrawEnemy(void)
{
	// “G‚ÌÅ‘å”•ªŒJ‚è•Ô‚µ
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		//	“G‚ª¶‘¶‚µ‚Ä‚¢‚é‚©
		if (enemy[countEnemy].enable)
		{
			// Fİ’è
			SetConsoleTextColor(LIGHTBLUE);

			// ‘O‰ñ‚ÌˆÊ’u‚Å‚Ì“G‚ğÁ‹
			SetCursorPosition((int)(enemy[countEnemy].oldPosX), (int)(enemy[countEnemy].oldPosY - 1.0f));
			printf("@");
			SetCursorPosition((int)(enemy[countEnemy].oldPosX), (int)(enemy[countEnemy].oldPosY));
			printf("@");

			// Œ»İ‚ÌˆÊ’u‚É“G‚ğ•\¦
			SetCursorPosition((int)(enemy[countEnemy].posX), (int)(enemy[countEnemy].posY - 1.0f));
			printf("¥");
			SetCursorPosition((int)(enemy[countEnemy].posX), (int)(enemy[countEnemy].posY));
			printf("¡");
		}
	}
}

//=============================================================================
// “G‚Ì¶¬
//=============================================================================
void SetEnemy(float posX, float posY, int type)
{
	// “G‚ÌÅ‘å”•ªŒJ‚è•Ô‚µ
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// “G‚ª¶‘¶‚µ‚Ä‚¢‚È‚¢‚©
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
			enemy[countEnemy].enable = true;	// “G‚ğ¶‘¶ó‘Ô‚É

			break;
		}
	}
}

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
