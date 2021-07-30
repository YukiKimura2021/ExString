
//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include"ExString.h"

using namespace std;

int main()
{
	//sprintf関数みたいに文字列を作れる
	ExString str("私の年齢は%dです。\n", 20);

	//printf形式, cout形式どちらでも対応化
	printf(str);
	cout << str;
}
