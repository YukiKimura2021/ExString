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

	//c言語形式
	ExString(const char* format, ...);
	ExString(const size_t size, const char* format, ...);

	//c++形式
	template<typename T>
	ExString(const T& src);

	//----------------------------------------------------------------
	// 代入演算子
	//----------------------------------------------------------------

	ExString& operator=(const ExString&) = default;
	ExString& operator=(const std::string& str);
	ExString& operator=(const char* cstr);

	//----------------------------------------------------------------
	// 変換演算子
	//----------------------------------------------------------------

	operator std::string();
	operator std::string() const;

	// HACK : string型への暗黙的な代入を可能にするため、とりあえず使えないようにした
	//operator const char*();
	//operator const char*() const;

	//----------------------------------------------------------------
	// 連結演算子
	//----------------------------------------------------------------

	friend ExString operator+(const ExString& a, const ExString& b);
	ExString&       operator+=(const ExString& a);

	//----------------------------------------------------------------
	// アクセッサ
	//----------------------------------------------------------------

	const char* c_str() const;

	//c言語形式
	friend int sprintf_s(ExString& const dst, const char* const format, ...);
	friend int sprintf_s(ExString& const dst, const size_t size, const char* const format, ...);

	// TODO : scanfの仕組みを勉強して実装したい

	//c++形式
	template<typename T>
	friend ExString&     operator<<(ExString& dst, const T& src);
	friend std::ostream& operator<<(std::ostream& os, const ExString& str);
	friend std::istream& operator>>(std::istream& is, ExString& dst);

private:

	std::string _str;
};

#include"ExString_Impl.h"
