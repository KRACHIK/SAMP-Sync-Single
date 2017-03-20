#pragma once

#ifndef C_VEHICLE_H
#define C_VEHICLE_H

#include "MyUtiles.h"

class c_ClientVehicle
{
public:
	c_ClientVehicle();

	c_ClientVehicle(float fHeandle, float  fServerID, float fModel, float x, float y, float z, float color_1, float color_2);

public:

	void  writeDebugLogDim()
	{
		Log("[c_ClientVehicle::writeDebugLogDim] heandle %f", m_fHeandle);
		Log("[c_ClientVehicle::writeDebugLogDim] ServId %f", m_fServerID);
		Log("[c_ClientVehicle::writeDebugLogDim] Model %f", m_fModel);
		Log("[c_ClientVehicle::writeDebugLogDim] x %f", m_fX);
		Log("[c_ClientVehicle::writeDebugLogDim] y %f", m_fY);
		Log("[c_ClientVehicle::writeDebugLogDim] z %f", m_fZ);

		Log("[c_ClientVehicle::writeDebugLogDim] color1 %f", m_fColor_1);
		Log("[c_ClientVehicle::writeDebugLogDim] color2 %f", m_fColor_2);
	}

	float m_fHeandle = -1.0f;
	float m_fServerID = -1.0f;
	float m_fModel = -1.0f;
	float m_fX = -1.0f;
	float m_fY = -1.0f;
	float m_fZ = -1.0f;

	float m_fColor_1 = -1.0f;
	float m_fColor_2 = -1.0f;
};




#endif  








