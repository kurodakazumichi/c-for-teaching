#pragma once
//-----------------------------------------------------------------------------
// common.h
// じゃんけんゲームで共通で扱う列挙体定義や、列挙型に関する関数の宣言
//-----------------------------------------------------------------------------

/// <summary>
/// TRUE、FALSEを定義
/// </summary>
typedef enum {
	FALSE = 0,
	TRUE = 1,
} BOOL;

/// <summary>
/// じゃんけんの手(グー、チョキ、パー)を定義(定数リスト)
/// </summary>
typedef enum {
	E_HAND_UNKNOWN = -1, // 不明(列挙型の先頭)

	E_HAND_G, // グー
	E_HAND_T, // チョキ
	E_HAND_P, // パー

	E_HAND_COUNT,    // 列挙型の最後の要素(チェック用)
} HAND;

/// <summary>
/// 勝敗のパターンを定義(定数リスト)
/// </summary>
typedef enum
{
	E_RESULT_UNKNOWN = -1, // なし
	E_RESULT_WIN,          // 勝ち
	E_RESULT_LOSE,         // 負け
	E_RESULT_DRAW,         // あいこ
} RESULT;

//-----------------------------------------------------------------------------
// 関数プロトタイプ宣言

// じゃんけんの手が正しいかチェックする関数
BOOL isRightHand(int maybeHand);

// ランダムでじゃんけんの手を取得する関数
HAND getRandomHand(void);

// じゃんけんの勝敗を判定する関数
int getResult(HAND player, HAND cpu);

// じゃんけんの手を表示
void showHand(char* prefix, HAND type);

// じゃんけんの勝敗を表示する関数
void showResult(RESULT type);

// 改行するだけの関数
void breakLine();