#include <iostream>
#include "DLL_client.h"

#include <boost/bind.hpp>
#include <boost/regex.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>

#include <cstdio>

HINSTANCE				g_hOrigDll = NULL;
HMODULE					g_hDllModule = NULL;
FILE					*g_flLog = NULL;
FILE					*g_flLogAll = NULL;
FILE					*g_flLogChatbox = NULL;
FILE					*g_flLogChatboxAll = NULL;
char					g_szLastFunc[256];
uint32_t				g_dwSAMP_Addr = NULL;
char					g_szSAMPVer[16];
char					g_szWorkingDirectory[MAX_PATH];



сUDPClientGTA *ptrClientGTA;

extern "C" __declspec(dllexport)  void Log(const char *fmt, ...)
{
	strcpy(g_szWorkingDirectory, getMeDirectory().c_str());

	if (!g_szWorkingDirectory) return;

	SYSTEMTIME	time;
	va_list		ap;

	if (g_flLog == NULL)
	{
		char	filename[512];
		_snprintf(filename, sizeof(filename), "%s\\%s", g_szWorkingDirectory, "NetworkCore.log");

		g_flLog = fopen(filename, "w");
		if (g_flLog == NULL)
			return;
	}

	GetLocalTime(&time);
	fprintf(g_flLog, "[%02d:%02d:%02d.%03d] ", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);

	va_start(ap, fmt);
	vfprintf(g_flLog, fmt, ap);
	va_end(ap);
	fprintf(g_flLog, "\n");
	fflush(g_flLog);

	if (g_flLogAll == NULL)
	{
		char	filename_all[512];
		_snprintf(filename_all, sizeof(filename_all), "%s\\%s", g_szWorkingDirectory, "NetworkCore_all.log");

		g_flLogAll = fopen(filename_all, "a");
		if (g_flLogAll == NULL)
			return;
	}

	GetLocalTime(&time);
	fprintf(g_flLogAll, "[%02d-%02d-%02d || %02d:%02d:%02d.%03d] ", time.wDay, time.wMonth, time.wYear, time.wHour,
		time.wMinute, time.wSecond, time.wMilliseconds);
	va_start(ap, fmt);
	vfprintf(g_flLogAll, fmt, ap);
	va_end(ap);
	fprintf(g_flLogAll, "\n");
	fflush(g_flLogAll);
}
void cDataBase_client::computePacketToNormalize(std::string paket)
{
	//	тут будут пропарсеная инфа
	std::shared_ptr<std::list <double>> sharedLIst;						//	тут объявления указателя
	sharedLIst = std::make_shared<std::list <double>>();				/* конструктор для типа через умный ptr */

	boost::regex reg("(-+|)\\d+(,\\d+)*");								// умеет получать числа: ( отрицательные ) целые, дробные
	for (boost::sregex_iterator it(paket.begin(), paket.end(), reg);
		it != boost::sregex_iterator(); ++it)
		sharedLIst->push_back(atof((*it).str().c_str()));				// ложим пропарсенные параметры в список

	std::list<double>::iterator it = sharedLIst->begin();				// итератор на начало списка 

	// (int)(*it) = firs number = byHost message;

	it++; // if (iterator!= NULL) iterator = design 

	if (!sharedLIst->empty())											// if список не пуст
	{
		switch (sharedLIst->size()) //int count_prms=sharedLIst->size();// свич по кол-ву аргументов
		{
			// if packet = hostBy? 
			//I WILL PROBABLY USE FOR TRANSFER OF THE CONSTANT LINE OF TYPE PLAYER_ANIM_NAME
		case 1: break;
			//-------------------------------------

		case 2:	break;
			//-------------------------------------

		case 3:	break;
			//-------------------------------------

		case 4:	break;
			//-------------------------------------

		case 5:	break;
			//-------------------------------------

		case 6: // 
			if ((int)(*it) == 33) // 33 это design ServerMarker_ID
			{

			}
			break;
			//-------------------------------------

		default: std::cout << "AHTUNG:" << "\n";  break;

		}
	}
}

//-------------------------------------


