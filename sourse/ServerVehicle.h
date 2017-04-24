#pragma once

#ifndef C_SERVER_VEHICLE_H
#define C_SERVER_VEHICLE_H

class c_ServerVehicle
{
public:

	c_ServerVehicle()
	{
	}


	c_ServerVehicle(float  fServerID, float fModel, float x, float y, float z, float fAngle, float fSpeed, float color_1, float color_2 );

	void set(float x, float y, float z, float fAngle, float fSpeed, float color_1, float color_2);

	void DebugPrintValueDIM();
	 
	float	m_fServerID		= -1.0f;
	float	m_fModel		= -1.0f;
	float	m_fX			= -1.0f;
	float	m_fY			= -1.0f;
	float	m_fZ			= -1.0f;
	float	m_fAngle		= -1.0f;
	float	m_fSpeed		= -1.0f;
	 						 
	float	m_fColor_1		= -1.0f;
	float	m_fColor_2		= -1.0f;

};



#endif  








