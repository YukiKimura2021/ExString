
#include"ExString.h"

using namespace std;

int sprintf_s(ExString& const dst, const char* const format, ...)
{
	va_list args;
	va_start(args, format);
	int size = _vscprintf(format, args) + 1;
	int strLength = -1;
	if (char* src = new char[size])
	{
		strLength = vsprintf_s(src, size, format, args);
		if (strLength != -1) dst.assign(src);
		delete[] src;
	}
	va_end(args);
	return strLength;
}

int sprintf_s(ExString& const dst, const size_t size, const char* const format, ...)
{
	va_list args;
	va_start(args, format);
	int strLength = -1;
	if (char* src = new char[size])
	{
		strLength = vsprintf_s(src, size, format, args);
		if(strLength != -1) dst.assign(src);
		delete[] src;
	}
	va_end(args);
	return strLength;
}
