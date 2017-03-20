cmake_minimum_required(VERSION 2.6)

project(SAMP++)

set(cmake_archive_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_library_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_runtime_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
file( GLOB SOURCE_CODE
	
	sourse/EXE_main.h
	sourse/EXE_main.cpp
	
	sourse/Virtual_CLEO/CLEO_connect.cpp
	sourse/Virtual_CLEO/CLEO_connect.h
	
	sourse/Virtual_CLEO/CLEO_machine.cpp
	sourse/Virtual_CLEO/CLEO_machine.h
	
	sourse/Virtual_CLEO/CLEO_reciver.cpp
	sourse/Virtual_CLEO/CLEO_reciver.h
	
	sourse/Virtual_CLEO/CLEO_reg_heandle_from_Pool.cpp
	sourse/Virtual_CLEO/CLEO_reg_heandle_from_Pool.h
	
	sourse/Virtual_CLEO/CLEO_send_request_car_spawn.cpp
	sourse/Virtual_CLEO/CLEO_send_request_car_spawn.h
	
	sourse/Virtual_CLEO/CLEO_sender_self_pos.cpp
	sourse/Virtual_CLEO/CLEO_sender_self_pos.h 
)
source_group("" FILES ${SOURCE_CODE})
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)
find_package(Boost COMPONENTS system filesystem program_options regex thread chrono REQUIRED)
if(Boost_FOUND)
	if(MSVC)
		if (COMMAND cmake_policy)
		CMAKE_POLICY(SET CMP0003 NEW)
		endif(COMMAND cmake_policy)
		set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   /MTd /Zi /Ob0 /Od /EHsc /RTC1 /D_DEBUG")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /O2 /Ob2") 
		add_definitions(-D _CRT_SECURE_NO_WARNINGS)
		add_definitions(/sdl /EHsc /Od /RTC1 /GS)
	endif()
	include_directories(${Boost_INCLUDE_DIR})
	add_executable(client_EXE ${SOURCE_CODE})
	# link_libraries(${Boost_LIBRARIES})
	target_link_libraries(client_EXE ${Boost_LIBRARIES})
endif()
 
#================================================================================================
set(cmake_archive_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_library_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_runtime_output_directory ${CMAKE_HOME_DIRECTORY}/bin)

file( GLOB SOURCE_CODE
   
	sourse/core.h
	sourse/core.cpp
	   
	sourse/input_output_cleo_prms.h
	sourse/input_output_cleo_prms.cpp
	
	sourse/MyUtiles.h
	sourse/MyUtiles.cpp
	  
	sourse/Output_Deque.h
	sourse/Output_Deque.cpp
	 
	sourse/package_type.h
	
	sourse/ELocal_command.h
  
	sourse/CLEO_manager.h
	sourse/CLEO_manager.cpp
   
	sourse/Decisions_making.h
	sourse/Decisions_making.cpp
	
	sourse/ServerPackage.h
	sourse/ServerPackage.cpp
	
	sourse/ServerVehicle.h
	sourse/ServerVehicle.cpp
	
	sourse/UDP_network.h
	sourse/UDP_network.cpp
	
	sourse/Vehicle.h
	sourse/Vehicle.cpp
	
	sourse/VehicleManager.h
	sourse/VehicleManager.cpp 
	
	sourse/BaseRequest.h
	sourse/BaseRequest.cpp 
	
	sourse/poolVehicleManager.h
	sourse/poolVehicleManager.cpp 
  
)
source_group("" FILES ${SOURCE_CODE})
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)
find_package(Boost COMPONENTS system filesystem program_options regex thread chrono REQUIRED)
if(Boost_FOUND)
	if(MSVC)
		if (COMMAND cmake_policy)
		CMAKE_POLICY(SET CMP0003 NEW)
		endif(COMMAND cmake_policy)
		set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG}   /MTd /Zi /Ob0 /Od /EHsc /RTC1 /D_DEBUG")
		set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT /O2 /Ob2") 
		add_definitions(-D _CRT_SECURE_NO_WARNINGS)
		add_definitions(/sdl /EHsc /Od /RTC1 /GS)
	endif()
	set ( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
	
	add_library( SAMP++ SHARED ${SOURCE_CODE} )
	
	# link_libraries(${Boost_LIBRARIES})
	include_directories(${Boost_INCLUDE_DIR})
	  
endif()
  














 