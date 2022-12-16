#include <stdio.h>
#include <string.h>
#include "log.h"

int main(int argc, char *argv[])
{

    const char *opt[2];
    opt[0] = "-p";
    opt[1] = "--program";
    log_init("");

    
    if (argc == 3 && ((strcmp(argv[1], opt[0]) == 0) 
                  || (strcmp(argv[1], opt[1]) == 0)))
    {
        log_display_prog(argv[2]);
    }
    else
    {
        log_display();
    }

    log_close();
    return 0;
}
