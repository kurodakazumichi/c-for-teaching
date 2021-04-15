#pragma once
//-----------------------------------------------------------------------------
// State.h
//
// ゲームの状態を保持しているState構造体に関する宣言
//-----------------------------------------------------------------------------
#include "common.h"

// ヘッダでは_Stateという構造体があるよという事を定義するのみ。
// 中身に関する情報を定義していないので、実際に使うときは
// struct _State* state;のようにポインタで使うことになる。
struct _State;

// structの定義だと変数定義する際にいちいち
// struct _State* state; と書かないといけないが
// struct _State を State という名前で定義しておく(別名定義ともいう)と
// State* state; と書けるようになるのでtypedefしている。
typedef struct _State State;

//-----------------------------------------------------------------------------
// Stateを扱うための関数プロトタイプ宣言

// State構造体のインスタンスを生成して返す
State* State_makeInstance(void);

// State構造体インスタンスを解放する
void State_freeInstance(State* this);

// State構造体のメンバをリセットする
void State_reset(State* this);

// State.inGameのアクセッサ
BOOL State_getInGame(State* this);
void State_setInGame(State* this, BOOL value);

// State.playerのアクセッサ
HAND State_getPlayer(State* this);
void State_setPlayer(State* this, HAND value);

// State.cpuのアクセッサ
HAND State_getCpu(State* this);
void State_setCpu(State* this, HAND value);

// State.resultのアクセッサ
RESULT State_getResult(State* this);
void State_setResult(State* this, HAND value);