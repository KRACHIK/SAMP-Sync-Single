#include "CLEO_machine.h"


CLEO_machine::CLEO_machine()
{
	// std::cout << "\n[CLEO_machine] create!" << "\n";
	initZeroDim();
	initPtr();
}

CLEO_machine::CLEO_machine(float A1, float A2, float A3, float A4, float A5,
	float A6, float A7, float A8, float A9, float A10)
	:
	m_fPRMS_1(A1)
	, m_fPRMS_2(A2)
	, m_fPRMS_3(A3)
	, m_fPRMS_4(A4)
	, m_fPRMS_5(A5)
	, m_fPRMS_6(A6)
	, m_fPRMS_7(A7)
	, m_fPRMS_8(A8)
	, m_fPRMS_9(A9)
	, m_fPRMS_10(A10)
{
	initPtr();
}

void CLEO_machine::initPtr()
{
	m_ptr1 = &m_fPRMS_1;	m_ptr2 = &m_fPRMS_2;	m_ptr3 = &m_fPRMS_3;	m_ptr4 = &m_fPRMS_4;
	m_ptr5 = &m_fPRMS_5;	m_ptr6 = &m_fPRMS_6;	m_ptr7 = &m_fPRMS_7;

	m_ptr8 = &m_fPRMS_8;
	m_ptr9 = &m_fPRMS_9;
	m_ptr10 = &m_fPRMS_10;
}

void CLEO_machine::initZeroDim()
{
	m_iPrms_1 = 0;			m_iPrms_2 = 0;
	m_fPRMS_1 = 0.0f;		m_fPRMS_2 = 0.0f;		m_fPRMS_3 = 0.0f;		m_fPRMS_4 = 0.0f;
	m_fPRMS_5 = 0.0f;		m_fPRMS_6 = 0.0f;		m_fPRMS_7 = 0.0f;
	m_fPRMS_8 = 0.0f;		m_fPRMS_9 = 0.0f;		m_fPRMS_10 = 0.0f;
}

void CLEO_machine::initCleoDim(float A1, int iPrms1, int iPrms2, float A2, float A3, float A4, float A5,
	float A6, float A7, float A8, float A9, float A10)
{
	m_iPrms_1 = iPrms1;
	m_iPrms_2 = iPrms2;
	m_fPRMS_1 = A1;
	m_fPRMS_2 = A2;
	m_fPRMS_3 = A3;
	m_fPRMS_4 = A4;
	m_fPRMS_5 = A5;
	m_fPRMS_6 = A6;
	m_fPRMS_7 = A7;
	m_fPRMS_8 = A8;
	m_fPRMS_9 = A9;
	m_fPRMS_10 = A10;
}

void CLEO_machine::Call_00A5_send_to_DLL()
{
	Public_InPutDimByCLEO(m_ptr1, m_iPrms_1, m_iPrms_2, m_ptr2, m_ptr3, m_ptr4, m_ptr5, m_ptr6, m_ptr7, m_ptr8, m_ptr9, m_ptr10);
}

void CLEO_machine::CALL_00A5_read_RECIVER_DLL()
{
	boost::this_thread::sleep(boost::posix_time::millisec(150));
	Public_OUTPUT_DimByCLEO(m_ptr1, m_ptr2, m_ptr3, m_ptr4, m_ptr5, m_ptr6, m_ptr7, m_ptr8, m_ptr9, m_ptr10);
}

void CLEO_machine::print_value_Dim()
{
	// printf("\n[CLEO_machine::print_value_Dim] ");
	// std::cout << "\nfPrms_1 = " << m_fPRMS_1 << " ";
	// std::cout << "\nfPrms_2 = " << m_fPRMS_2 << " ";
	// std::cout << "\nfPrms_3 = " << m_fPRMS_3 << " ";
	// std::cout << "\nfPrms_4 = " << m_fPRMS_4 << " ";
	// std::cout << "\nfPrms_5 = " << m_fPRMS_5 << " ";
	// std::cout << "\nfPrms_6 = " << m_fPRMS_6 << " ";
	// std::cout << "\nfPrms_7 = " << m_fPRMS_7 << " ";
	// std::cout << "\n" << "\n";
	Log("\n[CLEO_machine::print_value_Dim] "
		" prms_1: '%f'"
		" prms_2: '%f'"
		" prms_3: '%f'"
		" prms_4: '%f'"
		" prms_5: '%f'"
		" prms_6: '%f'"
		" prms_7: '%f'"
		"<- [CLEO]\n\n"
		, m_fPRMS_1, m_fPRMS_2, m_fPRMS_3, m_fPRMS_4, m_fPRMS_5, m_fPRMS_6, m_fPRMS_7, m_fPRMS_8, m_fPRMS_9, m_fPRMS_10);
}
