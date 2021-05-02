// ------------------------------------------------------
// File    : src/cross/kalup_exception.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------
#ifndef __KALLUP_EXCEPTIONS_H__
#define __KALLUP_EXCEPTIONS_H__

// ---------------------------------------
// pre-compiled header files:
// ---------------------------------------
# include "common.pch.hpp"		// common

// ---------------------------------------
// kallup::Exception ns:
// ---------------------------------------
namespace kallup::Exception
{
	// some short mapper:
	typedef wchar_t* ErrorText;
	typedef wchar_t* ErrorTitle;
  
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
		extern ErrorCode  m_ErrorCode;  // number of code
		extern ErrorText  m_ErrorText;  // text for exception
		extern ErrorTitle m_ErrorTitle; // title for message box
	#else
		ErrorCode  m_ErrorCode  = ErrorCode::success;
		ErrorTitle m_ErrorTitle = L"Error";
		ErrorText  m_ErrorText  = L"Unknown";
	#endif

	class Exception: public std::exception {
	public:
		virtual const ErrorText  toString() const throw () { return m_ErrorText; }
		virtual const ErrorCode  toCode  () const throw () { return m_ErrorCode; }
	};

	// ---------------------------------------
	// system error codes, and the message:
	// ---------------------------------------
	template <typename T1, typename T2, typename T3>
	struct onError {
		onError(void) { };
		onError(T1 t1, T2 t2, T3 t3) {
			if (std::is_same<ErrorCode, T1>::value) {
				if (kallup::ApplicationSystem == kallup::AppSystem::Dos) {
					kallup::GUI::DOS::TurboVision::MessageBox<String<Utf16>,String<Utf16>,
					kallup::GUI::DOS::TurboVision::Button>(t1,t2,
					kallup::GUI::DOS::TurboVision::Button::Ok);
				}	else
				if (kallup::ApplicationSystem == kallup::AppSystem::Windows) {
					kallup::GUI::Windows::Classic::MessageBox<String<Utf16>,String<Utf16>,
					kallup::GUI::Windows::Classic::Button>(t1,t2,
					kallup::GUI::Windows::Classic::Button::Ok);
				}
			};
		};
	};

/*
	template <template <typename> class TCode, class Y>
	struct onError<T1<Y>> {
		onError() {
			if (std::is_same<ErrorCode, T1>::value) {
				if (kallup::ApplicationSystem == kallup::AppSystem::Dos) {
					kallup::TUI::DOS::TurboVision::MessageBox<txt,L"Error">(kallup::TUI::DOS::TurboVision::Button::Ok);
				}	else
				if (kallup::ApplicationSystem == kallup::AppSystem::Windows) {
					kallup::GUI::Windows::Classic::MessageBox<txt,L"Error">(kallup::GUI::Windows::Classic::Button::Ok);
				}
			};
		};
	};
*/
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
	template< int16_t NC, std::function<void(std::string _text, std::string _title)> &EF>
	struct onWarn
	{
		void call(std::string _text, std::string _title) {
			EF(_text, _title);
		}
	};

	// ---------------------------------------
	// system info codes, and the message:
	// ---------------------------------------
	template< int16_t NC, std::function<void(std::string _text, std::string _title)> &EF>
	struct onInfo
	{
		void call(std::string _text, std::string _title) {
			EF(_text, _title);
		}
	};
};	    // namespace: kallup::Exception
#endif	// header:    Exception.hpp
