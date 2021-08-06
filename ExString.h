#pragma once

#include<iostream>

class ExString : public std::string
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

	//--------------------------------------------------------------------------------------------------
	// ������Z�q
	//--------------------------------------------------------------------------------------------------

	ExString& operator=(const ExString&) = default;
	ExString& operator=(const std::string& str);
	ExString& operator=(const char* cstr);

	//--------------------------------------------------------------------------------------------------
	// �^�ϊ����Z�q
	//--------------------------------------------------------------------------------------------------

	operator const char*();       //�����o�ϐ���������OK ver
	operator const char*() const; //�����o�ϐ�����������_�� ver

	//--------------------------------------------------------------------------------------------------
	// �A�����Z�q
	//--------------------------------------------------------------------------------------------------

	ExString& operator+=(const ExString& src);

	//--------------------------------------------------------------------------------------------------
	// �A�N�Z�b�T
	//--------------------------------------------------------------------------------------------------

	//c����`��
	friend int sprintf_s(ExString& const dst, const char* const format, ...);
	friend int sprintf_s(ExString& const dst, const size_t size, const char* const format, ...);

	// TODO : scanf�̎d�g�݂�׋����Ď���������

	//c++�`��
	template<typename T>
	friend ExString&     operator<<(ExString& dst, const T& src);
	friend std::ostream& operator<<(std::ostream& os, const ExString& src);
	friend std::istream& operator>>(std::istream& is, ExString& dst);

private:

	static constexpr size_t _default_size = 256;
};

#include"ExString_Impl.h"
