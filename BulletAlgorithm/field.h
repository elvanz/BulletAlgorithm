//=============================================================================
//
// 地面の処理 [field.h]
//
//=============================================================================
#ifndef _FIELD_H_
#define _FIELD_H_

#define	MAX_FIELD		(40)		// 地面の最大数

//*************************************
// 地面の構造体
//*************************************
typedef struct
{
	float posX;			// 地面の基準位置Ｘ座標
	float posY;			// 地面の基準位置Ｙ座標
	float width;		// 地面の幅
	bool enable;		// 地面を使用しているかどうか
} FIELD;

//*****************************************************************************
// プロトタイプ宣言
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
