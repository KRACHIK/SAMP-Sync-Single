#pragma  once

#ifndef C_DYNAMIC_MEMORY_MANAGER_FOR_GTA_SA_EXE_H
#define C_DYNAMIC_MEMORY_MANAGER_FOR_GTA_SA_EXE_H



#define GTA_SA_EXE_CLASS_CPool_Vehicle	 0xB74494


#include "Vehicle.h"

#include <windows.h>

#include "MyUtiles.h"



class CMemoeyManager_gta_saExe
{
public: 

	float* CreateBuffer();
	void AttachBufferToGameVehicleStruct(DWORD* MyBuffer, c_ClientVehicle &GameStruct);
	void DebugPringBuffer(float* Arr);
	 

	bool IsRunGTA();

	int GetMaxCountVehileOfPool();
	int GetVehicleCurreentSizePool();

	void FlameFirstVehicleOfPool();
private:
 
	int m_CountElementsSize4Byte = -1;
};

#endif  


