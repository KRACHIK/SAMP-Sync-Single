#include <boost/thread/thread.hpp>
#include <boost\date_time\posix_time\posix_time.hpp>
#include <boost/thread/thread.hpp>
//#include <boost/date_time/posix_time/posix_time.hpp>
#include "..//sourse/DLL_client.h"
#include "EXE_main.h"
#include <iostream> 
#include <string>
#pragma comment(lib, "..//project/Release/client_Dll_2016.lib")          





void thereadHandleConnect()
{
	printVersionProg();

	/*std::cout << "enter \'1\' \t for GENERATE big bang" << "\n";
	std::cout << "enter \'2\' \t for GENERATE fake pos" << "\n";
	std::cout << "enter \'3\' \t for Client onRead" << "\n";
	std::cout << "enter \'4\' \t for Client onRead and send get car" << "\n";
	std::cout << "enter \'5\' \t for getServerID && send FreeServerID" << "\n";
	*/

	int design; std::cout << ">:";	std::cin >> design;


	boost::thread conect(Public_CLEO_connect_to_server_fon_NEW_September);
	conect.detach();


	const int MAX = 80;

	char buf[MAX];

	int i = 0;
	
	do{
		std::cin >> buf[i];
		i++;
	} while (buf[i-1] != '/n');

	std::cout <<  buf;
	 
	std::cout << "я не вылЕтела" << "\n";
	//Public_send_char_to_serv_NEW_September(buffer);

	//if (design == 1 || design == 2)
	//{
	//	boost::thread thr_send_fake_pos(connect_to_server, design);
	//	thr_send_fake_pos.detach();
	//}

}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)thereadHandleConnect, NULL, 0, 0);

	boost::this_thread::sleep(boost::posix_time::millisec(12700));
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



/*float _idEmtyStack = 1; float _k1 = 1; float _k2 = 1; float _k3 = 1;
float _k4 = 1; float _k5 = 1; float _k6 = 1; float _k7 = 1; float _k8 = 1;

float* idEmtyStack = &_idEmtyStack; float* k1 = &_k1; float* k2 = &_k2;
float* k3 = &_k3; float* k4 = &_k4; float* k5 = &_k5; float* k6 = &_k6;
float* k7 = &_k7; float* k8 = &_k8;

while (true)
{
GTA_read_stack(idEmtyStack, k1, k2, k3, k4, k5, k6, k7, k8);

std::cout << _idEmtyStack << "\n"; std::cout << _k1 << "\n"; std::cout << _k2 << "\n"; std::cout << _k3 << "\n"; std::cout << _k4 << "\n";
std::cout << _k5 << "\n"; std::cout << _k6 << "\n"; std::cout << _k7 << "\n"; std::cout << _k8 << "\n";
boost::this_thread::sleep(boost::posix_time::millisec(1000));
}*/
/*if (design == 4)
{
for (int i = 0; i < 222; i++)
{
SYSTEMTIME	time;
GetLocalTime(&time);
int  handleForMap = time.wHour + time.wMinute + time.wSecond + time.wMilliseconds;
printf(" %d %04d \n", handleForMap, time.wMilliseconds);
Log("handleForMap: %d time.wMilliseconds: %03d", handleForMap, time.wMilliseconds);
}
}*/