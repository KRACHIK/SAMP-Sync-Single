#include "CLEO_send_ClientVehiclePossitions.h"

#include "../ELocal_command.h"


CLEO_SEND_CLIENT_POSSITIONS_VEHICLE::CLEO_SEND_CLIENT_POSSITIONS_VEHICLE()

{
	srand(time(NULL));
}

CLEO_SEND_CLIENT_POSSITIONS_VEHICLE::~CLEO_SEND_CLIENT_POSSITIONS_VEHICLE()
{
}
  
void CLEO_SEND_CLIENT_POSSITIONS_VEHICLE::send_Client_VehiclePossitions()
{  
	Call_00A5_send_to_DLL();	// and send to server
}
 
 
