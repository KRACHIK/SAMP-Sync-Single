#ifndef C_CLEO_CMD_MANAGER_H
#define C_CLEO_CMD_MANAGER_H
#pragma  once  

#include <iostream>
#include  <memory>
#include  <deque>

#include  "MyUtiles.h"
 
class c_CLEO_COMMAND_DATA
{
public:

	c_CLEO_COMMAND_DATA(float A1, int iPrms1, int iPrms2, float A2, float A3,
		float A4, float A5, float A6, float A7, float A8, float A9, float A10);

	c_CLEO_COMMAND_DATA();
	 
	void writeDimToLog(int step)
	{
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A1=%f",		step, m_fA1);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d prms1=%d",	step, m_iPrms1);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d prms2=%d",	step, m_iPrms2);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A2=%f",		step, m_fA2);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A3=%f",		step, m_fA3);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A4=%f",		step, m_fA4);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A5=%f",		step, m_fA5);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A6=%f",		step, m_fA6);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A7=%f",		step, m_fA7);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A8=%f",		step, m_fA8);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A9=%f",		step, m_fA9);
		Log("[c_CLEO_COMMAND_DATA] STEP_%d A10=%f",		step, m_fA10);
	}

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
