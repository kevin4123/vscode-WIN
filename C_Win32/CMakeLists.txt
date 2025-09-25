cmake_minimum_required(VERSION 3.16)  

project(MyProject LANGUAGES C CXX)   

set(CMAKE_CXX_STANDARD 17)            	
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_CXX_EXTENSIONS OFF)    


include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/third_party
)

file(GLOB_RECURSE PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.c
    ${PROJECT_SOURCE_DIR}/src/*.cpp
	main.cpp
)

file(GLOB_RECURSE THIRD_PARTY_SOURCES
    ${PROJECT_SOURCE_DIR}/src/third_party/*.c
    ${PROJECT_SOURCE_DIR}/src/third_party/*.cpp
)

set(ALL_SOURCES ${PROJECT_SOURCES} ${THIRD_PARTY_SOURCES})


add_executable(hello ${ALL_SOURCES})
#GUI application on Windows
#set_target_properties(App PROPERTIES WIN32_EXECUTABLE ON)

