#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <time.h>

#define LRED  "\x1B[31m"
#define LYEL  "\e[1;33m"
#define LBLU  "\x1B[34m"
#define LMAG  "\x1B[35m"
#define LNORM  "\x1B[0m"

enum log_type
{
    INFO = 0,
    WARNING = 1,
    ERROR = 2
};

void log_init(char program[]);
void log_display();
void log_log(enum log_type logT,char message[]);
void log_display_prog(char program[]);
void log_close();
