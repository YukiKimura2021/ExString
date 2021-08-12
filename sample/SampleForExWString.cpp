
#include"ExString.h"

using namespace std;

int main()
{
	// �W���o�͂�Unicode������\����������@�̂ЂƂ�(Unicode�̕W���o�͓͂������I�X�X�����Ȃ�)�B
	// - Unicode�\����   : printf, std::cout, std::wcout
	// - Unicode�\���s�� : wprintf
	// - �Q�l�ɂ����T�C�g : https://bit.ly/3AGO5Nt
	std::wcout.imbue(std::locale("", std::locale::ctype));

	wcout << L"�����������ĕ\��" << endl;

	//NULL�I�[��������A�ϒ�������p���č쐬����B
	ExWString str0(L"I am %d years old.", 20);
	wcout << str0 << endl; //�\�����ĉ��s

	//�R�s�[�R���X�g���N�^
	const ExWString str1 = str0;
	wcout << str1 << endl;

	//string�`���̏�����
	const ExWString str2 = str0 + L" My name is Yamada.";
	wcout << str2 << endl;

	//���l�ŏ�����
	const ExWString str3 = 3.14;
	wcout << str3 << endl;

	wcout << endl;

	wcout << L"��������ĕ\��" << endl;
	{
		//�V��������������B
		str0 = ExWString(L"He is %d years old.", 40);
		wcout << str0 << endl;
	}
	wcout << endl;

	wcout << L"���ꎞ�I�u�W�F�N�g���g���ĕ\��" << endl;
	{
		//�������Ȃ��Ă��A�ꎞ�I�u�W�F�N�g���g���ē������Ƃ��ł���B
		wcout << ExWString(L"He is %d years old.", 40) << endl;
	}
	wcout << endl;

	wcout << L"���ÖٓI�Ȍ^�ϊ��ŕ\��" << endl;
	{
		//const wchar_t*�^�ւ̈ÖٓI�Ȍ^�ϊ����s�����ƂŁA���̂悤��wprintf�̎g�������ł���B

		wprintf(L"�~���� = "); //���ŏ��̃��P�[���̊֌W��\������Ȃ�

		wprintf(str3);		   //���l��Unicode��������Ȃ��̂ŕ\���ł���

		wprintf(L"\n");		   //���ŏ��̃��P�[���̊֌W��\������Ȃ�
	}
	wcout << endl;

	wcout << L"��������̑}��" << endl;
	{
		//�����������ۂɂ���
		str0.clear();

		//'str'������̂�����ɁA�E���̕ϐ���A�����Ă���(���Ȃ킿�}��)�B
		str0 << L"He is " << 40 << L" years old.";
		str0 << L" His name is Takashi.";
		wcout << str0 << endl;

		//�A�����Z�q��string�^�Ɠ��l�Ɉ�����.
		wcout << L"Hello! " + str0 << endl;
	}
	wcout << endl;

	wcout << L"�����l�𕶎���Ƃ��Ĉ���" << endl;
	{
		str0.clear();
		for (int i = 0; i < 10; ++i)
		{
			//int, double�^�Ȃǂ̐��l��������Ƃ��đ���A�A���ł���B
			str0 += i % 2;
		}
		wcout << str0 << endl;
	}
	wcout << endl;

	wcout << L"�����[�U����" << endl;
	{
		//�����Ƃ̕�����ɏ㏑�����邱�Ƃɒ��ӁB
		wcin >> str0;
		wcout << L"���́F" << str0 << endl;
	}
	wcout << endl;
}
