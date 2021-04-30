// ------------------------------------------------------
// File    : src/cross/raii.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------
#ifndef __KALLUP_RAII_H__
#define __KALLUP_RAII_H__

// ---------------------------------------
// pre-compiled header files:
// ---------------------------------------
# include "common.pch.hpp"	  // common
# include <type_traits>       // run-time-type check - no RTTI ! 

// ---------------------------------------
// kallup::RAII ns:
// ---------------------------------------
namespace kallup::RAII
{
	template<class T, T _bool>
	struct integral_constant
	{
		static constexpr T value = _bool;
		constexpr operator ()(void) const { return value; }
	};
	
	typedef integral_constant<bool, true > true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T>
	struct is_integral : public false_type{};

	template <>
	struct is_integral<bool> : public true_type{};
	
	template <>
	struct is_integral<char> : public true_type{};
	
	template <>
	struct is_integral<signed char> : public true_type{};
	
	template <>
	struct is_integral<unsigned char> : public true_type{};
	
	template <>
	struct is_integral<short> : public true_type{};
	
	template <>
	struct is_integral<int> : public true_type{};
	
	template <>
	struct is_integral<long> : public true_type{};
	
	template <>
	struct is_integral<long long> : public true_type{};
	
	template <>
	struct is_integral<unsigned short> : public true_type{};
	
	template <>
	struct is_integral<unsigned int> : public true_type{};
	
	template <>
	struct is_integral<unsigned long> : public true_type{};
	
	template <>
	struct is_integral<unsigned long long> : public true_type{};
	
	template <>
	struct is_integral<wchar_t> : public true_type{};
	
	template <>
	struct is_integral<int> : public true_type{};
	
};	    // namespace: kallup::RAII
#endif	// header:    RAII.hpp
