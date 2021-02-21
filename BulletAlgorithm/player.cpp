//=============================================================================
//
// プレイヤー処理 [player.cpp]
//
//=============================================================================
#include "main.h"
#include "player.h"
#include "field.h"
#include "bullet.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	VALUE_MOVE_X			(0.75f)		// 地上での移動量Ｘ方向
#define	VALUE_MOVE_X_AIR		(0.30f)		// 空中での移動量Ｘ方向
#define	VALUE_JUMP				(0.80f)		// ジャンプ量
#define	VALUE_RESIST_X			(0.50f)		// 地上での移動摩擦抵抗
#define	VALUE_RESIST_X_AIR		(0.35f)		// 空中での移動摩擦抵抗
#define	VALUE_GRAVITY			(0.06f)		// 重力量

#define	LIMIT_LEFT				(2.0f)		// 移動範囲左端
#define	LIMIT_RIGHT				(78.0f)		// 移動範囲右端
#define	LIMIT_DOWN				(24.0f)		// 移動範囲下端

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
bool CheckCollisionField(void);

//*****************************************************************************
// グローバル変数
//*****************************************************************************
PLAYER player;		// プレイヤーの情報(構造体変数)

//=============================================================================
// プレイヤーの初期化処理
//=============================================================================
void InitPlayer(void)
{
	// プレイヤー情報の初期化
	player.posX = 20.0f;
	player.posY = 24.0f;
	player.oldPosX = 20.0f;
	player.oldPosY = 24.0f;
	player.moveX = 0.0f;
	player.moveY = 0.0f;
	player.jumpFlg = false;
	player.landFlg = false;
	player.moveFlg = false;
	player.shotFlg = false;
	player.direction = 1.0f;
}

//=============================================================================
// プレイヤーの終了処理
//=============================================================================
void UninitPlayer(void)
{
}

//=============================================================================
// プレイヤーの更新処理
//=============================================================================
void UpdatePlayer(void)
{
	// 現在の位置を保存
	player.oldPosX = player.posX;
	player.oldPosY = player.posY;

	// 左キーが押されている場合は左移動
	if (InputKeyMouse(PK_LEFT))
	{
		// ジャンプ中かの判定
		if (player.jumpFlg)
		{
			// ジャンプ中であればジャンプ中の移動量をセット
			player.moveX -= VALUE_MOVE_X_AIR;
		}
		else
		{
			// ジャンプ中ではない場合は移動量をセット
			player.moveX -= VALUE_MOVE_X;
		}

		// 移動中であることをフラグにセットする
		player.moveFlg = true;

		// プレイヤーの向きの情報をマイナス（左方向）にする
		player.direction = -1.0f;
	}

	// 右キーが押されている場合は右移動
	if (InputKeyMouse(PK_RIGHT))
	{
		// ジャンプ中かの判定
		if (player.jumpFlg)
		{
			// ジャンプ中であればジャンプ中の移動量をセット
			player.moveX += VALUE_MOVE_X_AIR;
		}
		else
		{
			// ジャンプ中ではない場合は移動量をセット
			player.moveX += VALUE_MOVE_X;
		}

		// 移動中であることをフラグにセットする
		player.moveFlg = true;

		// プレイヤーの向きの情報をプラス（右方向）にする
		player.direction = 1.0f;
	}

	// 上キーが押されている場合はジャンプ
	if (InputKeyMouse(PK_UP))
	{
		// 既にフラグがジャンプ中の場合は処理しない
		// ※これがないとずっとキーが押されている間
		// 　ずっと上に移動してしまいます
		if (!player.jumpFlg)
		{
			// Y方向にジャンプ中の移動量をセットする
			player.moveY = -VALUE_JUMP;

			// ジャンプ中であることをフラグにセットする
			player.jumpFlg = true;
		}
	}

	// スペースキーが押されたら攻撃
	if (InputKeyMouse(PK_SP))
	{
		// 弾が既に生成されていないか
		// （キー押し続けでの弾の連続発射を防ぐ）
		if (!player.shotFlg)
		{
			// 弾を生成する
			// この関数の中で弾の最大数まで弾を生成することができる
			SetBullet(player.posX + player.moveX + player.direction * 2.0f,
				player.posY,
				player.direction,
				0.0f,
				BULLETTYPE_PLAYER);
			player.shotFlg = true;
		}
	}
	else
	{
		// 弾が生成されているか
		if (player.shotFlg)
		{
			// 弾が生成されていたら未生成にする
			player.shotFlg = false;
		}
	}

	// ジャンプ中の移動計算
	if (player.jumpFlg)
	{
		// ジャンプ中は移動となるので移動フラグをセット
		player.moveFlg = true;

		// ジャンプ中はプレイヤーの横方向の移動に空中用の抵抗を加える
		player.moveX += (0.0f - player.moveX) * VALUE_RESIST_X_AIR;
	}
	else
	{
		// 地上にいるときはプレイヤーの横方向の移動に地上用の抵抗を加える
		player.moveX += (0.0f - player.moveX) * VALUE_RESIST_X;
	}

	// 現在の位置を更新する
	player.posX += player.moveX;

	// プレイヤーの位置が画面左端より小さい場合
	if (player.posX < LIMIT_LEFT)
	{
		// プレイヤーの位置を画面左端にする
		player.posX = LIMIT_LEFT;
	}

	// プレイヤーの位置が画面右端より大きい場合
	if (player.posX > LIMIT_RIGHT)
	{
		// プレイヤーの位置を画面右端にする
		player.posX = LIMIT_RIGHT;
	}

	// 重力を加える
	player.moveY += VALUE_GRAVITY;
	player.posY += player.moveY;

	// プレイヤーが画面下限を越えたか
	if (player.posY > LIMIT_DOWN)
	{
		// 地面にめり込んだ場合は画面下限に
		// 位置を合わせる
		player.posY = LIMIT_DOWN;
		player.moveY = 0.0f;
		player.jumpFlg = false;
	}

	// 地面との当たり判定
	if (CheckCollisionField() == true)
	{
		// 地面に当たった場合
		player.moveY = 0.0f;
		player.moveFlg = true;
		player.jumpFlg = false;
		player.landFlg = true;
	}
	else
	{
		// 地面と当たっていない場合
		if (player.landFlg)
		{
			// 地面に接していなければジャンプ中にする
			player.jumpFlg = true;
			player.landFlg = false;
		}
	}
}

