//-----------------------------------------------------------------------------
// 入力を受け取って処理を振り分けるシンプルなテクニック v2
// 配列や構造体、関数ポインタをうまくつかってメニュー表示や処理の振り分けをシンプル化
//-----------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// コンパイラにC6031の警告を無視するように伝えるプリプロセッサ
// scanfには戻り値があるが、特に戻り値を使っていないためC6031の警告がでる。
// 放置してもいいが、警告出てるのも気になるので今回は無視することにした。
#pragma warning (disable: 6031)

//-----------------------------------------------------------------------------
// 関数プロトタイプ宣言
void test1(void);
void test2(void);
void test3(void);

//-----------------------------------------------------------------------------
// タイトルとメインの処理を格納できるメニュー構造体を定義
struct Menu 
{
  // メニューのタイトル
  char* title;

  // メニューが選ばれた時に実行する関数のポインタ
  void (*func)(void);
};

//-----------------------------------------------------------------------------
// メニューリストと、メニューの個数を定義

struct Menu gMenus[] = {
  { "テスト1", test1 },
  { "テスト2", test2 },
  { "テスト3", test3 }
};

const int gMenuSize = sizeof(gMenus) / sizeof(struct Menu);

// エントリーポイント(プログラムの入り口)
int main(void)
{
  // 選択されたメニュー番号を保持するための変数
  int selectedMenuNo = 0;

  // ループフラグ、0にするとループを抜ける
  int isLoop = 1;

  while (isLoop)
  {
    printf("----------------------------------------------------------\n");
    printf("メニュー番号を入力しEnterを押してください。\n");
    for (int i = 0; i < gMenuSize; ++i) {
      printf("%d:%s\n", i, gMenus[i].title);
    }

    scanf("%d", &selectedMenuNo);

    // 余白を空けたいので改行
    printf("\n");

    // 選ばれたメニュー番号が配列の範囲外であれば終了
    if (selectedMenuNo < 0 || gMenuSize <= selectedMenuNo) break;

    // メニューの処理を実行
    gMenus[selectedMenuNo].func();

    // 余白を空けたいので改行
    printf("\n");
  }

  return 0;
}

void test1(void) {
  printf("Test1の処理です\n");
}

void test2(void) {
  printf("Test2の処理です\n");
}

void test3(void) {
  printf("Test3の処理です\n");
}