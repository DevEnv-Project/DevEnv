@echo off

REM This uses an environment variable called VCPKG_ROOT as the base of VCPKG so that it can find the cmake file

cmake -B build -S . -G "Visual Studio 17 2022" -A x64 -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake -DDEVENV_BUILD=OFF -DDEVENV_BUILD_DOCS=ON
cmake --build build --config Debug