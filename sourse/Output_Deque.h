#ifndef C_OUTPUT_DEQUE_H
#define C_OUTPUT_DEQUE_H

#pragma  once // if del this str geting many error

#include <iostream>
#include <deque>
#include <memory>

#include <windows.h>

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
	 
	/*void writeDebugDim()
	{
	Log("[c_CmmandVehiclePossitions] design %f", m_fDesign);
	Log("[c_CmmandVehiclePossitions] servTick %f", m_ServerTick);
	Log("[c_CmmandVehiclePossitions] servID %f", m_fServerID);
	Log("[c_CmmandVehiclePossitions] model %f", m_fModel);
	Log("[c_CmmandVehiclePossitions] x %f", m_fX);
	Log("[c_CmmandVehiclePossitions] y %f", m_fY);
	Log("[c_CmmandVehiclePossitions] z %f", m_fZ);
	Log("[c_CmmandVehiclePossitions] angle %f", m_fAngle);
	Log("[c_CmmandVehiclePossitions] speed %f", m_fSpeed);
	Log("[c_CmmandVehiclePossitions] color1  %f", m_fColor_1);
	Log("[c_CmmandVehiclePossitions] color2  %f", m_fColor_2);
	}*/

	void setDesign(float design) { m_fDesign = design;  m_bInit = true; }

	bool isInit() { return m_bInit; }
	 
	float* getPtrHeadMyBuffer()
	{
		return m_headpArr;
	}


	void SetAttachMyBuffer(float* Buff)
	{
		assert(Buff != nullptr);

		assert(m_fServerID != -1);
 
		m_headpArr = Buff;

		//Buff[1] = m_fServerID; // lol crash
	}

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

	float* m_headpArr = nullptr;
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
	}

	c_CommandGetHeandleVehicle() {}

	virtual void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10)
	{

		*A1 = m_fDesign;

		*A2 = m_ClientVehicle.m_fModel;
		*A3 = m_ClientVehicle.m_fServerID;
		*A4 = m_ClientVehicle.m_fX;
		*A5 = m_ClientVehicle.m_fY;
		*A6 = m_ClientVehicle.m_fZ;

		*A7 = m_ClientVehicle.m_fHeandle;
		*A8 = -1.0;// m_ClientVehicle.m_fSpeed;

		*A9 = m_ClientVehicle.m_fColor_1;
		*A10 = m_ClientVehicle.m_fColor_2;

		writeDimToLog(*A1, *A2, *A3, *A4, *A5, *A6, *A7, *A8, *A9, *A10);
	}

	void writeDimToLog(float  A1, float  A2, float  A3, float  A4, float  A5, float  A6, float  A7, float   A8, float   A9, float   A10)
	{
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A1=%f", A1);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A2=%f", A2);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A3=%f", A3);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A4=%f", A4);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A5=%f", A5);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A6=%f", A6);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A7=%f", A7);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A8=%f", A8);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A9=%f", A9);
		Log("[c_CLEO_COMMAND_DATA] STEP_4 A10=%f", A10);
	}


	void setDesign(float design) { m_fDesign = design;  m_bInit = true; }

	bool isInit() { return m_bInit; }

public:
	float	m_fDesign = -1.0f;

private:
	bool m_bInit = false;

public:
	c_ClientVehicle m_ClientVehicle;
};


class c_CmmandPlayerActorPossitions : public c_BasePackage
{
public:
	 
	c_CmmandPlayerActorPossitions();
	c_CmmandPlayerActorPossitions(std::string recovHexPackage);

	virtual void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10);

	void writeDebugDim()
	{
		Log("[c_CmmandVehiclePossitions] design %f", m_fDesign);
		Log("[c_CmmandVehiclePossitions] servTick %f", m_ServerTick);
		Log("[c_CmmandVehiclePossitions] servID %f", m_fServerID);
		Log("[c_CmmandVehiclePossitions] model %f", m_fModel);
		Log("[c_CmmandVehiclePossitions] x %f", m_fInterior);
		Log("[c_CmmandVehiclePossitions] x %f", m_fX);
		Log("[c_CmmandVehiclePossitions] y %f", m_fY);
		Log("[c_CmmandVehiclePossitions] z %f", m_fZ);
		Log("[c_CmmandVehiclePossitions] angle %f", m_fAngle);
		Log("[c_CmmandVehiclePossitions] speed %f", m_fSpeed);
	}

	void setDesign(float design) { m_fDesign = design;  m_bInit = true; }

	bool isInit() { return m_bInit; }
	 
public:
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

private:
	std::string m_package;

	bool m_bInit = false;
};




class c_PackageManager
{
public:
	c_PackageManager();

	void add(std::string package);

	void add(std::shared_ptr <c_CmmandVehiclePossitions> VehiclePackage);

	void add(std::shared_ptr <c_CommandGetHeandleVehicle> CommandVehicle);

	void add(std::shared_ptr <c_CmmandPlayerActorPossitions> CommandVehicle);

	void cast();

	void init(float* A1, float* A2, float* A3, float* A4, float* A5
		, float* A6, float* A7, float * A8, float * A9, float * A10);

private:
	std::deque <std::shared_ptr<c_BasePackage>> m_goodParsePackage_deque;
};

#endif  

//c_VehiclePossitionsPackage tmp = static_cast<c_VehiclePossitionsPackage> (m_goodParsePackage_deque[0])