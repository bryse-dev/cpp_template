cmake_minimum_required (VERSION 2.6)
project (persei8)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories(${CMAKE_SOURCE_DIR}/include)

# add the executable
file(GLOB_RECURSE PERSEI8_SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(persei8 ${PERSEI8_SRC_FILES})

#Include libpthread
find_package (Threads REQUIRED)

# Log4cplus
add_subdirectory("${PROJECT_SOURCE_DIR}/thirdparty/log4cpp")
include_directories("${PROJECT_SOURCE_DIR}/thirdparty/log4cpp/include")
include_directories("${PROJECT_BIN_DIR}/thirdparty/log4cpp/include")
target_link_libraries(persei8 log4cpp ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS persei8 RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin)

##use c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fvisibility=default")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fvisibility=default")


##Disable pragma warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unknown-pragmas")

##get IOV_MAX
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_XOPEN_SOURCE")

## Add all warnings
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -pg -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -g -Wall -Werror -O2")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_DEBUG} -Wall -Werror -g -O2")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS} ${CMAKE_C_FLAGS_RELEASE} -g -Wall -Werror -O2")
