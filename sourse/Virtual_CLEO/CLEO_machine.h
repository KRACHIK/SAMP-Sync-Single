#pragma once
 
#ifndef C_CLEO_MACHINE_H
#define C_CLEO_MACHINE_H

#include "..//package_type.h"
#include "..//MyUtiles.h"
#include "..//core.h"
#include "..//input_output_cleo_prms.h"
 
#include <iostream>
#include <ctime>

//#pragma comment(lib, "..//project/Release/SAMP++.lib")          

//#ifdef DEBUG
//#pragma comment(lib, "..//project/Debug/SAMP++.lib")          
//#endif
//
//#ifndef DEBUG
////#pragma comment(lib, "..//project/Release/SAMP++.lib")          
//#endif

//#pragma comment(lib, "..//project/Release/SAMP++.lib")  
#pragma comment(lib, "..//project/Debug/SAMP++.lib")          

class CLEO_machine
{
public:
	CLEO_machine();

	CLEO_machine(float A1, float A2, float A3, float A4, float A5
		, float A6, float A7, float A8, float A9, float A10);

	void initPtr();

	void initZeroDim();

	void initCleoDim(float A1, int iPrms1, int iPrms2, float A2, float A3, float A4, float A5
		, float A6, float A7, float A8, float A9, float A10);

	void print_value_Dim();

	void Call_00A5_send_to_DLL();

	void CALL_00A5_read_RECIVER_DLL();

public:

	int	m_iPrms_1, m_iPrms_2;

	float m_fPRMS_1, m_fPRMS_2
		, m_fPRMS_3, m_fPRMS_4
		, m_fPRMS_5, m_fPRMS_6
		, m_fPRMS_7, m_fPRMS_8
		, m_fPRMS_9, m_fPRMS_10;

	float *m_ptr1, *m_ptr2
		, *m_ptr3, *m_ptr4
		, *m_ptr5, *m_ptr6
		, *m_ptr7, *m_ptr8
		, *m_ptr9, *m_ptr10;
};

#endif  