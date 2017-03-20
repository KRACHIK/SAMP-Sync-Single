#include "ServerVehicle.h"

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
