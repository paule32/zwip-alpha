// --------------------------------------------------------------
// File    : src/cross/kallup.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// --------------------------------------------------------------
#ifndef __KALLUP_H__
#define __KALLUP_H__

// ---------------------------------------
// pre-compiled header files:
// ---------------------------------------
# include "common.pch.hpp"		// common

namespace kallup
{
	enum class AppMode  {
		Unknown = 0,
		Tui     = 1,	// text    user interface
		Gui     = 2,	// graphic user interface
		Service = 3 	// service application
	};
	
	enum class AppSystem {
		Unknown = 0,
		Dos     = 1,	// DOS target
		Windows = 2 	// Windows
	};
	
	enum class AppSubSystem {
		Unknown = 0,
		Console = 1,
		Desktop = 2
	};
	
	#ifndef LIB_IMPL
	extern AppMode ApplicationSystem;
	#else
		#ifdef WINDOWS
		AppSystem ApplicationSystem = AppSystem::Unknown;
		#else
		AppSystem ApplicationSystem = AppSystem::Dos;
		#endif
	#endif

};      // namespace: kallup
#endif  // __KALLUP_H__
