// ------------------------------------------------------
// File    : src/cross/common.pch.hpp
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------
#ifndef __COMMON_H__
#define __COMMON_H__

// ms-windows header's:
# include <windows.h>
# include <windowsx.h>
# include <commctrl.h>
# include <tchar.h>

# include "resource.hpp"
//-----


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

// common framework header's:
# include "raii.hpp"
# include "string.hpp"
# include "error.hpp"

#endif