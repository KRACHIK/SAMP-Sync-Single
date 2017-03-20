#include "CLEO_manager.h"
#include "MyUtiles.h"

c_CLEO_COMMAND_DATA::c_CLEO_COMMAND_DATA(float A1, int iPrms1, int iPrms2, float A2, float A3, float A4, float A5, float A6, float A7, float A8, float A9, float A10) :
m_fA1(A1),
m_iPrms1(iPrms1),
m_iPrms2(iPrms2),
m_fA2(A2),
m_fA3(A3),
m_fA4(A4),
m_fA5(A5),
m_fA6(A6),
m_fA7(A7),
m_fA8(A8),
m_fA9(A9),
m_fA10(A10)
{

}

c_CLEO_COMMAND_DATA::c_CLEO_COMMAND_DATA()
{

}


c_CLEO_commandManager::c_CLEO_commandManager()
{
	Log("[c_CLEO_commandManager::c_CLEO_commandManager()] Create!");
}

void c_CLEO_commandManager::add_p(float A1, int iPrms1, int iPrms2, float A2, float A3, float A4, float A5, float A6, float A7, float A8, float A9, float A10)
{
	c_CLEO_COMMAND_DATA cmd(A1, iPrms1, iPrms2, A2, A3, A4, A5, A6, A7, A8, A9, A10);

	m_CLEO_CMD_deque.push_front(cmd);
	//m_CLEO_CMD_deque.push_back(cmd);
}

bool c_CLEO_commandManager::empty()
{
	return m_CLEO_CMD_deque.empty();
}

c_CLEO_COMMAND_DATA c_CLEO_commandManager::getAndPopCLEOPrms()
{
	if (!empty())
	{
		c_CLEO_COMMAND_DATA prms = m_CLEO_CMD_deque[0];

		m_CLEO_CMD_deque.pop_front();

		return prms;
	}
	else
	{
		return c_CLEO_COMMAND_DATA();
	}
}
