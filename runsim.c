/*
 * runsim.c
 *
 *
 *
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <signal.h>
#include <ctype.h>

#include "config.h"

void docommand(char* cline);
char** make_argv(char* str);
void terminate_processes();
void signal_handler();
void usage();


int shmid;
int nLicenses;

key_t key = 904885;


int main(int argc, char* argv[]){
	
	signal(SIGINT, singal_handler);

	int license_count;

	if( argc != 2 ) {
		
		perror("ERROR: runsim: invalid arguments\n");
		usage();
		exit(1);

	}	
	if( isdigit(argv[1]) != 0 ){
		license_count = atoi(argv[1]);
		if( license_count <= 0 ){
			perror("ERROR: runsim: n must be a number greating than zero\n");
			usage();
			exit(1);
		}
	}
	else{
		perror("ERROR: runsim: Invalid argument\n");

		exit(1);
	}

	if(( shmid = shmget(key, sizeof(int)*2,IPC_CREAT | 0777 )) < 0)}
		perror("ERROR: runsim: error getting memory");
		exit(1);
	}

	if(( shm = (int nLicenses *)shmat(shmid, NULL, 0)) == (int nLicenses *) - 1) {
		perror("ERROR: runsim: unable to attach memory");
		exit(1);

	}

	initlicense();

	

	


}

void usage(){
	printf("usage");
}

char docommand( char* cline ){
	
	getlicense();

	char** _argv = make_argv(cline);

	execvp(argv[0], _argv);
	
	free(argv);
}

char make_argv( char* str ){
	
	char* substr;
	char** _argv = malloc(10 * sizeof(char));

	substr = strtok(str, " ");

	int i = 0;
	while( substr != NULL){
		_argv[i] = malloc(20 * sizeof(char));
		_argv[i] = substr;
		substr = strtok(NULL, " ");
		i++;
	}
	_argv[i] = NULL;
	
	return _argv;
}
