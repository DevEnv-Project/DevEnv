project(devenv LANGUAGES C CXX)

file(GLOB_RECURSE DEVENV_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

file(GLOB_RECURSE SHARED_FILES
	${CMAKE_SOURCE_DIR}/shared/src/*.c
    ${CMAKE_SOURCE_DIR}/shared/src/*.cpp
)

add_executable(devenv ${DEVENV_FILES} ${SHARED_FILES})

target_include_directories(devenv
    PRIVATE
        ${CMAKE_SOURCE_DIR}/cli/include
        ${CMAKE_SOURCE_DIR}/shared/include
    SYSTEM
        /usr/local/include
)