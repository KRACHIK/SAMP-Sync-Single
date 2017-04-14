#pragma  once

#include "Output_Deque.h"

#include "MyUtiles.h"

#include <sstream> 

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// class c_CmmandVehiclePossitions

c_CmmandVehiclePossitions::c_CmmandVehiclePossitions(std::string recivPackage)
{
	m_package = recivPackage;
	std::stringstream byteArr(recivPackage);

	//float fnotUsedHeader;

	//byteArr.read((char*)&fnotUsedHeader, 4);
	byteArr.read((char*)&m_fDesign, 4);
	byteArr.read((char*)&m_ServerTick, 4);
	byteArr.read((char*)&m_fServerID, 4);
	byteArr.read((char*)&m_fModel, 4);
	byteArr.read((char*)&m_fX, 4);
	byteArr.read((char*)&m_fY, 4);
	byteArr.read((char*)&m_fZ, 4);
	byteArr.read((char*)&m_fAngle, 4);
	byteArr.read((char*)&m_fSpeed, 4);
	byteArr.read((char*)&m_fColor_1, 4);
	byteArr.read((char*)&m_fColor_2, 4);

	Log("[c_CmmandVehiclePossitions::c_CmmandVehiclePossitions]");
}

c_CmmandVehiclePossitions::c_CmmandVehiclePossitions()
{

}

void c_CmmandVehiclePossitions::init(float* A1, float* A2, float* A3, float* A4, float* A5, float* A6, float* A7, float* A8, float* A9, float* A10)
{
	std::cout << "[c_VehiclePossitionsPackage::init]" << "\n";
	Log("[c_VehiclePossitionsPackage::init]");

	*A1 = m_fDesign;
	*A2 = m_fModel;

	/*if ((int)m_fDesign == 301)
	{
	float* pBuffer = getPtrHeadMyBuffer();
	void* pv = pBuffer;
	float *pTest;
	pTest = static_cast<float*>(pv); // [str 173] gl 7.2.1 Bjarne stroustrup
	/ *for (size_t i = 0; i < 11; i++)
	{
	std::cout << " [DWORD* pBuffer]" << *pBuffer  << "\n";
	std::cout << "\n [My Cast]  = " << *pTest << "\n";
	pBuffer += 1;
	pTest += 1;
	}* /

	A6 = pTest;	// *pTest; // Head Dword Arr

	Log("HI, KRACHIK, y teb9 vse poluchitsa ptr = %d ?", A6);
	}*/


	*A3 = m_fServerID;
	*A4 = m_fX;
	*A5 = m_fY;
	*A6 = m_fZ;
	*A7 = m_fAngle;
	*A8 = m_fSpeed;
	*A9 = m_fColor_1;
	*A10 = m_fColor_2;

	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A1);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A2);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A3);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A4);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A5);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A6);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A7);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A8);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A9);
	Log("[c_CmmandVehiclePossitions] STEP_2 %f", *A10);
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	class c_CommandGetHeandleVehicle


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

c_PackageManager::c_PackageManager()
{
	std::cout << "[c_PackageManager::c_PackageManager] create!!" << "\n";
}

void c_PackageManager::add(std::string package)
{
	//m_goodParsePackage_deque.push_back(std::shared_ptr<c_BasePackage>(new c_VehiclePossitionsPackage(package)));
	m_goodParsePackage_deque.emplace_back(new c_CmmandVehiclePossitions(package));
}

void c_PackageManager::add(std::shared_ptr <c_CmmandVehiclePossitions> VehiclePackage)
{
	m_goodParsePackage_deque.emplace_back(VehiclePackage);
}

void c_PackageManager::add(std::shared_ptr <c_CommandGetHeandleVehicle> CommandVehicle)
{
	m_goodParsePackage_deque.emplace_back(CommandVehicle);
}
 
void c_PackageManager::add(std::shared_ptr <c_CmmandPlayerActorPossitions> Command)
{
	m_goodParsePackage_deque.emplace_back(Command);
}




