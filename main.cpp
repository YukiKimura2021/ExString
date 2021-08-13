
#include"ExString.h"

using namespace std;

int main()
{
	cout << "●初期化して表示" << endl;

	//NULL終端文字列を、可変長引数を用いて作成する。
	ExString str0("I am %d years old.", 20);
	cout << str0 << endl; //表示して改行

	//コピーコンストラクタ
	const ExString str1 = str0;
	cout << str1 << endl;

	//string形式の初期化
	const ExString str2 = str0 + " My name is Yamada.";
	cout << str2 << endl;

	//数値で初期化
	const ExString str3 = 3.14;
	cout << str3 << endl;

	cout << endl;

	cout << "●代入して表示" << endl;
	{
		//新しい文字列を代入。
		str0 = ExString("He is %d years old.", 40);
		cout << str0 << endl;
	}
	cout << endl;

	cout << "●一時オブジェクトを使って表示" << endl;
	{
		//代入を介さなくても、一時オブジェクトを使って同じことができる。
		cout << ExString("He is %d years old.", 40) << endl;
	}
	cout << endl;

	cout << "●暗黙的な型変換で表示" << endl;
	{
		//const char*型への暗黙的な型変換を行うことで、このようなprintfの使い方ができる。
		printf("円周率 = "); printf(str3); printf("\n");
	}
	cout << endl;

	cout << "●文字列の挿入" << endl;
	{
		//文字列を空っぽにする
		str0.clear();

		//'str'文字列のうしろに、右側の変数を連結していく(すなわち挿入)。
		str0 << "He is " << 40 << " years old.";
		str0 << " His name is Takashi.";
		cout << str0 << endl;

		//連結演算子もstring型と同様に扱える.
		cout << "Hello! " + str0 << endl;
	}
	cout << endl;

	cout << "●数値を文字列として扱う" << endl;
	{
		str0.clear();
		for (int i = 0; i < 10; ++i)
		{
			//int, double型などの数値も文字列として代入、連結できる。
			str0 += i % 2;
		}
		cout << str0 << endl;
	}
	cout << endl;

	cout << "●ユーザ入力" << endl;
	{
		//※もとの文字列に上書きすることに注意。
		cin >> str0;
		cout << "入力：" << str0 << endl;
	}
	cout << endl;
}
