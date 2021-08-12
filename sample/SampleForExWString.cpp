
#include"ExString.h"

using namespace std;

int main()
{
	// 標準出力にUnicode文字を表示させる方法のひとつ(Unicodeの標準出力は難しいからオススメしない)。
	// - Unicode表示可   : printf, std::cout, std::wcout
	// - Unicode表示不可 : wprintf
	// - 参考にしたサイト : https://bit.ly/3AGO5Nt
	std::wcout.imbue(std::locale("", std::locale::ctype));

	wcout << L"●初期化して表示" << endl;

	//NULL終端文字列を、可変長引数を用いて作成する。
	ExWString str0(L"I am %d years old.", 20);
	wcout << str0 << endl; //表示して改行

	//コピーコンストラクタ
	const ExWString str1 = str0;
	wcout << str1 << endl;

	//string形式の初期化
	const ExWString str2 = str0 + L" My name is Yamada.";
	wcout << str2 << endl;

	//数値で初期化
	const ExWString str3 = 3.14;
	wcout << str3 << endl;

	wcout << endl;

	wcout << L"●代入して表示" << endl;
	{
		//新しい文字列を代入。
		str0 = ExWString(L"He is %d years old.", 40);
		wcout << str0 << endl;
	}
	wcout << endl;

	wcout << L"●一時オブジェクトを使って表示" << endl;
	{
		//代入を介さなくても、一時オブジェクトを使って同じことができる。
		wcout << ExWString(L"He is %d years old.", 40) << endl;
	}
	wcout << endl;

	wcout << L"●暗黙的な型変換で表示" << endl;
	{
		//const wchar_t*型への暗黙的な型変換を行うことで、このようなwprintfの使い方ができる。

		wprintf(L"円周率 = "); //※最初のロケールの関係上表示されない

		wprintf(str3);		   //数値はUnicode文字じゃないので表示できる

		wprintf(L"\n");		   //※最初のロケールの関係上表示されない
	}
	wcout << endl;

	wcout << L"●文字列の挿入" << endl;
	{
		//文字列を空っぽにする
		str0.clear();

		//'str'文字列のうしろに、右側の変数を連結していく(すなわち挿入)。
		str0 << L"He is " << 40 << L" years old.";
		str0 << L" His name is Takashi.";
		wcout << str0 << endl;

		//連結演算子もstring型と同様に扱える.
		wcout << L"Hello! " + str0 << endl;
	}
	wcout << endl;

	wcout << L"●数値を文字列として扱う" << endl;
	{
		str0.clear();
		for (int i = 0; i < 10; ++i)
		{
			//int, double型などの数値も文字列として代入、連結できる。
			str0 += i % 2;
		}
		wcout << str0 << endl;
	}
	wcout << endl;

	wcout << L"●ユーザ入力" << endl;
	{
		//※もとの文字列に上書きすることに注意。
		wcin >> str0;
		wcout << L"入力：" << str0 << endl;
	}
	wcout << endl;
}
