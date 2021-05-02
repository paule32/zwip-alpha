// --------------------------------------------------------------
// File    : src/cross/kallup_tui_dos_turbovision_messagebox.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// --------------------------------------------------------------
#ifndef __KALLUP_TUI_DOS_TURBOVISION_MESSAGEBOX_H__
#define __KALLUP_TUI_DOS_TURBOVISION_MESSAGEBOX_H__

// ---------------------------------------
// pre-compiled header files:
// ---------------------------------------
# include "common.pch.hpp"		// common

namespace kallup::TUI      { };
namespace kallup::TUI::DOS { };
namespace kallup::TUI::DOS::TurboVision
{
	// ---------------------------------------
	// Button supported at MessageBox:
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
	template < typename Text, typename Title, typename Btn >
	class MessageBox
	{
		Text   m_text;
		Title  m_title;
		Button m_Button;
	public:
		MessageBox(void) {}
		MessageBox(Text text, Title title, Btn button)
		: m_text  (text  )
		, m_title (title )
		, m_Button(button)
		{ /* empty */ };
		
		int operator ()(Button btn) {
			return 2;
		};
	};
};      // namespace: kallup::tui::turbovision
#endif  // __KALLUP_TUI_DOS_TURBOVISION_MESSAGEBOX_H__
