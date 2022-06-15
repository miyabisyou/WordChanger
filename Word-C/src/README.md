#ツール名

WordChanger.exe

#概要

入力した文字列を無作為なひらがなの羅列に変換するツールです

#機能

ー複数の文字列の変換に対応
ー変換する文字列長の変更
ーパラメータ含む登録した文字列の保存・読み込み・削除

#実行環境

ーコンパイラ
	g++ (GCC) 9.3.0
	Copyright (C) 2019 Free Software Foundation, Inc.
ーコンソール
	Cygwin 3.1.7

#インストール

$ git clone https://github.com/miyabisyou/WordChanger.git
$ cd Word-C/src/
$ make
$ ./WordChanger.exe
word_chengerでは言葉を無作為なひらがなの羅列に変換します

MODEを選択してください
言葉の追加        -> 0
言葉の削除        -> 1
変換              -> 2
プリセットの使用  -> 3
読み込み          -> 4
保存              -> 5
セーブデータの削除-> 6
一括削除          -> 7
パラメータ変更    -> 8
exit(終了)        -> 0~8以外の数字
=====================================
数字を入力してください : 10
