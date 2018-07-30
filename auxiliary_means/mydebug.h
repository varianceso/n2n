#ifndef __MY_DEBUG_H__
#define __MY_DEBUG_H__

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

#define DEBUG_ON

#ifndef DEBUG_ON

#define DEBUG(fmt, ...) do{} while(0)

#else

static char* getnowtime(char* current, int len) {
    if(len <= 0) {
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

#define DEBUG(fmt, args...) \
do { \
    char current[2048];\
    printf("[%s %s %d] "fmt, \
            getnowtime(current,sizeof(current)), \
            __FUNCTION__, \
            __LINE__, \
            ##args); \
}while(0)

//printf("%s(%d)-<%s>: "##fmt, __FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); 
#endif

#endif

//#undef DEBUG_ON
