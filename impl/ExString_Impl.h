#pragma once

#include"../ExString.h"
#include<stdarg.h>
#include<sstream>

//--------------------------------------------------------------------------------------------------
// コンストラクタ
//--------------------------------------------------------------------------------------------------

template<typename T>
inline ExBasicString<T>::ExBasicString()
	:std::basic_string<T>()
{
	//特になし
}

template<typename T>
inline ExBasicString<T>::ExBasicString(const std::basic_string<T>& str)
	:std::basic_string<T>(str)
{
	//特になし
}

template<typename T>
inline ExBasicString<T>::ExBasicString(const T* const format, ...)
{
	va_list args;
	va_start(args, format);
	int size = VsExPrinter<T>::vscexprintf_s(format, args) + 1;
	if (T* src = new T[size])
	{
		int strLength = VsExPrinter<T>::vsexprintf_s(src, size, format, args);
		if (strLength != -1) this->assign(src);
		delete[] src;
	}
	va_end(args);
}

template<typename T>
inline ExBasicString<T>::ExBasicString(const size_t size, const T* const format, ...)
{
	va_list args;
	va_start(args, format);
	if (T* src = new T[size])
	{
		int strLength = VsExPrinter<T>::vsexprintf_s(src, size, format, args);
		if (strLength != -1) this->assign(src);
		delete[] src;
	}
	va_end(args);
}

template<typename T>
template<typename U>
inline ExBasicString<T>::ExBasicString(const U& src)
{
	std::basic_stringstream<T> ss;
	ss << src;
	this->assign(ss.str());
}

//--------------------------------------------------------------------------------------------------
// 代入演算子
//--------------------------------------------------------------------------------------------------

template<typename T>
inline ExBasicString<T>& ExBasicString<T>::operator=(const std::basic_string<T>& str) { this->assign(str);  return *this; }
template<typename T>
inline ExBasicString<T>& ExBasicString<T>::operator=(const T* cstr)					  { this->assign(cstr); return *this; }

//--------------------------------------------------------------------------------------------------
// 型変換演算子
//--------------------------------------------------------------------------------------------------

template<typename T>
inline ExBasicString<T>::operator const T*()       { return this->c_str(); }
template<typename T>
inline ExBasicString<T>::operator const T*() const { return this->c_str(); }

//--------------------------------------------------------------------------------------------------
// 連結演算子
//--------------------------------------------------------------------------------------------------

template<typename T>
inline ExBasicString<T>& ExBasicString<T>::operator+=(const ExBasicString<T>& src)
{ 
	this->append(static_cast<std::basic_string<T>>(src));
	return *this;
}

//--------------------------------------------------------------------------------------------------
// アクセッサ
//--------------------------------------------------------------------------------------------------

template<typename T>
template<typename U>
inline ExBasicString<T>& ExBasicString<T>::operator<<(const U& src)
{
	std::basic_stringstream<T> ss;
	ss << src;
	return *this += ss.str();
}

template<typename T>
inline ExBasicString<T>& ExBasicString<T>::operator<<(const T* src)
{
	std::basic_stringstream<T> ss;
	ss << src;
	return *this += ss.str();
}

template<typename T>
int sprintf_s(ExBasicString<T>& dst, const T* const format, ...)
{
	va_list args;
	va_start(args, format);
	int size = VsExPrinter<T>::vscexprintf_s(format, args) + 1;
	int strLength = -1;
	if (T* src = new T[size])
	{
		strLength = VsExPrinter<T>::vsexprintf_s(src, size, format, args);
		if (strLength != -1) dst.assign(src);
		delete[] src;
	}
	va_end(args);
	return strLength;
}

template<typename T>
int sprintf_s(ExBasicString<T>& dst, const size_t size, const T* const format, ...)
{
	va_list args;
	int strLength = -1;
	if (T* src = new T[size])
	{
		strLength = VsExPrinter<T>::vsexprintf_s(src, size, format, args);
		if (strLength != -1) dst.assign(src);
		delete[] src;
	}
	va_end(args);
	return strLength;
}
