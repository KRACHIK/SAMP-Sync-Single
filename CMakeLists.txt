cmake_minimum_required(VERSION 2.6)

project(SAMP++)

set(cmake_archive_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_library_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_runtime_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
file( GLOB SOURCE_CODE
	sourse/EXE_main.h
	sourse/EXE_main.cpp
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
	sourse/UDP_network.cpp
	sourse/UDP_network.h
	
	sourse/core.cpp
	sourse/core.h
	
	sourse/Object_List.cpp
	sourse/Object_List.h
	
	sourse/MyUtiles.cpp
	sourse/MyUtiles.h
	
	sourse/DLL_main.cpp 
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
  














 