//#pragma once

#ifndef C_CLEO_SEND_CLIENT_POSSITIONS_VEHICLE_H
#define C_CLEO_SEND_CLIENT_POSSITIONS_VEHICLE_H


#include "CLEO_machine.h"
 
class CLEO_SEND_CLIENT_POSSITIONS_VEHICLE : public CLEO_machine
{
public:
	CLEO_SEND_CLIENT_POSSITIONS_VEHICLE();

	~CLEO_SEND_CLIENT_POSSITIONS_VEHICLE();

	 
	void send_Client_VehiclePossitions();
}; 

#endif  