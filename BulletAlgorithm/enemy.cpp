//=============================================================================
//
// 敵の処理 [enemy.cpp]
//
//=============================================================================
#include "main.h"
#include "enemy.h"
#include "bullet.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	MAX_ENEMY		(100)	// 敵の最大数

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

//*****************************************************************************
// グローバル変数
//*****************************************************************************
ENEMY enemy[MAX_ENEMY];			// 敵のワーク

//=============================================================================
// 敵の初期化処理
//=============================================================================
void InitEnemy(void)
{
	// 敵の最大数分繰り返し
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// 敵の情報の初期化
		enemy[countEnemy].posX = 0.0f;
		enemy[countEnemy].posY = 0.0f;
		enemy[countEnemy].oldPosX = 0.0f;
		enemy[countEnemy].oldPosY = 0.0f;
		enemy[countEnemy].moveX = 0.0f;
		enemy[countEnemy].moveY = 0.0f;
		enemy[countEnemy].type = 0;
		enemy[countEnemy].enable = false;
	}

	// 敵の生成
	SetEnemy(40.0f, 24.0f, 0);
}

//=============================================================================
// 敵の終了処理
//=============================================================================
void UninitEnemy(void)
{
}

//=============================================================================
// 敵の更新処理
//=============================================================================
void UpdateEnemy(void)
{
	// 敵の最大数分繰り返し
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// 敵が生存しているか
		if (enemy[countEnemy].enable)
		{
			// 敵が弾を発射するタイミングを乱数で決める
			if ((rand() % 100) == 0)
			{
				// 敵の弾発射
				SetBullet(enemy[countEnemy].posX + enemy[countEnemy].moveX + enemy[countEnemy].direction * 2.0f,
					enemy[countEnemy].posY,
					enemy[countEnemy].direction * 0.5f, 0.0f,
					BULLETTYPE_ENEMY);
			}
		}
	}
}

//=============================================================================
// 敵の描画処理
//=============================================================================
void DrawEnemy(void)
{
	// 敵の最大数分繰り返し
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		//	敵が生存しているか
		if (enemy[countEnemy].enable)
		{
			// 色設定
			SetConsoleTextColor(LIGHTBLUE);

			// 前回の位置での敵を消去
			SetCursorPosition((int)(enemy[countEnemy].oldPosX), (int)(enemy[countEnemy].oldPosY - 1.0f));
			printf("　");
			SetCursorPosition((int)(enemy[countEnemy].oldPosX), (int)(enemy[countEnemy].oldPosY));
			printf("　");

			// 現在の位置に敵を表示
			SetCursorPosition((int)(enemy[countEnemy].posX), (int)(enemy[countEnemy].posY - 1.0f));
			printf("▼");
			SetCursorPosition((int)(enemy[countEnemy].posX), (int)(enemy[countEnemy].posY));
			printf("■");
		}
	}
}

//=============================================================================
// 敵の生成
//=============================================================================
void SetEnemy(float posX, float posY, int type)
{
	// 敵の最大数分繰り返し
	for (int countEnemy = 0; countEnemy < MAX_ENEMY; countEnemy++)
	{
		// 敵が生存していないか
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
			enemy[countEnemy].enable = true;	// 敵を生存状態に

			break;
		}
	}
}

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
