#include "UDP_network.h"

c_Network_UDP::c_Network_UDP(boost::asio::io_service& io_service
	, const std::string& host
	, const std::string& port) :
	io_service_(io_service)
	, socket_(io_service, udp::endpoint(udp::v4(), 0))
{
	std::cout << "[c_Network_UDP::c_Network_UDP] Create!" << "\n";
	std::cout << "[c_Network_UDP::c_Network_UDP] ip " << host << ":" << port << "\n";

	udp::resolver resolver(io_service_);
	udp::resolver::query query(udp::v4(), host, port);
	udp::resolver::iterator iter = resolver.resolve(query);
	endpoint_ = *iter;
}

void c_Network_UDP::Mysend(const std::string& msg)
{
	std::cout << "[network void send] ->" << msg << "\n";
	socket_.send_to(boost::asio::buffer(msg, msg.size()), endpoint_);
}

std::string c_Network_UDP::recov()
{
	char buff[1024];
	int bytes = socket_.receive_from(boost::asio::buffer(buff), endpoint_);
	std::string msg(buff, bytes);

	//std::cout << "[c_Network_UDP recov]	<-" << msg << "\n";

	if (bytes < 1024){
		return msg;
	}
	else{
		std::cout << "[c_Network_UDP::recov] AHTING RECOV DOHUIA byte" << "\n";
	}

	return "-1"; // not reliz
}

//int i = 0;//for (i = 0; i < bytes; i++) m_ptr_buf_recever[i] = m_buff[i];//m_ptr_buf_recever[++i] = '\0';

