//#include "ServerPackage.h"
//#include "MyUtiles.h"
//
//#include <windows.h> 
// 
//// constructor
//C_VEHICLE_PACKAGE::C_VEHICLE_PACKAGE(std::stringstream& byteArr, int sizePackage)
//{
//	// 4
//	byteArr.read((char*)&m_fServerID, 4);
//	byteArr.read((char*)&m_fModel, 4);
//	byteArr.read((char*)&m_fX, 4);
//	byteArr.read((char*)&m_fY, 4);
//	byteArr.read((char*)&m_fZ, 4);
//	byteArr.read((char*)&m_fAngle, 4);
//	byteArr.read((char*)&m_fSpeed, 4);
//}
//
//C_VEHICLE_PACKAGE::C_VEHICLE_PACKAGE(std::string byteArr)
//{
//
//	std::cout << "this is ok " << "\n";
//}
//
//void C_VEHICLE_PACKAGE::printInfo() const
//{
//	Log(" %f", m_fModel);		// LOL ?
//	Log(" %f", m_fServerID);	// LOL ?
//	Log(" %f", m_fX);
//	Log(" %f", m_fY);
//	Log(" %f", m_fZ);
//	Log(" %f", m_fAngle);
//	Log(" %f", m_fSpeed);
//
//	MessageBoxA(0, " ", " lol ", 0);
//}
//
//void C_VEHICLE_PACKAGE::init(float* A1, float* A2, float* A3, float* A4, float* A5
//	, float* A6, float* A7, float * A8, float * A9, float * A10) const
//{
//	*A2 = m_fModel;		// LOL ?
//	*A3 = m_fServerID;	// LOL ?
//	*A4 = m_fX;
//	*A5 = m_fY;
//	*A6 = m_fZ;
//	*A7 = m_fAngle;
//	*A8 = m_fSpeed;
//}
//
//bool C_VEHICLE_PACKAGE::isInit()
//{
//	return m_bflagInit;
//}
//
//
