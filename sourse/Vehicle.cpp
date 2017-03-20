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
	 
{
	assert(m_fHeandle > 0);
	assert(m_fServerID >= 0);

	assert(m_fColor_1 >= 0);
	assert(m_fColor_2 >= 0);
}
	  





c_ClientVehicle::c_ClientVehicle()
{
}