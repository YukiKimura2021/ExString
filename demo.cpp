
#include"ExString.h"

using namespace std;

int main()
{
	cout << "●初期化" << endl;

	//NULL終端文字列を、可変長引数を用いて作成する。
	ExString str("I am %d years old.", 20);

	//コピーコンストラクタ
	ExString str1 = str;

	//string形式の初期化
	ExString str2 = str + " My name is Yamada.";

	//数値で初期化
	ExString str3 = 3.14;

	//文字列を表示して改行。
	printf(str);
	printf("\n");
	//この書き方でも同じ。
	cout << str << endl;

	cout << endl;

	cout << "●代入" << endl;
	{
		//新しい文字列を代入して表示する。
		str = ExString("%s My name is Yamada.", str.c_str());
		cout << str << endl;
	}
	cout << endl;

	cout << "●一時オブジェクト" << endl;
	{
		//一時オブジェクトを使っても同じことができる。
		cout << ExString("He is %d years old.", 40) << endl;
	}
	cout << endl;

	cout << "●文字列の挿入" << endl;
	{
		str.clear();
		//'str'文字列のうしろに、右側の変数を連結していく(すなわち挿入)。
		str << "He is " << 40 << " years old.";
		str << " His name is Takashi.";
		cout << str << endl;

		//連結演算子もstring型と同様使える.
		cout << "Hello! " + str << endl;
	}
	cout << endl;

	cout << "●数値を文字列として扱う" << endl;
	{
		str.clear();
		for (int i = 0; i < 10; ++i)
		{
			//int, double型などの数値も文字列として代入、連結できる。
			str += i % 2;
		}
		cout << str << endl;
	}
	cout << endl;

	cout << "●ユーザ入力" << endl;
	{
		cin >> str;
		cout << "入力：" << str << endl;
	}
	cout << endl;
}
