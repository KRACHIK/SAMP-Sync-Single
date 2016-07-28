cmake_minimum_required(VERSION 2.6)

set(cmake_archive_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_library_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_runtime_output_directory ${CMAKE_HOME_DIRECTORY}/bin)

project(client_EXE)

file( GLOB SOURCE_CODE
	C++/EXE_main.h
	C++/EXE_main.cpp
)
source_group("" FILES ${SOURCE_CODE})

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)
 
find_package(Boost COMPONENTS system filesystem program_options date_time regex thread chrono REQUIRED)

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
	target_link_libraries(client_EXE ${Boost_LIBRARIES})
endif()

set(cmake_archive_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_library_output_directory ${CMAKE_HOME_DIRECTORY}/bin)
set(cmake_runtime_output_directory ${CMAKE_HOME_DIRECTORY}/bin)

project(KRACHIK_client_Dll_2016)

file( GLOB SOURCE_CODE
	C++/DLL_client.cpp
	C++/DLL_client.h
	C++/DLL_main.cpp
)
source_group("" FILES ${SOURCE_CODE})

set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME     ON)
 
find_package(Boost COMPONENTS system filesystem program_options date_time regex thread chrono REQUIRED)

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

	add_library( client_Dll_2016 SHARED ${SOURCE_CODE} )

	include_directories(${Boost_INCLUDE_DIR})
 
endif()

  		




















 