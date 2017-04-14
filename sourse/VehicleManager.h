#pragma  once

#ifndef C_VEHICLEMANAGER_H
#define C_VEHICLEMANAGER_H

#include "ServerVehicle.h"

#include "Vehicle.h"

#include "Output_Deque.h"  

#include "poolVehicleManager.h"

#include <sstream>

#include <map>

#include <deque>

#include <memory.h>

#include "GTA_SA_DynamicMemoryManager.h"

class c_VehicleManager
{
public:
	c_VehicleManager();

	bool findClientVehicleMap(c_ServerVehicle vehicle);

	bool findServerVehicleMap(c_ServerVehicle vehicle);

	void refreshServerMap(c_ServerVehicle Vehicle);

	void refreshClientMap(c_ClientVehicle Vehicle);

	bool compareVehicleByModel(c_ClientVehicle Vehicle);

	c_ServerVehicle createServerVehicle(std::shared_ptr <c_CmmandVehiclePossitions> & VehiclePackage);

	int getSizeServerVehicle() { return m_serverVehicleMap.size(); }


	bool c_VehicleManager::isVehicleInitCorrect(c_ClientVehicle &vehicle);
	  				  
	std::shared_ptr	<c_CLEO_Object_pool> m_VehPoolManager;
private:
	std::map <int, c_ClientVehicle>	m_clientVehicleMap;
	std::map <int, c_ServerVehicle>	m_serverVehicleMap;

private:
	bool isValidServerID(int id);
	bool isDefinedGameCarModel(int modelIndex);
	bool isPosittionsForCarSpawnTry();

};

#endif  



//
//class cObject
//{
//public:
//	cObject(float _fHeandle);
//public:
//	float m_fHeandle;
//
//};
//
//class c_CLEO_Object_pool
//{
//public:
//	c_CLEO_Object_pool();
//
//	void register_By_key_ServId(const c_Vehicle & _obj);
//
//	void register_By_key_GameObjectHeandle(const c_Vehicle & _obj);
//
//	void initObjectVehicle(float fPrms, float A2, float A3, float A4, float A5, float A6);
//
//	void del(const c_Vehicle & _obj);
//
//	void incIteratorPool();
//
//	float getHeandlePool();
//
//	bool isDefineGameCarModel(int modelIndex);
//
//	c_Vehicle getObjectPool();
//
//	void printInfo(std::vector<c_Vehicle>::iterator it);
//	void printInfo(c_Vehicle obj);
//	void printDataBase();
//private:
//
//	std::vector<c_Vehicle> m_Vehicle_vec;
//	int m_curr_index;
//};