сUDPClientGTA::сUDPClientGTA(
	boost::asio::io_service& io_service,
	const std::string& host,
	const std::string& port) :
	io_service_(io_service),
	socket_(io_service, udp::endpoint(udp::v4(), 0))
{
	udp::resolver resolver(io_service_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint_ = *iter;

	Log("%s", VERSION);

	std::cout << "connect to " << host << ":" << port << "\n";

	boost::thread thrAntiKick(&сUDPClientGTA::thereadAntiKick, this);
	thrAntiKick.detach();
	Log("\'сUDPClientGTA thereadAntiKick\' start");


	boost::thread thereadRecov(&сUDPClientGTA::recov, this);
	thereadRecov.detach();
	Log("\'UDPClientGTA thereadRecov\' start");
	

	send("I new сUDPClientGTA ");
}

void	сUDPClientGTA::thereadAntiKick()
{
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::millisec(3000));
		send("0"); // 0 = I online (for antikick)
	}
}
 
void	сUDPClientGTA::send(const std::string& msg) {
	socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
}

void	сUDPClientGTA::recov()
{
	std::cout << "\nсUDPClientGTA::recov\n";
	int i = 0;
	char buff[1024];

	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::millisec(11));
		int bytes = socket_.receive_from(boost::asio::buffer(buff), endpoint_);
		std::string msg(buff, bytes);
		std::cout << "<- " << msg << "\n";
	}
}


//-------------------------------------


UDPClient::~UDPClient()
{
	std::cout << "UDPClient::~UDPClient\n";
	Log("UDPClient::~UDPClient\n");
	socket_.close();
}


