#pragma once

#include "command.h"

/// @brief Attempts to find a command
/// @param search The command name
/// @param cmd The command pointer
/// @return 0 = not found, 1 = found
int cli_find_command(const char* search, Command** cmd);