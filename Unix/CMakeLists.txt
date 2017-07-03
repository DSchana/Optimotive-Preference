cmake_minimum_required(VERSION 2.8)

project( Optimotive )
find_package( OpenCV )
find_package( WiringPi )
find_package( Threads )

file(GLOB_RECURSE Optimotive_SOURCES "../Optimotive/*.cpp")
file(GLOB_RECURSE Optimotive_HEADERS "../Optimotive/*.h")

set(Optimotive_INCLUDE_DIRS "")
foreach(_headerFile ${Optimotive_HEADERS})
	get_filename_component(_dir ${_headerFile} PATH)
	list(APPEND Optimotive_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES Optimotive_INCLUDE_DIRS)

set(CMAKE_CXX_STANDARD 11) # C++11...=	
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...

add_definitions(-lwiringPi -std=c++0x)  # compile flags
include_directories(${Optimotive_INCLUDE_DIRS} ${OpenCV_INCLUDE_DIRS}i ${WIRINGPI_INCLUDE_DIRS})
add_executable(Optimotive ${Optimotive_SOURCES})

target_link_libraries(Optimotive ${OpenCV_LIBS})
target_link_libraries(Optimotive ${WIRINGPI_LIBRARIES}) 
target_link_libraries(Optimotive ${CMAKE_THREAD_LIBS_INIT})
