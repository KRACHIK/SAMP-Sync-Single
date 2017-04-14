#include "CLEO_send_requestCarOfLocalPool.h"
#include "../ELocal_command.h"


TEST_GET_HEANDLE_VEHICLE_OF_POOL::TEST_GET_HEANDLE_VEHICLE_OF_POOL()
{

	srand(time(NULL));
}

TEST_GET_HEANDLE_VEHICLE_OF_POOL ::~TEST_GET_HEANDLE_VEHICLE_OF_POOL()
{

}
 
void TEST_GET_HEANDLE_VEHICLE_OF_POOL::request_car_of_pool()
{
	initCleoDim(
		static_cast <float> (eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL)
		, -1L						//  not use
		, -1L						//  not use
		, -1.0f
		, -1.0f
		, -1.0f
		, -1.0f
		, -1.0f
		, -1.0f
		, -1.0f
		, -1.0f
		, -1.0f
		);


	Call_00A5_send_to_DLL();	// and send to server
}


void TEST_GET_HEANDLE_VEHICLE_OF_POOL::_Thr_While_True()
{
	while (true)
	{
		boost::this_thread::sleep(boost::posix_time::millisec(311));

		initCleoDim(
			static_cast <float> (eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL)
			, -1L						//  not use
			, -1L						//  not use
			, -1.0f
			, -1.0f
			, -1.0f
			, -1.0f
			, -1.0f
			, -1.0f
			, -1.0f
			, -1.0f
			, -1.0f
			);
		Call_00A5_send_to_DLL();
	}
}

void TEST_GET_HEANDLE_VEHICLE_OF_POOL::start()
{
	boost::thread thrSpawnPosSender = boost::thread(&TEST_GET_HEANDLE_VEHICLE_OF_POOL::_Thr_While_True, this);
	thrSpawnPosSender.detach();
}
