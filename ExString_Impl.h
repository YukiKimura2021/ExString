#pragma once

#include"ExString.h"
#include<stdio.h>
#include<stdarg.h>
#include<sstream>

//#include<tchar.h>
//using tstring = std::basic_string<TCHAR>;
//using tchar   = TCHAR;

inline ExString::ExString()
	:_str()
{
	//“Á‚É‚È‚µ
}

inline ExString::ExString(const std::string& str)
	:_str(str)
{
	//“Á‚É‚È‚µ
}

inline ExString::ExString(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	char src[1024];
	vsprintf_s(src, format, args);
	va_end(args);
	_str = src;
}

inline ExString::ExString(const size_t size, const char* format, ...)
{
	va_list args;
	va_start(args, format);
	char* src = new char[size];
	vsprintf_s(src, size, format, args);
	va_end(args);
	_str = src;
	delete[] src;
}

template<typename T>
ExString::ExString(const T& src)
{
	std::stringstream ss;
	ss << src;
	_str = ss.str();
}

inline ExString& ExString::operator=(const std::string& str) { _str = str;  return *this; }
inline ExString& ExString::operator=(const char* cstr)       { _str = cstr; return *this; }

inline ExString::operator std::string()       { return _str; }
inline ExString::operator std::string() const { return _str; }
//inline ExString::operator const char*()       { return _str.c_str(); }
//inline ExString::operator const char*() const { return _str.c_str(); }

inline ExString            operator+(const ExString& a, const ExString& b) { return ExString(a._str + b._str); }
inline ExString& ExString::operator+=(const ExString& a)                   { _str += a._str; return *this; }

inline const char* ExString::c_str() const 
{ 
	return _str.c_str();
}

template<typename T>
inline ExString& operator<<(ExString& dst, const T& str)
{
	std::stringstream ss;
	ss << str;
	dst._str += ss.str();
	return dst;
}

inline std::ostream& operator<<(std::ostream& os, const ExString& str)
{
	return os << str._str;
}

inline std::istream& operator>>(std::istream& is, ExString& dst)
{
	return std::getline(is, dst._str);
}
