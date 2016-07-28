#include <iostream>

#include "EXE_main.h"
#include "..//C++/DLL_client.h"

#pragma comment(lib, "..//project/Release/client_Dll_2016.lib")          


 
void theread_connect()
{
	boost::asio::io_service io;
	EXE_Client_Connect_InitializeDLL(io, "127.0.0.1", "7777");
}


void theread_pop_struct_eplotions()
{

	int type2;
	float x2;
	float  y2;
	float  z2;
	float  radius2;

	int *type;
	float *x;
	float *y;
	float *z;
	float *radius;

	type = &type2;
	x = &x2;
	y = &y2;
	z = &z2;
	radius = &radius2;
	printf("THEREAD_POP_STRUCT_EPLOTIONS\n");
	printf("%d %f %f %f %f\n", type2, x2, y2, z2, radius2);
}

void enterStack()
{
	float g = 3; float *r = &g;	int k;
	while (true) 
	{
		Sleep(500);
		CLEO_public_call_func(r);
		if (*r == 66.0) 
		{
			float type = 999, x = 999, y = 999, z = 999;
			float *Ptype(&type), *Px(&x), *Py(&y), *Pz(&z);
			CLEO_read_stack(Ptype, Px, Py, Pz);
			std::cout << "\n pop\n";
			std::cout << " type " << *Ptype;// << "\n";
			std::cout << " x " << *Px ;//<< "\n";
			std::cout << " y " << *Py ;//<< "\n";
			std::cout << " z " << *Pz ;//<< "\n";
			std::cout << "\n";
		}
		else std::cout << "CLEO_isEmptyExplotion FALSe r=" << *r << "\n";
	}
}

void theread_connect_On_read()
{
	CLEO_public_connect_to_serv();
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)enterStack, NULL, 0, 0);	//	EXE 
	while (true)	{ PUBLIC_send_non_kick_space(200); }
}

void funcs_test()
{
	std::cout << "funcs_test " << std::endl;
}

void getFuncsForCall(void(*her)())
{
	her = funcs_test;
	std::cout << "her: " << her << std::endl;
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	printVersionProg();

	std::cout << "(1) fake pos\n(2) CLEO Machine\n-> ";
	int design;	std::cin >> design;

	switch (design)
	{
	case 1:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)theread_connect, NULL, 0, 0);	//	EXE 
		 
		break;
	case 2:
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)theread_connect_On_read, NULL, 0, 0);
		break;
	case 3:
	{
		break;
	}
	default:
		std::cout << "default: " << design << std::endl;
		break;
	}


	std::cout << std::endl;
	system("pause");
	return 0;
}
//----------------------
/*int		A = 13;
int		*ptrA;
ptrA = &A;
std::cout << "A=" << A << std::endl;
std::cout << "&A=" << &A << std::endl;
std::cout << "ptrA=" << ptrA << std::endl;
(*ptrA) = 23;
std::cout << "A=" << A << std::endl;
*/
/*Test summer;
summer.Print();
std::cout << "rez = " << addTEST(11, 4);*/

/*	auto client = getPointerClassUDPClientTEST();
(*client).sendChar("123"); 	*/
/*if () std::cout << "yeah startMain()\n";
else std::cout << "erorr startMain()\n";*/



/*

typedef int(*functionDll)(int, int);
HINSTANCE hDllInstance = LoadLibraryEx("NetworkCoreDll.dll", 0, DONT_RESOLVE_DLL_REFERENCES);
if (hDllInstance){
functionDll fpFunction = (functionDll)GetProcAddress(hDllInstance, "addTEST");
if (fpFunction)	{
int n = fpFunction(3, 5);
std::cout << "rez = " << n;
}
else std::cout << "Error number " << GetLastError();
}
else std::cout << "Error number " << GetLastError();
*/