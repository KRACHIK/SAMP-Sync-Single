#include "core.h"

std::shared_ptr<GameCore> glMyCLEO_Core;

std::deque <c_OutputValue> gl_Queue_PRMS;

std::deque <c_OutputValue> gl_c_OutputValue_Deque_PRMS;



GameCore::GameCore(c_Network_UDP* network) : m_network(network)
{
	std::cout << "[GameCore::GameCore] create!" << "\n";

	m_Veh_Manager = std::make_shared<c_VehicleManager>();

	m_Design_Maker = std::make_shared<c_recov_Decisions>();

	boost::thread thrRecov(&GameCore::thrReciver, this);
	thrRecov.detach();
}

GameCore::~GameCore()
{
	m_utiles.~c_MyUtiles();
}

void GameCore::thrReciver()
{
	std::cout << "[GameCore::thrRecov()] start" << "\n";
	while (true)
	{
		std::string package = (*m_network).recov();

		std::cout << "[GameCore::thrReciver()] <- " << package << "\n";

		m_Design_Maker->Decisions_Making_call_choice(package);

		// work code!
		//if (package.length() >= 4)
		//{
		//	std::stringstream byteArr(package);

		//	float fServerDesign = 0;

		//	byteArr.read((char*)&fServerDesign, 4);

		//	int iDesign = fServerDesign;

		//	switch (iDesign)
		//	{

		//	case 2:
		//		 
		//		std::cout << "unBoxPackageVehicle unBoxPackageVehicle unBoxPackageVehicle unBoxPackageVehicle" << "\n";
		//		unBoxPackageVehicle(byteArr, iDesign); // box prms for cleo
		//		break;

		//	default:
		//		break;
		//	}
		//}
	}
}

void GameCore::NetworkSend(char * msg)
{
	(*m_network).Mysend(msg);
}

void GameCore::INPUT_Dim_ByCLEO(float A1, float A2, float A3, float A4, float A5, float A6, float A7)
{
	// print input PRMS [debug] 
	printf("[GameCore::INPUT_Dim_ByCLEO] %f %f %f %f %f \n", A1, A2, A3, A4, A5);

	Log("[GameCore::INPUT_Dim_ByCLEO] %f %f %f %f %f \n", A1, A2, A3, A4, A5);

	Beep(1000, 200);

	int design = (int)A1;

	switch (design)
	{
	case 1:
		// hz
		break;

	case 2:
		sendGetServCarID(A1, A2, A3, A4, A5); // -> design, fWant_Model , x, y, z
		Log("[GameCore::INPUT_Dim_ByCLEO] sendGetServCarID %f %f %f %f %f \n", A1, A2, A3, A4, A5);

		Beep(500, 1100);

		break;


	case 3:
		//void refresh_vehicle_map(int serverID, int model, float x, float y, float z);
		m_Veh_Manager->refresh_vehicle_map(
			(int)A2		/*serverID*/
			, (int)A3	/*model*/
			, (int)A4	/*HeandleMemory*/
			, A5		/*Pos */
			, A6		/*Pos */
			, A6		/*Pos */
			);

		break;

	default:
		break;
	}
}

void GameCore::sendGetServCarID(float design, float want_ModelCar, float xPos, float yPos, float zPos)
{

	printf("[GameCore::sendGetServCarID boxPrms]"
		"\n\t design = %f"
		"\n\t modelCar= %f "
		"\n\t x= %f y= %f z= %f \n"
		, design
		, want_ModelCar
		, xPos
		, yPos
		, zPos
		);

	// package = int_CLIENT_IDintificator + int_design
	unsigned int passport = 65535;
	std::string package =
		m_utiles.IntToHEX(passport)			// clientPassport
		+ m_utiles.FloatToHEX(design) 		// design
		+ m_utiles.FloatToHEX(want_ModelCar)	// want ModelCar
		+ m_utiles.FloatToHEX(xPos)			// xPos
		+ m_utiles.FloatToHEX(yPos)			// yPos
		+ m_utiles.FloatToHEX(zPos);			// zPos

	(*m_network).Mysend(package);
}

void GameCore::unBoxPackageVehicle(std::stringstream& byteArr, int iDesign)
{
	int serverID;	// control size byteArr
	int iModel;
	float X;
	float Y;
	float Z;

	byteArr.read((char*)&serverID, 4);
	byteArr.read((char*)&iModel, 4);
	byteArr.read((char*)&X, 4);
	byteArr.read((char*)&Y, 4);
	byteArr.read((char*)&Z, 4);

	c_OutputValue tmp;

	tmp.iDesign = iDesign;
	tmp.iServID = serverID;
	tmp.iModel = iModel;
	tmp.fX = X;
	tmp.fY = Y;
	tmp.fZ = Z;

	gl_Queue_PRMS.push_back(tmp);
}

