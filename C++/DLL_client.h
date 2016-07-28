 
#include <iostream> 
#include <stdlib.h>
#include <ctime>

#include <boost/array.hpp>
#include <boost/asio.hpp>

#include <boost/thread.hpp>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/regex.hpp>

#include <vector>
#include <stack>

#include <windows.h>

#define VERSION "build 34, version 0.0.1"

using namespace boost::asio; // for buffer ?
using namespace boost::posix_time;	//for millisec
using boost::asio::ip::udp;

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
  
//		class		class		class		class		class
class UDPClientTEST
{
public:

	UDPClientTEST(boost::asio::io_service& io_service, const std::string& host, const std::string& port);
	~UDPClientTEST();
	void			send(const std::string& msg);
	std::string		recovdata();
	struct			Explotion{ int type, serverTic; float x, y, z, radius; }; 
	Explotion		m_struct_bangTmp;

	void			CLEO_Analiz_paket_and_push_prms_to_struct();
	void			printPaket();
	void			CLEO_popStruct(float *type, float *x, float *y, float *z);
	bool			CLEO_isEmptyExplotion();
	void			CLEO_parse_prms_for_explotion(std::string token);
	void			CLEO_replaceTochkaHazapiataia();
	void			CLEO_parse_pak_for_callback(std::stack <std::string, std::vector <std::string> > stack_Parse_Paket);
	std::stack		<struct Explotion, std::vector <struct Explotion> >		m_stackPakExplotin;
	std::string		getPaketStr();
	void			setPaketStr(std::string val);

private:
	bool			CLEO_isValid_Count_prms_numeral_to_srs_paket(int _count);
	void			parsePaketByClient();
	void			parseidentifier(std::stack <std::string, std::vector <std::string> > stack_Parse_Paket);
	
	bool			isValidCountParmsThisDesponsePaketSetPtrArrForFuncsCall(
		std::string desponsePaket, int *arr);

	
	boost::asio::io_service&		io_service_;
	udp::socket						socket_;
	udp::endpoint					endpoint_;

	std::string						m_CLEO_paket;
	char							buff[1024];
};
//-------------------------------------

//		public 		public 		public 		public 		public 		public 
//
extern "C" __declspec(dllexport)	bool	EXE_Client_Connect_InitializeDLL(
		boost::asio::io_service& io_service, std::string ip, std::string port);

extern "C" __declspec(dllexport)	int		EXE_test_funcs(int val);
extern "C" __declspec(dllexport)	void	printVersionProg();
extern "C" __declspec(dllexport)	void	CLEO_public_connect_to_serv();
extern "C" __declspec(dllexport)	void	PUBLIC_close_socket();
extern "C" __declspec(dllexport)	void 	CLEO_public_call_func(float *number);
extern "C" __declspec(dllexport)	void	CLEO_public_get_prms_using_ptr(float *x, float *y, float *z);
extern "C" __declspec(dllexport)	void	PUBLIC_CLEO_EXPLOTION();
extern "C" __declspec(dllexport)	void	PUBLIC_CLEO_NOP();

extern "C" __declspec(dllexport)
		void CLEO_read_stack(float *type, float *x, float *y, float *z);

extern "C" __declspec(dllexport)	void	CLEO_public_send(char *paket);
extern "C" __declspec(dllexport)	void	PUBLIC_send_non_kick_space(int sleep);




// =====	private		private		private		private		================
void	CLEO_private_theread_local_conncect();
void	CLEO_private_connect_on_read(
				boost::asio::io_service& io_service, std::string ip, std::string port);
void	CLEO_theread_local_conncect(); 
void	thread_EXE_recov(UDPClientTEST* currClient);
void	thread_EXE_send(UDPClientTEST* currClient, int timeOut);
void SetColor(int text, int background);
void SetColor(int text, ConsoleColor background);
//===========================================================================










