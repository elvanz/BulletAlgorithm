//=============================================================================
//
// 弾の処理 [bullet.h]
//
//=============================================================================
#ifndef _BULLET_H_
#define _BULLET_H_

//*************************************
// 弾の種類
//*************************************
typedef enum
{
	BULLETTYPE_PLAYER = 0,		// プレイヤーの弾
	BULLETTYPE_ENEMY,			// 敵の弾
	BULLETTYPE_MAX
} BULLETTYPE;

//*************************************
// 弾の構造体
//*************************************
typedef struct
{
	float posX;			// 現在のX座標
	float posY;			// 現在のY座標
	float oldPosX;		// 前回のX座標
	float oldPosY;		// 前回のY座標
	float moveX;		// X方向の移動量
	float moveY;		// Y方向の移動量
	BULLETTYPE type;	// 弾の種類
	bool enable;		// 使用中かどうか
} BULLET;

//*****************************************************************************
// プロトタイプ宣言
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
