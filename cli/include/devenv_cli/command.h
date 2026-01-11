#pragma once

#if defined(_WIN32)
    #define CMD_ARG_START "/"
    #define CMD_ARG_SHORT_START "/"
#else
    #define CMD_ARG_START "--"
    #define CMD_ARG_SHORT_START "-"
#endif

typedef struct CommandArgValuesInteger {
    int min;
    int max;
} CommandArgValuesInteger;

typedef union CommandArgValues {
    CommandArgValuesInteger integer;
} CommandArgValues;

#define FOREACH_ARG_TYPE(ARG_TYPE) \
        ARG_TYPE(ARG_TYPE_BOOL)    \
        ARG_TYPE(ARG_TYPE_STRING)  \
        ARG_TYPE(ARG_TYPE_PATH)    \
        ARG_TYPE(ARG_TYPE_INTEGER) \
        ARG_TYPE(ARG_TYPE_FLOAT)   \

#define GENERATE_ENUM(ENUM)     ENUM,
#define GENERATE_STRING(STRING) #STRING,

typedef enum CommandArgType {
    FOREACH_ARG_TYPE(GENERATE_ENUM)
} CommandArgType;

static const char* CommandArgTypeString[] = {
    FOREACH_ARG_TYPE(GENERATE_STRING)
};

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