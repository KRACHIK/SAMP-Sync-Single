#include "Vehicle.h" 
#include <assert.h>   


c_ClientVehicle::c_ClientVehicle(float fHeandle, float  fServerID, float fModel, float x, float y, float z, float color_1, float color_2)
	:
	m_fHeandle(fHeandle)
	, m_fServerID(fServerID)
	, m_fModel(fModel)
	, m_fX(x)
	, m_fY(y)
	, m_fZ(z)
	, m_fColor_1(color_1)
	, m_fColor_2(color_2)
	, m_pMyBuffer(nullptr)
{
	assert(m_fHeandle > 0);
	assert(m_fServerID >= 0);

	assert(m_fColor_1 >= 0);
	assert(m_fColor_2 >= 0);
}
	  
c_ClientVehicle::c_ClientVehicle()
{
}

void c_ClientVehicle::writeDebugLogDim()
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
