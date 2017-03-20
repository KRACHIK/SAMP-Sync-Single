#pragma once

#include "poolVehicleManager.h"
 
#include "MyUtiles.h"
 
   
c_CLEO_Object_pool::c_CLEO_Object_pool()
{
	m_curr_index = 0;
	Log("[c_CLEO_Object_pool::c_CLEO_Object_pool()] Create!");
}

void c_CLEO_Object_pool::register_By_key_ServId(const c_ClientVehicle & _obj)
{
	float id = _obj.m_fServerID;

	auto it = std::find_if(m_Vehicle_vec.begin(), m_Vehicle_vec.end(), [&](const c_ClientVehicle& d) {return (id == d.m_fServerID); });

	if (it != m_Vehicle_vec.end())
	{
		// std::cout << " update " << "\n";
		Log("\n[c_CLEO_Object_pool::add()] update\n");
	}
	else
	{
		Log("[c_CLEO_Object_pool::add()] register ");
		// std::cout << "[c_CLEO_Object_pool::add()] register " << "\t";
		//printInfo(_obj);

		m_Vehicle_vec.push_back(_obj);
	}
}

 
void c_CLEO_Object_pool::register_By_key_GameObjectHeandle(const c_ClientVehicle & _obj)
{
	float id = _obj.m_fHeandle;

	auto it = std::find_if(m_Vehicle_vec.begin(), m_Vehicle_vec.end(), [&](const c_ClientVehicle& d) {return (id == d.m_fHeandle); });
	 
	if (it != m_Vehicle_vec.end())
	{
		Log("\n[c_CLEO_Object_pool::register_By_key_GameObjectHeandle()] AHTUNG (Update ?) \n");
	}
	else
	{
		Log("[c_CLEO_Object_pool::register_By_key_GameObjectHeandle()] Yeah! register "); 
		  
		m_Vehicle_vec.push_back(_obj);
	}
}

void c_CLEO_Object_pool::del(const c_ClientVehicle & _obj)
{
	float id = _obj.m_fHeandle;

	auto it = std::find_if(m_Vehicle_vec.begin(), m_Vehicle_vec.end(), [&](const c_ClientVehicle& d) {return (id == d.m_fHeandle); });

	if (it != m_Vehicle_vec.end())
	{
		// std::cout << "delete" << "\t";
		Log("[c_CLEO_Object_pool::del()] delete!\t");
		printInfo(it);
		m_Vehicle_vec.erase(it);
	}
	else
	{
		 std::cout << "[c_CLEO_Object_pool::DEL] (debug) ahtung, zdes takih nety \n " << "\t";

		 Log("[c_CLEO_Object_pool::DEL] (debug) ahtung, zdes takih nety");

	}

}

void c_CLEO_Object_pool::incIteratorPool()
{
	// std::cout << "[c_CLEO_Object_pool::incIteratorPool] " << "\t";
	if (!m_Vehicle_vec.empty())
	{
		//// std::cout << " vec size = " << m_Objects.size() << " ";
		if (m_curr_index == m_Vehicle_vec.size() - 1)
		{
			m_curr_index = 0;
			//// std::cout << "m_curr_index = 0;" << "\n";
		}
		else
		{
			m_curr_index++;
			//// std::cout << "m_curr_index++  " << m_curr_index << "\n";
		}
	}
	// std::cout << "" << "\n";
}

float c_CLEO_Object_pool::getHeandlePool()
{
	if (!m_Vehicle_vec.empty())
		return m_Vehicle_vec[m_curr_index].m_fHeandle;
	return -1;
}
 

c_ClientVehicle c_CLEO_Object_pool::getObjectPool()
{
	Log("[c_ClientVehicle c_CLEO_Object_pool::getObjectPool()]");

	if (!m_Vehicle_vec.empty())
	{
		Log("Yeah!");
		return m_Vehicle_vec[m_curr_index];
	}
	else
	{	
		Log("Ahtung m_Vehicle_vec.empty(), return bad Heandle (-1,-1,-1,...)");
		return  c_ClientVehicle();
	}
}

void c_CLEO_Object_pool::printInfo(std::vector<c_ClientVehicle>::iterator it)
{

	 std::cout << "[c_CLEO_Object_pool::printInfo(iterator it)]" << "\n";
	 std::cout << " m_fHeandle " << it->m_fHeandle;
	 std::cout << " servId " << it->m_fServerID;
	 std::cout << " m_fModel " << it->m_fModel;
	 std::cout << " x " << it->m_fX;
	 std::cout << " y " << it->m_fY;
	 std::cout << " z " << it->m_fZ;
	 std::cout << "------------------" << "\n";

	Log("[c_CLEO_Object_pool::printInfo(iterator it)]");
	Log(" m_fHeandle %f", it->m_fHeandle);
	Log(" servId %f", it->m_fServerID);
	Log(" m_fModel %f", it->m_fModel);
	Log(" x %f", it->m_fX);
	Log(" y %f", it->m_fY);
	Log(" z %f\n", it->m_fZ);
	  
}


void c_CLEO_Object_pool::printDataBase()
{
	for (int i = 0; i < m_Vehicle_vec.size(); i++)
		printInfo(m_Vehicle_vec[i]);
}

void c_CLEO_Object_pool::printInfo(c_ClientVehicle obj)
{
	 std::cout << "[c_CLEO_Object_pool::printInfo(iterator it)]" << "\n";
	 std::cout << " m_fHeandle " << obj.m_fHeandle;
	 std::cout << " servId " << obj.m_fServerID;
	 std::cout << " m_fModel " << obj.m_fModel;
	 std::cout << " x " << obj.m_fX;
	 std::cout << " y " << obj.m_fY;
	 std::cout << " z " << obj.m_fZ;
	 std::cout << "" << "\n";

	Log("[c_CLEO_Object_pool::printInfo(iterator it)]");
	Log(" m_fHeandle %f", obj.m_fHeandle);
	Log(" servId %f", obj.m_fServerID);
	Log(" m_fModel %f", obj.m_fModel);
	Log(" x %f", obj.m_fX);
	Log(" y %f", obj.m_fY);
	Log(" z %f\n", obj.m_fZ);
}
