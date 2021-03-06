//-----------------------------------------------------------------------------
// じゃんけんゲーム v4 enumの定義を別ファイルへ分離
//
// プログラムの規模も大きくなってきたので、ファイルを分割していく。
// まずはenumの定義や、enumに関する関数ををcommon.h/cに分離します。
//-----------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common.h"

// コンパイラにC6031の警告を無視するように伝えるプリプロセッサ
// scanfには戻り値があるが、特に戻り値を使っていないためC6031の警告がでる。
// 放置してもいいが、警告出てるのも気になるので今回は無視することにした。
#pragma warning (disable: 6031)

/// <summary>
/// ゲームの状態を格納する構造体を定義
/// </summary>
typedef struct {
	BOOL inGame;   // ゲーム中はTRUE、ゲームを終了する場合にFALSEを設定
	HAND player;   // プレイヤーのじゃんけんの手
	HAND cpu;      // CPUのじゃんけんの手
	RESULT result; // 勝敗
} State;

/// <summary>
/// ゲームの状態を保持する変数を定義
/// </summary>
State gState;

//-----------------------------------------------------------------------------
// 関数プロトタイプ宣言

// 入力の処理
void input(void);

// 更新
void update(void);

// 描画
void draw(void);

// 状態をリセット
void ResetState(State* state);

// エントリーポイント(プログラムの入り口)
int main(void)
{
	// ゲームの初期化
	// コンピューターの乱数(ランダムな数)は疑似乱数といって、本当のランダムではない。
	// ランダムシートと呼ばれる、乱数の種を決める事で、その種を基準にランダムっぽい数を生成している。
	// 以下のsrandはランダムシードを設定する処理で、time(NULL)というのは現在時刻の数値を取得している。
	// 現在時刻は常に変化するため、ランダムシードに現在時刻を設定すると実質ランダムとなるため
	// 乱数を扱う場合は、プログラムの最初で以下の処理を書く事が多い。
	srand((unsigned int)time(NULL));

	printf("----------------------------------------------------------\n");
	printf("じゃんけんゲーム v4\n");
	printf("----------------------------------------------------------\n");

	// ゲームループ
	while (TRUE)
	{
		// 入力
		input();

		// ゲーム終了ならループを抜ける
		if (gState.inGame == FALSE) break;

		// 更新
		update();

		// 描画
		draw();
	}

	printf("ゲームを終了しました。");

	return 0;
}

/// プレイヤーの入力を受け取り、gStateに格納する。
void input(void)
{
	// 最初にゲームの状態をリセットしておく
	ResetState(&gState);

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
			gState.inGame = FALSE;
			break;
		}

		// 9以外が入力されていたら、じゃんけんの手として正しいかチェックし
		if (isRightHand(input)) {
			gState.player = input;
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
void update(void)
{
	// コンピューターの手を決める(gStateに格納)
	gState.cpu = getRandomHand();

	// 勝敗結果を格納
	gState.result = getResult(gState.player, gState.cpu);
}

/// <summary>
/// 描画(ゲームの状態を表示)
/// </summary>
void draw(void)
{
	// 結果を表示
	printf("********************\n");
	showHand("あなた", gState.player);
	showHand("相手　", gState.cpu);
	printf("--------------------\n");
	showResult(gState.result);
	printf("********************\n");
	breakLine();
}

/// <summary>
/// ゲームの状態をリセット
/// </summary>
void ResetState(State* state)
{
	// ポインタがNULLだったら何もしない
	if (state == NULL) return;

	// 内容をリセット
	state->inGame = TRUE;
	state->player = E_HAND_UNKNOWN;
	state->cpu = E_HAND_UNKNOWN;
	state->result = E_RESULT_UNKNOWN;
}