#include "input_output_cleo_prms.h"


#include <fstream>

#include "MyUtiles.h"
 
static std::shared_ptr<GameCore> glMyCLEO_Core;
 
void Init_UDP_Client()
{
	Log("Build 13.04.2017 ");



	//std::string ip("127.0.0.1");	//getFindFileToken("KRACHIK_setting.txt", "ip");			
	//std::string port("7778");		//getFindFileToken("KRACHIK_setting.txt", "port");			
	 
	std::string ip = getFindFileToken("KRACHIK_setting.txt", "ip");
	std::string port = getFindFileToken("KRACHIK_setting.txt", "port");
	  
	std::cout << "[InitConnect] ip: " << ip << "\n";
	std::cout << "[InitConnect] port: " << port << "\n";

	Log("[void InitConnect] getFindFileToken ip: %s", ip.c_str());
	Log("[void InitConnect] getFindFileToken port: %s", port.c_str());

	boost::asio::io_service io_service;

	//create Network object
	c_Network_UDP player(io_service, ip, port);

	//init core 
	glMyCLEO_Core = std::make_shared<GameCore>(&player);

	LogFile("sdmlsdfkgnsf");

	Beep(2000, 700);

	// for glMyCLEO_Core not deatch
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::seconds(4));
	}

}

extern "C" __declspec(dllexport) void Init_Client_backgraund_Thr() // CALL :A007
{
	std::cout << "\n\n\n[void Init_Client_backgraund_Thr]" << "\n";
	Log("[void Init_Client_backgraund_Thr]");

	std::thread t1(Init_UDP_Client);
	t1.detach();

	//CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init_UDP_Client, NULL, 0, 0);
}

extern "C" __declspec(dllexport) void Public_InPutDimByCLEO(
	float* A1,
	int iPrms1, int iPrms2,
	float* A2, float* A3, float* A4, float* A5, float* A6, float* A7, float* A8, float* A9, float* A10)
{
	glMyCLEO_Core->INPUT_Dim_ByCLEO(*A1, iPrms1, iPrms2, *A2, *A3, *A4, *A5, *A6, *A7, *A8, *A9, *A10);
}

extern "C" __declspec(dllexport) void Public_OUTPUT_DimByCLEO(
	float* A1, float* A2, float* A3, float* A4, float* A5,
	float* A6, float* A7, float* A8, float* A9, float* A10)
{
	// read stack Box package
	*A1 = 0; *A2 = 0; *A3 = 0; *A4 = 0; *A5 = 0;
	*A6 = 0; *A7 = 0; *A8 = 0; *A9 = 0; *A10 = 0;

	glMyCLEO_Core->m_Design_Maker->CLEO_DIM_initsializator(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);

	if (*A1 != 0 && *A2 != 0 && *A3 != 0)
	{
		Log(" ");
		Log("[extern void Public_OUTPUT_DimByCLEO] 1=%f", *A1);
		Log("[extern void Public_OUTPUT_DimByCLEO] 2=%f", *A2);
		Log("[extern void Public_OUTPUT_DimByCLEO] 3=%f", *A3);
		Log("[extern void Public_OUTPUT_DimByCLEO] 4=%f", *A4);
		Log("[extern void Public_OUTPUT_DimByCLEO] 5=%f", *A5);
		Log("[extern void Public_OUTPUT_DimByCLEO] 6=%f", *A6);
		Log("[extern void Public_OUTPUT_DimByCLEO] 7=%f", *A7);
		Log("[extern void Public_OUTPUT_DimByCLEO] 8=%f", *A8);
		Log("[extern void Public_OUTPUT_DimByCLEO] 9=%f", *A9);
		Log("[extern void Public_OUTPUT_DimByCLEO] 10=%f", *A10);
	}
}











