#ifndef C_CORE_H
#define C_CORE_H

#include "UDP_network.h" 

#include "Decisions_making.h"

#include "MyUtiles.h"

#include "BaseRequest.h"
  
class GameCore
{
public:
	GameCore(c_Network_UDP* network);
	~GameCore();
 
//network
public:
	void NetworkSend(char*);
	void thrReciver();
	void send_GetServCarID(float design, float ModelCar, float x, float y, float z, float angle, float speed);
	void INPUT_Dim_ByCLEO(float A1, int iPrms1, int iPrms2, float A2, float A3, float A4, float A5, float A6, float A7, float A8, float A9, float A10);

private:
	void sendSelfPositions(float design, float interior, float x, float y, float z, float speed);
	void sendPotential_place_to_spawn_car(float design, float model, float x, float y, float z, float angle, float speed);
	 

public:
	void intiLolalCommand(float A1, int iPrms1, int iPrms2, float A2, float A3, float A4, 
		float A5, float A6, float A7, float A8, float A9, float A10);
	 
public:
	std::shared_ptr	<c_recov_Decisions> m_Design_Maker;
	 
	std::shared_ptr	<c_RequestDataBaseManager> m_requestDataBase;
	 
private:
	c_Network_UDP*	m_network;

	c_MyUtiles		m_utiles;

	unsigned int	m_ClientPassport;

private:
	void  _TEST_send_admin_cmd(float design, const std::string & messaga);
};
 
#endif  






