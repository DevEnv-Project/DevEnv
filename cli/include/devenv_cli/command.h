#pragma once

typedef struct CommandArgValuesInteger {
    int min;
    int max;
} CommandArgValuesInteger;

typedef union CommandArgValues {
    CommandArgValuesInteger integer;
} CommandArgValues;

typedef enum CommandArgType {
    ARG_TYPE_BOOL,
    ARG_TYPE_STRING,
    ARG_TYPE_PATH,
    ARG_TYPE_INTEGER,
    ARG_TYPE_FLOAT
} CommandArgType;

typedef struct CommandArg {
    const char* arg;
    const char** aliases;
    const char* desc;
    const int total_aliases;

    const char* default_value;
    const CommandArgType type;
    const CommandArgValues values;
} CommandArg;

typedef struct {
    const char* name;
    const char* command;
    const char** aliases;
    const char* desc;
    const int total_aliases;

    const CommandArg* args;
    const int total_args;

    int  (*func)(int argc, const char* argv[]);
    //void (*usage)(const char* arg0);
} Command;

extern Command cli_commands[];