#include "CLEO_machine.h"

#ifndef C_CLEO_RECIVER_H
#define C_CLEO_RECIVER_H


class TEST_CLEO_Reciver : public CLEO_machine
{
public:
	TEST_CLEO_Reciver(); 
	~TEST_CLEO_Reciver(); 

	void ThrReciver();
	void start(); 


	void isRecovCommandVehiclePossitions();

	void isRecovCommandVehicleSpawn();

private:
	int m_Test_IheandleVehicle_exe;
};


#endif  