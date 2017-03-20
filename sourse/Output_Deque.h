#ifndef C_OUTPUT_DEQUE_H
#define C_OUTPUT_DEQUE_H

#pragma  once // if del this str geting many error

#include <iostream>
#include <deque>
#include <memory>


#include "Vehicle.h"

class c_CmmandVehiclePossitions;
class c_PackageManager;
class c_BasePackage;

class c_BasePackage
{
public:
	virtual void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10) = 0;
};


class c_CmmandVehiclePossitions : public c_BasePackage
{
public:
	c_CmmandVehiclePossitions(std::string recivPackage);

	c_CmmandVehiclePossitions();

	virtual void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10);

	void setDesign(float design) { m_fDesign = design;  m_bInit = true; }

	bool isInit() { return m_bInit; }

public:
	float			m_fDesign = -1.0f;
	unsigned int	m_ServerTick = -1;
	float			m_fServerID = -1.0f;
	float			m_fModel = -1.0f;
	float			m_fX = -1.0f;
	float			m_fY = -1.0f;
	float			m_fZ = -1.0f;
	float			m_fAngle = -1.0f;
	float			m_fSpeed = -1.0f;

	float			m_fColor_1;
	float			m_fColor_2;

private:
	std::string m_package;

	bool m_bInit = false;
};

 
/*
class c_CmmandVehicleSetColor : public c_BasePackage
{
public:
	c_CmmandVehicleSetColor(c_ClientVehicle Veh)
	{
		m_ClientVehicle = Veh;
	}


	virtual void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10)
	{
		*A1 = m_fDesign;
		*A2 = m_ClientVehicle.m_fColor_1;
		*A2 = m_ClientVehicle.m_fColor_2;
		*A2 = m_ClientVehicle.m_fHeandle;
		*A2 = m_ClientVehicle.m_fServerID;
		*A2 = m_ClientVehicle.m_fModel;
	}

	void setDesign(float design) { m_fDesign = design;  m_bInit = true; }

	bool isInit() { return m_bInit; }

public:
	float			m_fDesign = -1.0f;
	 
public:
	c_ClientVehicle m_ClientVehicle;

 
private:
	bool m_bInit = false;
};
*/


class c_CommandGetHeandleVehicle : public c_BasePackage
{
public:
	c_CommandGetHeandleVehicle(c_ClientVehicle Veh)
	{
		m_ClientVehicle = Veh;

		m_fDesign = -1;

		/*m_fHeandle = Veh.m_fHeandle;
		m_fServerID = Veh.m_fServerID;
		m_fModel = Veh.m_fModel;*/
	}

	c_CommandGetHeandleVehicle() {}
	 
	virtual void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10)
	{
	
		*A1 = m_fDesign;
		
		*A2 =  -1.0f ; //m_ClientVehicle.m_fModel;
		*A3 =  -2.0f ; //m_ClientVehicle.m_fServerID;
		*A4 =  -3.0f ; //m_ClientVehicle.m_fX;
		*A5 =  -4.0f ; //m_ClientVehicle.m_fY;
		*A6 =  -5.0f ; //m_ClientVehicle.m_fZ;
		
		*A7 = m_ClientVehicle.m_fHeandle;  
		*A8 = -6.0f; // m_ClientVehicle.m_fSpeed;
		
		*A9 =  -7.0f ; // m_ClientVehicle.m_fColor_1;
		*A10 = -8.0f ; // m_ClientVehicle.m_fColor_2;
	}
	

	void setDesign(float design) { m_fDesign = design;  m_bInit = true; }

	bool isInit() { return m_bInit; }

public:
	float	m_fDesign		= -1.0f;	
	 
private:
	bool m_bInit = false;

public:
	c_ClientVehicle m_ClientVehicle;
};



class c_PackageManager
{
public:
	c_PackageManager();

	void add(std::string package);

	void add(std::shared_ptr <c_CmmandVehiclePossitions> VehiclePackage);

	void add(std::shared_ptr <c_CommandGetHeandleVehicle> CommandVehicle);

	void cast();

	void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10);

private:
	std::deque <std::shared_ptr<c_BasePackage>> m_goodParsePackage_deque;
};

#endif  

//c_VehiclePossitionsPackage tmp = static_cast<c_VehiclePossitionsPackage> (m_goodParsePackage_deque[0])