UDPClient::UDPClient(
	boost::asio::io_service& io_service,
	const std::string& host,
	const std::string& port,
	//UDPClient *ptrClient,
	int _fakeClientStartEXE
	) : io_service_(io_service), socket_(io_service, udp::endpoint(udp::v4(), 0)), fakeClientStartEXE(_fakeClientStartEXE)
{
	udp::resolver resolver(io_service_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint_ = *iter;
	flag_close = false;

	std::cout << "connect to " << host << ":" << port << "\n";
	Log("connect to \'%s:%s\'", host.c_str(), port.c_str());

	boost::thread thereadRecov(&UDPClient::recov, this);
	thereadRecov.detach();
	Log("\'thereadRecov\' start");


	boost::thread thrAntiKick(&UDPClient::thereadAntiKick, this);
	thrAntiKick.detach();
	Log("\'thereadAntiKick\' start");

	if (fakeClientStartEXE)
	{
		boost::thread thr_send_fake_pos(&UDPClient::thereadFakeGeneratePos, this, _fakeClientStartEXE);
		thr_send_fake_pos.detach();
		Log("\'thereadFakeGeneratePos\' start");
	}

	send("reg me");
	Beep(3200, 400);
}

void	UDPClient::thereadAntiKick()
{
	while (true)
	{
		if (FlagExit()) break;
		std::lock_guard<std::recursive_mutex> locker(_lock);
		boost::this_thread::sleep(boost::posix_time::millisec(2700));
		send("0"); // 0 = I online (for antikick)
	}
}

void	UDPClient::thereadFakeGeneratePos(int design)
{
	int i = 0;
	while (true)
	{
		std::lock_guard<std::recursive_mutex> locker(_lock);
		if (FlagExit()) break;

		char buf[513];

		switch (design)
		{
		case 1:
		{	//	generate bigBang
			sprintf_s(buf, sizeof(buf), "%f %d %d.%d %d.%d %d.%d %d.%d paket-%d",
				66.0, 10, rand() % 6, 666, rand() % 100, 1, rand() % 100, 2, rand() % 20, 3, i);
			std::string PACKED = buf;
			std::cout << "thereadFakeGeneratePos " << PACKED << "\n";
			++i;
			send(PACKED);
			boost::this_thread::sleep(boost::posix_time::millisec(4500));
			break;
		}

		case 2: // fake pos
		{
			// design, x, y, z, angle, speed
			sprintf_s(buf, sizeof(buf), "%d %d.%d %d.%d %d.%d %d.%d %d.%d",
				/*design*/	65,
				/*x*/		rand() % 100, 1,
				/*y*/		rand() % 100, 1,
				/*z*/		rand() % 100, 1,
				/*angle*/	rand() % 360, 1,
				/*speed*/	rand() % 6, 1

				);
			std::string PACKED = buf;
			++i;
			send(PACKED);
			boost::this_thread::sleep(boost::posix_time::millisec(4500));
			break;
		}
		default:
			std::cout << "hz: " << design << "\n";
			break;
		}
	}
}

std::string UDPClient::getMsg()
{
	return msg;
}

void	UDPClient::setMsg(std::string _msg)
{
	msg = _msg;
}

void	UDPClient::recov()
{
	std::cout << "\nUDPClient::recov\n";
	int i = 0;
	char buff[1024];

	while (true)
	{
		//std::lock_guard<std::recursive_mutex> locker(_lock);
		//if (FlagExit()) break;

		boost::this_thread::sleep(boost::posix_time::millisec(11));
		int bytes = socket_.receive_from(boost::asio::buffer(buff), endpoint_);
		std::string msg(buff, bytes);
		setMsg(msg);
		std::cout << "<- " << msg << "\n";
		startDecompose();
	}
}

bool	UDPClient::FlagExit()
{
	std::lock_guard<std::recursive_mutex> locker(_lock);
	if (flag_close) return true;
	return false;
}

void	UDPClient::setFlagCloseTheread()
{
	std::lock_guard<std::recursive_mutex> locker(_lock);
	flag_close = true;
}

void	UDPClient::send(const std::string& msg) {
	if (!flag_close)
	{
		socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
	}
	else
	{
		Log("Error send not connect");
	}
}

void	UDPClient::startDecompose()
{
	if (isValid_Count_prms_numeral_to_srs_paket(2))
	{
		calculate_regular_parse_packed();
	}
}

bool	UDPClient::isValidCountParmsThisDesponsePaketSetPtrArrForFuncsCall(
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

bool	UDPClient::isValid_Count_prms_numeral_to_srs_paket(int _count)
{
	std::string m_CLEO_paket = getMsg();
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

void	UDPClient::calculate_regular_parse_packed()
{
	std::string m_CLEO_paket = getMsg();
	for (int i = 0; i < m_CLEO_paket.length(); i++)
		if (m_CLEO_paket[i] == '.') m_CLEO_paket[i] = ',';
	setMsg(m_CLEO_paket);

	//-------------------------------------
	//		parse by client
	m_CLEO_paket = getMsg();
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
	//-------------------------------------
	//  parse paket for callback
	while (!stack_Parse_Paket.empty())
	{
		int ArrfuncsCall[3]; // float to int 
		std::string token = stack_Parse_Paket.top();

		//true if token >= 2 tcifry` 
		if (isValidCountParmsThisDesponsePaketSetPtrArrForFuncsCall(token, ArrfuncsCall))
		{
			std::cout << ArrfuncsCall[0] << " <->" << ArrfuncsCall[1] << "\n";

			switch (ArrfuncsCall[1])
			{

			case 66:
				std::cout << "положить взрыв в стек" << "\n";
				GTA_push_Explotion_to_Dot(token);

				//case 65:
				//	std::cout << "положить в стек новые координаты" << "\n";
				//	GTA_push_obj_pos(token);

			default:
				break;
			}

		}
		stack_Parse_Paket.pop();
	}
}

void	UDPClient::GTA_push_Explotion_to_Dot(std::string token)
{
	//std::cout << "CLEO_parse_prms_for_explotion() sourse: " << token << "\n";
	int numberLeksema = 0;
	infoWorld	infoWorld_TempForBox;
	boost::regex reg("(-+|)\\d+(,\\d+)*");
	for (boost::sregex_iterator it(token.begin(), token.end(), reg); it != boost::sregex_iterator(); ++it)
	{
		//			SetColor(Yellow, Black);
		switch (numberLeksema)
		{
		case 1:
			std::cout << " box:  design marker: " << it->str().c_str();
			infoWorld_TempForBox.GtaPackedType = 66.0f; //atoi(it->str().c_str());
			break;
		case 2:
			std::cout << " box: type explitions: " << it->str().c_str();
			infoWorld_TempForBox.k1 = (float)atof(it->str().c_str());//radius = (float)atof(it->str().c_str());
			break;
		case 3:
			std::cout << " box: x: " << it->str().c_str();
			infoWorld_TempForBox.k2 = (float)atof(it->str().c_str());
			break;
		case 4:
			std::cout << " box: у: " << it->str().c_str();
			infoWorld_TempForBox.k3 = (float)atof(it->str().c_str());
			break;
		case 5:
			std::cout << " box: z: " << it->str().c_str();
			infoWorld_TempForBox.k4 = (float)atof(it->str().c_str());
			break;
		default:
			std::cout << "\t чет сломалось: " << it->str().c_str() << "\n";
			break;
		}
		++numberLeksema;
	}

	std::cout << "\n";
	m_InfoWorldStack.push(infoWorld_TempForBox);
}

bool	UDPClient::CLEO_stack_not_Emty()
{
	if (!m_InfoWorldStack.empty()) return true;
	return false;
}

void	UDPClient::GTA_push_obj_pos(std::string token)
{
	int numberLeksema = 0;
	infoWorld	infoWorld_TempForBox;
	boost::regex reg("(-+|)\\d+(,\\d+)*");
	for (boost::sregex_iterator it(token.begin(), token.end(), reg); it != boost::sregex_iterator(); ++it)
	{
		switch (numberLeksema)
		{
		case 1:
			infoWorld_TempForBox.GtaPackedType = 65.0f; //  atof(it->str().c_str());
			break;
		case 2:
			infoWorld_TempForBox.k1 = atof(it->str().c_str());
			break;
		case 3:
			infoWorld_TempForBox.k2 = atof(it->str().c_str());
			break;
		case 4:
			infoWorld_TempForBox.k3 = atof(it->str().c_str());
			break;
		case 5:
			infoWorld_TempForBox.k4 = atof(it->str().c_str());
			break;
		default:
			std::cout << "неизвестность: i=" << numberLeksema << "\t value: " << it->str().c_str() << "\n";
			break;
		}
		++numberLeksema;
	}
	std::cout << "\n";
	m_InfoWorldStack.push(infoWorld_TempForBox);
}

void	UDPClient::GTA_read_stack(float* idEmtyStack, float* k1, float* k2, float* k3,
	float* k4, float* k5, float* k6, float* k7, float* k8)
{
	*idEmtyStack = -1;
	if ((*ptrClient).CLEO_stack_not_Emty())
	{
		*idEmtyStack = m_InfoWorldStack.top().GtaPackedType;
		*k1 = m_InfoWorldStack.top().k1;
		*k2 = m_InfoWorldStack.top().k2;
		*k3 = m_InfoWorldStack.top().k3;
		*k4 = m_InfoWorldStack.top().k4;
		*k5 = m_InfoWorldStack.top().k5;
		*k6 = m_InfoWorldStack.top().k6;
		*k7 = m_InfoWorldStack.top().k7;
		*k8 = m_InfoWorldStack.top().k8;

		m_InfoWorldStack.pop();
	}

}

extern "C" __declspec(dllexport) void	GTA_read_stack(float* idEmtyStack, float* k1, float* k2, float* k3,
	float* k4, float* k5, float* k6, float* k7, float* k8)
{
	*idEmtyStack = -1.13;
	*k1 = 1.13;
	*k2 = 2.13;
	*k3 = 3.13;
	*k4 = 4.13;
	*k5 = 5.13;
	*k6 = 6.13;
	*k7 = 7.13;
	*k8 = 8.13;
	(*ptrClient).GTA_read_stack(idEmtyStack, k1, k2, k3, k4, k5, k6, k7, k8);
}

extern "C" __declspec(dllexport) void	CLEO_connect_to_server_fon()
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)connect_to_server, NULL, 0, 0);
	Log("start \'CLEO_connect_to_server_fon\'");
}

