#include <iostream>			
#include <Windows.h> // for DllMain
 

int WINAPI DllMain(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		setlocale(LC_ALL, "Russian");
		//MessageBoxA(0, "DllMain", "DLL_PROCESS_ATTACH", 0);
	}
	return 1;
}



