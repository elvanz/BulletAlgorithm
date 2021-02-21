//=============================================================================
//
// プレイヤー処理 [player.h]
//
//=============================================================================
#pragma once

//*************************************
// プレイヤー構造体
//*************************************
typedef struct
{
	float posX;			// 現在のX座標
	float posY;			// 現在のY座標
	float oldPosX;		// 前回のX座標
	float oldPosY;		// 前回のY座標
	float moveX;		// X方向の移動量
	float moveY;		// Y方向の移動量
	bool jumpFlg;		// ジャンプ中ならtrue
	bool landFlg;		// 着地中ならtrue
	bool moveFlg;		// 移動しているならtrue
	bool shotFlg;		// ショット中ならtrue
	float direction;	// 向き
} PLAYER;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