extern "C" __declspec(dllexport) void	connect_to_server(int fakeClientStartEXE)
{
	boost::asio::io_service io_service;
	try
	{
		std::string ip = getFindFileToken("KRACHIK_setting.txt", "ip");
		std::string port = getFindFileToken("KRACHIK_setting.txt", "port");

		UDPClient  client(io_service, ip, port, fakeClientStartEXE);
		ptrClient = &client;
		Log("pointer ptrClient  = 0x%x", ptrClient);

		while (true)
		{
			boost::this_thread::sleep(boost::posix_time::seconds(13));
		}
		(*ptrClient).setFlagCloseTheread();
	}
	catch (std::exception& e){ std::cerr << e.what() << std::endl; }
}


extern "C" __declspec(dllexport) void	Public_CLEO_connect_to_server_fon_NEW_September() // CALL :A007
{
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)connect_to_server_private_GTA, NULL, 0, 0);
	Log("start \'CLEO_connect_to_server_fon_NEW_September\'");
}
void	connect_to_server_private_GTA()
{
	boost::asio::io_service io_service;
	try
	{
		std::string ip = getFindFileToken("KRACHIK_setting.txt", "ip");
		std::string port = getFindFileToken("KRACHIK_setting.txt", "port");

		сUDPClientGTA player(io_service, ip, port);
		ptrClientGTA = &player;

		while (true)
		{
			boost::this_thread::sleep(boost::posix_time::seconds(1));
		}

	}
	catch (std::exception& e){ std::cerr << e.what() << std::endl; }
}



