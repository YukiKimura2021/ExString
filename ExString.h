#pragma once

//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include<iostream>
#include<sstream>

// stringŒ^, const char*Œ^‚Ö‚ÌŒ^•ÏŠ·‚ª‰Â”\‚È‰Â•Ï’·ˆø”‚ðˆµ‚¦‚é•¶Žš—ñƒNƒ‰ƒX
class ExString
{
public:

	ExString();
	ExString(const std::string& str);
	ExString(const char* format, ...);
	ExString(const ExString&) = default;

	//----------------------------------------------------------------
	// ‘ã“ü‰‰ŽZŽq
	//----------------------------------------------------------------

	const ExString& operator=(const ExString& ex);
	const ExString& operator=(const std::string& str);
	const ExString& operator=(const char* cstr);

	//----------------------------------------------------------------
	// •ÏŠ·‰‰ŽZŽq
	//----------------------------------------------------------------

	// FIXME : ‚È‚º‚©ExStringŒ^‚©‚çstringŒ^‚Ö‚Ì–¾Ž¦“I‚ÈŒ^•ÏŠ·‚ª‚Å‚«‚È‚¢
	// FIXME : ExStringŒ^‚©‚çstringŒ^‚Ö‚Ì‘ã“ü‚ª‚ ‚¢‚Ü‚¢‚È‚¹‚¢‚Ås‚¦‚È‚¢
	operator std::string();
	operator std::string() const;
	operator const char*();
	operator const char*() const;

	//----------------------------------------------------------------
	// ‘}“ü‰‰ŽZŽq
	//----------------------------------------------------------------

	friend std::istream& operator>>(std::istream& is, ExString& ex);

	//----------------------------------------------------------------
	// ˜AŒ‹‰‰ŽZŽq
	//----------------------------------------------------------------

	friend ExString operator+(const ExString& a, const ExString& b);
	const ExString& operator+=(const ExString& a);

	//----------------------------------------------------------------
	// ƒAƒNƒZƒbƒT
	//----------------------------------------------------------------

	std::string GetStr() const;
	const char* GetCStr() const;

	void SetStr(const std::string& str);
	void SetCStr(const char* format, ...);

	bool Debug() const;

private:

	std::string _str;
};

inline const ExString& ExString::operator=(const ExString& ex)
{
	_str = ex._str;
	return *this;
}

inline const ExString& ExString::operator=(const std::string& str)
{
	_str = str;
	return *this;
}

inline const ExString& ExString::operator=(const char* cstr)
{
	_str = cstr;
	return *this;
}

inline ExString::operator std::string()		  { return _str; }
inline ExString::operator std::string() const { return _str; }
inline ExString::operator const char*()		  { return _str.c_str(); }
inline ExString::operator const char*() const { return _str.c_str(); }

inline std::string ExString::GetStr() const  { return _str; }
inline const char* ExString::GetCStr() const { return _str.c_str(); }

inline void ExString::SetStr(const std::string& str) { _str = str; }

inline std::istream& operator>>(std::istream& is, ExString& ex) { return std::getline(is, ex._str); }

inline ExString operator+(const ExString& a, const ExString& b) { return ExString(a._str + b._str); }
inline const ExString& ExString::operator+=(const ExString& a)
{
	_str += a._str;
	return *this;
}
