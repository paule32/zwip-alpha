// ------------------------------------------------------
// File    : src/cross/kallup_string.hpp
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
namespace kallup::String
{
	class Ansi  { };
	class Utf8  { };
	class Utf16 { };
	class Utf32 { };
	
	template <class TC>
	class String {
	public:
	
	};  // class:     String<>
};	    // namespace: kallup::string
#endif	// header:    String.hpp
