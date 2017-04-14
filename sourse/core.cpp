#pragma once

#include "core.h"
#include "package_type.h"
#include "ELocal_command.h"


GameCore::GameCore(c_Network_UDP* network) : m_network(network)
{
	std::cout << "[GameCore::GameCore] create!" << "\n";
	Log("[GameCore::GameCore] create!");

	m_ClientPassport = 443332211;

	m_Design_Maker = std::make_shared<c_recov_Decisions>();

	m_requestDataBase = std::make_shared<c_RequestDataBaseManager>();

	boost::thread thrRecov(&GameCore::thrReciver, this);
	thrRecov.detach();
	m_network->Mysend("GameCore Init");
}

GameCore::~GameCore()
{
	// std::cout << "[GameCore::~GameCore()] Destroy!" << "\n";
	m_utiles.~c_MyUtiles();
}

void GameCore::thrReciver()
{
	// std::cout << "[GameCore::thrRecov()] start" << "\n";
	while (true)
	{
		std::string package = (*m_network).recov();

		//std::cout << "package" << package << "\n";

		Log("\n\n[GameCore::thrReciver] size recov = %d \n", package.length());

		// std::cout << "[GameCore::thrReciver()]  size recov = ", package.length());

		m_Design_Maker->new_parsing_package_2017(package);
	}
}

void GameCore::NetworkSend(char * msg)
{
	(*m_network).Mysend(msg);
}


void GameCore::INPUT_Dim_ByCLEO(float A1, int iPrms1, int iPrms2, float A2, float A3, float A4, float A5, float A6, float A7, float A8, float A9, float A10)
{
	boost::this_thread::sleep(boost::posix_time::millisec(1));

	// print input PRMS [debug] 
	//printf("\n[GameCore::INPUT_Dim_ByCLEO] %f %d %d %f %f %f %f %f %f %f \t", A1, iPrms1, iPrms2, A2, A3, A4, A5, A6, A7, A8, A9, A10);

#if 0
	Log(" ");
	Log("[GameCore::INPUT_Dim_ByCLEO] 1=%f", A1);
	Log("[GameCore::INPUT_Dim_ByCLEO] i1=%d", iPrms1);
	Log("[GameCore::INPUT_Dim_ByCLEO] i2=%d", iPrms2);
	Log("[GameCore::INPUT_Dim_ByCLEO] 2=%f", A3);
	Log("[GameCore::INPUT_Dim_ByCLEO] 3=%f", A4);
	Log("[GameCore::INPUT_Dim_ByCLEO] 4=%f", A5);
	Log("[GameCore::INPUT_Dim_ByCLEO] 5=%f", A6);
	Log("[GameCore::INPUT_Dim_ByCLEO] 6=%f", A7);
	Log("[GameCore::INPUT_Dim_ByCLEO] 7=%f", A8);
	Log("[GameCore::INPUT_Dim_ByCLEO] 8=%f", A9);
	Log("[GameCore::INPUT_Dim_ByCLEO] 9=%f", A10);
#endif

	int design = (int)A1;

	std::shared_ptr	<c_BaseRequest> intitbaseRequest;
	//switch input Network prms
	switch (design)
	{
		// get server info for car spawn
	case static_cast <int> (EDESIGN_COMMAND::CMD_SPAWN_VEHICLE) :

		intitbaseRequest = std::make_shared<c_REQUEST_GET_VEHICLE>((float)m_ClientPassport, A1, A2, A3, A4, A5, A6, A7, A8, A9);

		Log("\n[input CleoAdminToolsSpawn] %f %f %f\t", A8, A9, A10);
		 
		m_requestDataBase->add(intitbaseRequest);

		//send_GetServCarID(A1, A2, A3, A4, A5, A6, A7); // -> design, fWant_Model , x, y, z, angle, speed
		break;

	case static_cast <int> (eHeaderPackage::RPC_PLAYER_ACTOR_POSSITIONS) :
		sendSelfPositions(A1, A2, A3, A4, A5, A6);

		/*intitbaseRequest = std::make_shared<c_REQUEST_SAY_SELF_POSSITIONS>((float)m_ClientPassport, A1, A2, A3, A4, A5, A6);
		m_requestDataBase->add(intitbaseRequest);*/
		break;
		  
	default:
		Log("[GameCore::INPUT_Dim_ByCLEO] case default design=%d", design);
		break;
	}


	m_Design_Maker->m_CLEO_Manager->add_p(A1, iPrms1, iPrms2, A2, A3, A4, A5, A6, A7, A8, A9, A10);

	m_Design_Maker->computeGameWord();


#if 1
	// send to server
	if (!m_requestDataBase->emty())
	{
		(*m_network).Mysend(m_requestDataBase->getFirstMessageAndPopPackage());
	}
#endif
}


