#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "log.h"


int getRandomSecondsNumber()
{
    srand ( time ( NULL));

    int random_value = (int)rand()%15;
    return random_value;
}

int main()
{
    log_init("");
    while(1)
    {
        log_log(ERROR,"This is my log too!");
        sleep(getRandomSecondsNumber()+ 2);
        log_log(INFO,"INFO!");
        sleep(getRandomSecondsNumber()+ 1);

    }
    log_close();
    return 0;
}