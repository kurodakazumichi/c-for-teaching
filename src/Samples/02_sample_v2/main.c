//-----------------------------------------------------------------------------
// じゃんけんゲーム v2 (enumの活用)
// ゲームの基本は入力を受け取り、入力を元に演算をし、その結果を表示すること
//
// 1. プレイヤーの入力を受け取る
// 2. コンピュータの手(グー、チョキ、パー)をランダムに決める
// 3. 勝敗判定
// 4. 勝敗を表示
// 5. リトライ処理
//-----------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// コンパイラにC6031の警告を無視するように伝えるプリプロセッサ
// scanfには戻り値があるが、特に戻り値を使っていないためC6031の警告がでる。
// 放置してもいいが、警告出てるのも気になるので今回は無視することにした。
#pragma warning (disable: 6031)

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
BOOL isRightHand(HAND type);

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
	printf("じゃんけんゲーム\n");
	printf("----------------------------------------------------------\n");

	// ゲームループ
	while (1)
	{
		printf("何を出しますか？\n");
		printf("0:グー\n");
		printf("1:チョキ\n");
		printf("2:パー\n");

		// 1. プレイヤーの入力
		// プレイヤーのじゃんけんの手(0:グー、1:チョキ、2:パー)とする
		int playerHand = 0;
		scanf("%d", &playerHand);
		breakLine();

		// 入力内容が正しいかどうかをチェック
		if (!isRightHand(playerHand)) {
			printf("グー、チョキ、パーから選んでください。\n");
			continue;
		}

		// 2. コンピューターの手を決める
		int cpuHand = getRandomHand();

		// 3. 勝敗判定
		int result = getResult(playerHand, cpuHand);

		// 4. 結果を表示
		showHand("あなた", playerHand);
		showHand("相手　", cpuHand);
		showResult(result);

		// リトライ？
		printf("もう一度勝負しますか？\n");
		printf("0: いいえ\n");
		printf("1: はい\n");

		// 入力番号を受け取る
		int no = 0;
		scanf("%d", &no);
		breakLine();

		// はいが選ばれたらまたループの最初へ戻る
		if (no == 1) {
			continue;
		}

		// はい以外が選ばれていたらループ終了
		break;
	}

	printf("ゲームを終了しました。");

	return 0;
}


// 引数に渡されたじゃんけんの手が正しいかどうか(グー、チョキ、パーか？)をチェックする関数
BOOL isRightHand(HAND type)
{
	// 列挙型の定義を使ってじゃんけんの手が正しいか判定する
	// UNKNOWN < type < E_HAND_ENDであればグー、チョキ、パーのいずれかになる
	return (E_HAND_UNKNOWN < type && type < E_HAND_COUNT) ? TRUE : FALSE;
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
	breakLine();
}

// 改行するだけの処理
void breakLine() {
	printf("\n");
}