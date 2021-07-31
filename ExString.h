#pragma once

//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include<iostream>

class ExString
{
public:

	ExString();
	ExString(const std::string& str);
	ExString(const ExString&) = default;

	//c����`��
	ExString(const char* format, ...);
	ExString(const size_t size, const char* format, ...);

	//c++�`��
	template<typename T>
	ExString(const T& src);

	//----------------------------------------------------------------
	// ������Z�q
	//----------------------------------------------------------------

	ExString& operator=(const ExString&) = default;
	ExString& operator=(const std::string& str);
	ExString& operator=(const char* cstr);

	//----------------------------------------------------------------
	// �ϊ����Z�q
	//----------------------------------------------------------------

	operator std::string();
	operator std::string() const;

	// HACK : string�^�ւ̈ÖٓI�ȑ�����\�ɂ��邽�߁A�Ƃ肠�����g���Ȃ��悤�ɂ���
	//operator const char*();
	//operator const char*() const;

	//----------------------------------------------------------------
	// �A�����Z�q
	//----------------------------------------------------------------

	friend ExString operator+(const ExString& a, const ExString& b);
	ExString&       operator+=(const ExString& a);

	//----------------------------------------------------------------
	// �A�N�Z�b�T
	//----------------------------------------------------------------

	const char* c_str() const;

	//c����`��
	friend int sprintf_s(ExString& const dst, const char* const format, ...);
	friend int sprintf_s(ExString& const dst, const size_t size, const char* const format, ...);

	// TODO : scanf�̎d�g�݂�׋����Ď���������

	//c++�`��
	template<typename T>
	friend ExString&     operator<<(ExString& dst, const T& src);
	friend std::ostream& operator<<(std::ostream& os, const ExString& str);
	friend std::istream& operator>>(std::istream& is, ExString& dst);

private:

	std::string _str;
};

#include"ExString_Impl.h"
