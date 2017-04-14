#include "GTA_SA_DynamicMemoryManager.h"

#include <iostream>
#include <assert.h>



void CMemoeyManager_gta_saExe::DebugPringBuffer(float* Arr)
{
	assert(Arr != nullptr);

	if (Arr == nullptr)
	{
		Log("[c_DynamicMemoryManager::DebugPringBuffer] AHTUNG HEAD Arr = nullptr");

		std::cout << ("[c_DynamicMemoryManager::DebugPringBuffer] AHTUNG HEAD Arr = nullptr\n");

		return;
	}

	float *MyBuff = &Arr[0];

	for (int i = 0; i < m_CountElementsSize4Byte; i++)
	{
		Log("[c_DynamicMemoryManager::DebugPringBuffer] i = %d, val = %f", i, MyBuff[i]);

		printf("\n[c_DynamicMemoryManager::DebugPringBuffer] i = %d, val = %f", i, MyBuff[i]);
	}
}

bool CMemoeyManager_gta_saExe::IsRunGTA()
{
	HWND hWnd = FindWindow(NULL, "GTA:SA:MP");
	if (hWnd == NULL)
		return false;

	//if (IsIconic(hWnd)) return false; // если окно найдено но свернто 
	return true;
}

int CMemoeyManager_gta_saExe::GetMaxCountVehileOfPool()
{
	DWORD* m_p1_BaseVehiclePool;

	DWORD* m_BaseVehiclePoolCuurrentSize;

	m_p1_BaseVehiclePool = (DWORD*)0xB74494;
	m_BaseVehiclePoolCuurrentSize = (DWORD*)(*m_p1_BaseVehiclePool + 0x8);
	return *m_BaseVehiclePoolCuurrentSize;
}

int CMemoeyManager_gta_saExe::GetVehicleCurreentSizePool()
{

	DWORD* m_p1_BaseVehiclePool;
	DWORD* m_p2_BaseVehiclePool;
	DWORD* m_BaseVehiclePoolCuurrentSize;

	m_p1_BaseVehiclePool = (DWORD*)0xB74494;	//0A8D: 28@ = read_memory 0xB74494 size 4 virtual_protect 0 // Указатель на первый элемент в пуле транспорта 

	m_p2_BaseVehiclePool = (DWORD*)(*m_p1_BaseVehiclePool); // 0A8D: 28@ = read_memory 28@ size 4 virtual_protect 0

	m_BaseVehiclePoolCuurrentSize = (DWORD*)(*m_p1_BaseVehiclePool + 0xC);

	Log("[CMemoeyManager_gta_saExe::GetVehicleCurreentSizePool] VehiclePoolCuurrentSize =  %d ", *m_BaseVehiclePoolCuurrentSize);

	return *m_BaseVehiclePoolCuurrentSize;
}



void CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool()
{
	Log("[CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool]");

	int CountVehicle = GetVehicleCurreentSizePool();

	/*
	не робит
	if (CountVehicle > 0)
	{
		DWORD *pDVehiclePool;

		pDVehiclePool = (DWORD*)0xB74494;

		DWORD *NextElement;

		for (int i = 0; i < CountVehicle - 1; i++)
		{
			NextElement = (DWORD*)*pDVehiclePool;

			//...
			float* HealthVehicle;

			HealthVehicle = (float*)(*NextElement + 0x4C0);

			Log("[CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool] *HealthVehicle = %f, NextElement = %d *NextElement = %d\n", *HealthVehicle, NextElement, *NextElement);

			// действие
			pDVehiclePool = (DWORD*)*pDVehiclePool + 0xA18;
		}
	}*/


#if 0 // робит. но только с первой найденой тачкой 
	DWORD *pDVehiclePool;
	pDVehiclePool = (DWORD*)0xB74494;
	Log("[CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool] pDVehiclePool %d  *pDVehiclePool = %d", pDVehiclePool, *pDVehiclePool);
	DWORD *firstElement;
	firstElement = (DWORD*)*pDVehiclePool;
	Log("[CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool] firstElement %d  *firstElement = %d", firstElement, *firstElement);
	float* HealthVehicle;
	HealthVehicle = (float*)(*firstElement + 0x4C0);
	Log("[CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool] *firstElement + 0x4C0 = %d  ", *firstElement + 0x4C0);
	Log("[CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool] HealthVehicle = %f", *HealthVehicle);
	// *HealthVehicle = 1.0f;
	Log("[CMemoeyManager_gta_saExe::FlameFirstVehicleOfPool] Set HealthVehicle = %f", *HealthVehicle);
#endif


}



float* CMemoeyManager_gta_saExe::CreateBuffer()
{
	float *Arr = new float[m_CountElementsSize4Byte];

	for (size_t i = 0; i < m_CountElementsSize4Byte; i++)
		Arr[i] = i + 13;

	return Arr;
}

class CPed
{
	DWORD* Base;
	float* Health;
	float* Armour;
	DWORD* XYZMatrix;
	float* X;
	float* Y;
	float* Z;

public:
	CPed();
	void Kill();
	void SetHealth(float hp);
	void SetArmour(float ar);
	void FixLags();
};

void CMemoeyManager_gta_saExe::AttachBufferToGameVehicleStruct(DWORD* MyBuffer, c_ClientVehicle &GameStruct)
{
	Log("[c_DynamicMemoryManager::AttachBufferToGameVehicleStruct(] kill");

	/*CPed Player;

	Player.Kill();*/

	//DWORD AddressVehicleStruct = static_cast<DWORD> (GameStruct.m_fHeandle);

	//DWORD* p = (DWORD*)(AddressVehicleStruct + 0x4C0);

	//Log("[c_DynamicMemoryManager::AttachBufferToGameVehicleStruct] CarHealch! %f", *p);
}



CPed::CPed()
{
	Base = (DWORD*)0xB6F5F0;
}
void CPed::Kill()
{
	Log("CPed::Kill()");

	if (Base != NULL)
	{
		if (Health == NULL)
			Health = (float*)(*Base + 0x540);

		if (Armour == NULL)
			Armour = (float*)(*Base + 0x548);

		*Health = 0.0;
		*Armour = 0.0;
	}
	Log("CPed::Kill() end");
}
void CPed::SetHealth(float hp)
{
	if (Base != NULL)
	{
		if (Health == NULL) Health = (float*)(*Base + 0x540);
		if (hp < 0.0)hp = 0.0;
		if (hp > 100.0)hp = 100.0;
		*Health = hp;
	}
}
void CPed::SetArmour(float ar)
{
	if (Base != NULL)
	{
		if (Armour == NULL) Armour = (float*)(*Base + 0x548);
		if (ar < 0.0)ar = 0.0;
		if (ar > 100.0)ar = 100.0;
		*Armour = ar;
	}
}
void CPed::FixLags()
{
	if (Base != NULL)
	{
		if (XYZMatrix == NULL) XYZMatrix = (DWORD*)(*Base + 0x14);
		if (X == NULL) X = (float*)(*XYZMatrix + 0x30);
		if (Y == NULL) Y = (float*)(*XYZMatrix + 0x34);
		if (Z == NULL) Z = (float*)(*XYZMatrix + 0x38);

		*X += 1000.0;
		*Y += 1000.0;
		*Z += 1000.0;
		Sleep(200);
		*X -= 1000.0;
		*Y -= 1000.0;
		*Z -= 1000.0;
	}
}
