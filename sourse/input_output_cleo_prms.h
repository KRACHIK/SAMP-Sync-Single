#ifndef C_INPUT_OUTPUT_CLEO_PRMS_H
#define C_INPUT_OUTPUT_CLEO_PRMS_H

#include <boost/shared_ptr.hpp>
#include <boost/thread/thread.hpp>
#include <thread>

#include "core.h"

//#include "package_type.h"


void Init_UDP_Client();

extern "C" __declspec(dllexport) void Init_Client_backgraund_Thr(); // CALL :A007 


extern "C" __declspec(dllexport) void Public_InPutDimByCLEO(
	/* fDesign */ float* A1
	/* iPrms */, int iPrms1, int iPrms2
	/* fPrms_i */, float* A2, float* A3, float* A4, float* A5
	/* fPrms_i */, float* A6, float* A7, float * A8, float * A9, float * A10
	);

extern "C" __declspec(dllexport) void Public_OUTPUT_DimByCLEO(float* A1, float* A2, float* A3, float* A4, float* A5
	, float* A6, float* A7, float * A8, float * A9, float * A10);

#endif  
// 