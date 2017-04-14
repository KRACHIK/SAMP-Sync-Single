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

	void  writeDebugLogDim();

	float m_fHeandle = -1.0f;
	float m_fServerID = -1.0f;
	float m_fModel = -1.0f;
	float m_fX = -1.0f;
	float m_fY = -1.0f;
	float m_fZ = -1.0f;

	float m_fColor_1 = -1.0f;
	float m_fColor_2 = -1.0f;

	float* m_pMyBuffer;
};




#endif  








