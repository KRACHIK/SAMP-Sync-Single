//#pragma once

#ifndef C_CLEO_SEND_REQUEST_CAR_SPAWN_H
#define C_CLEO_SEND_REQUEST_CAR_SPAWN_H


#include "CLEO_machine.h"
 
class TEST_GET_CAR_INFO_for_SPAWN : public CLEO_machine
{
public:
	TEST_GET_CAR_INFO_for_SPAWN();

	~TEST_GET_CAR_INFO_for_SPAWN();

	void request_car_spawn();
	void potential_place_to_spawn_car();

	void start_Thr_generate_spawn_pos_car();
}; 

#endif  