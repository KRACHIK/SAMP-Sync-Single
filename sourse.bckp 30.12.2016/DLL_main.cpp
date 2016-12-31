#include <iostream>			

#include "Object_List.h" 

#include <Windows.h>


int WINAPI DllMain(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		printf("\n[network] int WINAPI DllMain \n");
		setlocale(LC_ALL, "Russian");
	}
	return 1;
}

 