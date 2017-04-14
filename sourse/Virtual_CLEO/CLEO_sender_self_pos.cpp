#include "CLEO_sender_self_pos.h"

#include <boost/thread/thread.hpp>

void TEST_CLEO_SELF_POSITIONS_SENDER::ThrInit_Dim_for_send_Pos_2()
{
	srand(time(0));
	float m_step_x = 0.6, m_step_y = 1.17;
	float x = rand() % 10, y = rand() % 10, z = 10.1;
	float fInterior = 1.0f;
	float fSpeed = 20.0f;

	while (true)
	{
		x += m_step_x;	y += m_step_y;

		//call sendSelfPositions(float design, float interior, float x, float y, float z, float speed);
		//std::cout << "[TEST_CLEO_SELF_POSITIONS_SENDER::ThrInit_Dim_for_send_Pos_2]"  << "\n";
		// std::cout << " x = " << x << "\n";
		// std::cout << " y = " << y << "\n";

		initCleoDim((float)eHeaderPackage::RPC_PLAYER_ACTOR_POSSITIONS, -1L, -1L, x, y, z, fInterior, fSpeed, -1
			, -1.0f
			, -1.0f
			, -1.0f
			);

		Call_00A5_send_to_DLL();

		boost::this_thread::sleep(boost::posix_time::millisec(4101));
	}
}

void TEST_CLEO_SELF_POSITIONS_SENDER::startThr_Self_Pos()
{
	boost::thread thrPosSender = boost::thread(&TEST_CLEO_SELF_POSITIONS_SENDER::ThrInit_Dim_for_send_Pos_2, this);
	thrPosSender.detach();
} 