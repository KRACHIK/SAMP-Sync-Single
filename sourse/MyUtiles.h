#ifndef C_MYUTILES_H
#define C_MYUTILES_H 

#include <string>
#include <iostream>

#include <boost/thread/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

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

std::string  getMeDirectory();

void Log(const char *fmt, ...);
void LogFile(const char *fmt, ...);



class c_MyBackGraundMessageBox // not used
{
public:

	c_MyBackGraundMessageBox(std::string msg, std::string msg2);
private:
	void MyMsgBox();
	std::string m_msg;
	std::string m_msg2;
};


#endif  







