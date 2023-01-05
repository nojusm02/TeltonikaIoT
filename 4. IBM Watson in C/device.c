#include <stdio.h>
#include <signal.h>
#include <memory.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <argp.h>
#include <syslog.h>

#include "inputHandling.h"
#include "deviceHandling.h"
#include "iotp_device.h"

/* Program documentation. */
char doc[] =
    "IBM WATSON DAEMON";

/* A description of the arguments we accept. */
char args_doc[] = "\"Device_id\" \"Organization_id\" \"Type_id\" \"Auth_token\"";

/* The options we understand. */
struct argp_option options[] = {
    {"config", 'c', "FILE", 0, "Config file location"},
    {"orgID", 'o', "FILE", 0, "Organization id"},
    {"typeID", 't', "FILE", 0, "Type id"},
    {"deviceID", 'd', "FILE", 0, "Device id"},
    {"authT", 'a', "FILE", 0, "Auth token"},
    {"daemon", 'b', 0, 0, "Make a daemon process"},
    {0}};

volatile int interrupt = 0;

void sigHandler(int signo)
{
    signal(SIGINT, NULL);
    fprintf(stdout, "Received signal: %d\n", signo);
    interrupt = 1;
}

long get_uptime()
{
    struct sysinfo s_info;
    int error = sysinfo(&s_info);
    if (error != 0)
    {
        printf("code error = %d\n", error);
    }
    return s_info.uptime;
}

int main(int argc, char **argv)
{
    openlog("WatsonLog", LOG_PID, LOG_USER);
    syslog(LOG_INFO, "Log opened\n");
    struct argp argp = {options, parse_opt, args_doc, doc};
    struct arguments arguments;
    arguments.configFilePath = "-";
    arguments.daemonize = 0;
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    /*
    printf("Organization id = %s\nType id = %s\n"
           "Device id = %s\nAuth token = %s\nConfig file = %s\n",
           arguments.args[0],
           arguments.args[1],
           arguments.args[2],
           arguments.args[3],
           arguments.configFilePath);
    */

    int rc = 0;

    signal(SIGINT, sigHandler);
    signal(SIGTERM, sigHandler);

    IoTPConfig *config = NULL;
    IoTPDevice *device = NULL;

    rc = deviceConfigInit(&config, arguments);

    rc = IoTPDevice_create(&device, config);
    if (rc != 0)
    {
        syslog(LOG_ERR, "ERROR: Failed to configure IoTP device: rc=%d\n", rc);
        interrupt = 1;
    }
    rc = IoTPDevice_connect(device);
    if (rc != 0)
    {
        syslog(LOG_ERR, "ERROR: Failed to connect to Watson IoT Platform: rc=%d\n", rc);
        syslog(LOG_ERR, "ERROR: Returned error reason: %s\n", IOTPRC_toString(rc));
        interrupt = 1;
    }

    char data[200];

    while (!interrupt)
    {
        // sprintf(data, "{\"d\" : {\"Up_Time\": \"%ld\", \"Reading\": 7 }}", get_uptime());
        sprintf(data, "{\"System data\" : {\"Up_Time\": \"%ld\"}}", get_uptime());

        syslog(LOG_INFO, "Send status event\n");
        rc = IoTPDevice_sendEvent(device, "status", data, "json", QoS0, NULL);
        syslog(LOG_INFO, "RC from publishEvent(): %d\n", rc);
        sleep(10);
        if (arguments.daemonize == 0)
        {
            interrupt = 1;
        }
    }

    syslog(LOG_INFO, "Publish event cycle is complete.\n");

    IoTPDevice_disconnect(device);
    if (rc != IOTPRC_SUCCESS)
    {
        syslog(LOG_ERR, "ERROR: Failed to disconnect from  Watson IoT Platform: rc=%d\n", rc);
    }
    IoTPDevice_destroy(device);
    IoTPConfig_clear(config);

    closelog();
    return 0;
}