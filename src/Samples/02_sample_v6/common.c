#pragma once
//-----------------------------------------------------------------------------
// common.c
// じゃんけんゲームで共通で扱う列挙体に関する関数定義
//-----------------------------------------------------------------------------
#include <stdio.h>
#include "common.h"

// 引数に渡されたじゃんけんの手が正しいかどうか(グー、チョキ、パーか？)をチェックする関数
BOOL isRightHand(int maybeHand)
{
	// 列挙型の定義を使ってじゃんけんの手が正しいか判定する
	// UNKNOWN < type < E_HAND_ENDであればグー、チョキ、パーのいずれかになる
	return (E_HAND_UNKNOWN < maybeHand&& maybeHand < E_HAND_COUNT) ? TRUE : FALSE;
}

// じゃんけんの手をランダムで取得する
HAND getRandomHand(void)
{
	// E_HAND_ENDはじゃんけん手数を表す。
	return rand() % E_HAND_COUNT;
}

// プレイヤーとコンピュータの手から勝敗を判定し、結果を返す。
enum Result getResult(HAND player, HAND cpuHand)
{
	// 手が同じならあいこ
	if (player == cpuHand) return E_RESULT_DRAW;

	// プレイヤーがグーの場合
	if (player == E_HAND_G)
	{
		// CPUがチョキならプレイヤーの勝ち
		if (cpuHand == E_HAND_T) return E_RESULT_WIN;
		// CPUがパーならプレイヤーの負け
		if (cpuHand == E_HAND_P) return E_RESULT_LOSE;
	}

	// プレイヤーがチョキの場合
	if (player == E_HAND_T) {
		// CPUがグーならプレイヤーの負け
		if (cpuHand == E_HAND_G) return E_RESULT_LOSE;
		// CPUがパーならプレイヤーの勝ち
		if (cpuHand == E_HAND_P) return E_RESULT_WIN;
	}

	// プレイヤーがパーの場合
	if (player == E_HAND_P) {
		// CPUがグーならプレイヤーの勝ち
		if (cpuHand == E_HAND_G) return E_RESULT_WIN;
		// CPUがチョキならプレイヤーの負け
		if (cpuHand == E_HAND_T) return E_RESULT_LOSE;
	}

	// 勝敗不明
	return E_RESULT_UNKNOWN;
}

// じゃんけんの手を表示
void showHand(char* prefix, HAND type)
{
	switch (type) {
	case E_HAND_G: printf("%s:%s\n", prefix, "グー"); break;
	case E_HAND_T: printf("%s:%s\n", prefix, "チョキ"); break;
	case E_HAND_P: printf("%s:%s\n", prefix, "パー"); break;
	}
}

// じゃんけんの勝敗を表示する関数
void showResult(RESULT type)
{
	switch (type) {
	case E_RESULT_WIN: printf("あなたの勝ち\n"); break;
	case E_RESULT_LOSE: printf("あなたの負け\n"); break;
	case E_RESULT_DRAW: printf("あいこでした\n"); break;
	default: printf("想定しない結果でした"); break;
	}
}

// 改行するだけの処理
void breakLine() {
	printf("\n");
}