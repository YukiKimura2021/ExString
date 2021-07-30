#pragma once

//------------------------------------------------------------
// develop ver
//------------------------------------------------------------

#include<iostream>
#include<sstream>

// string�^, const char*�^�ւ̌^�ϊ����\�ȉϒ������������镶����N���X
class ExString
{
public:

	ExString();
	ExString(const std::string& str);
	ExString(const char* format, ...);
	ExString(const ExString&) = default;

	//----------------------------------------------------------------
	// ������Z�q
	//----------------------------------------------------------------

	const ExString& operator=(const ExString& ex);
	const ExString& operator=(const std::string& str);
	const ExString& operator=(const char* cstr);

	//----------------------------------------------------------------
	// �ϊ����Z�q
	//----------------------------------------------------------------

	// FIXME : �Ȃ���ExString�^����string�^�ւ̖����I�Ȍ^�ϊ����ł��Ȃ�
	// FIXME : ExString�^����string�^�ւ̑���������܂��Ȃ����ōs���Ȃ�
	operator std::string();
	operator std::string() const;
	operator const char*();
	operator const char*() const;

	//----------------------------------------------------------------
	// �}�����Z�q
	//----------------------------------------------------------------

	friend std::istream& operator>>(std::istream& is, ExString& ex);

	//----------------------------------------------------------------
	// �A�����Z�q
	//----------------------------------------------------------------

	friend ExString operator+(const ExString& a, const ExString& b);
	const ExString& operator+=(const ExString& a);

	//----------------------------------------------------------------
	// �A�N�Z�b�T
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
