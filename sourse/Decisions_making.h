#pragma once 

#ifndef C_RECOV_DECISIONS_MAKING_H
#define C_RECOV_DECISIONS_MAKING_H

#include <boost/shared_ptr.hpp> 

#include <sstream>
#include <string>
#include <memory>
#include <deque>

#include "MyUtiles.h"

#include "package_type.h"

#include "ELocal_command.h"

#include "Output_Deque.h"

#include "CLEO_manager.h"

#include "VehicleManager.h"

#include "GTA_SA_DynamicMemoryManager.h"

class c_recov_Decisions
{
public:

	//std::deque <std::shared_ptr<c_BasePackage>> m_goodParsePackage_deque;
public:

	c_recov_Decisions();

	~c_recov_Decisions();

	void new_parsing_package_2017(std::string package);

	void read(std::stringstream byteArr);
	  
	//void reg_car_heandle();
	//void GET_HEANDLE_CAR_OF_POOL();
	/*void isCLEO_ScriptSpawnedVehicle(float fModel, float fServID, float fX,
		float fY, float fZ, float fAngle, float fSpeed, float fHeandle);*/

	void CLEO_DIM_initsializator(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10);

	void computeGameWord();

	void update();

public:

	std::shared_ptr	<c_VehicleManager> m_VehManager;

	std::shared_ptr	<c_PackageManager> m_packageManager;

	std::shared_ptr	<c_CLEO_commandManager> m_CLEO_Manager;

	/*std::shared_ptr	<c_DynamicMemoryManager> m_DynamicMemoryManager;
*/
private:

};

#endif  

