#include<Windows.h>
#include"link.h"

#pragma data_seg("Shared")
int dwID = 0;
#pragma data_seg()
#pragma comment(linker , "/SECTION:Shared,RWS")

BOOL WINAPI DllMain(HANDLE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call)
	{
	default:
	case DLL_PROCESS_ATTACH:
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return true;
}

int _stdcall Add(int a, int b) {
	return a + b;
}
int _stdcall Substract(int a, int b) {
	return a - b;
}
int _stdcall getData() {
	return dwID;
}
void _stdcall setData(int x) {
	dwID = x;
}
