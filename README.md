# c-for-teaching
C言語の教材的な何か



## 内容物

```
root
┣ docs ... C言語に関する資料
┣ src
┃ ┣ Samples ... c言語のサンプルコード
┃ ┗ Challenges ... デバッグチャレンジ
┗ README.md ...このファイル
```



### src/Samples

簡単な関数の実装や、書籍や問題集だけでは身に付きにくいノウハウが学べそうなサンプルプロジェクト集が格納されています。



#### 01_sample

入力された内容によって、実行する処理を振り分けるプログラムで、簡単なコマンドラインツールの実装の基礎にもなります。

- v1：switch文を使ったシンプルな実装例
- v2：構造体、配列、関数ポインタを用いた実装例
- v3：処理を複数のファイルに分けた実装例



#### 02_sample

コンソールで動く簡素なじゃんけんゲームのプログラムです。

まずは基礎的な文法だけを使って実装し、段階的にC言語の様々なテクニックを組み込み発展させていきます。

- v1：条件文、繰り返し文、関数など基本の構文だけで作る実装例
- v2：**enum**を使う
- v3：**構造体**を使い、**ゲームフロー**と**ゲームの状態**を分離

- v4：共通処理を別のファイルに分離
- v5：**ゲーム状態**を別のファイルに分離、オブジェクト指向
- v6：**ゲームフロー**を別のファイルに分離



### src/Challenges

このフォルダにはあえてバグのあるコード集が格納されています。

プログラムを解読し、バグの原因を解明し、正しい挙動に修正するというデバッグはプログラムの実力を伸ばすうえでとても効率のいい方法です。

そういった力を伸ばすための、デバッグチャレンジプロジェクト集が格納されています。

