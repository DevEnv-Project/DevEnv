#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <devenv_cli/command.h>
#include <devenv_cli/command_funcs.h>

int cli_command_version_func(int argc, const char* argv[]) {
    printf("DevEnv (\"%s\") version information:\n\n", argv[0]);

    /// @todo Add version information

    return 0;
}