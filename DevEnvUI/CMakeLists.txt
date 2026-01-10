project(DevEnvUI LANGUAGES CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTKMM REQUIRED gtkmm-4.0)
#find_package(gtkmm CONFIG REQUIRED)

include_directories(include)
add_subdirectory(src)