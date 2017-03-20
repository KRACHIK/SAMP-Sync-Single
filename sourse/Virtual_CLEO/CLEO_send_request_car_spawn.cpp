#include "CLEO_send_request_car_spawn.h"
#include "../ELocal_command.h"
#include "..//ELocal_command.h"


TEST_GET_CAR_INFO_for_SPAWN::TEST_GET_CAR_INFO_for_SPAWN()
{
	// std::cout << "\n[TEST_GET_CAR_INFO_for_SPAWN] create!" << "\n";
	srand(time(NULL));
}

TEST_GET_CAR_INFO_for_SPAWN::~TEST_GET_CAR_INFO_for_SPAWN()
{
	// std::cout << "\n[TEST_GET_CAR_INFO_for_SPAWN] destroy!" << "\n";
}

void TEST_GET_CAR_INFO_for_SPAWN::request_car_spawn()
{

	// get Info Car_Sapwn 
		 
	initCleoDim(
		static_cast <float> (EDESIGN_COMMAND::CMD_SPAWN_VEHICLE)
		, -1L						//  not use
		, -1L						//  not use
		, 411.0f 					//  car model + rand  
		, 30.0f 					//  posX + rand
		, 30.0f 					//  posY + rand
		, 30.0f						//  posZ Const
		, 45.45f					//  angle
		, 99.99f					//  hz 
		, 178.0f // color_1
		, 179.0f // color_1
		, -1.0f
		);					// speed

  
	Call_00A5_send_to_DLL();	// and send to server
}


void TEST_GET_CAR_INFO_for_SPAWN::potential_place_to_spawn_car()
{
	srand(time(0));
	float m_step_x = 0.3, m_step_y = 0.57;

	float x = rand() % 10, y = rand() % 10, z = 10.1;
	float angle = 45.5, speed = 10.0, model = 411;
	while (true)
	{
		x += m_step_x;	y += m_step_y;
		boost::this_thread::sleep(boost::posix_time::millisec(3311));
		initCleoDim(
			static_cast <float> (EDESIGN_COMMAND::CMD_SPAWN_VEHICLE)
			, 1L, 1L, model, x, y, z, angle, speed
			, -1.0f
			, -1.0f
			, -1.0f
			);
		Call_00A5_send_to_DLL();
	}
}

void TEST_GET_CAR_INFO_for_SPAWN::start_Thr_generate_spawn_pos_car()
{
	boost::thread thrSpawnPosSender = boost::thread(&TEST_GET_CAR_INFO_for_SPAWN::potential_place_to_spawn_car, this);
	thrSpawnPosSender.detach();
}
