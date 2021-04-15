//-----------------------------------------------------------------------------
// Game.c
//
// じゃんけんゲームの本体
//-----------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"
#include "State.h"
#include "Game.h"

// コンパイラにC6031の警告を無視するように伝えるプリプロセッサ
// scanfには戻り値があるが、特に戻り値を使っていないためC6031の警告がでる。
// 放置してもいいが、警告出てるのも気になるので今回は無視することにした。
#pragma warning (disable: 6031)

/// <summary>
/// ゲームの状態を保持すグローバル変数(ポインタ)を定義
/// </summary>
State* gState = NULL;

//-----------------------------------------------------------------------------
// 関数プロトタイプ宣言

/// プレイヤーの入力を受け取り、gStateに格納する。
static void input(void)
{
	// 最初にゲームの状態をリセットしておく
	State_reset(gState);

	// 入力内容が確定するまでループする
	while (TRUE)
	{
		printf("コマンドを入力してください\n");
		printf("%d:グー\n", E_HAND_G);
		printf("%d:チョキ\n", E_HAND_T);
		printf("%d:パー\n", E_HAND_P);
		breakLine();
		printf("9:終了する\n");

		// 入力内容を受け取る
		int input = 0;
		scanf("%d", &input);
		breakLine();

		// 9が入力されていたら状態のinGameをFALSEにして終了
		if (input == 9) {
			State_setInGame(gState, FALSE);
			break;
		}

		// 9以外が入力されていたら、じゃんけんの手として正しいかチェックし
		if (isRightHand(input)) {
			State_setPlayer(gState, input);
			break;
		}
		else {
			printf("グー、チョキ、パーから選んでください。\n\n");
		}
	}
}

/// ゲームの更新
/// CPUのじゃんけんの内容を決定し、勝敗判定を行う。
/// 結果表示に必要な情報をgStateに書き込む。
static void update(void)
{
	// コンピューターの手を決める(gStateに格納)
	State_setCpu(gState, getRandomHand());

	// 勝敗結果を格納
	State_setResult(gState, getResult(State_getPlayer(gState), State_getCpu(gState)));
}

/// <summary>
/// 描画(ゲームの状態を表示)
/// </summary>
static void draw(void)
{
	// 結果を表示
	printf("********************\n");
	showHand("あなた", State_getPlayer(gState));
	showHand("相手　", State_getCpu(gState));
	printf("--------------------\n");
	showResult(State_getResult(gState));
	printf("********************\n");
	breakLine();
}

// ゲームループ処理
void gameLoop(void) {
	// ゲームの状態を管理するStateを作成(動的にメモリを確保しているので最後に解放すること)
	gState = State_makeInstance();

	// ゲームの初期化
	// コンピューターの乱数(ランダムな数)は疑似乱数といって、本当のランダムではない。
	// ランダムシートと呼ばれる、乱数の種を決める事で、その種を基準にランダムっぽい数を生成している。
	// 以下のsrandはランダムシードを設定する処理で、time(NULL)というのは現在時刻の数値を取得している。
	// 現在時刻は常に変化するため、ランダムシードに現在時刻を設定すると実質ランダムとなるため
	// 乱数を扱う場合は、プログラムの最初で以下の処理を書く事が多い。
	srand((unsigned int)time(NULL));

	printf("----------------------------------------------------------\n");
	printf("じゃんけんゲーム v6\n");
	printf("----------------------------------------------------------\n");

	// ゲームループ
	while (TRUE)
	{
		// 入力
		input();

		// ゲーム終了ならループを抜ける
		if (State_getInGame(gState) == FALSE) break;

		// 更新
		update();

		// 描画
		draw();
	}

	printf("ゲームを終了しました。");

	// メモリを解放
	State_freeInstance(gState);
	gState = NULL;
}