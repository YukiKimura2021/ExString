#pragma once

#include<iostream>
#include<stdio.h>
#include<tchar.h>

template<typename T = char>
class ExBasicString : public std::basic_string<T>
{
public:

	ExBasicString();
	ExBasicString(const std::basic_string<T>& str);
	ExBasicString(const ExBasicString&) = default;

	//c����`��
	ExBasicString(const T* const format, ...);
	ExBasicString(const size_t size, const T* const format, ...);

	//c++�`��
	template<typename U>
	ExBasicString(const U& src);

	//--------------------------------------------------------------------------------------------------
	// ������Z�q
	//--------------------------------------------------------------------------------------------------

	ExBasicString& operator=(const ExBasicString&) = default;
	ExBasicString& operator=(const std::basic_string<T>& str);
	ExBasicString& operator=(const T* cstr);

	//--------------------------------------------------------------------------------------------------
	// �^�ϊ����Z�q
	//--------------------------------------------------------------------------------------------------

	operator const T*();       //�����o�ϐ���������OK ver
	operator const T*() const; //�����o�ϐ�����������_�� ver

	//--------------------------------------------------------------------------------------------------
	// �A�����Z�q
	//--------------------------------------------------------------------------------------------------

	ExBasicString& operator+=(const ExBasicString& src);

	//--------------------------------------------------------------------------------------------------
	// �A�N�Z�b�T
	//--------------------------------------------------------------------------------------------------

	//c����`��
	friend int sprintf_s(ExBasicString& dst, const T* const format, ...);
	friend int sprintf_s(ExBasicString& dst, const size_t size, const T* const format, ...);

	// TODO : scanf�̎d�g�݂�׋����Ď���������

	//c++�`��
	template<typename U>
	ExBasicString& operator<<(const U& src);
	ExBasicString& operator<<(const T* src);
};

using ExString	= ExBasicString<char>;
using ExWString = ExBasicString<wchar_t>;
using ExTString = ExBasicString<TCHAR>;

#include"impl/VsExPrinter_Impl.h"
#include"impl/ExString_Impl.h"
