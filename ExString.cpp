
//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include"ExString.h"

using namespace std;

int sprintf_s(ExString& const dst, const char* const format, ...)
{
	va_list args;
	va_start(args, format);
	char src[1024];
	int rtn = vsprintf_s(src, format, args);
	va_end(args);
	dst._str = src;
	return rtn;
}

int sprintf_s(ExString& const dst, const size_t size, const char* const format, ...)
{
	va_list args;
	va_start(args, format);
	char* src = new char[size];
	int rtn = vsprintf_s(src, size, format, args);
	va_end(args);
	dst._str = src;
	delete[] src;
	return rtn;
}
