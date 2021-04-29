// ------------------------------------------------------
// File    : src/cross/dos/main.cc
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------

# include "common.pch.hpp"
using namespace kallup::Exception;

// lambda [capture locals](arguments to lambda)
std::function<
	void (std::wstring text,
		  std::wstring title) > handleError = [](
		  std::wstring text,
		  std::wstring title)
{
//	wchar_t s1[100] = { &text.c_str() };
//	MessageBoxW(0, s1, title.c_str(), MB_OK); 
};


// -----------------------------------------------------
// main: EntryPoint of application.
// -----------------------------------------------------
#ifdef WINDOWS
	#ifdef TARGET_DLL
	BOOL WINAPI
	DllMain(
		HINSTANCE hinstDLL ,	// handle to DLL module
		DWORD	  fdwReason,	// reason for calling function
		LPVOID    lpReserved)
	#else
	INT WINAPI
	WinMain(
		HINSTANCE hInstance,
		HINSTANCE hPrevInstance,
		PSTR      pCmdLine,
		int       nCmdShow)
	#endif
#else
int main(void)
#endif
{
	onError<1>();
	
	#ifdef TARGET_DLL 
	return true;
	#else
    return 0;
	#endif
}
