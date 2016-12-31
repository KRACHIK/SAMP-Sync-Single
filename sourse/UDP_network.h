#pragma once

#ifdef WIN32
#define _WIN32_WINNT 0x0501
#include <stdio.h>
#endif

#ifndef C_UDP_NETWORK_H
#define C_UDP_NETWORK_H 

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp> 

#include <iostream>
#include <fstream> 
#include <cstdlib>
#include <string>
 
using boost::asio::ip::udp;

class c_Network_UDP
{
public:
	c_Network_UDP(boost::asio::io_service& io_service
		, const std::string& host
		, const std::string& port);

	std::string recov();

	void Mysend(const std::string& package);

private:
	 
	std::string					host;
	std::string					port;

	boost::asio::io_service&	io_service_;
	udp::socket					socket_;
	udp::endpoint				endpoint_;
};

#endif  