void GameCore::send_GetServCarID(float design, float want_ModelCar, float xPos, float yPos, float zPos, float angle, float speed)
{
	printf("[GameCore::send_GetServCarIDboxPrms] "
		" design = %f"
		" modelCar= %f "
		" x= %f y= %f z= %f"
		" angle %f"
		" speed %f"
		, design, want_ModelCar, xPos, yPos, zPos, angle, speed);

	Log("[GameCore::send_GetServCarIDboxPrms] ");
	Log(" design = %f", design);
	Log(" modelCar = %f ", want_ModelCar);
	Log(" x = %f ", xPos);
	Log(" x = %f ", yPos);
	Log(" x = %f ", zPos);
	Log(" angle = %f", angle);
	Log(" speed = %f\n\n", speed);

	std::string package =
		m_utiles.IntToHEX(m_ClientPassport)		// clientPassport
		+ m_utiles.FloatToHEX(design) 			// design
		+ m_utiles.FloatToHEX(want_ModelCar)	// want ModelCar
		+ m_utiles.FloatToHEX(xPos)				// xPos
		+ m_utiles.FloatToHEX(yPos)				// yPos
		+ m_utiles.FloatToHEX(zPos)				// zPos
		+ m_utiles.FloatToHEX(angle)			// yPos
		+ m_utiles.FloatToHEX(speed);			// zPos

	(*m_network).Mysend(package);
}


void GameCore::sendSelfPositions(float design, float x, float y, float z, float interior, float speed)
{
//	printf(" [GameCore::sendSelfPositions] ");
//	printf(" design = %f", design);
//	printf(" x = %f", x);
//	printf(" y = %f", y);
//	printf(" z = %f", z);
//	printf(" interior = %f \n", interior);

	Log("[GameCore::sendSelfPositions]");
	Log("design = %f", design);
	Log("x = %f", x);
	Log("y = %f", y);
	Log("z = %f\n", z);
	Log("interior = %f", interior);

	std::string package =
		m_utiles.IntToHEX(m_ClientPassport)		// clientPassport
		+ m_utiles.FloatToHEX(design) 			// design
		+ m_utiles.FloatToHEX(x)				// xPos
		+ m_utiles.FloatToHEX(y)				// yPos
		+ m_utiles.FloatToHEX(z) 				// zPos
		+ m_utiles.FloatToHEX(interior) 			// cuurrient Actor interior
		+ m_utiles.FloatToHEX(speed);

	(*m_network).Mysend(package);

	Beep(200, 100);
}


void GameCore::sendPotential_place_to_spawn_car(float design, float model, float x, float y, float z, float angle, float speed)
{
	/*initCleoDim(8.0f, 1L, 1L, model, x, y, z, angle, speed);*/

	printf("[GameCore::sendPotential_place_to_spawn_car] ");
	printf("design = %f", design);
	printf("x = %f", x);
	printf("y = %f", y);
	printf("z = %f\t", z);

	Log("[GameCore::sendPotential_place_to_spawn_car]\n");
	Log("design = %f", design);
	Log("x = %f", x);
	Log("y = %f", y);
	Log("z = %f\n", z);

	std::string package =
		m_utiles.IntToHEX(m_ClientPassport)		// clientPassport
		+ m_utiles.FloatToHEX(design) 			// design
		+ m_utiles.FloatToHEX(model)
		+ m_utiles.FloatToHEX(x)				// xPos
		+ m_utiles.FloatToHEX(y)				// yPos
		+ m_utiles.FloatToHEX(z)  				// zPos
		+ m_utiles.FloatToHEX(angle)
		+ m_utiles.FloatToHEX(speed);

	(*m_network).Mysend(package);
}


void GameCore::_TEST_send_admin_cmd(float design, const std::string & messaga)
{
	std::cout << "[GameCore::_TEST_send_admin_cmd] " << "\n";
	std::string package =
		m_utiles.IntToHEX(m_ClientPassport)		// clientPassport
		+ m_utiles.FloatToHEX(design) 			// design
		+ messaga;
	(*m_network).Mysend(package);
}















