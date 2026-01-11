#include <malloc.h>
#include <devenv_cli.h>
#include <devenv_utils.h>

int main(int argc, const char* argv[]) {
    if(argc == 1) {
        /// @todo Print version and usage information
        cli_command_help_func(argc, argv);

        return 0;
    }

    Command* cmd = malloc(sizeof(Command));
    if(cli_find_command(argv[1], cmd) == 0) {
        printf(
            "DevEnv: Command \"%s\" not found. Use \"%s help\" for usage information.",
            argv[1],
            argv[0]
        );

        return 1;
    } else {
        if(!cmd->func || cmd->func == NULL) {
            printf("DevEnv: Command \"%s\" found, but missing a function pointer.", argv[1]);
            return 1;
        }

        int result = cmd->func(argc, argv);
        if(result != 0) {
            printf("DevEnv: Command exited with a non-zero result code.");
            return result;
        }
    }

    return 0;
}