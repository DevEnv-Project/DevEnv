#include <stddef.h>

#include <devenv_cli/command.h>
#include <devenv_cli/command_funcs.h>

const Command cli_help_command = {
    .name = "Help",
    .command = "help",
    .aliases = { NULL },
    .desc = "Displays help information",
    .total_aliases = 0,

    .args = { NULL },
    .total_args = 0,

    .func = cli_command_help_func
};

Command cli_commands[] = {
    cli_help_command
};