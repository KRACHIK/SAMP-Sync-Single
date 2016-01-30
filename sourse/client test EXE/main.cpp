#include <iostream>

#include <time.h>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 

extern "C" __declspec(dllexport)	int			main_start(int);
extern "C" __declspec(dllexport)	void		MeCoord(char *s);
extern "C" __declspec(dllexport)	int			UnloadSocket(int a);
extern "C" __declspec(dllexport)	int			head_ptr_arr(int a);
extern "C" __declspec(dllexport)	int			head_ptr_arr_CarPed(int a);
extern "C" __declspec(dllexport)	float		test(int a);
extern "C" __declspec(dllexport)	int  		prms2(int a);
extern "C" __declspec(dllexport)	int  		Border(float x, float y);
extern "C" __declspec(dllexport)	int  		Get_id_Actor(int a);
extern "C" __declspec(dllexport)	int  		Get_id_Car(int a);
extern "C" __declspec(dllexport)	int 		Car_Spawn_Pos(int StoronaDorogi, float x, float y, float z);
extern "C" __declspec(dllexport)	void 		Get_Me_Pos(float x, float y, float z);
extern "C" __declspec(dllexport)	int 		Get_X(int a);
extern "C" __declspec(dllexport)	int 		Get_Y(int a);
extern "C" __declspec(dllexport)	int 		Get_Z(int a); 




extern "C" __declspec(dllexport) int 	Get_X(int a)
{
	return  a;// carSpawn.X_Left_Up;
}

extern "C" __declspec(dllexport) int Get_Y(int a)
{
	return  a;// carSpawn.Y_Left_Up;
}

extern "C" __declspec(dllexport) int Get_Z(int a)
{
	return a; //carSpawn.Z_Left_Up;
}

extern "C" __declspec(dllexport)	int head_ptr_arr_CarPed(int a)
{

	return 1;
}
