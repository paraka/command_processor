cmake_minimum_required (VERSION 2.8.11)
project(CommandProcessor)

# We need C++ 14 (g++ >= 4.9)
if (${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION} GREATER 3.0)
      # CMake 3.1 has built-in CXX standard checks.
      set(CMAKE_CXX_STANDARD 14)
      set(CMAKE_CXX_STANDARD_REQUIRED on)
else ()
      if (CMAKE_COMPILER_IS_GNUCXX)
        message ("Assuming that GNU CXX uses -std=c++14 flag for C++14 compatibility.")
        list(APPEND CMAKE_CXX_FLAGS "-std=c++14")
      else()
        message ("No CMAKE C++14 check. If the build breaks, you're on your own.")
      endif()
endif ()

find_package(Threads)

set(SRCS main.cpp)
add_executable(command_processor ${SRCS})
target_link_libraries(command_processor ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS command_processor DESTINATION bin)
