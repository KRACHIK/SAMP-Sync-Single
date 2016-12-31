#include "Object_List.h"


c_Object::c_Object()
{
	FlagSpawn = false;
	iHeandle = 0;

	iModel = 0;
	fHealth = 0;

	fX = 0;
	fY = 0;
	fZ = 0;
}



//===============================================

c_Vehicle::c_Vehicle()
{

	iModel = 0;
	fHealth = 0;
	fX = 0;
	fY = 0;
	fZ = 0;
}

c_VehicleManager::c_VehicleManager()
{
	std::cout << "[c_VehicleManager] create!" << "\n";
}

void c_VehicleManager::refresh_vehicle_map(int serverID, int model, int iHeandle, float x, float y, float z)
{
	auto it = std::find_if(m_map_veh.begin(), m_map_veh.end(),
		[&serverID](const std::pair<int, c_Vehicle> &p)
	{
		return p.first == serverID;
	});

	if (it != m_map_veh.end())
	{// update 	 
		(*it).second.fX = x;
		(*it).second.fY = y;
		(*it).second.fZ = z;
	}
	else
	{		// register 
		c_Vehicle tmp; 	// for box
		tmp.serverID = serverID;
		tmp.iModel = model;
		tmp.iHeandle = iHeandle;
		tmp.fX = x;
		tmp.fY = y;
		tmp.fZ = z;
		m_map_veh.insert(std::pair<int, c_Vehicle>(serverID, tmp));

		std::cout << "\\nn===================\n";
		std::cout << "[c_VehicleManager::getHexInfoCarID]" << "\n";
		std::cout << " serverID " <<	tmp.serverID << " ";
		std::cout << " iModel  " << tmp.iModel << " ";
		std::cout << " iHeandle  " << tmp.iHeandle<< " ";

		std::cout << " pos " <<			tmp.fX;
		std::cout << " pos " <<			tmp.fY;
		std::cout << " pos " <<			tmp.fZ;
		std::cout << "\n===================\n";
		std::cout << "\n";

	
	
	}
}

std::string c_VehicleManager::getHexInfoCarID(int serverID)
{
	auto it = std::find_if(m_map_veh.begin(), m_map_veh.end(),
		[&serverID](const std::pair<int, c_Vehicle> &p)
	{
		return p.first == serverID;
	});

	if (it != m_map_veh.end())
	{// update 	 
		std::cout << "[c_VehicleManager::getHexInfoCarID]" << "\n";
		std::cout << " serverID " << (*it).second.serverID << " ";
		std::cout << " iModel  " << (*it).second.iModel << " ";
		std::cout << " pos " << (*it).second.fX;
		std::cout << " pos " << (*it).second.fY;
		std::cout << " pos " << (*it).second.fZ;
		std::cout << "\n===================\n";
		std::cout << "\n";

 
		return "not reliz";
	}
	else
	{		// register  
		std::cout << "add log client hack" << "\n";
	}
	return "0";
}



