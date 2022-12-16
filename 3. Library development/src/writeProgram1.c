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
    log_init("Program");
    
    while(1)
    {
        log_log(WARNING,"This is my log!");
        sleep(getRandomSecondsNumber()+ 2);
        log_log(4,"This is my log undefined!");
        sleep(getRandomSecondsNumber()+ 3);
    }
    log_close();
    return 0;
}