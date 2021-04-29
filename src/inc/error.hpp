// ------------------------------------------------------
// File    : src/cross/error.h
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------
#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

// ---------------------------------------
// pre-compiled header files:
// ---------------------------------------
# include "windows.pch.hpp" 	// windows: 10 pro
# include "common.pch.hpp"		// common

using namespace kallup::String

// the list of error codes:
typedef struct {
	std::int16_t  ecCode;
	std::string   ecError; 
}
WINDOWS_ERROR_CODES;

// ---------------------------------------
// kallup::Exception ns:
// ---------------------------------------
namespace kallup::Exception
{
	// ---------------------------------------
	// win32api C++ "const" definition's:
	// ---------------------------------------
	enum Error : int16_t {
		//SUCCESS 			= 0x0000,
		success = 0x0,
		INVALID_FUNCTION	= 0x0001,
		FILE_NOT_FOUND      = 0x0002,
		PATH_NOT_FOUND      = 0x0003,
		TOO_MANY_OPEN_FILES = 0x0004,
		ACCESS_DENIED       = 0x0005,
		INVALID_HANDLE      = 0x0006
	};

	Error        ErrorCode;  // number of code
	std::wstring ErrorText;  // text for exception

	class Exception: public std::exception {
	public:
		virtual const std::wstring text() const throw () { return ErrorText; }
		virtual const Error        code() const throw () { return ErrorCode; }
	};
		
