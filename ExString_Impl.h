#pragma once

#include"ExString.h"
#include<stdio.h>
#include<stdarg.h>
#include<sstream>

//--------------------------------------------------------------------------------------------------
// �R���X�g���N�^
//--------------------------------------------------------------------------------------------------

inline ExString::ExString()
	:std::string()
{
	//���ɂȂ�
}

inline ExString::ExString(const std::string& str)
	:std::string(str)
{
	//���ɂȂ�
}

inline ExString::ExString(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	int size = _vscprintf(format, args) + 1;
	if (char* src = new char[size])
	{
		int strLength = vsprintf_s(src, size, format, args);
		if (strLength != -1) assign(src);
		delete[] src;
	}
	va_end(args);
}

inline ExString::ExString(const size_t size, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	if (char* src = new char[size])
	{
		int strLength = vsprintf_s(src, size, format, args);
		if (strLength != -1) assign(src);
		delete[] src;
	}
	va_end(args);
}

template<typename T>
ExString::ExString(const T& src)
{
	std::stringstream ss;
	ss << src;
	assign(ss.str());
}

//--------------------------------------------------------------------------------------------------
// ������Z�q
//--------------------------------------------------------------------------------------------------

inline ExString& ExString::operator=(const std::string& str) { assign(str);  return *this; }
inline ExString& ExString::operator=(const char* cstr)       { assign(cstr); return *this; }

//--------------------------------------------------------------------------------------------------
// �^�ϊ����Z�q
//--------------------------------------------------------------------------------------------------

inline ExString::operator const char*()       { return c_str(); }
inline ExString::operator const char*() const { return c_str(); }

//--------------------------------------------------------------------------------------------------
// �A�����Z�q
//--------------------------------------------------------------------------------------------------

inline ExString& ExString::operator+=(const ExString& src) { append(static_cast<std::string>(src)); return *this; }

//--------------------------------------------------------------------------------------------------
// �A�N�Z�b�T
//--------------------------------------------------------------------------------------------------

inline std::ostream& operator<<(std::ostream& os, const ExString& src) { return os << static_cast<std::string>(src); }
inline std::istream& operator>>(std::istream& is, ExString& dst)	   { return std::getline(is, dst); }

template<typename T>
inline ExString& operator<<(ExString& dst, const T& src)
{
	std::stringstream ss;
	ss << src;
	dst += ss.str();
	return dst;
}
