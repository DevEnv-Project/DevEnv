#include <ctype.h>
#include <devenv_utils/string.h>

void shared_str_ptr_to_upper(char* str) {
    char* ptr = str;

    while(*ptr) {
        *ptr = toupper(*ptr);
        ptr++;
    }
}

void shared_str_ptr_to_lower(char* str) {
    char* ptr = str;

    while(*ptr) {
        *ptr = tolower(*ptr);
        ptr++;
    }
}