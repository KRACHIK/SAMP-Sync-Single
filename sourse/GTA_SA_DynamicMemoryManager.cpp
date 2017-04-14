#include "GTA_SA_DynamicMemoryManager.h"

#include <iostream>
#include <assert.h>

c_DynamicMemoryManager::c_DynamicMemoryManager(int sizeBuffer) : m_CountElementsSize4Byte(sizeBuffer)
{
	bool f = true;

	//assert(f == false);

	std::cout << "[c_DynamicMemoryManager::c_DynamicMemoryManager()] Create!" << "\n";
}

void c_DynamicMemoryManager::DebugPringBuffer(float* Arr)
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

bool c_DynamicMemoryManager::getStatusBigBang()
{

	return false;
}

float* c_DynamicMemoryManager::CreateBuffer()
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

void c_DynamicMemoryManager::AttachBufferToGameVehicleStruct(DWORD* MyBuffer, c_ClientVehicle &GameStruct)
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
 