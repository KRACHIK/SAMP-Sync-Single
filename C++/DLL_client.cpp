#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <string>

#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

#include <boost/regex.hpp>

#include <vector>
#include <stack>

#include <windows.h>
#include "DLL_client.h"

//DIM
UDPClientTEST *Ptrclient;
void(*ptrFuncsEplotionPOP)();

//-------------------------------------

//============		UDPClientTEST	===========================================
UDPClientTEST::UDPClientTEST(boost::asio::io_service& io_service, const std::string& host,
	const std::string& port) : io_service_(io_service),
	socket_(io_service, udp::endpoint(udp::v4(), 0))
{
	//udp::socket::non_blocking_io non_blocking_io(true);
	udp::resolver resolver(io_service_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint_ = *iter;
	m_CLEO_paket = "SAMP AWESOME";
	//send(" reg me please (konstructor) ");
}

UDPClientTEST::~UDPClientTEST()
{
	socket_.close();
}

void UDPClientTEST::send(const std::string& msg)
{
	socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
}

std::string UDPClientTEST::recovdata()
{ 
	boost::system::error_code error;// Receive client query
 	boost::system::error_code ignored_error;

	int bytes = socket_.receive_from(buffer(buff), endpoint_);
	std::string msg(buff, bytes);
	
	if (error && error != boost::asio::error::message_size)
		throw boost::system::system_error(error);
	
	return msg;
}

void UDPClientTEST::printPaket()
{
	SetColor(Red, Black);
	std::cout << "\n";
	std::cout << "<- " << m_CLEO_paket << "\n";
	SetColor(White, Black);
}

void UDPClientTEST::CLEO_replaceTochkaHazapiataia()
{
	for (int i = 0; i < m_CLEO_paket.length(); i++)
		if (m_CLEO_paket[i] == '.') m_CLEO_paket[i] = ',';
}

void UDPClientTEST::CLEO_Analiz_paket_and_push_prms_to_struct()
{
	// podschet kolichestva tcifr v paketk
	if (CLEO_isValid_Count_prms_numeral_to_srs_paket(2))
	{
		CLEO_replaceTochkaHazapiataia();

		// parsePaketByClient(); - разбивает строку до ";" кладет в стек, передает подстроки
		// другой функции, другая функция разбивает строку на числа, и кладет результат
		// встек класса
		parsePaketByClient();
	}
}

bool UDPClientTEST::CLEO_isValid_Count_prms_numeral_to_srs_paket(int _count)
{
	boost::regex reg("(\\d+)*");	//poluchaet chislo
	boost::sregex_iterator it(m_CLEO_paket.begin(), m_CLEO_paket.end(), reg);
	int count = 0;
	while (it != boost::sregex_iterator()) 
	{
		if (it->length() >= 1) 
		{
			++count;
			if (count >= _count) break;
		}
		++it;
	}
	if (count >= _count) return true;
	return false;
}

bool UDPClientTEST::isValidCountParmsThisDesponsePaketSetPtrArrForFuncsCall(
	std::string desponsePaket, int *PtrArr)
{
	int cnt = 0;
	boost::regex reg("(-+|)\\d+(,\\d+)*");
	boost::sregex_iterator it(desponsePaket.begin(), desponsePaket.end(), reg);
	while (it != boost::sregex_iterator())
	{
		PtrArr[cnt] = atoi(it->str().c_str());
		++cnt; ++it;
		if (cnt >= 2) break;
	}
	if (cnt >= 2) return true;
	return false;
}

void UDPClientTEST::CLEO_parse_pak_for_callback(
	std::stack <std::string, std::vector <std::string> > stack_Parse_Paket)
{
	while (!stack_Parse_Paket.empty())
	{
		int ArrfuncsCall[3];
		std::string token = stack_Parse_Paket.top();

		//true if token >= 2 tcifry` 
		if (isValidCountParmsThisDesponsePaketSetPtrArrForFuncsCall(token, ArrfuncsCall))
		{
			//std::cout << ArrfuncsCall[0] << " <->" << ArrfuncsCall[1] << std::endl;
			//std::cout << "isValidCountParmsThisDesponsePaketSetPtrArrForFuncsCall " << std::endl;
			switch (ArrfuncsCall[1])
			{
			case 66:
				//std::cout << "положить взрыв в стек" << std::endl;
				CLEO_parse_prms_for_explotion(token);
			default:
				break;
			}

		}
		stack_Parse_Paket.pop();
	}
}


void UDPClientTEST::parsePaketByClient()
{
	boost::regex reg(".*?;|.*\\z");  // umeet poluchit` kusok stroki do simvolv ";"
	std::stack <std::string, std::vector <std::string> > stack_Parse_Paket;
	for (boost::sregex_iterator it(m_CLEO_paket.begin(), m_CLEO_paket.end(), reg);
		it != boost::sregex_iterator(); ++it)
	{
		if (it->length() >= 1)
		{
			stack_Parse_Paket.push(it->str().c_str());  
		}
	}
	CLEO_parse_pak_for_callback(stack_Parse_Paket);
}


void UDPClientTEST::CLEO_popStruct(float *type, float *x, float *y, float *z)
{
	if (!m_stackPakExplotin.empty())
	{
		(*type) = m_stackPakExplotin.top().type;
		(*x) = m_stackPakExplotin.top().x;
		(*y) = m_stackPakExplotin.top().y;
		(*z) = m_stackPakExplotin.top().z;

		m_stackPakExplotin.pop();  
	}
}

void thread_EXE_send(UDPClientTEST* currClient, int timeOut)
{

	int i=0;
	while (true)
	{
		// random packet bullet explotions
		char buf[513];
		sprintf_s(buf, sizeof(buf), "%d %d %d.%d %d.%d %d.%d %d.%d paket-%d",
			66, 10, rand() % 6, 666, rand() % 100, 1, rand() % 100, 2, rand() % 20, 3, i);
		std::string PACKED = buf;
		++i;
		(*currClient).send(PACKED);
		boost::this_thread::sleep(boost::posix_time::millisec(timeOut));
	}
}

std::string		UDPClientTEST::getPaketStr()
{
	return m_CLEO_paket;
}
void UDPClientTEST::setPaketStr(std::string val)
{
	m_CLEO_paket = val;
}

void thread_EXE_recov(UDPClientTEST* currClient)
{
	while (true)
	{
		std::string newPaket = (*currClient).recovdata();
		(*currClient).setPaketStr(newPaket);
		(*currClient).printPaket();
		(*currClient).CLEO_Analiz_paket_and_push_prms_to_struct();
		 
		boost::this_thread::sleep(boost::posix_time::millisec(13));
	}
}


extern "C" __declspec(dllexport)	bool EXE_Client_Connect_InitializeDLL(
	boost::asio::io_service& io_service, std::string ip, std::string port)
{
	std::cout << "client startInitialize\n";
	UDPClientTEST client(io_service, ip, port);
	Ptrclient = &client;
	boost::thread trd0(&thread_EXE_recov, &client);
	boost::thread trd1(&thread_EXE_send, &client, 4111);
	trd0.join();
	trd1.join();
	client.~UDPClientTEST();
	return true;
}



extern "C" __declspec(dllexport) void CLEO_read_stack(
	float *type, float *x, float *y, float *z)
{
	(*Ptrclient).CLEO_popStruct(type, x, y, z);
}

void CLEO_private_connect_on_read(
	boost::asio::io_service& io_service, std::string ip, std::string port)
{
	UDPClientTEST client(io_service, ip, port);
	Ptrclient = &client;
	boost::thread trd0(&thread_EXE_recov, &client);
	trd0.join();
}

void CLEO_private_theread_local_conncect()
{
	boost::asio::io_service io;
	CLEO_private_connect_on_read(io, "127.0.0.1", "7777");
}

extern "C" __declspec(dllexport)	void CLEO_public_connect_to_serv()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)CLEO_private_theread_local_conncect, NULL, 0, 0);
}

