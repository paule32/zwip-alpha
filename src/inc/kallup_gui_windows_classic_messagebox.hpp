// --------------------------------------------------------------
// File    : src/cross/kallup_gui_windows_classic_messagebox-hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// --------------------------------------------------------------
#ifndef __KALLUP_GUI_WINDOWS_CLASSIC_MESSAGEBOX_H__
#define __KALLUP_GUI_WINDOWS_CLASSIC_MESSAGEBOX_H__

// ---------------------------------------
// pre-compiled header files:
// ---------------------------------------
# include "common.pch.hpp"		// common

using namespace kallup::Locales;

namespace kallup::GUI          { };
namespace kallup::GUI::Windows { };
namespace kallup::GUI::Windows::Classic
{
	// ---------------------------------------
	// Button's supported at MessageBox:
	// ---------------------------------------
	enum class Button {
		AbortRetryIgnore	= 0x00000002L,
		CancelRetryContinue = 0x00000006L,
		Help                = 0x00004000L,
		Ok                  = 0x00000000L,
		OkCancel            = 0x00000001L,
		RetryCancel         = 0x00000005L,
		YesNo               = 0x00000004L,
		YesNoCancel         = 0x00000003L
	};
	
	// ---------------------------------------
	// Icon's supported for MessageBox:
	// ---------------------------------------
	enum class Icon {
		Exclamation         = 0x00000030L,
		Warning             = 0x00000030L,
		Information         = 0x00000040L,
		Asterisk            = 0x00000040L,
		Question            = 0x00000020L,
		Stop                = 0x00000010L,
		Error               = 0x00000010L,
		Hand                = 0x00000010L
	};
	
	// ---------------------------------------
	// default Button:
	// ---------------------------------------
	enum class Default {
		Button1             = 0x00000000L,
		Button2             = 0x00000100L,
		Button3             = 0x00000200L,
		Button4             = 0x00000300L
	};
	
	// ---------------------------------------
	// position of MessageBox + text:
	// ---------------------------------------
	enum class Position {
		DesktopOnly         = 0x00020000L,
		Right               = 0x00080000L,  // right justified
		RightToLeft         = 0x00100000L,  // for Arabic systems
		Foreground          = 0x00010000L,
		TopMost             = 0x00040000L
	};
	
	// ---------------------------------------
	// return value result from button click:
	// ---------------------------------------
	enum class Result {
		Abort               =  3,
		Cancel              =  2,
		Continue            = 11,
		Ignore              =  5,
		No                  =  7,
		Ok                  =  1,
		Retry               =  4,
		TryAgain            = 10,
		Yes                 =  6
	};
	
	// ---------------------------------------
	// MessageBox< Text, Title, Button >:
	// ---------------------------------------
	template <
		template < typename Ta > typename Text ,
		template < typename Tb > typename Title, typename Btn& >
	class MessageBox
	{
		Text   m_Text;
		Title  m_Title;
		Button m_Button;
	public:
		MessageBox(void)
		: m_Text  (L"unknow message")
		, m_Title (L"Warning")
		, m_Button(Button::Ok)
		{ /* empty */ }
		
		MessageBox(Text text, Title title, Btn button)
		: m_Text  (text  )
		, m_Title (title )
		, m_Button(button)
		{ /* empty */ }
		
		MessageBox(Text& text, Title& title, Btn& button)
		: m_Text  (text  )
		, m_Title (title )
		, m_Button(button)
		{ /* empty */ }

		int operator ()(Icon code)   { return msgBox(Button::Ok); };
		int operator ()(Button code) { return msgBox(code);       };
		
	private:
		int msgBox(Button code) {
			if (std::is_same<wchar_t*, Text>::value && std::is_same<wchar_t*, Title>::value) {
				#ifdef WINDOWS
				return ::MessageBoxW(0, m_Text, m_Title, reinterpret_cast<UINT>(code));
				#else
					// todo
				#endif
			}	else
			if (std::is_same<char*, Text>::value && std::is_same<char*, Title>::value) {
				#ifdef WINDOWS
				return ::MessageBoxA(0, m_Text, m_Title, reinterpret_cast<UINT>(code));
				#else
					// todo
				#endif
			}
		};
	};
};      // namespace: kallup::gui::classic
#endif  // __KALLUP_GUI_WINDOWS_CLASSIC_MESSAGEBOX_H__
