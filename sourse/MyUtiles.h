#ifndef C_MYUTILES_H
#define C_MYUTILES_H 

#include <string>
#include <iostream>


class c_MyUtiles
{

public:
	c_MyUtiles();
	~c_MyUtiles();

	std::string ToHEX(float Arr[], size_t size);

	std::string IntToHEX(int);

	std::string FloatToHEX(float);
private:

};

#endif  

std::string  getMeDirectory();

 

void Log(const char *fmt, ...);



