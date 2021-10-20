#ifndef CONFIG_H
#define CONFIG_H

#define MAX_CANON 20	
#define MAX_TIME 100

#define SHMKEY 102938

#include <stdio.h>
#include <unistd.h>


int getlicense(void);
int returnlicense(void);
int initlicense(void);
void addtolicenses(int n);
void removelicenses(int n);
void logmsg(char* msg); 

extern int shmid; // global for shared memory id
extern int* shm;
extern int nLicenses; // global license object to use shared memory


#endif
