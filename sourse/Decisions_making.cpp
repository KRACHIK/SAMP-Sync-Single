//#pragma once 
#include "Decisions_making.h"

#include <windows.h>
#include <iostream> 

#include "package_type.h"
#include "ELocal_command.h"

#include "GTA_SA_DynamicMemoryManager.h"

#include <utility>// for std::move ? 

c_recov_Decisions::c_recov_Decisions()
{
	Log("[c_recov_Decisions::c_recov_Decisions] create");

	m_VehManager = std::make_shared<c_VehicleManager>();

	m_packageManager = std::make_shared<c_PackageManager>();

	m_CLEO_Manager = std::make_shared<c_CLEO_commandManager>();

	m_GTA_SAMemoryManager = std::make_shared<CMemoeyManager_gta_saExe>();
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
		//assert(package.length() == 44); // ?

		// unBox package
		std::shared_ptr	<c_CmmandPlayerActorPossitions> VehiclePackage = std::make_shared<c_CmmandPlayerActorPossitions>(package);
		m_packageManager->add(VehiclePackage);

		//Beep(400, 400);
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
			Log("[c_recov_Decisions::new_parsing_package_2017] : AHTUNG  package.length() != 36  (int)eHeaderPackage::RPC_SERVER_VEHICLE_CAR_POSSITIONS ");
			return;
		}

		// unBox package
		std::shared_ptr	<c_CmmandVehiclePossitions> VehiclePackage = std::make_shared<c_CmmandVehiclePossitions>(package);

		Log("[c_recov_Decisions::new_parsing_package_2017] :  eHeaderPackage::RPC_SERVER_VEHICLE_CAR_POSSITIONS");

		//VehiclePackage->writeDebugDim();

		c_ServerVehicle servCar = m_VehManager->createServerVehicle(VehiclePackage);


		Log("Server Say: ");
		servCar.DebugPrintValueDIM();


		bool isServVehicleReg = m_VehManager->findServerVehicleMap(servCar);


		if (isServVehicleReg)
		{
			// refresh possitions
			Log("[c_recov_Decisions::new_parsing_package_2017] : c_CmmandVehiclePossitions  STEP_1_2 %f", static_cast <float> (EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS));

			c_ServerVehicle OldServVehicle = m_VehManager->GetServerVehicleMap(servCar.m_fServerID);


			Log("Client Say: (old Data)");
			OldServVehicle.DebugPrintValueDIM();

			CPoint3D NewPos(servCar.m_fX, servCar.m_fY, servCar.m_fZ);
			CPoint3D PosOld(OldServVehicle.m_fX, OldServVehicle.m_fY, OldServVehicle.m_fZ);

			c_Compute compute;
			Log("[Delta OnFoot] = %f", compute.Distance(NewPos, PosOld ));
			 

			m_VehManager->refreshServerMap(servCar);


			/*if (compute.Distance(NewPositonsVehicle, PosOld) > 5.0f)
			{
			}*/

			VehiclePackage->setDesign(static_cast <float>(EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS));
			  
		}
		else
		{
			Log("[c_CmmandVehiclePossitions] STEP_1_1 %f", static_cast <float> (EDESIGN_COMMAND::CMD_SPAWN_VEHICLE));
			VehiclePackage->setDesign(static_cast <float> (EDESIGN_COMMAND::CMD_SPAWN_VEHICLE));
			// create Buffer for Save ServerId inside gta_sa.exe; 
		}

		m_packageManager->add(VehiclePackage);

		// refresh possition or reg server vehicle
		m_VehManager->refreshServerMap(servCar);
	}
}

