
#include"ExString.h"

using namespace std;

int sprintf_s(ExString& const dst, const char* const format, ...)
{
	va_list args;
	va_start(args, format);
	char src[ExString::_default_size];
	int rtn = vsprintf_s(src, format, args);
	va_end(args);
	dst.assign(src);
	return rtn;
}

int sprintf_s(ExString& const dst, const size_t size, const char* const format, ...)
{
	va_list args;
	va_start(args, format);
	char* src = new char[size];
	int rtn = vsprintf_s(src, size, format, args);
	va_end(args);
	dst.assign(src);
	delete[] src;
	return rtn;
}
