//=============================================================================
//
// アクションゲームサンプル [main.cpp]
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "field.h"
#include "enemy.h"
#include "bullet.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
#ifdef _DEBUG
void DispFPS(void);
#endif

//*****************************************************************************
// グローバル変数
//*****************************************************************************
int countFps;				// FPSカウンタ

//=============================================================================
// メイン関数
//=============================================================================
int main(void)
{
	int execLastTime;
	int fpsLastTime;
	int currentTime;
	int frameCount;

	// 分解能を設定
	timeBeginPeriod(1);

	execLastTime = fpsLastTime = timeGetTime();
	currentTime = frameCount = 0;

	InitConio(80, 40);

	// 地面の初期化処理
	InitField();

	// プレイヤーの初期化処理
	InitPlayer();

	// 敵の初期化処理
	InitEnemy();

	// 弾の初期化処理
	InitBullet();

	// ゲームメイン処理
	while(1)
	{
		currentTime = timeGetTime();
		if((currentTime - fpsLastTime) >= 500)	// 0.5秒ごとに実行
		{
			countFps = frameCount * 1000 / (currentTime - fpsLastTime);
			fpsLastTime = currentTime;
			frameCount = 0;
		}

		if((currentTime - execLastTime) >= (1000 / 60))
		{
			execLastTime = currentTime;

			// 地面の更新処理
			UpdateField();

			// プレイヤーの更新処理
			UpdatePlayer();

			// 敵の更新処理
			UpdateEnemy();

			// 弾の更新処理
			UpdateBullet();


			// 地面の描画処理
			DrawField();

			// プレイヤーの描画処理
			DrawPlayer();

			// 敵の描画処理
			DrawEnemy();

			// 弾の描画処理
			DrawBullet();

#ifdef _DEBUG
			// FPS表示
			DispFPS();
#endif
			frameCount++;
		}
	}

	// プレイヤーの終了処理
	UninitPlayer();

	// 地面の終了処理
	UninitField();

	// 分解能を戻す
	timeEndPeriod(1);
}

#ifdef _DEBUG
//=============================================================================
// FPS表示
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
