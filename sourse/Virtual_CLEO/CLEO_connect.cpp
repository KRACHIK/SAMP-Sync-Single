
#include "CLEO_connect.h"

 
void TEST_CLEO_connect_to_server::connect()
{
	// connect to server
	Init_Client_backgraund_Thr();

	// wait for not crash
	boost::this_thread::sleep(boost::posix_time::millisec(750));
}

