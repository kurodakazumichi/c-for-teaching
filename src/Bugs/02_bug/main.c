//-----------------------------------------------------------------------------
// 大文字を小文字に、小文字を大文字に
//
// 'ABC'→'abc'のように小文字に変換するlowerStr関数
// 'abc'→'ABC'のように大文字に変換するupperStr関数
// 大文字、小文字の変換はうまくいっているようだが、想定しない文字が表示されてしまう。
// 原因を調査して、不具合を修正してほしい。
//
// lowerStr, upperStrの補足
// ・アルファベットのa-z,A-Z以外は変換されずそのままでよい。
//
// ※解答はソースコードの下の方に記載しています。
//-----------------------------------------------------------------------------
#include <stdio.h>

// 関数プロトタイプ宣言
void lowerStr(char* src, char* dst);
void upperStr(char* src, char* dst);
char lower(char c);
char upper(char c);

// エントリーポイント
int main(void)
{
	char buf[1000];

	// 大文字→小文字
	lowerStr("Hello World!", buf);
	printf("%s\n", buf);
	lowerStr("Good morning World!", buf);
	printf("%s\n", buf);

	// 小文字→大文字
	upperStr("Hello World!", buf);
	printf("%s\n", buf);
	upperStr("Good morning World!", buf);
	printf("%s\n", buf);
}

// '0'~'9'の1文字を数値の1~9に変換する(char to int)
int ctoi(char c)
{
	// '0'~'9'以外の文字だったら-1を返す
	if (c <= 0x30 || 0x39 < c) return -1;

	// 文字を数値に変換
	return c - 0x30;
}

// srcに含まれる大文字を小文字に変換して、結果をdstに書き込む
void lowerStr(char* src, char* dst) 
{
	for (int i = 0; src[i] != '\0'; ++i) {
		dst[i] = lower(src[i]);
	}
}

// srcに含まれる小文字を大文字に変換して、結果をdstに書き込む
void upperStr(char* src, char* dst) 
{
	for (int i = 0; src[i] != '\0'; ++i) {
		dst[i] = upper(src[i]);
	}
}

// 大文字なら小文字に
char lower(char c) 
{
	if (0x41 <= c && c <= 0x5a) return c + 0x20;
	return c;
}

// 小文字なら大文字に
char upper(char c) {
	if (0x61 <= c && c <= 0x7a) return c - 0x20;
	return c;
}






















//-----------------------------------------------------------------------------
// 解答
#if 0

// バグの原因は変換後の文字列配列の末尾にヌル文字が設定されていない事です。
// 文字列配列の最後にはヌル文字(終端文字)がなければいけません。
// lowerStrを例にしてみてみると
// srcを元に変換したdstの中身は以下のようになっている
//
// src = Hello World!\0
// dst = hello world!
//
// 大文字→小文字の変換はできているが、終端文字がなくなってしまっている。
// これを修正した関数は以下のようになります。
// (最終的に終端文字を正しく設定できれば処理の書き方はこの通りでなくてもよい)

// srcに含まれる大文字を小文字に変換して、結果をdstに書き込む
void lowerStr(char* src, char* dst)
{
	int i = 0;
	for (; src[i] != '\0'; ++i) {
		dst[i] = lower(src[i]);
	}
	dst[i] = '\0';
}

// srcに含まれる小文字を大文字に変換して、結果をdstに書き込む
void upperStr(char* src, char* dst)
{
	int i = 0;
	for (; src[i] != '\0'; ++i) {
		dst[i] = upper(src[i]);
	}
	dst[i] = '\0';
}

#endif







