
#include"ExString.h"

using namespace std;

int main()
{
	cout << "��������" << endl;

	//NULL�I�[��������A�ϒ�������p���č쐬����B
	ExString str("I am %d years old.", 20);

	//�R�s�[�R���X�g���N�^
	ExString str1 = str;

	//string�`���̏�����
	ExString str2 = str + " My name is Yamada.";

	//���l�ŏ�����
	ExString str3 = 3.14;

	//�������\�����ĉ��s�B
	printf(str);
	printf("\n");
	//���̏������ł������B
	cout << str << endl;

	cout << endl;

	cout << "�����" << endl;
	{
		//�V����������������ĕ\������B
		str = ExString("%s My name is Yamada.", str.c_str());
		cout << str << endl;
	}
	cout << endl;

	cout << "���ꎞ�I�u�W�F�N�g" << endl;
	{
		//�ꎞ�I�u�W�F�N�g���g���Ă��������Ƃ��ł���B
		cout << ExString("He is %d years old.", 40) << endl;
	}
	cout << endl;

	cout << "��������̑}��" << endl;
	{
		str.clear();
		//'str'������̂�����ɁA�E���̕ϐ���A�����Ă���(���Ȃ킿�}��)�B
		str << "He is " << 40 << " years old.";
		str << " His name is Takashi.";
		cout << str << endl;

		//�A�����Z�q��string�^�Ɠ��l�g����.
		cout << "Hello! " + str << endl;
	}
	cout << endl;

	cout << "�����l�𕶎���Ƃ��Ĉ���" << endl;
	{
		str.clear();
		for (int i = 0; i < 10; ++i)
		{
			//int, double�^�Ȃǂ̐��l��������Ƃ��đ���A�A���ł���B
			str += i % 2;
		}
		cout << str << endl;
	}
	cout << endl;

	cout << "�����[�U����" << endl;
	{
		cin >> str;
		cout << "���́F" << str << endl;
	}
	cout << endl;
}
