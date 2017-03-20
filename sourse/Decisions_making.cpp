//#pragma once 
#include "Decisions_making.h"

#include <windows.h>
#include <iostream> 

#include "package_type.h"
#include "ELocal_command.h"

#include <utility>// for std::move ? 

c_recov_Decisions::c_recov_Decisions()
{
	Log("[c_recov_Decisions::c_recov_Decisions] create");

	m_VehManager = std::make_shared<c_VehicleManager>();

	m_packageManager = std::make_shared<c_PackageManager>();

	m_CLEO_Manager = std::make_shared<c_CLEO_commandManager>();
}


c_recov_Decisions::~c_recov_Decisions()
{
	// std::cout << "[c_recov_Decisions::~c_recov_Decisions] destroy" << "\n";
	Log("[c_recov_Decisions::~c_recov_Decisions] destroy");
}

void c_recov_Decisions::new_parsing_package_2017(std::string package)
{
	assert(package.length() >= 8);	// ?

	if (package.length() < 8)
		return;


	// init Header
	char headr[4];

	for (int i = 0; i < 4; i++)
		headr[i] = package[i];

	std::string HeadPackage = "1234";

	for (int i = 0; i < 4; i++)
		HeadPackage[i] = headr[i];

	std::stringstream byteArr(HeadPackage);

	float design = -1;

	byteArr.read((char*)&design, 4);
	// end init header;

	if ((int)design == (int)eHeaderPackage::RPC_PLAYER_ACTOR_POSSITIONS)
	{
		MessageBoxA(0, "not reliz x089", "not reliz x089", 0);
	}
	 
	if ((int)design == (int)eHeaderPackage::RPC_SERVER_VEHICLE_CAR_POSSITIONS)
	{
		assert(package.length() == 44);

		// 1 reg server vehivle
		// 2 find server vehicle to server vehicle map
		// 2.1 if find false -> set flag SPAWN
		// 2.2 if find true -> set flag NEW_POSSITIONS

		if (package.length() != 44) // 36 + 8 
		{
			Log("AHTUNG [package.length() != 36] (int)eHeaderPackage::RPC_SERVER_VEHICLE_CAR_POSSITIONS ");
			return;
		}

		// unBox package
		std::shared_ptr	<c_CmmandVehiclePossitions> VehiclePackage = std::make_shared<c_CmmandVehiclePossitions>(package);

		c_ServerVehicle servCar = m_VehManager->createServerVehicle(VehiclePackage);
 
		bool isServVehicleReg = m_VehManager->findServerVehicleMap(servCar);

		if (isServVehicleReg)
		{
			// refresh possitions
			VehiclePackage->setDesign(static_cast <float>(EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS));
			Log("void c_recov_Decisions::new_parsing_package_2017(std::string package) -> (float)EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS");
		}
		else
		{
			VehiclePackage->setDesign(static_cast <float> (EDESIGN_COMMAND::CMD_SPAWN_VEHICLE));
			Log("void c_recov_Decisions::new_parsing_package_2017(std::string package) -> (float)EDESIGN_COMMAND::CMD_SPAWN_VEHICLE");
		}
		 
		m_packageManager->add(VehiclePackage);

		// refresh possition or reg server vehicle
		m_VehManager->refreshServerMap(servCar);
	}
}
  
// 19.03.2017 00:59
//void c_recov_Decisions::isCLEO_ScriptSpawnedVehicle(float fModel, float fServID, float fX,
//	float fY, float fZ, float fAngle, float fSpeed, float fHeandle)
//{
//	c_ClientVehicle clientVeh(fHeandle, fServID, fModel, fX, fY, fZ);
//
//	m_VehManager->refreshClientMap(clientVeh);
//
//	// [DEBUG]
//	Log("[c_recov_Decisions::isCLEO_ScriptSpawnedVehicle] c_ClientVehicle , c_ServerVehicle, m_VehPoolManager init");
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fModel);
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fSpeed);
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fX);
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fY);
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fZ);
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fAngle);
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fSpeed);
//	Log("[void isCLEO_ScriptSpawnedVehicle] %f", fHeandle);
//}

void c_recov_Decisions::CLEO_DIM_initsializator(float* A1, float* A2, float* A3, float* A4, float* A5
	, float* A6, float* A7, float * A8, float * A9, float * A10)
{
	std::cout << "[void c_recov_Decisions::CLEO_DIM_initsializator]" << "\n";
	Log("[void c_recov_Decisions::CLEO_DIM_initsializator]");

	m_packageManager->init(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
}

void c_recov_Decisions::computeGameWord()
{
	if (!m_CLEO_Manager->empty())
	{
		c_CLEO_COMMAND_DATA prms = m_CLEO_Manager->getAndPopCLEOPrms();

		int design = (int)prms.m_fA1;

#if 1
		if (design == static_cast <int> (eLOCAL_CLIENT_CMD::REG_CAR_HEANDLE))
		{

			c_ClientVehicle clientVeh(
				prms.m_iPrms1,	// fHeandle
				prms.m_fA3,	// serv id
				prms.m_fA2, // model
				prms.m_fA4,	// X
				prms.m_fA5,	// Y
				prms.m_fA6,	// Z

				prms.m_fA7,	// color 
				prms.m_fA8	// color 
				);


			// [debug] cleo script
			Log("[c_recov_Decisions::computeGameWord()] eLOCAL_CLIENT_CMD::REG_CAR_HEANDLE");
			clientVeh.writeDebugLogDim();

			m_VehManager->refreshClientMap(clientVeh);

			m_VehManager->m_VehPoolManager->register_By_key_GameObjectHeandle(clientVeh);
		}
#endif

#if 1
		if (design == static_cast <int> (eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL))
		{
			 
			if (!m_VehManager->m_VehPoolManager->empty())
			{
				c_ClientVehicle veh = m_VehManager->m_VehPoolManager->getObjectPool();

				m_VehManager->m_VehPoolManager->incIteratorPool();

				std::shared_ptr	<c_CommandGetHeandleVehicle> VehiclePackage = std::make_shared<c_CommandGetHeandleVehicle>(veh);
				 
				VehiclePackage->setDesign(static_cast <float> (eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL));

				m_packageManager->add(VehiclePackage);
			}

		}
#endif

#if 1
		/*if (design == static_cast <int> (eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR))
		{
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");
		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR]");


		c_ClientVehicle clientVeh(
		666,//prms.m_iPrms1,
		prms.m_fA3,	// serv id
		prms.m_fA2, // model
		prms.m_fA4,
		prms.m_fA5,
		prms.m_fA6
		);

		// [debug] cleo script
		clientVeh.writeDebugLogDim();

		if (m_VehManager->compareVehicleByModel(clientVeh))
		{

		std::shared_ptr	<c_CommandGetHeandleVehicle> VehiclePackage = std::make_shared<c_CommandGetHeandleVehicle>(clientVeh);

		VehiclePackage->setDesign(static_cast <float> (eLOCAL_CLIENT_CMD::GOOD_HEANDLE_CAR));

		m_packageManager->add(VehiclePackage);

		Log("[eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR] Yeah!!!!!!!!!!");
		}
		else
		{
		Log("AHTUNG [eLOCAL_CLIENT_CMD::COMPARE_HEANDLE_CAR] bad prms");

		}
		}
		*/
#endif

	}

}


