#include <stddef.h>

#include <devenv_cli/command.h>
#include <devenv_cli/command_funcs.h>

Command cli_commands[] = {
    {
        .name = "Help",
        .command = "help",
        .aliases = { NULL },
        .desc = "Displays help information",
        .total_aliases = 0,

        .args = (CommandArg[]) {
            {
                .arg = "details",
                .desc = "Detailed command usage information",
                .aliases = (char*[]){ (char*)"d" },
                .total_aliases = 1,
                .default_value = "false",
                .type = ARG_TYPE_BOOL
            },
            NULL
        },
        .total_args = 1,

        .func = cli_command_help_func
    },
    {
        .name = "Version",
        .command = "version",
        .aliases = (char*[]){ (char*)"ver" },
        .desc = "Displays version information",
        .total_aliases = 1,

        .args = { NULL },
        .total_args = 0,

        .func = cli_command_version_func
    },
    NULL
};