void c_recov_Decisions::CLEO_DIM_initsializator(float* A1, float* A2, float* A3, float* A4, float* A5
	, float* A6, float* A7, float * A8, float * A9, float * A10)
{
	//std::cout << "[void c_recov_Decisions::CLEO_DIM_initsializator]" << "\n";
	Log("[void c_recov_Decisions::CLEO_DIM_initsializator]");

	m_packageManager->init(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
}

void c_recov_Decisions::computeGameWord()
{
	if (m_CLEO_Manager->empty())
		return;

	c_CLEO_COMMAND_DATA prms = m_CLEO_Manager->getAndPopCLEOPrms();

	int design = (int)prms.m_fA1;

	Log("[c_recov_Decisions::computeGameWord] Design %d", design);


	/*
		intitbaseRequest = std::make_shared<CVEHICLE_POSSITIONS>((float)m_ClientPassport, A1, A2, A3, A4, A5, A6, A7, A8);
		CVEHICLE_POSSITIONS( float design, float want_ModelCar, float xPos, float yPos, float zPos, float angle, float speed, float fServerID)
		1				2				3			4			5			6				7			8
		*/


	if (design == static_cast <int> (EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS))
	{

		Log("[c_recov_Decisions::computeGameWord] : [EDESIGN_COMMAND::CMD_VEHICLE_NEW_POSSITIONS]  ");

		prms.writeDimToLog(13888);

		/*
		c_ServerVehicle(float  fServerID, float fModel, float x, float y, float z, float fAngle, float fSpeed, float color_1, float color_2);
		void set(float x, float y, float z, float fAngle, float fSpeed, float color_1, float color_2);
		*/

		float fServerID = prms.m_fA8;
		float fModelCar = prms.m_fA2;

		float xPos = prms.m_fA3;
		float yPos = prms.m_fA4;
		float zPos = prms.m_fA5;
		float angle = prms.m_fA6;
		float speed = prms.m_fA7;

		c_ServerVehicle Server(
			fServerID,
			fModelCar,
			xPos,
			yPos,
			zPos,
			angle,
			speed,
			1,	/* color_1 */
			1	/* color_2 */
			);
		 
		Log("[KRACHIK] Update Vehicle SYka");
		Server.DebugPrintValueDIM();

		//m_VehManager->refreshServerMap(Server);
	}


	if (design == static_cast <int> (eLOCAL_CLIENT_CMD::REG_CAR_HEANDLE))
	{
		c_ClientVehicle clientVeh(
			prms.m_iPrms1,	// fHeandle
			prms.m_fA3,	// serv id
			prms.m_fA2, // model
			prms.m_fA4,	// X
			prms.m_fA5,	// Y
			prms.m_fA6,	// Z

			prms.m_fA9,	// color 
			prms.m_fA10	// color 
			);

		// [debug] cleo script
		Log("[eLOCAL_CLIENT_CMD::REG_CAR_HEANDLE] STEP 3 [begin]");

		prms.writeDimToLog(3);

		clientVeh.writeDebugLogDim();

		Log("[eLOCAL_CLIENT_CMD::REG_CAR_HEANDLE] STEP 3 [end]");

		m_VehManager->refreshClientMap(clientVeh);

		m_VehManager->m_VehPoolManager->register_By_key_GameObjectHeandle(clientVeh);


	}
	if (design == static_cast <int> (eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL))
	{

		if (!m_VehManager->m_VehPoolManager->empty())
		{
			Log("[eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL] STEP 4 [Begin]");

			c_ClientVehicle veh = m_VehManager->m_VehPoolManager->getObjectPool();
			veh.writeDebugLogDim();

			m_VehManager->m_VehPoolManager->incIteratorPool();

			std::shared_ptr	<c_CommandGetHeandleVehicle> VehiclePackage = std::make_shared<c_CommandGetHeandleVehicle>(veh);


			VehiclePackage->setDesign(static_cast <float> (eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL));

			m_packageManager->add(VehiclePackage);

			Log("[eLOCAL_CLIENT_CMD::GET_HEANDLE_CAR_OF_POOL] STEP 4 [end]");
		}
	}

}



#if 0
if (design == static_cast <int> (eLOCAL_CLIENT_CMD::TEST_GET_HEALCH_VEHICLE))
{

	Log("[static_cast <int> (eLOCAL_CLIENT_CMD::TEST_GET_HEALCH_VEHICLE)]");

	if (!m_VehManager->m_VehPoolManager->empty())
	{

		Log("[Get Car of Vehicle, Print Dim]");

		c_ClientVehicle veh = m_VehManager->m_VehPoolManager->getObjectPool();

		veh.writeDebugLogDim();

		m_VehManager->m_VehPoolManager->incIteratorPool();

		DWORD* Buff = m_DynamicMemoryManager->CreateBuffer();

		}
	}
#endif





/*
if (m_GTA_SAMemoryManager->IsRunGTA()) // test read gta sa mem
{



}
*/
/*

if (0)
{ // work  rand armour ped
DWORD* Base;
float* Health;
float* Armour;
Base = (DWORD*)0xB6F5F0;
Armour = (float*)(*Base + 0x548);
*Armour = rand() % 50 + 10;
}

if (0)
{ // flame first Pool Vehicle ?
DWORD* BaseVehiclePool;
DWORD* BaseVehiclePool_2;
DWORD* BaseVehiclePool_2_count;

BaseVehiclePool = (DWORD*)0xB74494;	//0A8D: 28@ = read_memory 0xB74494 size 4 virtual_protect 0 // Указатель на первый элемент в пуле транспорта

BaseVehiclePool_2 = (DWORD*)(*BaseVehiclePool); // 0A8D: 28@ = read_memory 28@ size 4 virtual_protect 0

BaseVehiclePool_2_count = (DWORD*)(*BaseVehiclePool + 0xC);

Log("Krachik, you did it! %d ", *BaseVehiclePool_2_count);
}

*/