//boost::this_thread::sleep(boost::posix_time::millisec(7000));

extern "C" __declspec(dllexport) void	Public_send_to_serv(std::string msg)
{
	Log("\'Public_send_to_serv\' %s", msg.c_str());
	Log("\'Public_send_to_serv\' pointer ptrClient  = 0x%x", ptrClient);
	(*ptrClient).send(msg);
}

extern "C" __declspec(dllexport) void	Public_send_char_to_serv(char* charmsg)
{
	/*Log("\'Public_send_char_to_serv\' %s", charmsg);
	Log("\'Public_send_char_to_serv\' pointer ptrClient  = 0x%x", ptrClient);*/
	(*ptrClient).send(charmsg);
}

extern "C" __declspec(dllexport) void	Public_send_char_to_serv_NEW_September(char* charmsg)
{
	(*ptrClientGTA).send(charmsg);
}

extern "C" __declspec(dllexport) void	printVersionProg()
{
	std::cout << VERSION << "\n";
}

std::string  getMeDirectory()
{
	char buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer), buffer);
	std::string str(buffer);
	return str;
}

std::string getFindFileToken(std::string fileName, std::string findToken)
{
	std::string line = getMeDirectory() + "\\" + fileName;
	std::ifstream myfile(line);
	line = "";
	size_t pos;
	bool flag = false;
	if (myfile.is_open())
	{
		while (myfile.good())
		{
			getline(myfile, line);
			pos = line.find(findToken);
			if (pos != std::string::npos){
				flag = true;
				pos += findToken.length();
				break;
			}
		}
		myfile.close();
	}
	else
		Log("File \'%s\' not found ", fileName.c_str());


	if (flag){
		std::string rez(line, pos + 1, line.length());
		return rez;
	}
	else
		Log("token \'%s\' not found ", findToken.c_str());

	return "NULL";
}


cVeh::cVeh()
{
	Log("cVeh()");
}
cVeh::~cVeh()
{
	Log("~cVeh()");
}

void cVeh::printHandleCar()
{

}
void cVeh::InfoCarNew(int key, int GTA_HANDLE_CAR, int model, int heal, float x, float y, float z, float speed, int color_1, int color_2)
{
	auto it = std::find_if(m_veh_Handle_Map.begin(), m_veh_Handle_Map.end(),
		[&key](const std::pair<int, struct Car> &p)
	{
		return p.first == key;
	});

	if (it != m_veh_Handle_Map.end())
	{	// new info by client	
		//(*it).second.last_ping = microsec_clock::local_time(); // update Ping
	}
	else
	{// register 
		Car tempBox;
		tempBox.GTA_HANDLE_CAR = GTA_HANDLE_CAR;
		tempBox.model = model;
		tempBox.heal = heal;
		tempBox.pos[0] = x;
		tempBox.pos[1] = y;
		tempBox.pos[2] = z;
		tempBox.speed = 11.0f;
		tempBox.color_1 = color_1;
		tempBox.color_2 = color_2;

		m_veh_Handle_Map.insert(std::pair<int, struct Car>(key, tempBox));
	}
}
//std::map	<int, struct ClienInfo>		m_veh_Handle_Map;

void Public_InfoMapCarNew(int key, int GTA_HANDLE_CAR, int model, int heal,
	float x, float y, float z, float speed, int color_1, int color_2)
{
	Beep(333, 444);
}
