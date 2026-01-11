find_package(Doxygen)
if(Doxygen_FOUND)
    message(STATUS "Found Doxygen Version "
        "${DOXYGEN_VERSION} at ${DOXYGEN_EXECUTABLE}")

    set(FLXR_DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(FLXR_DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

    configure_file(${FLXR_DOXYGEN_IN} ${FLXR_DOXYGEN_OUT} @ONLY)
    message("Building Doxygen")

    add_custom_target(flxr_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
endif()