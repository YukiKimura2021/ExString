# ExString ver2.0
std::string型をもっと扱いやすいように改良したクラス。もちろんstd::string型で使えた機能はすべて使えます。
 - ver2.0でstd::wstring型(ワイド文字, Unicode文字)にも対応しました。

改良点は以下に記述

- 文字列の作成で、printf関数のように可変長引数を扱えるようにしました。
- 一時オブジェクトを使って、可変長引数の文字列を渡せるようにしました。
- const char* 型、const wchar_t*型への暗黙的な型変換を実装。
- ユーザ入力による文字列作成もできる（おまけ程度）。
- ver2.0よりUnicode文字に一部対応。※ただし使い方が難しいので、注意事項を要確認

## 注意事項

13/08/21 ExString ver2.0
- ExWStringクラスとstd::wcoutなどとの併用で、ワイド文字(Unicode文字)出力に対応。  
最近のWindowsでは、<b>ワイド文字出力にUnicode文字が対応</b>しているみたいです。しかし、ロケールの関係上  
wprintf関数の動作が不安定化するなど、扱い方が少し難しくなっています。  
詳細は私が参考にしたサイト https://bit.ly/3AGO5Nt をどうぞ。  

- ExTStringクラスは、Unicodeマクロが定義されているかどうかで、ExString、ExWStringを切り替えます。  
また、ExTStringクラスを扱う際は、必ず_Tマクロを使用してください。  
例）ExTString str = _T("Hello World!");  

## アップデート履歴

13/08/21 ExString ver2.0
- Unicode文字に対応した【ExWString】クラスを追加。
- Unicode文字に対応しているかどうか、勝手に判断してくれる【ExTString】クラスを追加。

11/08/21 ExString ver1.3
- printf関数のような、可変長引数を取り入れる形式の文字列作成に関して、内部の実装をより安全に改良。

06/08/21 ExString ver1.2
- std::string型で使えた機能(メンバ関数など)を扱えるよう、std::stringをpublic継承する形にExString型を改良。
- 結合演算子(+)による処理がstd::string型で行えた範囲を超えていたため、一貫性重視により従来どおりの範囲に修正。
