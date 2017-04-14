#pragma once

#include "VehicleManager.h"

#include "MyUtiles.h"

#include <iostream>

#include "package_type.h"


c_VehicleManager::c_VehicleManager()
{
	std::cout << "[c_VehicleManager] create!" << "\n";

	m_VehPoolManager = std::make_shared<c_CLEO_Object_pool>();
	m_DynamicMemoryManager = std::make_shared<c_DynamicMemoryManager>(13); // 13*4 = 52 byte
}

 
bool c_VehicleManager::findClientVehicleMap(c_ServerVehicle vehicle)
{
	int serverID = (int)vehicle.m_fServerID;

	auto it = std::find_if(m_clientVehicleMap.begin(), m_clientVehicleMap.end(),
		[&serverID](const std::pair<int, c_ClientVehicle> &p){
		return p.first == serverID;
	});

	if (it != m_clientVehicleMap.end())		// update 	 
		return true;

	return false;
}


bool c_VehicleManager::findServerVehicleMap(c_ServerVehicle vehicle) 
{
	int serverID = (int)vehicle.m_fServerID;

	auto it = std::find_if(m_serverVehicleMap.begin(), m_serverVehicleMap.end(),
		[&serverID](const std::pair<int, c_ServerVehicle> &p){
		return p.first == serverID;
	});

	if (it != m_serverVehicleMap.end())		// update 	 
		return true;

	return false;
}

//void c_VehicleManager::regServVehAtClientVehicleMap(c_ServerVehicle Vehicle)
//{
//
//	Log("heandle car not init");
//	//m_clientVehicleMap.insert(std::pair<int, c_ClientVehicle>((int)Vehicle.m_fServerID, Vehicle));
//}

//void c_VehicleManager::regHeandleMemoryVehicle(float fModel, float fServID,float fX, float fY, float fZ, float fAngle, float fSpeed, float fHeandle)
//{
//
//	c_ClientVehicle	spawnedVehicle(fHeandle, fServID, fModel, fX, fY, fZ);
//
//	//m_VehPoolManager->register_By_key_GameObjectHeandle(spawnedVehicle);
//}

void c_VehicleManager::refreshServerMap(c_ServerVehicle vehicle)
{
	int serverID = (int)vehicle.m_fServerID;

	auto it = std::find_if(m_serverVehicleMap.begin(), m_serverVehicleMap.end(),
		[&serverID](const std::pair<int, c_ServerVehicle> &p){
		return p.first == serverID;
	});

	if (it != m_serverVehicleMap.end())		// update 	 
	{
		m_serverVehicleMap.insert(std::pair<int, c_ServerVehicle>(serverID, vehicle));
	}
	else
	{// reg
		m_serverVehicleMap.insert(std::pair<int, c_ServerVehicle>(serverID, vehicle));
	}

}

void c_VehicleManager::refreshClientMap(c_ClientVehicle vehicle)
{
	if (!isVehicleInitCorrect(vehicle))
	{
		Log("AHTUNG! [c_VehicleManager::refreshClientMap]  if (!isVehicleInitCorrect(vehicle))");
		exit(1);
		return;
	}

	 
	m_VehPoolManager->register_By_key_GameObjectHeandle(vehicle);
	 
	int serverID = (int)vehicle.m_fServerID;

	auto it = std::find_if(m_clientVehicleMap.begin(), m_clientVehicleMap.end(),
		[&serverID](const std::pair<int, c_ClientVehicle> &p){
		return p.first == serverID;
	});

	if (it != m_clientVehicleMap.end())		// update 	 
	{
		m_clientVehicleMap.insert(std::pair<int, c_ClientVehicle>(serverID, vehicle));

		Log("[c_VehicleManager::refreshClientMap] AHTUNG  [update ClientVehicle]");
	}
	else
	{// reg
		m_clientVehicleMap.insert(std::pair<int, c_ClientVehicle>(serverID, vehicle));
	}

}
  
bool c_VehicleManager::compareVehicleByModel(c_ClientVehicle vehicle)
{
	if (!isVehicleInitCorrect(vehicle))
	{
		Log("AHTUNG! [c_VehicleManager::compareVehicleByModel]  if (!isVehicleInitCorrect(vehicle))");
		exit(1);
		return false;
	}
	  
	int serverID = (int)vehicle.m_fServerID;

	auto it = std::find_if(m_clientVehicleMap.begin(), m_clientVehicleMap.end(),
		[&serverID](const std::pair<int, c_ClientVehicle> &p){
		return p.first == serverID;
	});

		 
	if (it != m_clientVehicleMap.end())		// update 	 
	{
		if (it->second.m_fModel == vehicle.m_fModel)
			if (it->second.m_fServerID == vehicle.m_fServerID)
			return true;
	}
	else
	{// reg
		Log("AHTUNG [c_VehicleManager::compareVehicleByModel] VEHICLE NOT FIND");
		exit(0);
	}
	return false;
}
		 


c_ServerVehicle c_VehicleManager::createServerVehicle(std::shared_ptr <c_CmmandVehiclePossitions> & VehiclePackage)
{
	c_ServerVehicle tmp(
		VehiclePackage->m_fServerID
		, VehiclePackage->m_fModel
		, VehiclePackage->m_fX
		, VehiclePackage->m_fY
		, VehiclePackage->m_fZ
		, VehiclePackage->m_fAngle
		, VehiclePackage->m_fSpeed
		, VehiclePackage->m_fColor_1
		, VehiclePackage->m_fColor_2
		);

	return tmp;
}
  


bool c_VehicleManager::isVehicleInitCorrect(c_ClientVehicle &vehicle)
{ 
	if (isDefinedGameCarModel((int)vehicle.m_fModel)
		&& isValidServerID((int)vehicle.m_fServerID))
		return true;

	return false;
}

bool c_VehicleManager::isValidServerID(int id)
{
	if (id < 0) return false;
	return true;
}

bool c_VehicleManager::isDefinedGameCarModel(int modelIndex)
{
	if (modelIndex >= 400 && modelIndex <= 611)
	{
		return true;
	}

	std::cout << "AHTUNG [bool c_VehicleManager::isDefineGameCarModel] AHTUNG, HAX, false" << "\n";

	Log("AHTUNG [bool c_VehicleManager::isDefineGameCarModel] AHTUNG, HAX, false");

	return false;
}
