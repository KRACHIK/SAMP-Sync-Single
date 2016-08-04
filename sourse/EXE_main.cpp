#include <boost/thread/thread.hpp>
#include <boost\date_time\posix_time\posix_time.hpp>
//#include <boost/thread/thread.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
#include "..//sourse/DLL_client.h"
#include "EXE_main.h"
#include <iostream>

#pragma comment(lib, "..//project/Release/client_Dll_2016.lib")          



void thereadHandleConnect()
{
	boost::thread thr_send_fake_pos(connect_to_server, 1); // 1 = start fakeClientStartEXE
	thr_send_fake_pos.detach();
}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	printVersionProg();


	std::cout << "enter ""1"" \t for fake client" << "\n";
	std::cout << "enter ""2"" \t Client onRead" << "\n";
	int design = 1;

	std::cout << ">:";
	std::cin >> design;

	if (design == 1)
	{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)thereadHandleConnect, NULL, 0, 0);
	}
	if (design == 2)
	{
		CLEO_connect_to_server_fon();
		while (true)
		{
			boost::this_thread::sleep(boost::posix_time::millisec(1000));
			Public_send_to_serv("test");
		}
	}
	if (design == 3)
	{
		CLEO_connect_to_server_fon();
	}
	std::cout << "end custom theread\n";

	system("pause");
	return 0;
}
 
//%с	Символ типа char
//%d	Десятичное число целого типа со знаком
//%i	Десятичное число целого типа со знаком
//%е	Научная нотация(е нижнего регистра)
//% Е	Научная нотация(Е верхнего регистра)
//% f	Десятичное число с плавающей точкой
//%g	Использует код %е или %f — тот из них, который короче(при использовании %g используется е нижнего регистра)
//% G	Использует код %Е или %f — тот из них, который короче(при использовании %G используется Е верхнего регистра)
//% о	Восьмеричное целое число без знака
//%s	Строка символов
//%u	Десятичное число целого типа без знака
//%х	Шестнадцатиричное целое число без знака(буквы нижнего регистра)
//% Х	Шестнадцатиричное целое число без знака(буквы верхнего регистра)
//% р	Выводит на экран значение указателя
//%n	Ассоциированный аргумент — это указатель на переменную целого типа, в которую помещено количество символов, записанных на данный момент
//%%	Выводит символ %