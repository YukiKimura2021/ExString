# ExString
std::string型をもっと扱いやすいように改良したクラス。もちろんstd::string型で使えた機能はすべて使えます。

改良点は以下に記述

- 文字列の作成で、printf関数のように可変長引数を扱えるようにした。
- 一時オブジェクトを使って、可変長引数の文字列を渡せるようにした。
- const char* 型への暗黙的な型変換を実装。
- ユーザ入力による文字列作成もできる（おまけ程度）。

## アップデート履歴

06/08/21 ExString ver1.2
 - std::string型で使えた機能(メンバ関数など)を扱えるよう、std::stringをpublic継承する形にExString型を改良。
 - 結合演算子(+)による処理がstd::string型で行えた範囲を超えていたため、一貫性重視により従来どおりの範囲に修正。
