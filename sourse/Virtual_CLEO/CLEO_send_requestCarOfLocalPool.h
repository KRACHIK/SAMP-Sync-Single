//#pragma once

#ifndef C_CLEO_GET_HEANDLE_VEH_OF_POOL_H
#define C_CLEO_GET_HEANDLE_VEH_OF_POOL_H


#include "CLEO_machine.h"
 
class TEST_GET_HEANDLE_VEHICLE_OF_POOL : public CLEO_machine
{
public:
	TEST_GET_HEANDLE_VEHICLE_OF_POOL();

	~TEST_GET_HEANDLE_VEHICLE_OF_POOL();

	void start();
	void _Thr_While_True();

	void request_car_of_pool();
}; 

#endif  