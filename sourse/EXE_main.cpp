#pragma once 

#define Hello "this is my test client 0.0.0.3"

#include "Virtual_CLEO\CLEO_send_request_car_spawn.h"
#include "Virtual_CLEO\CLEO_reg_heandle_from_Pool.h"
#include "Virtual_CLEO\CLEO_sender_self_pos.h"
#include "Virtual_CLEO\CLEO_connect.h"
#include "Virtual_CLEO\CLEO_reciver.h"

#include "VehicleManager.h"



TEST_CLEO_SELF_POSITIONS_SENDER			SELF_POS_SENDER;
TEST_GET_CAR_INFO_for_SPAWN				test_get_car_info_FOR_spawn;
TEST_CLEO_connect_to_server				cleo_connect;
TEST_CLEO_Reciver						CLEO_RECIVER_SCRIPT;
TEST_CLEO_REQUET_GET_HEANDLE_OF_PO0L	send_Get_Heandle_Vehicle;

void TEST_CLEO_CONNECT()
{
	std::cout << "EXE connect start" << "\n";
	cleo_connect.connect();
}


void TEST_CLEO_RECIVER()
{
	CLEO_RECIVER_SCRIPT.start();
}

void TEST_SENDER_SELF_POSSITIONS()
{
	SELF_POS_SENDER.startThr_Self_Pos();
}

void TEST_REQUEST_CAR_SPAWN()
{
	test_get_car_info_FOR_spawn.request_car_spawn(); 
}
	



void Test_Get_Heandle_Car()
{
	send_Get_Heandle_Vehicle.START_Thr_Get_Heandle_of_Pool ();
}
							  


#if 0 
std::shared_ptr	<c_VehicleManager> VehManager = std::make_shared<c_VehicleManager>();
void TEST_STL_DLL_CONTAINER()
{
	std::cout << "[TEST_STL_DLL_CONTAINER]" << "\n";

	int countVehicle = 10;

	for (int i = 0; i < countVehicle; i++)
	{
		float  fServerID = i;
		float fModel = rand() % 100;
		float x = rand() % 100;
		float y = rand() % 100;
		float z = rand() % 100;
		float fAngle = rand() % 100;
		float fSpeed = rand() % 100;

		c_ServerVehicle vehForBox(fServerID, fModel, x, y, z, fAngle, fSpeed);

		VehManager->refreshServerMap(vehForBox);
	}

	std::cout << "count ServerVehicle = " << VehManager->getSizeServerVehicle() << "\n";
}
#endif


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");

	std::cout << "" << Hello << "\n";

#if 1
	TEST_CLEO_CONNECT();

	TEST_SENDER_SELF_POSSITIONS(); 

	boost::this_thread::sleep(boost::posix_time::millisec(1750));

	TEST_REQUEST_CAR_SPAWN();

	TEST_CLEO_RECIVER();
	    
	Test_Get_Heandle_Car(); 
	//MessageBoxA(0, "void main", "", 0);

#endif
	  

	system("pause");

	return 0;
}

