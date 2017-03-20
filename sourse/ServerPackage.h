//#pragma once
//#include <iostream>
//
//#include <vector>
//#include <string>
//#include <memory>
//
//#include <sstream>
//
//
//class c_OutPutPackage
//{
//public:
//	c_OutPutPackage(std::string byteArr){ }
//	 
//
//	virtual void printInfo() const = 0;
//
//	virtual void init(float* A1, float* A2, float* A3, float* A4, float* A5, float* A6, float* A7, float * A8, float * A9, float * A10) const = 0;
//};
//
//
//class C_VEHICLE_PACKAGE : public c_OutPutPackage
//{
//public:
//	C_VEHICLE_PACKAGE(std::stringstream& byteArr, int sizePackage);
//
//	C_VEHICLE_PACKAGE(std::string byteArr);
//
//	void printInfo() const override;
//
//	void init(float* A1, float* A2, float* A3, float* A4, float* A5
//		, float* A6, float* A7, float * A8, float * A9, float * A10) const override;
//	  
//	
//	bool isInit();
//public:
//	float	m_fServerID;
//	float	m_fModel;
//	float	m_fX;
//	float	m_fY;
//	float	m_fZ;
//	float	m_fAngle;
//	float	m_fSpeed;
//
//
//private:
//	bool m_bflagInit = 0;
//};
//
//  
////class C_VEHICLE_PAC
////{
////public:
////	float	m_fServerID;
////	float	m_fModel;
////	float	m_fX;
////	float	m_fY;
////	float	m_fZ;
////	float	m_fAngle;
////	float	m_fSpeed;
////};
////
////C_VEHICLE_PAC veh;
//// 