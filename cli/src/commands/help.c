#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <devenv_cli/command.h>
#include <devenv_cli/command_funcs.h>

void cli_command_print_usage(Command cmd, int detailed) {
    printf("%s:\n\t%s (", cmd.name, cmd.command);
    if(cmd.total_aliases == 0) {
        printf("No aliases");
    } else {
        for(int i = 0; i < cmd.total_aliases; i++) {
            printf(cmd.aliases[i]);
            if(i != cmd.total_aliases - 1) {
                printf(", ");
            }
        }
    }
    printf(")\n");

    if(cmd.total_args == 0) {
        printf("\t\tNo arguments.");
    } else {
        for(int i = 0; i < cmd.total_args; i++) {
            printf("\t\t" CMD_ARG_START "%s (", cmd.args[i].arg);
            if(cmd.args[i].total_aliases == 0) {
                printf("No aliases");
            } else {
                for(int j = 0; j < cmd.args[i].total_aliases; j++) {
                    printf(CMD_ARG_SHORT_START "%s", cmd.args[i].aliases[j]);
                    if(j != cmd.args[i].total_aliases - 1) {
                        printf(", ");
                    }
                }
            }

            printf(")\n\t\t\tDescription: %s\n", cmd.args[i].desc);
            if(detailed == 1) {
                printf("\t\t\t    Default: %s\n", cmd.args[i].default_value);
                printf("\t\t\t       Type: %s\n", CommandArgTypeString[cmd.args[i].type]);

                /// @todo Add type-specific information
            }
        }
    }
}

int cli_command_help_func(int argc, const char* argv[]) {
    printf("DevEnv (\"%s\") usage information:\n\n", argv[0]);

    int detailed = 0;

    if(argc < 2) {
        for(int i = 2; i < argc; i++) {
            if(strcmp(CMD_ARG_START "details", argv[i]) == 1 ||
               strcmp(CMD_ARG_SHORT_START "d", argv[i]) == 1)
                detailed = 1;
        }
    }

    int i = 0;
    while(1) {
        Command cmd = cli_commands[i];
        if(cmd.name == NULL) {
            break;
        }

        cli_command_print_usage(cmd, detailed);

        printf("\n");

        i++;
    }

    return 0;
}