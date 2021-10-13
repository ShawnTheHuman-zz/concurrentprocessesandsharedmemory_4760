#include <stdio.h>
#include <string>
#include <unistd.h>


int getlicense(void);
int returnlicense(void);
int initlicense(void);
void addtolicenses(int n);
void removelicenses(int n);
void logmsg(char* msg); 

extern int shmid; // global for shared memory id

extern struct nLicenses *shm; // global license object to use shared memory

struct nLicenses {

	int total_licenses;    // total number of license
	int child_processes;   // number of child processes
	int current_processes; // total concurrent processes
	int block;             // flag if no available processes
 
	bool choosing[50];      // arrays for bakery algorithm
	int number[50];          //  

};

