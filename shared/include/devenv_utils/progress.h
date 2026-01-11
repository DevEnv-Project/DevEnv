#ifndef DEVENV_SHARED_PROGRESS_H
#define DEVENV_SHARED_PROGRESS_H

// Original: https://stackoverflow.com/a/75135110/16426057

#include <stdio.h>
#if defined(_WIN32)
    #include <memory.h>
#else
    #include <unistd.h>
#endif

/// @brief Start the progress bar
#define START_PROGRESS_BAR(pbar, len) \
    char __##pbar[len] = {0};         \
    memset(__##pbar, '#', sizeof(__##pbar) - 1)

/// @brief Update the running progress bar
#define PROGRESS_BAR_RUNING(pbar, per, fmt, ...) ({                                       \
    float p = per >= 100.0 ? 100.0 : per;                                                 \
    int left = (p / 100.0) * (sizeof(__##pbar) - 1);                                      \
    int right = (sizeof(__##pbar) - 1) - left;                                            \
    printf("\r[%.*s%*s] %.0f%%" fmt, left, __##pbar, right, "", (float)per, __VA_ARGS__); \
})


#endif // DEVENV_SHARED_PROGRESS_H