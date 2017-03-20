#pragma once
#include "MyUtiles.h"
#include <string>
#include <memory>
#include <iostream>

//class c_REQUEST_SAY_SELF_POSSITIONS;
//class c_SendRequestDataBase;
//class c_BaseRequest;

class c_BaseRequest
{
public:
	virtual void init() = 0;
	virtual std::string getMsg() = 0;
};


class c_REQUEST_SAY_SELF_POSSITIONS : public c_BaseRequest
{
public:

	c_REQUEST_SAY_SELF_POSSITIONS(float ClientPassport, float design, float x, float y, float z, float interior, float speed);

	virtual void init();

	virtual std::string getMsg();

	void debugPrintvalueDim();

private:

	float m_fClientPassport;
	float m_fdesign;
	float m_fx;
	float m_fy;
	float m_fz;
	float m_finterior;
	float m_fspeed;

	std::string m_sendPackage;
};


class c_REQUEST_GET_VEHICLE : public c_BaseRequest
{
public:
	 
	c_REQUEST_GET_VEHICLE(float ClientPassport, float design, float want_ModelCar,
		float xPos, float yPos, float zPos, float angle, float speed, float color1, float color2);

	virtual void init();

	std::string getMsg();

	void debugPrintvalueDim();

private:

	float m_fClientPassport;
	float m_want_ModelCar;
	float m_design;
	float m_xPos;
	float m_yPos;
	float m_zPos;
	float m_angle;
	float m_speed;
	 
	float m_fColor1;
	float m_fColor2;

	std::string m_sendPackage;
};


class c_RequestDataBaseManager
{
public:
	c_RequestDataBaseManager();

	void add(std::shared_ptr <c_BaseRequest> package);
	  
	std::string getFirstMessageAndPopPackage();

	bool emty();

private:

	void pop();
	 
	std::deque <std::shared_ptr<c_BaseRequest>> m_sendPackagedeque;
};
