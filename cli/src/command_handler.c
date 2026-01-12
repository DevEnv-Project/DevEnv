#include <string.h>
#include <devenv_cli/command_handler.h>
#include <devenv_utils.h>

int cli_find_command(const char* search, Command** cmd) {
    char* str = malloc(sizeof(search));
    strcpy(str, search);
    shared_str_ptr_to_lower(str);

    int i = 0;
    while(1) {
        Command _cmd = cli_commands[i];
        if(_cmd.name == NULL) {
            break;
        }

        int found = 0;

        if(strcmp(_cmd.command, str) == 0) {
            found = 1;
        } else {
            for(int j = 0; j < _cmd.total_aliases; j++) {
                if(strcmp(_cmd.aliases[j], str) == 0) {
                    found = 1;
                    break;
                }
            }
        }

        if(found == 1) {
            *cmd = &cli_commands[i];
            return 1;
        }

        i++;
    }

    return 0;
}