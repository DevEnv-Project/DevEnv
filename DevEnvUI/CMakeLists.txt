# CMakeList.txt : CMake project for DevEnvUI, include source and define
# project specific logic here.
#

if (NOT VCPKG_TOOLCHAIN)
  find_package(PkgConfig)
  pkg_check_modules(GTKMM_LIB gtkmm-4.0)
  include_directories(${GTKMM_INCLUDE_DIRS})
  link_directories(${GTKMM_LIBRARY_DIRS})
  link_libraries(${GTKMM_LIBRARIES})
else()
  find_package(PkgConfig REQUIRED)
  message(${PKG_CONFIG_FOUND})
  pkg_check_modules(GTKMM_LIB REQUIRED IMPORTED_TARGET gtkmm-4.0)
endif()

# Add source to this project's executable.
add_executable (DevEnvUI "DevEnvUI.cpp" "DevEnvUI.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DevEnvUI PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.