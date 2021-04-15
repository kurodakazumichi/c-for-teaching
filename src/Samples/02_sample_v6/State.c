//-----------------------------------------------------------------------------
// State.c
//
// ゲームの状態を保持しているState構造体に関する定義
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include "common.h"
#include "State.h"

/// <summary>
/// ゲームの状態を格納する構造体を定義
/// </summary>
struct _State
{
	BOOL inGame;   // ゲーム中はTRUE、ゲームを終了する場合にFALSEを設定
	HAND player;   // プレイヤーのじゃんけんの手
	HAND cpu;      // CPUのじゃんけんの手
	RESULT result; // 勝敗
};

//-----------------------------------------------------------------------------
// Stateを扱うための関数定義

// State構造体のインスタンスを生成して返す
State* State_makeInstance(void) 
{
	State* state = malloc(sizeof(struct _State));
	State_reset(state);
}

// State構造体インスタンスを解放する
void State_freeInstance(State* this) {
	free(this);
}

// State構造体のメンバをリセットする
void State_reset(State* this) 
{
	this->inGame = TRUE;
	this->player = E_HAND_UNKNOWN;
	this->cpu    = E_HAND_UNKNOWN;
	this->result = E_RESULT_UNKNOWN;
}

// State.inGameのアクセッサ
BOOL State_getInGame(State* this) {
	return this->inGame;
}
void State_setInGame(State* this, BOOL value) {
	this->inGame = value;
}

// State.playerのアクセッサ
HAND State_getPlayer(State* this) {
	return this->player;
}
void State_setPlayer(State* this, HAND value) 
{
	// おかしな値が入らないようにチェックを挟む
	this->player = (isRightHand(value) == TRUE)
		? value
		: E_HAND_UNKNOWN;
}

// State.cpuのアクセッサ
HAND State_getCpu(State* this) {
	return this->cpu;
}
void State_setCpu(State* this, HAND value) 
{
	// おかしな値が入らないようにチェックを挟む
	this->cpu = (isRightHand(value) == TRUE)
		? value
		: E_HAND_UNKNOWN;
}

// State.resultのアクセッサ
RESULT State_getResult(State* this) {
	return this->result;
}
void State_setResult(State* this, RESULT value) {
	this->result = value;
}