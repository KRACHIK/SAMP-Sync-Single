#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <stdio.h>
#endif

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <thread>
#include <mutex>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <vector>
#include <stack>
#include <list>
#include <map>

//#include <stdarg.h>
//#include <cstdarg>
//#include <chrono>

#define VERSION "build 38 \tDATE 29.09.2016 " // version 0.0.1

using boost::asio::ip::udp;


class cDataBase_client
{
public:
	void	computePacketToNormalize(std::string);

	// ��� ����� idEmtyStack ?
	void	GTA_read_stack(float* _1, float* _2, float* _3, float* _4,
		float* _5, float* _6, float* _7, float* _8);

	struct ClientMarker
	{
		float x;
		float y;
		float z;
		int ServerMarkerID;
		const int markerID = 62; // gruv street
	};
	 
	private:
		std::list <float>				m_parseValuePacket;
		std::map <int, ClientMarker>	m_CLEO_Marker_map;
	//std::stack <std::string, std::vector <std::string> > stack_Parms_for_CLEO;
};



// NEW 
class �UDPClientGTA
{

public:
	�UDPClientGTA(boost::asio::io_service& io_service,
		const std::string& host,
		const std::string& port);

	//	funcs	while(true)
	void		recov();
	void		thereadAntiKick(); // send I online ("0")
	//	end
	void		send(const std::string& msg);

	std::shared_ptr			<cDataBase_client>			m_DataBasa;
private:

	std::string					host;
	std::string					port;

	boost::asio::io_service&	io_service_;
	udp::socket					socket_;
	udp::endpoint				endpoint_;

};


std::string getFindFileToken(std::string fileName, std::string findToken);
std::string  getMeDirectory();


// FOR use CLEO
void	connect_to_server_private_GTA();
//-----------
extern "C" __declspec(dllexport) 
	void		Public_CLEO_connect_to_server_fon_NEW_September();
//-----------
extern "C" __declspec(dllexport) 
	void		Public_send_char_to_serv_NEW_September(char* msg);
//-----------
extern "C" __declspec(dllexport) 
	void		GTA_read_stack(
			float* idEmtyStack, float* k1, float* k2, float* k3,
			float* k4, float* k5, float* k6, float* k7, float* k8);
//-----------
extern "C" __declspec(dllexport) void printVersionProg();
//-----------
extern "C" __declspec(dllexport)  void Log(const char *fmt, ...);
//-----------


enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};




//extern "C" __declspec(dllexport) void connect_to_server(int i); 
//
//extern "C" __declspec(dllexport) void Public_send_to_serv(std::string msg);
//extern "C" __declspec(dllexport) void Public_send_char_to_serv(char* msg);




//void Public_InfoMapCarNew(int key, int GTA_HANDLE_CAR, int model, int heal,
//		float x, float y, float z, float speed, int color_1, int color_2);

//class UDPClient
//{
//
//public:
//
//	UDPClient::UDPClient(
//		boost::asio::io_service& io_service,
//		const std::string& host,
//		const std::string& port,
//		//	UDPClient *ptrClient,
//		int _fakeClientStartEXE
//		);
//
//	~UDPClient();
//
//	//		funcs	while(true)
//	void			recov();
//	void			thereadAntiKick();
//	//	-------
//
//	bool			FlagExit();
//
//	void			send(const std::string& msg);
//	void			setFlagCloseTheread();
//	std::string		getMsg();
//	void			setMsg(std::string _msg);
//	void			thereadFakeGeneratePos(int design);
//	void			GTA_read_stack(
//		float* idEmtyStack, float* k1, float* k2, float* k3,
//		float* k4, float* k5, float* k6, float* k7, float* k8);
//
//	//			compute
//	//----
//	void startDecompose();
//
//	struct infoWorld
//	{
//
//		float	GtaPackedType;
//		int		GTA_marker_id;
//
//		float	radius;
//		float	speed;
//		float	angle;
//		float	x;
//		float	y;
//		float	z;
//
//		float	k1;
//		float	k2;
//		float	k3;
//		float	k4;
//		float	k5;
//		float	k6;
//		float	k7;
//		float	k8;
//		float	k9;
//	};
//
//	std::stack	<struct infoWorld, std::vector <struct infoWorld> > m_InfoWorldStack;
//
//protected:
//
//	bool	CLEO_stack_not_Emty();
//	bool	isValidCountParmsThisDesponsePaketSetPtrArrForFuncsCall(
//		std::string desponsePaket, int *PtrArr);
//	bool	isValid_Count_prms_numeral_to_srs_paket(int _count);
//	void	calculate_regular_parse_packed();
//	void	GTA_push_obj_pos(std::string token);
//	void	GTA_push_Explotion_to_Dot(std::string token);
//
//	std::string host;
//	std::string port;
//	std::string msg;
//
//	boost::asio::io_service& io_service_;
//	udp::socket socket_;
//	udp::endpoint endpoint_;
//
//	std::recursive_mutex _lock;
//
//	bool flag_close;
//	int  fakeClientStartEXE; // 0=cansel, 1=bigBang, = 2=clientFakePOs
//};
//
//UDPClient *ptrClient;
