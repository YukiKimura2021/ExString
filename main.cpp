
//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include"ExString.h"

using namespace std;

int main()
{
	//sprintf�֐��݂����ɕ����������
	ExString str("���̔N���%d�ł��B\n", 20);

	//printf�`��, cout�`���ǂ���ł��Ή���
	printf(str);
	cout << str;
}
