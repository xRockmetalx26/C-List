# PROJECT NAME
project(App)

# CMAKE VERSION
cmake_minimum_required(VERSION "3.17")

# C FLAGS
set(CMAKE_C_FLAGS "-std=c18 -Wextra -Wall -Wpedantic")

# INCLUDE PATHS
include_directories("include")

# C HEADER FILES
FILE(GLOB HEADER_FILES "include/*.h")

# C SOURCE FILES
FILE(GLOB SOURCE_FILES "src/*.c")

# C LIB FILES
FILE(GLOB LIBRARY_FILES "lib/*.a")
FILE(GLOB LIBRARY_FILES "lib/*.*.a")

# RESOURCE FILES
#set(RESOURCE_FILE "res/res.rc")

# FILES OUTPUT PATHS
#set(LIBRARY_OUTPUT_PATH "build/lib")
set(EXECUTABLE_OUTPUT_PATH "build/bin")

# LIBRARIES CONFIGURATION
#add_library(app_static STATIC ${SOURCE_FILES})
#add_library(app_shared SHARED ${SOURCE_FILES})

# EXECUTABLES CONFIGURATION
add_executable(app ${SOURCE_FILES} ${HEADER_FILES} ${RESOURCE_FILE})

# LINKED CONFIGURATION
target_link_libraries(app ${LIBRARY_FILES})