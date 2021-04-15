#pragma once
//-----------------------------------------------------------------------------
// 列挙型の定義をまとめたファイル
//-----------------------------------------------------------------------------

/// <summary>
/// TRUE、FALSEを定義
/// </summary>
typedef enum {
	FALSE = 0,
	TRUE  = 1,
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