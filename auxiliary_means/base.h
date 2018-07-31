#ifndef __BASE_H__
#define __BASE_H__

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <sys/ioctl.h>
#include <sys/poll.h>

#include <errno.h>
#include <fcntl.h>
#include <time.h>
#include <stddef.h>

#include <pthread.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

static char* getnowtime(char* current, int len) {
    if(current == NULL || len <= 0) {
        return NULL;
    }

    memset(current,len,0x00);
    struct timespec time;
    clock_gettime(CLOCK_REALTIME, &time);
    struct tm nowtime;
    localtime_r(&time.tv_sec, &nowtime);
    sprintf(current, "%04d-%02d-%02d %02d:%02d:%02d", 
                        nowtime.tm_year + 1900, 
                        nowtime.tm_mon+1, 
                        nowtime.tm_mday, 
                        nowtime.tm_hour, 
                        nowtime.tm_min, 
                        nowtime.tm_sec);
    return current;
}

#endif
