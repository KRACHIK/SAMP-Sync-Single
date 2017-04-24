#include "ServerVehicle.h"

#include "MyUtiles.h"

//=====================================================================================================================
c_ServerVehicle::c_ServerVehicle(float  fServerID, float fModel, float x, float y, float z, float fAngle, float fSpeed, float color_1, float color_2)
	:
	m_fServerID(fServerID)
	, m_fModel(fModel)
	, m_fX(x)
	, m_fY(y)
	, m_fZ(z)
	, m_fAngle(fAngle)
	, m_fSpeed(fSpeed)
	, m_fColor_1(color_1)
	, m_fColor_2(color_2)
{

}

void c_ServerVehicle::set(float x, float y, float z, float fAngle, float fSpeed, float color_1, float color_2)
{
	m_fX = x;
	m_fY = y;
	m_fZ = z;
	m_fSpeed = fSpeed;
	m_fAngle = fAngle;
		
	m_fColor_1 = (color_1);
	m_fColor_2 = (color_2);
}

void c_ServerVehicle::DebugPrintValueDIM()
{
	Log("[c_ServerVehicle::writeDebugLogDim] ServId %f", m_fServerID);
	Log("[c_ServerVehicle::writeDebugLogDim] Model %f", m_fModel);
	Log("[c_ServerVehicle::writeDebugLogDim] x %f", m_fX);
	Log("[c_ServerVehicle::writeDebugLogDim] y %f", m_fY);
	Log("[c_ServerVehicle::writeDebugLogDim] z %f", m_fZ);

	Log("[c_ServerVehicle::writeDebugLogDim] color1 %f", m_fColor_1);
	Log("[c_ServerVehicle::writeDebugLogDim] color2 %f", m_fColor_2);

	Log("[c_ServerVehicle::writeDebugLogDim] fAngle %f", m_fAngle);
	Log("[c_ServerVehicle::writeDebugLogDim] fSpeed %f", m_fSpeed);
}