void Init_UDP_Client()
{
	std::string ip("127.0.0.1");	//getFindFileToken("KRACHIK_setting.txt", "ip");			//ip	("127.0.0.1");
	std::string port("7778");		//getFindFileToken("KRACHIK_setting.txt", "port");		//port		("7778");

	std::cout << "[InitConnect] getFindFileToken ip: " << ip << "\n";
	std::cout << "[InitConnect] getFindFileToken port: " << port << "\n";

	boost::asio::io_service io_service;

	// create Network object
	c_Network_UDP player(io_service, ip, port);

	// init core 
	glMyCLEO_Core = std::make_shared<GameCore>(&player);
	Beep(4000, 400);
	// for glMyCLEO_Core not deatch
	while (true)
	{
		//std::cout << "[thr void Public_Init_UDP_Client()]" << "\n";
		boost::this_thread::sleep(boost::posix_time::seconds(4));
		//glMyCLEO_Core->NetworkSend("REG");
	}
}

extern "C" __declspec(dllexport) void Init_Client_backgraund_Thr() // CALL :A007
{
	std::cout << "[void Init_Client_backgraund_Thr]" << "\n";
	Log("[void Init_Client_backgraund_Thr]");

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init_UDP_Client, NULL, 0, 0);
	boost::this_thread::sleep(boost::posix_time::seconds(1));
}

extern "C" __declspec(dllexport) void Public_InPutDimByCLEO(float* A1, float* A2, float* A3, float* A4, float* A5, float* A6, float* A7)
{
	Log("[extern void Public_InPutDimByCLEO] \n\t prms = (%f %f %f %f %f %f %f)\n"
		, *A1
		, *A2
		, *A3
		, *A4
		, *A5
		, *A6
		, *A7);

	printf("[extern void Public_InPutDimByCLEO] \n\t prms = (%f %f %f %f %f)\n"
		, *A1
		, *A2
		, *A3
		, *A4
		, *A5);

	glMyCLEO_Core->INPUT_Dim_ByCLEO(*A1, *A2, *A3, *A4, *A5, *A6, *A7);
}

extern "C" __declspec(dllexport) void Public_OUTPUT_DimByCLEO(float* A1, float* A2, float* A3, float* A4, float* A5, float* A6, float* A7)
{
	Log("[extern void Public_OUTPUT_DimByCLEO]");
	// read stack Box package
	*A1 = 0;
	*A2 = 0;
	*A3 = 0;
	*A4 = 0;
	*A5 = 0;
	*A6 = 0;
	*A7 = 0;

	Beep(444, 444);

	if (!gl_Queue_PRMS.empty())
	{
		switch (gl_Queue_PRMS[0].iDesign)
		{
		case 2:
			if (gl_Queue_PRMS[0].iServID != -1)
			{
				Log("[extern void Public_OUTPUT_DimByCLEO] case 2");
				*A1 = (float)gl_Queue_PRMS[0].iDesign;
				*A2 = (float)gl_Queue_PRMS[0].iServID;
				*A3 = (float)gl_Queue_PRMS[0].iModel;
				*A4 = gl_Queue_PRMS[0].fX;
				*A5 = gl_Queue_PRMS[0].fY;
				*A6 = gl_Queue_PRMS[0].fZ;
				// not reliz angle;
				gl_Queue_PRMS.pop_front(); 	// delete 
			}
			break;

		default:
			std::cout << "[GameCore::INPUT_Dim_ByCLEO !gl_Queue_PRMS.empty() defailt]" << "\n";
			break;
		}	// end switch

		// print Info [debug]
		printf("[CLEO]->"
			"\n\t prms_1: '%f'"
			"\n\t prms_2: '%f'"
			"\n\t prms_3: '%f'"
			"\n\t prms_4: '%f'"
			"\n\t prms_5: '%f'"
			"\n\t prms_6: '%f'"
			"<- [CLEO]\n"
			, *A1
			, *A2
			, *A3
			, *A4
			, *A5
			, *A6
			, *A7
			);

	}	// end  !gl_Queue_PRMS.empty() 

}


c_recov_Decisions::c_recov_Decisions()
{
	std::cout << "[PackageManager::PackageManager] create" << "\n";
}

c_recov_Decisions::~c_recov_Decisions()
{
	std::cout << "[PackageManager::~PackageManager] destroy" << "\n";
}


void c_recov_Decisions::Decisions_Making_call_choice(const std::string& input_Hex_Package)
{
	if (input_Hex_Package.length() >= 4) // size 1 prms = 4 byte
	{
		std::stringstream byteArr(input_Hex_Package);

		float fDesign = 0;

		byteArr.read((char*)&fDesign, 4);

		int iDesign = fDesign;
		 
		switch (iDesign)
		{

		case 2:
			Add_Vehicle_Queue_PRMS(byteArr, iDesign); // box prms for cleo
			break;
			 
		default:
			break;
		}
	}
}
 
// for read Cleo Script
void c_recov_Decisions::Add_Vehicle_Queue_PRMS(std::stringstream& byteArr, int iDecisions_making)
{
	// control size byteArr if (byteArr.size() == ? )

	int serverID, iModel;;	
	float X, Y, Z;
	 
	byteArr.read((char*)&serverID, 4);
	byteArr.read((char*)&iModel, 4);
	byteArr.read((char*)&X, 4);
	byteArr.read((char*)&Y, 4);
	byteArr.read((char*)&Z, 4);

	c_OutputValue tmp;

	tmp.iDesign = iDecisions_making;
	tmp.iServID = serverID;
	tmp.iModel = iModel;
	tmp.fX = X;
	tmp.fY = Y;
	tmp.fZ = Z;

	gl_c_OutputValue_Deque_PRMS.push_back(tmp);
}

