void c_PackageManager::cast()
{	//			TEST
	if (!m_goodParsePackage_deque.empty())
	{
		std::shared_ptr	<c_BasePackage> FirstBasePackage = m_goodParsePackage_deque[0];

		std::shared_ptr	<c_CmmandVehiclePossitions> BarVehiclePackage = std::make_shared<c_CmmandVehiclePossitions>();

		BarVehiclePackage = std::dynamic_pointer_cast<c_CmmandVehiclePossitions>(FirstBasePackage);

		std::cout << "Yeah! prms = " << BarVehiclePackage->m_fServerID << "\n";
		std::cout << "Yeah! prms = " << BarVehiclePackage->m_fModel << "\n";
		std::cout << "Yeah! prms = " << BarVehiclePackage->m_fX << "\n";
		std::cout << "Yeah! prms = " << BarVehiclePackage->m_fY << "\n";
		std::cout << "Yeah! prms = " << BarVehiclePackage->m_fZ << "\n";

		m_goodParsePackage_deque.pop_front();
	}
}

void c_PackageManager::init(float* A1, float* A2, float* A3, float* A4, float* A5,
	float* A6, float* A7, float * A8, float * A9, float * A10)
{
	if (!m_goodParsePackage_deque.empty())
	{
		//std::cout << "[c_PackageManager::init] size = " << m_goodParsePackage_deque.size() << "\n";
		Log("[c_PackageManager::init] m_goodParsePackage_deque.size() = %d", m_goodParsePackage_deque.size());



		/*std::shared_ptr	<c_BasePackage> FirstBasePackage = m_goodParsePackage_deque[0];

		std::shared_ptr	<c_CmmandVehiclePossitions> BarVehiclePackage = std::make_shared<c_CmmandVehiclePossitions>();

		BarVehiclePackage = std::dynamic_pointer_cast<c_CmmandVehiclePossitions>(FirstBasePackage);

		if (BarVehiclePackage->isInit())
		{
		BarVehiclePackage->init(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);
		}*/

		m_goodParsePackage_deque[0]->init(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10);

		m_goodParsePackage_deque.pop_front();
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//// work
//std::shared_ptr	<c_BasePackage> BaseVehicle;  

//std::shared_ptr	<c_VehiclePossitionsPackage> NewVehicle;
// 
//NewVehicle = std::make_shared<c_VehiclePossitionsPackage>();
// 
//NewVehicle = std::dynamic_pointer_cast<c_VehiclePossitionsPackage>(BaseVehicle);
//// end

c_CmmandPlayerActorPossitions::c_CmmandPlayerActorPossitions(std::string recovHexPackage)
{
	m_package = recovHexPackage;
	std::stringstream byteArr(recovHexPackage);

	byteArr.read((char*)&m_fDesign, 4);
	byteArr.read((char*)&m_ServerTick, 4);
	byteArr.read((char*)&m_fServerID, 4);
	byteArr.read((char*)&m_fModel, 4);
	byteArr.read((char*)&m_fX, 4);
	byteArr.read((char*)&m_fY, 4);
	byteArr.read((char*)&m_fZ, 4);
	byteArr.read((char*)&m_fAngle, 4);
	byteArr.read((char*)&m_fSpeed, 4);
	byteArr.read((char*)&m_fInterior, 4);
	 
	printf("[c_CmmandPlayerActorPossitions::c_CmmandPlayerActorPossitions] %f %f %f ", m_fDesign, m_fServerID, m_fModel);
	Log("[c_CmmandPlayerActorPossitions::c_CmmandPlayerActorPossitions] %f %f %f ", m_fDesign, m_fServerID, m_fModel);
	writeDebugDim();  
}

void c_CmmandPlayerActorPossitions::init(float* A1, float* A2, float* A3, float* A4, float* A5, float* A6, float* A7, float * A8, float * A9, float * A10)
{

	*A1 = m_fDesign;
	*A2 = m_fModel;

	*A3 = m_fServerID;
	*A4 = m_fX;
	*A5 = m_fY;
	*A6 = m_fZ;
	*A7 = m_fAngle;
	*A8 = m_fSpeed;
	*A9 = m_fInterior;
	*A10 = 0;

	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A1);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A2);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A3);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A4);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A5);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A6);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A7);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A8);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A9);
	Log("[c_CmmandVehiclePossitions] STEP_PlayerActor_? = %f", *A10);

}

float			m_fDesign = -1.0f;
unsigned int	m_ServerTick = -1;
float			m_fServerID = -1.0f;
float			m_fModel = -1.0f;
float			m_fInterior = -1.0f;
float			m_fX = -1.0f;
float			m_fY = -1.0f;
float			m_fZ = -1.0f;
float			m_fSpeed = -1.0f;
float			m_fAngle = -1.0f;


