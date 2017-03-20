#include "MyUtiles.h"
#include <windows.h>

FILE	*g_flLog = NULL;

void MyMsgBox(const std::string msg, const std::string msg2)
{

}

FILE	*g_flLogAll = NULL;

char	g_szSAMPVer[16];
char	g_szWorkingDirectory[256];

c_MyUtiles::c_MyUtiles()
{
	std::cout << "[c_MyUtiles] create!" << "\n";
}

c_MyUtiles::~c_MyUtiles()
{
	std::cout << "[c_MyUtiles] Destroy!" << "\n";
}


std::string c_MyUtiles::ToHEX(float Arr[], size_t size)
{
	if (size == 0)
		return "";

	std::string Package;
	for (size_t i = 0; i < size; i++)
	{
		std::string tmpStr((char*)&Arr[i], 4);
		Package += tmpStr;
	}
	return Package;
}


std::string c_MyUtiles::IntToHEX(int Value)
{
	std::string tmpStr((char*)&Value, 4);
	return tmpStr;
}


std::string c_MyUtiles::FloatToHEX(float Value)
{
	std::string tmpStr((char*)&Value, 4);
	return tmpStr;
}




std::string  getMeDirectory()
{
	char buffer[MAX_PATH];
	GetCurrentDirectory(sizeof(buffer), buffer);
	std::string str(buffer);
	return str;
}


void Log(const char *fmt, ...)
{
	strcpy(g_szWorkingDirectory, getMeDirectory().c_str());

	if (!g_szWorkingDirectory) return;

	SYSTEMTIME	time;
	va_list		ap;

	if (g_flLog == NULL)
	{
		char	filename[512];
		_snprintf(filename, sizeof(filename), "%s\\%s", g_szWorkingDirectory, "NetworkCore.log");

		g_flLog = fopen(filename, "w");
		if (g_flLog == NULL)
			return;
	}

	GetLocalTime(&time);
	fprintf(g_flLog, "[%02d:%02d:%02d.%03d] ", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);

	va_start(ap, fmt);
	vfprintf(g_flLog, fmt, ap);
	va_end(ap);
	fprintf(g_flLog, "\n");
	fflush(g_flLog);

	if (g_flLogAll == NULL)
	{
		char	filename_all[512];
		_snprintf(filename_all, sizeof(filename_all), "%s\\%s", g_szWorkingDirectory, "NetworkCore_all.log");

		g_flLogAll = fopen(filename_all, "a");
		if (g_flLogAll == NULL)
			return;
	}

	GetLocalTime(&time);
	fprintf(g_flLogAll, "[%02d-%02d-%02d || %02d:%02d:%02d.%03d] ", time.wDay, time.wMonth, time.wYear, time.wHour,
		time.wMinute, time.wSecond, time.wMilliseconds);
	va_start(ap, fmt);
	vfprintf(g_flLogAll, fmt, ap);
	va_end(ap);
	fprintf(g_flLogAll, "\n");
	fflush(g_flLogAll);
}


void LogFile(const char *fmt, ...)
{
	strcpy(g_szWorkingDirectory, getMeDirectory().c_str());

	if (!g_szWorkingDirectory) return;

	SYSTEMTIME	time;
	va_list		ap;

	if (g_flLog == NULL)
	{
		char	filename[512];
		_snprintf(filename, sizeof(filename), "%s\\%s", g_szWorkingDirectory, "2NetworkCore.log");

		g_flLog = fopen(filename, "w");
		if (g_flLog == NULL)
			return;
	}

	GetLocalTime(&time);
	fprintf(g_flLog, "[%02d:%02d:%02d.%03d] ", time.wHour, time.wMinute, time.wSecond, time.wMilliseconds);

	va_start(ap, fmt);
	vfprintf(g_flLog, fmt, ap);
	va_end(ap);
	fprintf(g_flLog, "\n");
	fflush(g_flLog);

	if (g_flLogAll == NULL)
	{
		char	filename_all[512];
		_snprintf(filename_all, sizeof(filename_all), "%s\\%s", g_szWorkingDirectory, "2NetworkCore_all.log");

		g_flLogAll = fopen(filename_all, "a");
		if (g_flLogAll == NULL)
			return;
	}

	GetLocalTime(&time);
	fprintf(g_flLogAll, "[%02d-%02d-%02d || %02d:%02d:%02d.%03d] ", time.wDay, time.wMonth, time.wYear, time.wHour,
		time.wMinute, time.wSecond, time.wMilliseconds);
	va_start(ap, fmt);
	vfprintf(g_flLogAll, fmt, ap);
	va_end(ap);
	fprintf(g_flLogAll, "\n");
	fflush(g_flLogAll);
}


c_MyBackGraundMessageBox::c_MyBackGraundMessageBox(std::string msg, std::string msg2)
	: m_msg(msg)
	, m_msg2(msg2)
{
	boost::thread thrRecov(&c_MyBackGraundMessageBox::MyMsgBox, this);
	thrRecov.detach();
}

void c_MyBackGraundMessageBox::MyMsgBox()
{
	MessageBoxA(0, m_msg.c_str(), m_msg2.c_str(), 0);
}
