file(GLOB_RECURSE UI_FILES
	${CMAKE_CURRENT_SOURCE_DIR}/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
)

set(TARGET DevEnvUI)
add_executable(${TARGET} ${UI_FILES} ${SHARED_FILES})

#target_link_libraries(${TARGET} PRIVATE gtkmm::gtkmm)

target_include_directories(DevEnvUI PRIVATE ${GTKMM_INCLUDE_DIRS})
target_link_directories   (DevEnvUI PRIVATE ${GTKMM_LIBRARY_DIRS})
target_link_libraries     (DevEnvUI PRIVATE ${GTKMM_LIBRARIES})
target_compile_options    (DevEnvUI PRIVATE ${GTKMM_CFLAGS_OTHER})