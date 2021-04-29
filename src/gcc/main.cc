// ------------------------------------------------------
// File    : src/cross/dos/main.cc
//
// Autor   : Jens Kallup <kallup.jens@web.de> - paule32
// License : (c) kallup.net - non-profit - 2021
// -----------------------------------------------------

# include "common.pch.hpp"

// lambda [capture locals](arguments to lambda)
constexpr std::function<
	void (std::wstring text,
		  std::wstring title) >
		  handleError = [](
		  std::wstring text,
		  std::wstring title) const
{
//	wchar_t s1[100] = { &text.c_str() };
//	MessageBoxW(0, s1, title.c_str(), MB_OK); 
};


// -----------------------------------------------------
// main: EntryPoint of application.
// -----------------------------------------------------
#ifdef WINDOWS
BOOL WINAPI
DllMain(
	HINSTANCE hinstDLL ,	// handle to DLL module
    DWORD	  fdwReason,	// reason for calling function
    LPVOID    lpReserved)
#else
int main(void)
#endif
{
	namespace zwip = kallup::Exception;
	
	zwip::onError<3, handleError> 	error;
	error.call("my text", "my title");
    return 0;
}
