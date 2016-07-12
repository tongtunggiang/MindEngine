project(MindEngine)
cmake_minimum_required(VERSION 2.8)

# OS-specific configuration
if (WIN32)
endif(WIN32)

if (UNIX)
endif(UNIX)

#aux_source_directory(. SRC_LIST)
#aux_source_directory(./Database SRC_LIST)

file(GLOB_RECURSE LIBS_HDRS Libs/*.h)
file(GLOB_RECURSE LIBS_SRCS Libs/*.cpp)

file(GLOB_RECURSE ENGINE_HDRS Engine/*.h)
file(GLOB_RECURSE ENGINE_SRCS Engine/*.cpp)

file(GLOB_RECURSE SAMPLE_HDRS Sample/*.h)
file(GLOB_RECURSE SAMPLE_SRCS Sample/*.cpp)

include_directories(
    # 3rd-party libraries source files
    ${PROJECT_SOURCE_DIR}/Libs

    # Engine source files
    ${PROJECT_SOURCE_DIR}/Engine
    ${PROJECT_SOURCE_DIR}/Engine/Database
    ${PROJECT_SOURCE_DIR}/Engine/Rules

    # Sample source files
    ${PROJECT_SOURCE_DIR}/Sample
)

# Uncomment the first line to get a executable file, do the same for second line to get a UNIX static library
add_library(${PROJECT_NAME}_s STATIC ${LIBS_HDRS} ${LIBS_SRCS} ${ENGINE_HDRS} ${ENGINE_SRCS})
add_library(${PROJECT_NAME} SHARED ${LIBS_HDRS} ${LIBS_SRCS} ${ENGINE_HDRS} ${ENGINE_SRCS})
add_executable(${PROJECT_NAME}_sample ${LIBS_HDRS} ${LIBS_SRCS} ${ENGINE_HDRS} ${ENGINE_SRCS} ${SAMPLE_HDRS} ${SAMPLE_SRCS})
