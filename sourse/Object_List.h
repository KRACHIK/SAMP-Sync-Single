#ifndef C_OBJECT_LIST_H
#define C_OBJECT_LIST_H

#include "UDP_network.h"

#include "MyUtiles.h"
 
class c_Object // not reliz
{
public: 
	c_Object();
	unsigned int iHeandle;

	bool FlagSpawn;

	int iModel;
	int fHealth;

	float fX;
	float fY;
	float fZ;
};
	 
	  



class c_Vehicle
{
public:
	c_Vehicle();

	int serverID;

	int iHeandle;

	int iModel;
	int fHealth;

	float fX;
	float fY;
	float fZ;
};


class c_VehicleManager
{
public:
	c_VehicleManager();
	std::map <int, c_Vehicle>	m_map_veh;

	void refresh_vehicle_map(int serverID, int model, int iHeandle , float x, float y, float z);
	std::string getHexInfoCarID(int serverID);

};
  
     
class c_OutputValue
{
public:
	
	int iDesign;

	int	iModel;
	int iServID;

	float fHealth;
	float fArmour;
	 
	float fX;
	float fY;
	float fZ;
};

	      
#endif  





