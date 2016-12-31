#ifndef C_CORE_H
#define C_CORE_H

#include "UDP_network.h"
#include "Object_List.h"
#include "MyUtiles.h"

#include <deque>
#include <stack>



class c_recov_Decisions
{
public:
	c_recov_Decisions();
	~c_recov_Decisions();
	  
	void Decisions_Making_call_choice(const std::string& input_Hex_Package);
	 
private:
	void Add_Vehicle_Queue_PRMS(std::stringstream& byteArr, int iDecisions_making);
};


class GameCore
{
public:
	GameCore(c_Network_UDP* network);
	~GameCore();
 
	void NetworkSend(char*);
	void thrReciver();

	void INPUT_Dim_ByCLEO(float A1, float A2, float A3, float A4, float A5, float A6, float A7);
		
	void send_GetServCarID(float design, float ModelCar, float x, float y, float z);

	//void unBoxPackageVehicle(std::stringstream& byteArr, int iDesign);
 	 

public:
	std::shared_ptr	<c_VehicleManager> m_Veh_Manager;

	std::shared_ptr	<c_recov_Decisions> m_Design_Maker;
	 
private:
	c_Network_UDP*	m_network;
	c_MyUtiles		m_utiles;

	unsigned int m_ClientPassport;
};

void Init_UDP_Client();
 
extern "C" __declspec(dllexport) void Init_Client_backgraund_Thr(); // CALL :A007 

extern "C" __declspec(dllexport) void Public_TestDebug(float* fPrms, int* Iprms);

extern "C" __declspec(dllexport) void Public_InPutDimByCLEO(float* A1, float* A2, float* A3, float* A4, float* A5, float* A6, float* A7);
extern "C" __declspec(dllexport) void Public_OUTPUT_DimByCLEO(float* A1, float* A2, float* A3, float* A4, float* A5, float* A6, float* A7);

#endif  






