#pragma once

#include"../ExString.h"

template<typename T>
class VsExPrinter
{
	//このクラスにだけ下２つの関数の使用を許可
	friend ExBasicString<T>;
	friend int sprintf_s(ExBasicString<T>& dst, const size_t size, const T* const format, ...);
	friend int sprintf_s(ExBasicString<T>& dst, const size_t size, const T* const format, ...);

	static int vsexprintf_s(T* dst, const size_t size, const T* const format, va_list args);
	static int vscexprintf_s(const T* format, va_list args);
};

template<>
class VsExPrinter<char>
{
	friend ExString;
	template<typename T> friend int sprintf_s(ExBasicString<T>& dst, const T* const format, ...);
	template<typename T> friend int sprintf_s(ExBasicString<T>& dst, const size_t size, const T* const format, ...);

	static int vsexprintf_s(char* dst, const size_t size, const char* const format, va_list args);
	static int vscexprintf_s(const char* format, va_list args);
};

template<>
class VsExPrinter<wchar_t>
{
	friend ExWString;
	template<typename T> friend int sprintf_s(ExBasicString<T>& dst, const T* const format, ...);
	template<typename T> friend int sprintf_s(ExBasicString<T>& dst, const size_t size, const T* const format, ...);

	static int vsexprintf_s(wchar_t* dst, const size_t size, const wchar_t* const format, va_list args);
	static int vscexprintf_s(const wchar_t* format, va_list args);
};

template<typename T>
inline int VsExPrinter<T>::vsexprintf_s(T* dst, const size_t size, const T* const format, va_list args)
{ 
	return -1;
}
template<typename T>
inline int VsExPrinter<T>::vscexprintf_s(const T* format, va_list args)
{ 
	return -1;
}

inline int VsExPrinter<char>::vsexprintf_s(char* dst, const size_t size, const char* const format, va_list args) 
{ 
	return vsprintf_s(dst, size, format, args);
}
inline int VsExPrinter<char>::vscexprintf_s(const char* format, va_list args)
{
	return _vscprintf(format, args);
}

inline int VsExPrinter<wchar_t>::vsexprintf_s(wchar_t* dst, const size_t size, const wchar_t* const format, va_list args)
{
	return vswprintf_s(dst, size, format, args);
}
inline int VsExPrinter<wchar_t>::vscexprintf_s(const wchar_t* format, va_list args)
{
	return _vscwprintf(format, args);
}
