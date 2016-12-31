#include <iostream>
#include "core.h"
#pragma comment(lib, "..//project/Release/SAMP++.lib")          




void VIRTUAL_CLEO_MASHINE()
{
	std::cout << "VIRTUAL_CLEO_MASHINE is Start" << "\n";

	float fPRMS_1 = 2.0;
	float fPRMS_2 = 0;
	float fPRMS_3 = 0;
	float fPRMS_4 = 0;
	float fPRMS_5 = 0;
	float fPRMS_6 = 0;
	float fPRMS_7 = 0;

	float * ptr1 = &fPRMS_1;
	float * ptr2 = &fPRMS_2;
	float * ptr3 = &fPRMS_3;
	float * ptr4 = &fPRMS_4;
	float * ptr5 = &fPRMS_5;
	float * ptr6 = &fPRMS_6;
	float * ptr7 = &fPRMS_7;

	while (true)
	{
		// fPRMS_1 = 2.0; => getServerCarID
		Public_OUTPUT_DimByCLEO(ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7);

		boost::this_thread::sleep(boost::posix_time::millisec(50));
	}
}

void VIRTUAL_CLEO_REALISTIC_DEBUG()
{
	Init_Client_backgraund_Thr();		// connect to server

	//	cleo DIM
	float fPRMS_1 = 0.0f;
	float fPRMS_2 = 0.0f;
	float fPRMS_3 = 0.0f;
	float fPRMS_4 = 0.0f;
	float fPRMS_5 = 0.0f;
	float fPRMS_6 = 0.0f;
	float fPRMS_7 = 0.0f;

	float * ptr1 = &fPRMS_1;
	float * ptr2 = &fPRMS_2;
	float * ptr3 = &fPRMS_3;
	float * ptr4 = &fPRMS_4;
	float * ptr5 = &fPRMS_5;
	float * ptr6 = &fPRMS_6;
	float * ptr7 = &fPRMS_7;

	// SEND GET CAR SPAWN
	fPRMS_1 = 2.0;		// design
	fPRMS_2 = 411;		// wantModel
	fPRMS_3 = 11.1f;	// x
	fPRMS_4 = 12.2f;	// y
	fPRMS_5 = 13.3f;	// z
	fPRMS_6 = 12.2f;	// y
	fPRMS_7 = 13.3f;	// z
	Public_InPutDimByCLEO(ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7);



	// read reciver DataStack
	boost::this_thread::sleep(boost::posix_time::millisec(1150));

	Public_OUTPUT_DimByCLEO(ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7);
	if ((int)*ptr1 == 2)
	{
		printf("[VIRTUAL_CLEO_REALISTIC_DEBUG]->"
			"\n\t prms_1: design '%f'"
			"\n\t prms_2: serverCarID '%f'"
			"\n\t prms_3: model'%f'"
			"\n\t prms_4: x'%f'"
			"\n\t prms_5: y'%f'"
			"\n\t prms_6: z'%f'"
			"<- [VIRTUAL_CLEO_REALISTIC_DEBUG]\n"
			, *ptr1
			, *ptr2
			, *ptr3
			, *ptr4
			, *ptr5
			, *ptr6
			, *ptr7
			);

		//refresh_vehicle_map(int serverID, int model, int iHeandle, float x, float y, float z);

		*ptr1 = 3.0; // design init HeandleMemory
		*ptr7 = 1123456;
		Public_InPutDimByCLEO(ptr1, ptr2, ptr3, ptr7, ptr4, ptr5, ptr6);

	}

	//// read reciver DataStack
	Public_OUTPUT_DimByCLEO(ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7);
	Public_OUTPUT_DimByCLEO(ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7);
	Public_OUTPUT_DimByCLEO(ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7);

}

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");

	//boost::thread while_thr(VIRTUAL_CLEO_MASHINE);
	//while_thr.detach();

	VIRTUAL_CLEO_REALISTIC_DEBUG();

	std::cin.get();
	system("pause");
	return 0;
}

//void testQueue()
//{
//#include <deque>
//#include <stack>
//#include "Object_List.h"
//
//	std::deque <c_OutputValue> gl_Queue_PRMS;
//
//	for (int i = 0; i < 3; i++)
//	{
//		c_OutputValue  tmp;
//		tmp.iDesign = 2 + i;
//		tmp.iModel = 411 + i;
//		gl_Queue_PRMS.push_back(tmp);
//	}
//	while (!gl_Queue_PRMS.empty())
//	{
//		// UnBox
//		int design = gl_Queue_PRMS[0].iDesign;
//		int model = gl_Queue_PRMS[0].iModel;
//
//		std::cout << "--------------------" << "\n";
//		std::cout << "model " << model << "\n";
//		std::cout << "design " << design << "\n";
//
//		// delete
//		gl_Queue_PRMS.pop_front();
//	}
//	std::cout << "в контейнеере осталось: " << gl_Queue_PRMS.size() << " элементов" << "\n";
//
//
//
//}


