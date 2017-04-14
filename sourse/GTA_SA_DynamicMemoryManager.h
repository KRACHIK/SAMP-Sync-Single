#pragma  once

#ifndef C_DYNAMIC_MEMORY_MANAGER_FOR_GTA_SA_EXE_H
#define C_DYNAMIC_MEMORY_MANAGER_FOR_GTA_SA_EXE_H

//class c_ClientVehicle; // head v cpp
#include "Vehicle.h"

#include <windows.h>

#include "MyUtiles.h"

class c_DynamicMemoryManager
{
public:
	c_DynamicMemoryManager(int m_CountElementsSize4byte);

	void DebugPringBuffer(float* Arr);
			 


	bool  getStatusBigBang();

	float* CreateBuffer();

	void AttachBufferToGameVehicleStruct(DWORD* MyBuffer, c_ClientVehicle &GameStruct);

private:
	int m_CountElementsSize4Byte;

};

#endif  


