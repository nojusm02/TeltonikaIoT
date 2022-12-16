#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "log.h"

char logDir[80];
char logLocation[] = "/var/log/";
char logName[] = "liblog.db";
char tempName[] = "USER"; 

sqlite3 *db;

char * programName = "USER";


void log_init(char program[])
{

    if(strcmp(program,"")!=0)
    {
        programName = program;
    }
    else
    {
        programName = tempName;
    }

    strcat(logDir, logLocation);
    strcat(logDir, logName);
    int rc = sqlite3_open(logDir, &db);
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return;
    }
    printf("Library initialized in location : \n %s \n", logDir);
    log_create_table();
    return;
}

void log_create_table()
{
    sqlite3_stmt *res;
    int rc;
    char *sql;
    sql = "CREATE TABLE IF NOT EXISTS liblog("  \
      "LOG_TYPE           TEXT    NOT NULL," \
      "LOG_TIME           TEXT    NOT NULL," \
      "PROG_NAME           TEXT    NOT NULL," \
      "LOG           TEXT    NOT NULL );";

    rc = sqlite3_prepare_v2(db, sql, -1, &res, NULL);
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return;
    }
    rc = sqlite3_step(res);
    sqlite3_finalize(res);
}

char* getColor(char *logType)
{
    char *lColor;
    if(strcmp(logType,"INFO") == 0)
    {
        lColor = LBLU;
    }
    else if(strcmp(logType, "WARNING") == 0)
    {
        lColor = LYEL;
    }
    else if(strcmp(logType, "ERROR") == 0)
    {
        lColor = LRED;
    }
    else
    {
        lColor = LMAG;
    }
    return lColor;
}

void log_display()
{
    int ret;
    sqlite3_stmt* stmt;
    char* sql_stmt = "SELECT * FROM liblog";
    ret = sqlite3_prepare_v2(db, sql_stmt, -1, &stmt, 0);
    if(ret != SQLITE_OK)
    {
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
            printf("\n%s %s %s %s %s %s", 
                                 getColor(sqlite3_column_text(stmt, 0)),
                                 sqlite3_column_text(stmt, 0),
                                 LNORM,
                                 sqlite3_column_text(stmt, 1),
                                 sqlite3_column_text(stmt, 2),
                                 sqlite3_column_text(stmt, 3));
    }
    printf("\n");
    sqlite3_finalize(stmt);
}

char *concatenate(char *a, char *b, char *c)
{
  int size = strlen(a) + strlen(b) + strlen(c) + 1;
  char *str = malloc(size);
  strcpy (str, a);
  strcat (str, b);
  strcat (str, c); 

  return str;
}

void log_display_prog(char program[])
{
    int ret;
    sqlite3_stmt* stmt;
    
    char* smt_p_1 = "SELECT * FROM liblog WHERE PROG_NAME LIKE '";
    char* stmt_p_2 = program;
    char* stmt_p_3 = "'";
    char* sql_stmt = concatenate(smt_p_1,stmt_p_2,stmt_p_3);

    ret = sqlite3_prepare_v2(db, sql_stmt, -1, &stmt, 0);
    if(ret != SQLITE_OK)
    {
        return;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
            printf("\n%s %s %s %s %s %s", 
                                 getColor(sqlite3_column_text(stmt, 0)),
                                 sqlite3_column_text(stmt, 0),
                                 LNORM,
                                 sqlite3_column_text(stmt, 1),
                                 sqlite3_column_text(stmt, 2),
                                 sqlite3_column_text(stmt, 3));
    }
    printf("\n");
    sqlite3_finalize(stmt);
    
}

const char* getLogType(enum log_type logT)
{

    switch (logT)
    {
        case INFO:
            return "INFO";
            break;
        case WARNING:
            return "WARNING";
            break;
        case ERROR: 
            return "ERROR";
            break;
        
        default:
            return "UNDEFINED";
            break;
    }
}

void log_log(enum log_type logT,char message[])
{
    const char* logTypeText = getLogType(logT);

    int ret;
    char sql[512];
    snprintf(sql, sizeof(sql), "INSERT INTO LIBLOG(LOG_TYPE,LOG_TIME,PROG_NAME, LOG) VALUES (?1,?2,?3,?4);");

    char TimeStamp[20];
    time_t now = time(NULL);
    strftime(TimeStamp, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, sql, sizeof(sql), &stmt, NULL);
    sqlite3_bind_text(stmt, 1, logTypeText, 20, NULL);
    sqlite3_bind_text(stmt, 2, TimeStamp, 20, NULL);
    sqlite3_bind_text(stmt, 3, programName, 20, NULL);
    sqlite3_bind_text(stmt, 4, message, 100, NULL);


    ret = sqlite3_step(stmt);
    if (ret == SQLITE_DONE)
        ;
    else
        printf("Error: %s\n", sqlite3_errmsg(db));

    sqlite3_finalize(stmt);
}


void log_close()
{
    sqlite3_close(db);
}