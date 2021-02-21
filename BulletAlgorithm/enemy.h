//=============================================================================
//
// 敵の処理 [enemy.h]
//
//=============================================================================
#ifndef _ENEMY_H_
#define _ENEMY_H_

//*************************************
// 敵の構造体
//*************************************
typedef struct
{
	float posX;			// 現在のX座標
	float posY;			// 現在のY座標
	float oldPosX;		// 前回のX座標
	float oldPosY;		// 前回のY座標
	float moveX;		// X方向の移動量
	float moveY;		// Y方向の移動量
	float direction;	// 向き
	int type;			// タイプ	
	bool enable;		// 使用中かどうか
} ENEMY;

//*****************************************************************************
// プロトタイプ宣言
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
