
//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include"ExString.h"
#include<stdarg.h>

using namespace std;

ExString::ExString()
	:_str()
{
	//“Á‚É‚È‚µ
}

ExString::ExString(const std::string& str)
	:_str(str)
{
	//“Á‚É‚È‚µ
}

ExString::ExString(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	char str[1024];
	vsprintf_s(str, format, args);
	va_end(args);

	_str = str;
}

void ExString::SetCStr(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	char str[1024];
	vsprintf_s(str, format, args);
	va_end(args);

	_str = str;
}
