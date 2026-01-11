#include <string.h>
#include <malloc.h>
#include <devenv_cli/command_handler.h>
#include <devenv_utils.h>

int cli_find_command(const char* search, Command* cmd) {
    char* str = search;
    shared_str_ptr_to_lower(str);

    int i = 0;
    while(1) {
        Command _cmd = cli_commands[i];
        if(_cmd.name == NULL) {
            break;
        }

        int found = 0;

        if(strcmp(_cmd.aliases[i], str) == 0) {
            found = 1;
        } else {
            for(int i = 0; i < _cmd.total_aliases; i++) {
                if(strcmp(_cmd.aliases[i], str) == 0) {
                    found = 1;
                    break;
                }
            }
        }

        if(found == 1) {
            cmd = malloc(sizeof(cli_commands[i]));
            memcpy(cmd, &cli_commands[i], sizeof(cli_commands[i]));
            return 1;
        }

        i++;
    }

    return 0;
}