//=============================================================================
// プレイヤーの描画処理
//=============================================================================
void DrawPlayer(void)
{
	// プレイヤーが移動したか
	if (player.moveFlg)
	{
		// 前回の位置でのプレイヤーを消去
		SetCursorPosition((int)player.oldPosX, (int)player.oldPosY);
		PrintString("  ", 2);
		SetCursorPosition((int)player.oldPosX, (int)(player.oldPosY - 1.0f));
		PrintString("  ", 2);

		player.moveFlg = false;
	}

	// 色設定
	SetConsoleTextColor(YELLOW);

	// 現在の位置にプレイヤーを表示
	SetCursorPosition((int)player.posX, (int)player.posY);
	PrintString("■", 2);
	SetCursorPosition((int)player.posX, (int)(player.posY - 1.0f));
	PrintString("●", 2);
}

//=============================================================================
// 地面との当たり判定
//=============================================================================
bool CheckCollisionField(void)
{
	FIELD *field;

	// 地面のデータの先頭アドレスを取得する
	field = GetField();

	// 地面のデータ数分繰り返す
	for (int cntField = 0; cntField < MAX_FIELD; cntField++, field++)
	{
		// 地面が有効か
		if (field->enable)
		{
			// 上から地面に当たった時の判定
			// プレイヤーと地面の範囲が重なっているかをチェック（X方向）
			if ((player.posX + 0.9f) > field->posX && player.posX < (field->posX + field->width - 0.1f))
			{
				// プレイヤーと地面の範囲が重なっているかをチェック（Y方向）
				if (player.posY > (field->posY - 1.0f) && player.oldPosY <= (field->posY - 1.0f))
				{
					// XもYも重なっているため地面のY座標の上をプレイヤーの座標とする
					player.posY = field->posY - 1.0f;

					return true;
				}
			}

			// 下から地面に当たった時の判定
			// プレイヤーと地面の範囲が重なっているかをチェック（X方向）
			if ((player.posX + 0.9f) > field->posX && player.posX < (field->posX + field->width - 0.1f))
			{
				// プレイヤーと地面の範囲が重なっているかをチェック（Y方向）
				if ((player.posY - 2.0f) < field->posY && (player.oldPosY - 1.0f) >= field->posY)
				{
					// XもYも重なっているため地面のY座標の上をプレイヤーの座標とする
					player.posY = field->posY + 2.0f;
					player.moveY = 0.0f;
				}
			}
		}
	}

	return false;
}

/**
 * @copyright (c) 2018-2021 HAL Osaka College of Technology & Design (Ihara, H.)
 */
