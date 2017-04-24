#ifndef C_MYUTILES_H
#define C_MYUTILES_H 

#include <string>
#include <iostream>

#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class c_MyUtiles
{

public:
	c_MyUtiles();
	~c_MyUtiles();

	std::string ToHEX(float Arr[], size_t size);

	std::string IntToHEX(int);

	std::string FloatToHEX(float);
private:

};

std::string  getMeDirectory();

std::string getFindFileToken(std::string fileName, std::string findToken);

void Log(const char *fmt, ...);
void LogFile(const char *fmt, ...);



class c_MyBackGraundMessageBox // not used
{
public:

	c_MyBackGraundMessageBox(std::string msg, std::string msg2);
private:
	void MyMsgBox();
	std::string m_msg;
	std::string m_msg2;
};





class CPoint3D
{
public:
	CPoint3D() {};

	 
	CPoint3D(float x, float y, float z) : m_X(x), m_Y(y), m_Z(z)
	{

	}


	void Set(float x, float y, float z)
	{
		m_X = x;
		m_Y = y;
		m_Z = z;
	}

	void Set(CPoint3D point3D)
	{
		m_X = point3D.m_X;
		m_Y = point3D.m_Y;
		m_Z = point3D.m_Z;
	}


	CPoint3D Get() { return *this; }

	float GetX() { return m_X; }
	float GetY() { return m_Y; }
	float GetZ() { return m_Z; }


private:
	float m_X = 0.0f;
	float m_Y = 0.0f;
	float m_Z = 0.0f;

};


class c_Compute
{
public:
	c_Compute(){};
	~c_Compute(){};

	double Distance(CPoint3D Point1, CPoint3D Point2);

	 
};




#endif  








