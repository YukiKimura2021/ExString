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

	//c言語形式
	ExBasicString(const T* const format, ...);
	ExBasicString(const size_t size, const T* const format, ...);

	//c++形式
	template<typename U>
	ExBasicString(const U& src);

	//--------------------------------------------------------------------------------------------------
	// 代入演算子
	//--------------------------------------------------------------------------------------------------

	ExBasicString& operator=(const ExBasicString&) = default;
	ExBasicString& operator=(const std::basic_string<T>& str);
	ExBasicString& operator=(const T* cstr);

	//--------------------------------------------------------------------------------------------------
	// 型変換演算子
	//--------------------------------------------------------------------------------------------------

	operator const T*();       //メンバ変数いじってOK ver
	operator const T*() const; //メンバ変数いじっちゃダメ ver

	//--------------------------------------------------------------------------------------------------
	// 連結演算子
	//--------------------------------------------------------------------------------------------------

	ExBasicString& operator+=(const ExBasicString& src);

	//--------------------------------------------------------------------------------------------------
	// アクセッサ
	//--------------------------------------------------------------------------------------------------

	//c言語形式
	friend int sprintf_s(ExBasicString& dst, const T* const format, ...);
	friend int sprintf_s(ExBasicString& dst, const size_t size, const T* const format, ...);

	// TODO : scanfの仕組みを勉強して実装したい

	//c++形式
	template<typename U>
	ExBasicString& operator<<(const U& src);
	ExBasicString& operator<<(const T* src);
};

using ExString	= ExBasicString<char>;
using ExWString = ExBasicString<wchar_t>;
using ExTString = ExBasicString<TCHAR>;

#include"impl/VsExPrinter_Impl.h"
#include"impl/ExString_Impl.h"
