project(MindEngine)
cmake_minimum_required(VERSION 2.8)

# OS-specific configuration
if (WIN32)
endif(WIN32)

if (UNIX)
endif(UNIX)

#aux_source_directory(. SRC_LIST)
#aux_source_directory(./Database SRC_LIST)

file(GLOB_RECURSE HDRS *.h)
file(GLOB_RECURSE SRCS *.cpp)

include_directories(
	${PROJECT_SOURCE_DIR}/Engine
	${PROJECT_SOURCE_DIR}/Engine/Database
)

# Uncomment the first line to get a executable file, do the same for second line to get a UNIX static library
#add_executable(${PROJECT_NAME} ${HDRS} ${SRCS})
add_library(${PROJECT_NAME}_s STATIC ${HDRS} ${SRCS})
add_library(${PROJECT_NAME} SHARED ${HDRS} ${SRCS})