	// ---------------------------------------
	// system error codes, and the message:
	// ---------------------------------------
	template < Error ErrorCode >
	struct onError
	{
		void operator()(void               ) const { }
		void operator()(char         * text) const { }
		void operator()(std:: string   text) const { }
		void operator()(std::wstring   text) const { }
		void operator()(String         text) const { }
		//
		void operator()(char * text, char         * title) const { }
		void operator()(char * text, std:: string   title) const { }
		void operator()(char * text, std::wstring * title) const { }
		void operator()(char * text, String         title) const { }
		//
		void operator()(std::string text, char         * title) const { }
		void operator()(std::string text, std:: string   title) const { }
		void operator()(std::string text, std::wstring * title) const { }
		void operator()(std::string text, String         title) const { }
		//
		void operator()(std::wstring text, char         * title) const { }
		void operator()(std::wstring text, std:: string   title) const { }
		void operator()(std::wstring text, std::wstring * title) const { }
		void operator()(std::wstring text, String         title) const { }
		//
		void operator()(String text, char         * title) const { }
		void operator()(String text, std:: string   title) const { }
		void operator()(String text, std::wstring * title) const { }
		void operator()(String text, String         title) const { }
	};
	template < String ErrorText >
	struct onError
	{
		void operator()(void               ) const { }
		void operator()(char         * text) const { }
		void operator()(std:: string   text) const { }
		void operator()(std::wstring   text) const { }
		void operator()(String         text) const { }
		//
		void operator()(char * text, char         * title) const { }
		void operator()(char * text, std:: string   title) const { }
		void operator()(char * text, std::wstring * title) const { }
		void operator()(char * text, String         title) const { }
		//
		void operator()(std::string text, char         * title) const { }
		void operator()(std::string text, std:: string   title) const { }
		void operator()(std::string text, std::wstring * title) const { }
		void operator()(std::string text, String         title) const { }
		//
		void operator()(std::wstring text, char         * title) const { }
		void operator()(std::wstring text, std:: string   title) const { }
		void operator()(std::wstring text, std::wstring * title) const { }
		void operator()(std::wstring text, String         title) const { }
		//
		void operator()(String text, char         * title) const { }
		void operator()(String text, std:: string   title) const { }
		void operator()(String text, std::wstring * title) const { }
		void operator()(String text, String         title) const { }
	};
	template < std::wstring ErrorText >
	struct onError
	{
		void operator()(void               ) const { }
		void operator()(char         * text) const { }
		void operator()(std:: string   text) const { }
		void operator()(std::wstring   text) const { }
		void operator()(String         text) const { }
		//
		void operator()(char * text, char         * title) const { }
		void operator()(char * text, std:: string   title) const { }
		void operator()(char * text, std::wstring * title) const { }
		void operator()(char * text, String         title) const { }
		//
		void operator()(std::string text, char         * title) const { }
		void operator()(std::string text, std:: string   title) const { }
		void operator()(std::string text, std::wstring * title) const { }
		void operator()(std::string text, String         title) const { }
		//
		void operator()(std::wstring text, char         * title) const { }
		void operator()(std::wstring text, std:: string   title) const { }
		void operator()(std::wstring text, std::wstring * title) const { }
		void operator()(std::wstring text, String         title) const { }
		//
		void operator()(String text, char         * title) const { }
		void operator()(String text, std:: string   title) const { }
		void operator()(String text, std::wstring * title) const { }
		void operator()(String text, String         title) const { }
	};
	template < std::string ErrorText >
	struct onError
	{
		void operator()(void               ) const { }
		void operator()(char         * text) const { }
		void operator()(std:: string   text) const { }
		void operator()(std::wstring   text) const { }
		void operator()(String         text) const { }
		//
		void operator()(char * text, char         * title) const { }
		void operator()(char * text, std:: string   title) const { }
		void operator()(char * text, std::wstring * title) const { }
		void operator()(char * text, String         title) const { }
		//
		void operator()(std::string text, char         * title) const { }
		void operator()(std::string text, std:: string   title) const { }
		void operator()(std::string text, std::wstring * title) const { }
		void operator()(std::string text, String         title) const { }
		//
		void operator()(std::wstring text, char         * title) const { }
		void operator()(std::wstring text, std:: string   title) const { }
		void operator()(std::wstring text, std::wstring * title) const { }
		void operator()(std::wstring text, String         title) const { }
		//
		void operator()(String text, char         * title) const { }
		void operator()(String text, std:: string   title) const { }
		void operator()(String text, std::wstring * title) const { }
		void operator()(String text, String         title) const { }
	};
	template < char * ErrorText >
	struct onError
	{
		void operator()(void               ) const { }
		void operator()(char         * text) const { }
		void operator()(std:: string   text) const { }
		void operator()(std::wstring   text) const { }
		void operator()(String         text) const { }
		//
		void operator()(char * text, char         * title) const { }
		void operator()(char * text, std:: string   title) const { }
		void operator()(char * text, std::wstring * title) const { }
		void operator()(char * text, String         title) const { }
		//
		void operator()(std::string text, char         * title) const { }
		void operator()(std::string text, std:: string   title) const { }
		void operator()(std::string text, std::wstring * title) const { }
		void operator()(std::string text, String         title) const { }
		//
		void operator()(std::wstring text, char         * title) const { }
		void operator()(std::wstring text, std:: string   title) const { }
		void operator()(std::wstring text, std::wstring * title) const { }
		void operator()(std::wstring text, String         title) const { }
		//
		void operator()(String text, char         * title) const { }
		void operator()(String text, std:: string   title) const { }
		void operator()(String text, std::wstring * title) const { }
		void operator()(String text, String         title) const { }
	};

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

	WINDOWS_ERROR_CODES windows_error_code[] =
	{
		{ ERROR_SUCCESS,             "The operation completed successfully"      },
		{ ERROR_INVALID_FUNCTION,    "Incorrect function."                       },
		{ ERROR_FILE_NOT_FOUND,      "The system cannot find the file specified" },
		{ ERROR_PATH_NOT_FOUND,      "The system cannot find the path specified" },
		{ ERROR_TOO_MANY_OPEN_FILES, "The system cannot open the file"           },
		{ ERROR_ACCESS_DENIED,       "Access is denied" },
	};
};	    // namespace: kallup::Exception
#endif	// header:    Exception.hpp
