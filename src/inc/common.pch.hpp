// ------------------------------------------------------
// File    : src/cross/common.pch.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------
#ifndef __COMMON_H__
#define __COMMON_H__

// ms-windows header's:
#ifdef WINDOWS
# include <windows.h>
# include <windowsx.h>
# include <commctrl.h>
# include <tchar.h>

# include "resource.hpp"
#endif


// common header's:
# include <stdlib.h>
# include <stdio.h>
# include <malloc.h>
# include <memory.h>

// common std c++ header's:
# include <cwchar>            // utf-16: default for windows 10 pro
# include <iostream>
# include <string>
# include <iterator>
# include <fstream>
# include <sstream>
# include <vector>
# include <map>
# include <list>
# include <algorithm>
# include <functional>
# include <cstdint>
# include <exception>
# include <regex>

// win32api #undef functions (todo: own header):
# undef MessageBox

// common framework header's:
namespace kallup                        { };

namespace kallup::TUI                   { };
namespace kallup::TUI::DOS              { };
namespace kallup::TUI::DOS::TurboVision { };

namespace kallup::GUI                   { };
namespace kallup::GUI::Windows          { };
namespace kallup::GUI::Windows::Classic { };

# include "kallup_string.hpp"
# include "kallup_locales.hpp"
# include "kallup_exception.hpp"
# include "kallup_tui_dos_turbovision_messagebox.hpp"
# include "kallup_gui_windows_classic_messagebox.hpp"

#endif
