#include"pch.h"
#include "thread.h"

CMutex mutexObj(FALSE, _T("mutex"));
UINT ThreadGet(LPVOID pParam)
{
	
	HWND hWnd = (HWND)pParam;
	LPCTSTR lpszName = L"SENDDATA";
	HINSTANCE hdll = ::LoadLibrary(L"Dll.dll");
	if (hdll == NULL) {
		MessageBox(NULL, L"´ò¿ª¶¯Ì¬Á´½Ó¿âÊ§°Ü", L"Ê§°Ü", MB_OK);
	}
	typedef int(__stdcall* PROC)();
	PROC proc = (PROC)GetProcAddress(hdll, "getData");
	CEvent event(FALSE, FALSE, lpszName);
	while (1) {
		
		::WaitForSingleObject(event.m_hObject, INFINITE);
		mutexObj.Lock();
		int result = (*proc)();
		mutexObj.Unlock();
		::SendMessage(hWnd, WM_RESULT, result, 0);
	}
	FreeLibrary(hdll);
}
