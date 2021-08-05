#pragma once

#include<iostream>

class ExString : public std::string
{
public:

	ExString();
	ExString(const std::string& str);
	ExString(const ExString&) = default;

	//c言語形式
	ExString(const char* format, ...);
	ExString(const size_t size, const char* format, ...);

	//c++形式
	template<typename T>
	ExString(const T& src);

	//--------------------------------------------------------------------------------------------------
	// 代入演算子
	//--------------------------------------------------------------------------------------------------

	ExString& operator=(const ExString&) = default;
	ExString& operator=(const std::string& str);
	ExString& operator=(const char* cstr);

	//--------------------------------------------------------------------------------------------------
	// 型変換演算子
	//--------------------------------------------------------------------------------------------------

	operator const char*();       //メンバ変数いじってOK ver
	operator const char*() const; //メンバ変数いじっちゃダメ ver

	//--------------------------------------------------------------------------------------------------
	// 連結演算子
	//--------------------------------------------------------------------------------------------------

	ExString& operator+=(const ExString& src);

	//--------------------------------------------------------------------------------------------------
	// アクセッサ
	//--------------------------------------------------------------------------------------------------

	//c言語形式
	friend int sprintf_s(ExString& const dst, const char* const format, ...);
	friend int sprintf_s(ExString& const dst, const size_t size, const char* const format, ...);

	// TODO : scanfの仕組みを勉強して実装したい

	//c++形式
	template<typename T>
	friend ExString&     operator<<(ExString& dst, const T& src);
	friend std::ostream& operator<<(std::ostream& os, const ExString& src);
	friend std::istream& operator>>(std::istream& is, ExString& dst);

private:

	static constexpr size_t _default_size = 256;
};

#include"ExString_Impl.h"
