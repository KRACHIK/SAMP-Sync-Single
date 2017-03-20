#ifndef C_CLEO_CMD_MANAGER_H
#define C_CLEO_CMD_MANAGER_H
#pragma  once  

#include <iostream>
#include  <memory>
#include  <deque>

class c_CLEO_COMMAND_DATA
{
public:

	c_CLEO_COMMAND_DATA(float A1, int iPrms1, int iPrms2, float A2, float A3,
		float A4, float A5, float A6, float A7, float A8, float A9, float A10);

	c_CLEO_COMMAND_DATA();

public:

	float	m_fA1 = -1;
	int	m_iPrms1 = -1;
	int	m_iPrms2 = -1;
	float	m_fA2 = -1;
	float	m_fA3 = -1;
	float	m_fA4 = -1;
	float	m_fA5 = -1;
	float	m_fA6 = -1;
	float	m_fA7 = -1;
	float	m_fA8 = -1;
	float	m_fA9 = -1;
	float	m_fA10 = -1;

};


class c_CLEO_commandManager
{
public:
	c_CLEO_commandManager();

	void add(c_CLEO_COMMAND_DATA cmd);

	void add_p(float A1, int iPrms1, int iPrms2, float A2, float A3,
		float A4, float A5, float A6, float A7, float A8, float A9, float A10);

	bool empty();
	 
	c_CLEO_COMMAND_DATA getAndPopCLEOPrms();

	std::deque <c_CLEO_COMMAND_DATA> m_CLEO_CMD_deque;
private:
				 
};



#endif  
