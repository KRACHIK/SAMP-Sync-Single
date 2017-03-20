#ifndef C_Pool_Veehicle_H
#define C_Pool_Veehicle_H

#include "poolVehicleManager.h"

#include "ServerVehicle.h"

#include "Vehicle.h"

#include <sstream>

#include <boost/shared_ptr.hpp> 
 
#include <vector> 




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
//class c_floatValue
//{
//public:
//	c_floatValue(float _fHeandle);
//public:
//	float m_fHeandle;
//
//};
  
class c_CLEO_Object_pool
{
public:
	c_CLEO_Object_pool();
	
	void register_By_key_ServId(const c_ClientVehicle & _obj);

	void register_By_key_GameObjectHeandle(const c_ClientVehicle & _obj);

	void initObjectVehicle(float fPrms, float A2, float A3, float A4, float A5, float A6);

	void del(const c_ClientVehicle & _obj);

	void incIteratorPool();

	float getHeandlePool();
	 

	c_ClientVehicle getObjectPool();

	bool empty() { return m_Vehicle_vec.empty(); }

	void printInfo(std::vector<c_ClientVehicle>::iterator it);
	void printInfo(c_ClientVehicle obj);
	void printDataBase();
private:

	std::vector<c_ClientVehicle> m_Vehicle_vec;
	int m_curr_index;
};


#endif  
