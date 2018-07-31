#ifndef __MY_DEBUG_H__
#define __MY_DEBUG_H__

#include "base.h"

#define DEBUG_ON

#ifndef DEBUG_ON

#define DEBUG(fmt, ...) do{} while(0)

#else

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
