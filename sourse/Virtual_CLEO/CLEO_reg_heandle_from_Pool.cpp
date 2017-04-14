#include "CLEO_reg_heandle_from_Pool.h" 

#include "..//package_type.h"



TEST_SPAWN_AND_REG_CAR_DATABASE::TEST_SPAWN_AND_REG_CAR_DATABASE()
{

}

TEST_SPAWN_AND_REG_CAR_DATABASE::TEST_SPAWN_AND_REG_CAR_DATABASE(
	float A1, float A2, float A3, float A4, float A5, float A6, float A7, float A8, float A9, float A10)
	: CLEO_machine(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)
{
	boost::this_thread::sleep(boost::posix_time::millisec(118));
	srand(time(NULL));
}


void TEST_SPAWN_AND_REG_CAR_DATABASE::regCarbyheandle()
{
	Call_00A5_send_to_DLL();
}

 
//--------------------------------------------------


#if 0
void TEST_CLEO_REQUET_GET_HEANDLE_OF_PO0L::Get_Heandle_of_Pool()
{
	srand(time(0));
	 
	while (true)
	{
		float design = static_cast<float>(eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL);

  		initCleoDim(
			design
			, -1L
			, -1L
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

		boost::this_thread::sleep(boost::posix_time::millisec(101));
	}  
}

void TEST_CLEO_REQUET_GET_HEANDLE_OF_PO0L::START_Thr_Get_Heandle_of_Pool()
{
	boost::thread thrGetCarHeandle = boost::thread(&TEST_CLEO_REQUET_GET_HEANDLE_OF_PO0L::Get_Heandle_of_Pool, this);
	thrGetCarHeandle.detach();
}
#endif 
//--------------------------------------------------































//void TEST_SPAWN_AND_REG_CAR_DATABASE::reg_car_by_game_sa_object_heandle()
//{
//	// dynamic value
//
//	int iPrms_1 = 177100 + rand() % 1000;
//	int iPrms_2 = -1L;
//
//	initCleoDim(
//		eLOCAL_CLIENT_CMD::REG_CAR_HEANDLE
//		, iPrms_1	// iHeandleCarMemory
//		, iPrms_2	//	null not use
//		, *m_ptr2	//	serv Id
//		, *m_ptr3	//  model
//		, *m_ptr4	//  x
//		, *m_ptr5	//	y
//		, *m_ptr6	//	z
//		, *m_ptr7
//		, *m_ptr8
//		, *m_ptr9
//		, *m_ptr10
//		);	// not use	
//	Call_00A5_send_to_DLL();
//}
   
//class TEST_SPAWN_AND_REG_CAR_DATABASE : public CLEO_machine
//{
//public:
//	TEST_SPAWN_AND_REG_CAR_DATABASE( float A1, float A2, float A3, float A4, float A5, float A6, float A7, float A8, float A9, float A10)
//		: CLEO_machine(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10)
//	{
//		boost::this_thread::sleep(boost::posix_time::millisec(118));
//		srand(time(NULL));
//	}
//
//	void reg_car_by_serv_id()
//	{
//		boost::this_thread::sleep(boost::posix_time::millisec(111));
//		initCleoDim(
//			LOCAL_REG_CAR_HEANDLE // design
//			, 170023L + rand() % 1000 		// iHeandleCarMemory
//			, -1L		//	null not use
//			, *m_ptr2	//	serv Id
//			, *m_ptr3	//  model
//			, *m_ptr4	//  x
//			, *m_ptr5	//	y
//			, *m_ptr6	//	z
//			, -1.0f);	// not use	
//		Call_00A5_send_to_DLL();
//	}
//
//	void reg_car_by_game_sa_object_heandle()
//	{
//		boost::this_thread::sleep(boost::posix_time::millisec(111));
//		initCleoDim(
//			4.0f		// design
//			, 170023L + rand() % 1000 // iHeandleCarMemory
//			, -1L		//	null not use
//			, *m_ptr2	//	serv Id
//			, *m_ptr3	//  model
//			, *m_ptr4	//  x
//			, *m_ptr5	//	y
//			, *m_ptr6	//	z
//			, -1.0f);	// not use	
//		Call_00A5_send_to_DLL();
//	}
//};
//
//class TEST_ADMIN_TOOLS : public CLEO_machine
//{
//public:
//
//	void GetCarHeandleByLocal_dataBase()
//	{
//		// Get Car Heandle
//		initCleoDim(5.0f, -1L, -1L, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
//		Call_00A5_send_to_DLL();	// and send to DLL
//	}
//
//	void send_andmin_char_cmd()
//	{
//		initCleoDim(-18.0f, -1L, -1L, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
//		Call_00A5_send_to_DLL();	// and send to DLL
//	}
//
//	void print_DatabaseCar()
//	{
//		// get Info Car_Sapwn 
//		initCleoDim(-6.0f, -1L, -1L, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
//		Call_00A5_send_to_DLL();	// and send to DLL
//	}
//};
//
//class TEST_GET_CAR_INFO_for_SPAWN : public CLEO_machine
//{
//public:
//	TEST_GET_CAR_INFO_for_SPAWN()
//	{
//		// std::cout << "\n[TEST_GET_CAR_INFO_for_SPAWN] create!" << "\n";
//		srand(time(NULL));
//	}
//
//	~TEST_GET_CAR_INFO_for_SPAWN()
//	{
//		// std::cout << "\n[TEST_GET_CAR_INFO_for_SPAWN] destroy!" << "\n";
//	}
//
//	void request_car_spawn()
//	{
//		// get Info Car_Sapwn 
//		initCleoDim((float)RPC_CAR_SPAWN
//			, -1L						// not use
//			, -1L						// not use
//			, (rand() % 100 + 411.0f)	// car model + rand  
//			, (rand() % 10 + 11.1f)		// posX + rand
//			, (rand() % 10 + 12.2f)		// posY + rand
//			, 13.05f					// posZ Const
//			, 45.45f					// angle
//			, 10.0f);					// speed
//
//		Call_00A5_send_to_DLL();	// and send to server
//	}
//
//
//	void potential_place_to_spawn_car()
//	{
//		srand(time(0));
//		float m_step_x = 0.3, m_step_y = 0.57;
//
//		float x = rand() % 10, y = rand() % 10, z = 10.1;
//		float angle = 45.5, speed = 10.0, model = 411;
//		while (true)
//		{
//			x += m_step_x;	y += m_step_y;
//			boost::this_thread::sleep(boost::posix_time::millisec(3311));
//			initCleoDim(2.0f, 1L, 1L, model, x, y, z, angle, speed); 
//			Call_00A5_send_to_DLL();
//		}
//	}
//
//	void start_Thr_generate_spawn_pos_car()
//	{
//		boost::thread thrSpawnPosSender = boost::thread(&TEST_GET_CAR_INFO_for_SPAWN::potential_place_to_spawn_car, this);
//		thrSpawnPosSender.detach();
//	}
//
//};
//
//class TEST_CLEO_SELF_POSITIONS_SENDER : public CLEO_machine
//{
//public:
//	void ThrInit_Dim_for_send_Pos_2()
//	{
//		srand(time(0));
//		float m_step_x = 0.6, m_step_y = 1.17;
//		float x = rand() % 10, y = rand() % 10, z = 10.1;
//		float fInterior = 1.0f;
//		float fSpeed = 20.0f;
//		while (true)
//		{
//			x += m_step_x;	y += m_step_y;
//			// std::cout << "[TEST_CLEO_SELF_POSITIONS_SENDER]" << "\n";
//
//			//call sendSelfPositions(float design, float interior, float x, float y, float z, float speed);
//			initCleoDim((float)RPC_PLAYER_ACTOR_POSSITIONS, -1L, -1L, x, y, z, fInterior, fSpeed, -1);
//			Call_00A5_send_to_DLL();
//			boost::this_thread::sleep(boost::posix_time::millisec(17711));
//		}
//	}
//
//	void startThr_Self_Pos()
//	{
//		boost::thread thrPosSender = boost::thread(&TEST_CLEO_SELF_POSITIONS_SENDER::ThrInit_Dim_for_send_Pos_2, this);
//		thrPosSender.detach();
//	}
//};
//
////TEST_ADMIN_TOOLS				admin_tools_test;
//TEST_GET_CAR_INFO_for_SPAWN		test_get_car_info_FOR_spawn;
//TEST_CLEO_connect_to_server		join_to_serv;
////TEST_CLEO_Reciver				recovScript;
//TEST_CLEO_SELF_POSITIONS_SENDER test_cleo_self_positions_sender;
//
//void INIT_NETWORK_FUNCS()
//{
//	// std::cout << "[TEST_INIT_NETWORK_FUNCS]" << "\n";
//	// connect to serv
//	join_to_serv.connect();
//	// start script recov 
//	recovScript.start();
//}
//
//void TEST_request_car_spawn()
//{
//	// send fake request car spawn
//	test_get_car_info_FOR_spawn.start_Thr_generate_spawn_pos_car();
//	boost::this_thread::sleep(boost::posix_time::millisec(1000));
//}
//
//	 
////void TEST_SEND_ADMINT_CMD_FOR_DATABASE_PLAYER_GAME_INFO()
////{
////	// std::cout << "start send my positions" << "\n";
////	// send print database;
////	//admin_tools_test.send_andmin_char_cmd();
////}
//
//void TEST_SEND_SELF_POS()
//{
//	// std::cout << "[TEST_SEND_SELF_POS]" << "\n";
//	test_cleo_self_positions_sender.startThr_Self_Pos();
//}
//
//int main(int argc, char *argv[])
//{
//	setlocale(LC_ALL, "Russian");
//
//	INIT_NETWORK_FUNCS();
//	TEST_SEND_SELF_POS();
//	TEST_request_car_spawn();
//
//	/*
//	TEST_CAR_MANIPULATION();
//	*/
//
//
//	std::cin.get();
//	return 0;
//}