extern "C" __declspec(dllexport)	void	CLEO_public_send(char *paket)
{
	(*Ptrclient).send(paket);
}

void SetColor(int text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

extern "C" __declspec(dllexport)	void printVersionProg()
{
	std::cout << VERSION << std::endl;
}

extern "C" __declspec(dllexport)	void	PUBLIC_send_non_kick_space(int sleep)
{
	boost::this_thread::sleep(boost::posix_time::millisec(sleep));
	(*Ptrclient).send(" ");
}

extern "C" __declspec(dllexport)	void	PUBLIC_close_socket()
{
	(*Ptrclient).~UDPClientTEST();
}

bool	UDPClientTEST::CLEO_isEmptyExplotion()
{
	//Beep(10000, 23);
	if (!m_stackPakExplotin.empty()) return true;
	return false;
}
extern "C" __declspec(dllexport)	void 	CLEO_public_call_func(float *number)
{
	SetColor(Red, Black);
	*number = -1;
	if ((*Ptrclient).CLEO_isEmptyExplotion())	{ *number = 66; }
	SetColor(White, Black);
}

extern "C" __declspec(dllexport)	
		void	CLEO_public_get_prms_using_ptr(float *x, float *y, float *z){
	(*x)++; (*y)++; (*z)++;
}




extern "C" __declspec(dllexport)	void	PUBLIC_CLEO_NOP()
{
	Beep(400, 400);
}

extern "C" __declspec(dllexport)	void	PUBLIC_CLEO_EXPLOTION()
{
	std::cout << "this is PUBLIC_CLEO_EXPLOTION" << std::endl;
	Beep(1400, 1400);
}



void UDPClientTEST::CLEO_parse_prms_for_explotion(std::string token)
{
	//std::cout << "CLEO_parse_prms_for_explotion() sourse: " << token << "\n";
	int numberLeksema = -1;
	boost::regex reg("(-+|)\\d+(,\\d+)*");
	for (boost::sregex_iterator it(token.begin(), token.end(), reg); it != boost::sregex_iterator(); ++it)
	{
		SetColor(Yellow, Black);
		switch (numberLeksema)
		{
		case 1:
			std::cout << " box: type babax: " << it->str().c_str();
			m_struct_bangTmp.type = atoi(it->str().c_str());
			break;
		case 2:
			std::cout << " box: raduys: " << it->str().c_str();
			m_struct_bangTmp.radius = (float)atof(it->str().c_str());
			break;
		case 3:
			std::cout << " box: x: " << it->str().c_str();
			m_struct_bangTmp.x = (float)atof(it->str().c_str());
			break;
		case 4:
			std::cout << " box: у: " << it->str().c_str();
			m_struct_bangTmp.y = (float)atof(it->str().c_str());
			break;
		case 5:
			std::cout << " box: z: " << it->str().c_str();
			m_struct_bangTmp.z = (float)atof(it->str().c_str());
			break;
		default:
			//std::cout << "\t чет сломалось: " << it->str().c_str() << std::endl;
			break;
		}
		++numberLeksema;
	}
	SetColor(White, Black);
	std::cout << "\n";
	m_stackPakExplotin.push(m_struct_bangTmp);
}




/*
	возрат параметров в клео скрипт, возрат осуществляется через у казатель переданный
	в аргумете Функции.

	1 сколько аргументов будет в теле функции ?
	2 сколько будет таких функций ?
	3 как осуществляется их вызов ?

	1 аргументов будет - фиксированное число, пока что.
	механизм вызова нужной функции, сначала вызываем одну определенную функцию,
	затем получив от нее возращаемый номер, переедаем этот номер в клео скрипт,
	дальше, этот клео скрипт сопоставляет полученный номер со своей таблицей,
	находит (или не находит) соответствующую функцию, и вызывает ее,
	полученые результаты, передает в дочерний тред.
*/
