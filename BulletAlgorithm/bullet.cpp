//=============================================================================
//
// 弾の処理 [bullet.cpp]
//
//=============================================================================
#include "main.h"
#include "bullet.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	MAX_BULLET		(100)	// 弾の最大数

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************


//*****************************************************************************
// グローバル変数
//*****************************************************************************
BULLET bullet[MAX_BULLET];		// 弾のワーク

//=============================================================================
// 弾の初期化処理
//=============================================================================
void InitBullet(void)
{
	// 弾の最大数分繰り返し
	for (int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// 弾の情報の初期化
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
// 弾の終了処理
//=============================================================================
void UninitBullet(void)
{
}

//=============================================================================
// 弾の更新処理
//=============================================================================
void UpdateBullet(void)
{
	// 弾の最大数分繰り返し
	for (int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// 弾が使用状態か
		if (bullet[countBullet].enable)
		{
			// 現在の位置を保存
			bullet[countBullet].oldPosX = bullet[countBullet].posX;
			bullet[countBullet].oldPosY = bullet[countBullet].posY;

			// 位置を更新
			bullet[countBullet].posX += bullet[countBullet].moveX;
			bullet[countBullet].posY += bullet[countBullet].moveY;

			// 弾が画面外に出たか？
			if (bullet[countBullet].posX < 2.0f
				|| bullet[countBullet].posX > 78.0f
				|| bullet[countBullet].posY < 2.0f
				|| bullet[countBullet].posY > 24.0f)
			{
				// 前回の位置での弾を消去
				SetCursorPosition((int)(bullet[countBullet].oldPosX), (int)(bullet[countBullet].oldPosY));
				printf("　");

				bullet[countBullet].enable = false;	// 弾を未使用状態に
			}
		}
	}
}

//=============================================================================
// 弾の描画処理
//=============================================================================
void DrawBullet(void)
{
	// 弾の最大数分繰り返し
	for(int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// 弾が使用状態か
		if(bullet[countBullet].enable)
		{
			 // 色設定
			if(bullet[countBullet].type == BULLETTYPE_PLAYER)
			{
				// プレイヤーの弾の色を指定
				SetConsoleTextColor(LIGHTGREEN);
			}
			else
			{
				// 敵の弾の色を指定
				SetConsoleTextColor(LIGHTCYAN);
			}

			// 前回の位置での弾を消去
			SetCursorPosition((int)(bullet[countBullet].oldPosX), (int)(bullet[countBullet].oldPosY));
			printf("　");

			// 現在の位置に玉を表示
			SetCursorPosition((int)(bullet[countBullet].posX), (int)(bullet[countBullet].posY));
			printf("◎");
		}
	}
}

//=============================================================================
// 弾の生成
//=============================================================================
void SetBullet(float posX, float posY, float moveX, float moveY, BULLETTYPE type)
{
	// 弾の最大数分繰り返し
	for(int countBullet = 0; countBullet < MAX_BULLET; countBullet++)
	{
		// 弾が未使用状態か
		if(!bullet[countBullet].enable)
		{
			bullet[countBullet].posX = posX;
			bullet[countBullet].posY = posY;
			bullet[countBullet].oldPosX = posX;
			bullet[countBullet].oldPosY = posY;
			bullet[countBullet].moveX = moveX;
			bullet[countBullet].moveY = moveY;
			bullet[countBullet].type = type;
			bullet[countBullet].enable = true;	// 弾を使用状態に

			break;
		}
	}
}


/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
