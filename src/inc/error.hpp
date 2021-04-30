// ------------------------------------------------------
// File    : src/cross/Exception.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------
#ifndef __KALLUP_EXCEPTIONS_H__
#define __KALLUP_EXCEPTIONS_H__

// ---------------------------------------
// pre-compiled header files:
// ---------------------------------------
//# include "windows.pch.hpp" 	// windows: 10 pro
# include "common.pch.hpp"		// common

using namespace std;
using namespace kallup::String;

// ---------------------------------------
// kallup::Exception ns:
// ---------------------------------------
namespace kallup::Exception
{
	// some short mapper:
	typedef wchar_t* ErrorText;
  
	// ---------------------------------------
	// win32api C++ "const" code definition's:
	// ---------------------------------------
	enum class ErrorCode {
		success             = 0x0000,
		invalid_function    = 0x0001,
		file_not_found      = 0x0002,
		path_not_found      = 0x0003,
		too_many_open_files = 0x0004,
		access_denied       = 0x0005,
		invalid_handle      = 0x0006
	};
	
	// ---------------------------------------
	// win32api C++ "const" text definition's:
	// ---------------------------------------
	constexpr wchar_t* success                      = L"The operation completed successfully.";
	constexpr wchar_t* invalid_function             = L"Incorrect function.";
	constexpr wchar_t* file_not_found               = L"%s find the file specified.";
	constexpr wchar_t* path_no_found                = L"%s find the path specified.";
	constexpr wchar_t* too_many_open_files          = L"%s open the file.";
	constexpr wchar_t* access_denied                = L"Access is denied";
	
	// ---------------------------------------------
	// -D LIB_IMPLEMENTATION : only at impl. time !
	// ---------------------------------------------
	#ifdef LIB_IMPL
		extern ErrorCode m_ErrorCode;  // number of code
		extern ErrorText m_ErrorText;  // text for exception
	#else
		ErrorCode m_ErrorCode = ErrorCode::success;
		ErrorText m_ErrorText = L"";
	#endif

	class Exception: public std::exception {
	public:
		virtual const ErrorText toString() const throw () { return m_ErrorText; }
		virtual const ErrorCode toCode  () const throw () { return m_ErrorCode; }
	};
		
	// ---------------------------------------
	// system error codes, and the message:
	// ---------------------------------------
	template <ErrorCode EC>
	struct onError {
		onError(void) {
			// todo
			MessageBoxW(0, L"Unknown Error", L"Error",MB_OK);
		};
		onError(const wchar_t* text, const wchar_t* title) {
			// todo
			MessageBoxW(0, text, title,MB_OK);
		};
	};
	template <const wchar_t* text>
	struct onError {
		onError(void) {
			// todo
		};
	};
	/*
	struct onError
	{
		template <void T>
		void operator()(void               ) const { }
		
		template <char* T>
		void operator()(char         * text) const { }
		
		void operator()(std:: string   text) const { }
		void operator()(std::wstring   text) const { }
		void operator()(class String         text) const { }
		//
		void operator()(char * text, char         * title) const { }
		void operator()(char * text, std:: string   title) const { }
		void operator()(char * text, std::wstring * title) const { }
		void operator()(char * text, class String   title) const { }
		//
		void operator()(std::string text, char         * title) const { }
		void operator()(std::string text, std:: string   title) const { }
		void operator()(std::string text, std::wstring * title) const { }
		void operator()(std::string text, class String   title) const { }
		//
		void operator()(std::wstring text, char         * title) const { }
		void operator()(std::wstring text, std:: string   title) const { }
		void operator()(std::wstring text, std::wstring * title) const { }
		void operator()(std::wstring text, class String   title) const { }
		//
		void operator()(class String text, char         * title) const { }
		void operator()(class String text, std:: string   title) const { }
		void operator()(class String text, std::wstring * title) const { }
		void operator()(class String text, class String   title) const { }
	};*/

	// ---------------------------------------
	// system warning codes, and the message:
	// ---------------------------------------
	template< int16_t NC, std::function<void(std::string text, std::string title)> &EF>
	struct onWarn
	{
		void call(std::string text, std::string title) {
			EF(text, title);
		}
	};

	// ---------------------------------------
	// system info codes, and the message:
	// ---------------------------------------
	template< int16_t NC, std::function<void(std::string text, std::string title)> &EF>
	struct onInfo
	{
		void call(std::string text, std::string title) {
			EF(text, title);
		}
	};
};	    // namespace: kallup::Exception
#endif	// header:    Exception.hpp
