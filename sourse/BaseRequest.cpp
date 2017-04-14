#include "BaseRequest.h"

c_RequestDataBaseManager::c_RequestDataBaseManager()
{
	std::cout << "[c_SendRequestDataBase::c_SendRequestDataBase] create! " << "\n";
	Log("[c_SendRequestDataBase::c_SendRequestDataBase] create! ");
}


void c_RequestDataBaseManager::add(std::shared_ptr <c_BaseRequest> package)
{
	m_sendPackagedeque.emplace_back(package);
}

std::string c_RequestDataBaseManager::getFirstMessageAndPopPackage()
{
	std::string sendRequest = "-1";

	if (!emty())
	{
		sendRequest = m_sendPackagedeque[0]->getMsg();

		pop();
	}

	return sendRequest;
}

bool c_RequestDataBaseManager::emty()
{
	return m_sendPackagedeque.empty();
}

void c_RequestDataBaseManager::pop()
{
	if (!emty())
	{
		m_sendPackagedeque.pop_front();
	}
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

c_REQUEST_SAY_SELF_POSSITIONS::c_REQUEST_SAY_SELF_POSSITIONS(float ClientPassport, float design,
	float x, float y, float z, float interior, float speed) :m_fClientPassport(ClientPassport)
	, m_fdesign(design)
	, m_fx(x)
	, m_fy(y)
	, m_fz(z)
	, m_finterior(interior)
	, m_fspeed(speed)
{
	init();
}

void c_REQUEST_SAY_SELF_POSSITIONS::debugPrintvalueDim()
{
	printf(" [GameCore::sendSelfPositions] ");
	printf(" design = %f", m_fdesign);
	printf(" x = %f", m_fx);
	printf(" y = %f", m_fy);
	printf(" z = %f", m_fz);
	printf(" interior = %f ", m_finterior);

	Log("[GameCore::sendSelfPositions]");
	Log("design = %f", m_fdesign);
	Log("x = %f", m_fx);
	Log("y = %f", m_fy);
	Log("z = %f\n", m_fz);
	Log("interior = %f", m_finterior);
}

void c_REQUEST_SAY_SELF_POSSITIONS::init()
{
	c_MyUtiles m_utiles;

	m_sendPackage =
		m_utiles.IntToHEX(m_fClientPassport)		// clientPassport
		+ m_utiles.FloatToHEX(m_fdesign) 			// design
		+ m_utiles.FloatToHEX(m_fx)				// xPos
		+ m_utiles.FloatToHEX(m_fy)				// yPos
		+ m_utiles.FloatToHEX(m_fz) 				// zPos
		+ m_utiles.FloatToHEX(m_finterior) 			// cuurrient Actor interior
		+ m_utiles.FloatToHEX(m_fspeed);
}


std::string c_REQUEST_SAY_SELF_POSSITIONS::getMsg()
{
	//std::cout << "[c_REQUEST_SAY_SELF_POSSITIONS::getMsg()]" << "\n";
	//Log("[c_REQUEST_SAY_SELF_POSSITIONS::getMsg()]");

	return m_sendPackage;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
c_REQUEST_GET_VEHICLE::c_REQUEST_GET_VEHICLE(float ClientPassport, float design
	, float want_ModelCar, float xPos, float yPos, float zPos, float angle, float speed, float color1, float color2)
	:
	m_fClientPassport(ClientPassport)
	, m_want_ModelCar(want_ModelCar)
	, m_design(design)
	, m_xPos(xPos)
	, m_yPos(yPos)
	, m_zPos(zPos)
	, m_angle(angle)
	, m_speed(speed)
	, m_fColor1(color1)
	, m_fColor2(color2)
{
	init();
}

void c_REQUEST_GET_VEHICLE::init()
{
	c_MyUtiles m_utiles;

	m_sendPackage =
		m_utiles.IntToHEX(m_fClientPassport)		// clientPassport
		+ m_utiles.FloatToHEX(m_design) 			// design
		+ m_utiles.FloatToHEX(m_want_ModelCar)	// want ModelCar
		+ m_utiles.FloatToHEX(m_xPos)				// xPos
		+ m_utiles.FloatToHEX(m_yPos)				// yPos
		+ m_utiles.FloatToHEX(m_zPos)				// zPos
		+ m_utiles.FloatToHEX(m_angle)			// yPos
		+ m_utiles.FloatToHEX(m_speed)			// zPos
		+ m_utiles.FloatToHEX(m_fColor1)
		+ m_utiles.FloatToHEX(m_fColor2);


	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_design));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_fClientPassport));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_want_ModelCar));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_xPos));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_yPos));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_zPos));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_angle));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_speed));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_fColor1));
	Log("[INIT_PACKAGE_c_REQUEST_GET_VEHICLE] STEP_0 %f", (m_fColor2));
}
	  

std::string c_REQUEST_GET_VEHICLE::getMsg()
{
	return m_sendPackage;
}
