#include "PicturaPCH.h"
#include "NTWindow.h"

#ifdef PLATFORM_WINDOWS
extern "C" {
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}
#endif

namespace Pictura::UI
{
	NTWindow::NTWindow()
	{
		Debug::Log::GetFrameworkLog().Info("Creating Win32 Window...");
		m_wndHandle = SetupWindow();
	}

	NTWindow::~NTWindow()
	{
		Debug::Log::GetFrameworkLog().Info("Destroying Win32 Window...");
	}

	void NTWindow::Show()
	{
		throw NotImplementedException();
	}

	void NTWindow::Hide()
	{
		throw NotImplementedException();
	}

	void NTWindow::Close()
	{
		throw NotImplementedException();
	}

	void NTWindow::Focus()
	{
		throw NotImplementedException();
	}
}