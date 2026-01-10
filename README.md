# DevEnv
The cross-platform developer environment.

## The continuation of DevEnv
DevEnv was originally going to be a relatively small project, and I ended up basically giving up on it after a while due to other projects, and other reasons.
I feel like I would like to restart this project as I think that it would be a nice idea.

This project has moved to this organisation for a few reasons, including:
- I would like to keep the original version on my GitHub account
- Using an organisation means that I can use GitHub pages, and have multiple repositories
- I could split the project up more, which could make it easier to manage

This is going to be similar to the original project idea.
- Cross-platform, with a platform-specific engine running in the background to efficiently manage things like resources
- High-customisability, with potentially modifications like plugins later on
- Custom configuration language, which could add logic to environment configuration files
- Beginner friendly, with explanative errors
- Quick, easy, and overall simple to get set up and running
- Easy to update, or even potentially self-updating
- Minimising the impact of specific issues including the impact of node modules (Messy and large)
- Support for, and integration with a large range of IDEs, compilers, tools (like git), languages, and more
- Detecting the developer environment, which could allow you to copy it to another device as a configuration file
- Support for Dev Drive (Which is Windows only, but potential support for a linux version later)
  - Automatically updating path environment variables so things such as node modules, vcpkg packages, NuGet packages, rust crates, etc cache to the Dev Drive
  - Easily create, manage, move, copy, or remove a Dev Drive
- Allow you to install everything needed for a project, including potentially going across IDEs
- Project templates
- Informative documentation
- Integration with other projects, including GNPM (Graphical Node Package Manager)

## Building
Building this can be quite annoying, you need to set an environment variable firs#

### Windows
You can either use CMD, or PowerShell to add an environment variable, for example with PS:
```ps
Set-Item -Path Env:VCPKG_ROOT -Value "C:\vcpkg"
```

### DevEnvUI
First, you need to make sure that CMake and VCPkg are set up correctly, you need to use `vcpkg install integrate`, and `vcpkg install gtkmm:x64-windows` (or other platforms)

Then use `cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=(CMake base)/scripts/buildsystems/vcpkg.cmake`
E.g. `cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=G:/vcpkg/scripts/buildsystems/vcpkg.cmake`

Finally, build with `cmake --build build` (You may need to create a `build` directory)