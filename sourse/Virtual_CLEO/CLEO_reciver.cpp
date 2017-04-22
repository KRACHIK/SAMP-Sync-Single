#include "CLEO_reciver.h"
#include "CLEO_reg_heandle_from_Pool.h"
#include "CLEO_send_ClientVehiclePossitions.h"

#include "..\\package_type.h"

#include "..\\ELocal_command.h"

TEST_CLEO_Reciver::TEST_CLEO_Reciver()
{
	m_Test_IheandleVehicle_exe = 1770011;
	std::cout << "\n[TEST_CLEO_Reciver] create!" << "\n";
}

TEST_CLEO_Reciver::~TEST_CLEO_Reciver()
{
	std::cout << "\n[TEST_CLEO_Reciver] Destroy!" << "\n";
}

void TEST_CLEO_Reciver::ThrReciver()
{
	while (true)
	{
		initZeroDim();

		CALL_00A5_read_RECIVER_DLL();

		//	// kak chujoi theread poluchait dostup k dim > ?

		if ((int)*m_ptr1 == static_cast <int> ( EDESIGN_COMMAND::CMD_SPAWN_VEHICLE)) // ? 
		{
			isRecovCommandVehicleSpawn();
		}
		 
		if ((int)*m_ptr1 == static_cast <int> (EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS))
		{
			isRecovCommandVehiclePossitions();
		}
	}

}

void TEST_CLEO_Reciver::start()
{
	boost::thread thrRecov(&TEST_CLEO_Reciver::ThrReciver, this);
	thrRecov.detach();
}

void TEST_CLEO_Reciver::isRecovCommandVehiclePossitions()
{ 
	std::cout << "[CLEO SCRIPT] UPDATE VEHICLE possitions " << "\n";


	CLEO_SEND_CLIENT_POSSITIONS_VEHICLE test_send_new_pos_vehicle;

	test_send_new_pos_vehicle.initCleoDim
		(
		/* fPrms_1 */    (float)(EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS )

		/* iPrms_1 */, -1L
		/* iPrms_2 */, -1L

		/* fPrms_2 */, *m_ptr2 // model ?
		/* fPrms_3 */, 0.0
		/* fPrms_4 */, 0.0
		/* fPrms_5 */, 0.0
		/* fPrms_6 */, 45.0
		/* fPrms_7 */, 10
		/* fPrms_8 */, *m_ptr3 // Server ID ? 
		/* fPrms_9 */, 126//  
		/* fPrms_9 */, 126 //  
		);

	test_send_new_pos_vehicle.Call_00A5_send_to_DLL();

}

void TEST_CLEO_Reciver::isRecovCommandVehicleSpawn()
{
	  
	// CLEO.cs init dim REG_HEANDLE_CAR 

	// fake init (CLEO MACHINE)
	TEST_SPAWN_AND_REG_CAR_DATABASE test_spawn_and_reg_car_database;

	test_spawn_and_reg_car_database.initCleoDim
		(
		/* fPrms_1 */    (float) (eLOCAL_CLIENT_CMD::REG_CAR_HEANDLE)

		/* iPrms_1 */, m_Test_IheandleVehicle_exe //+ rand() % 1000
		/* iPrms_2 */, -1L

		/* fPrms_2 */, *m_ptr2
		/* fPrms_3 */, *m_ptr3
		/* fPrms_4 */, *m_ptr4
		/* fPrms_5 */, *m_ptr5
		/* fPrms_6 */, *m_ptr6
		/* fPrms_7 */, *m_ptr7
		/* fPrms_8 */, *m_ptr8
		/* fPrms_9 */, *m_ptr9	// color_1
		/* fPrms_9 */, *m_ptr10 // color_2
		);

 
	m_Test_IheandleVehicle_exe++;

	test_spawn_and_reg_car_database.Call_00A5_send_to_DLL();

}
