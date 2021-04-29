// ------------------------------------------------------
// File    : src/cross/string.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------
#ifndef __KALLUP_STRING_H__
#define __KALLUP_STRING_H__

# include "common.pch.hpp"

// ---------------------------------------
// string handling: utf-16 as default:
// ---------------------------------------
namespace kallup::string
{
	class ansi  { };
	class utf8  { };
	class utf16 { };
	class utf32 { };
	
	template <class CharType>
	class String
	{
	public:
		String(CharType Type)
		{
		}
	};  //
};	    // namespace: kallup::string
#endif	// header:    String.hpp
