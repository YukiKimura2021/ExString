
#include"ExString.h"

using namespace std;

int main()
{
	cout << "�����������ĕ\��" << endl;

	//NULL�I�[��������A�ϒ�������p���č쐬����B
	ExString str0("I am %d years old.", 20);
	cout << str0 << endl; //�\�����ĉ��s

	//�R�s�[�R���X�g���N�^
	const ExString str1 = str0;
	cout << str1 << endl;

	//string�`���̏�����
	const ExString str2 = str0 + " My name is Yamada.";
	cout << str2 << endl;

	//���l�ŏ�����
	const ExString str3 = 3.14;
	cout << str3 << endl;

	cout << endl;

	cout << "��������ĕ\��" << endl;
	{
		//�V��������������B
		str0 = ExString("He is %d years old.", 40);
		cout << str0 << endl;
	}
	cout << endl;

	cout << "���ꎞ�I�u�W�F�N�g���g���ĕ\��" << endl;
	{
		//�������Ȃ��Ă��A�ꎞ�I�u�W�F�N�g���g���ē������Ƃ��ł���B
		cout << ExString("He is %d years old.", 40) << endl;
	}
	cout << endl;

	cout << "���ÖٓI�Ȍ^�ϊ��ŕ\��" << endl;
	{
		//const char*�^�ւ̈ÖٓI�Ȍ^�ϊ����s�����ƂŁA���̂悤��printf�̎g�������ł���B
		printf("�~���� = "); printf(str3); printf("\n");
	}
	cout << endl;

	cout << "��������̑}��" << endl;
	{
		//�����������ۂɂ���
		str0.clear();

		//'str'������̂�����ɁA�E���̕ϐ���A�����Ă���(���Ȃ킿�}��)�B
		str0 << "He is " << 40 << " years old.";
		str0 << " His name is Takashi.";
		cout << str0 << endl;

		//�A�����Z�q��string�^�Ɠ��l�Ɉ�����.
		cout << "Hello! " + str0 << endl;
	}
	cout << endl;

	cout << "�����l�𕶎���Ƃ��Ĉ���" << endl;
	{
		str0.clear();
		for (int i = 0; i < 10; ++i)
		{
			//int, double�^�Ȃǂ̐��l��������Ƃ��đ���A�A���ł���B
			str0 += i % 2;
		}
		cout << str0 << endl;
	}
	cout << endl;

	cout << "�����[�U����" << endl;
	{
		//�����Ƃ̕�����ɏ㏑�����邱�Ƃɒ��ӁB
		cin >> str0;
		cout << "���́F" << str0 << endl;
	}
	cout << endl;
}
