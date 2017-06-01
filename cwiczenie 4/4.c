#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#define FIFO_NAME "abc"


int main(int argc, char **argv) {

	int i;
	long z;
	int a;
	pid_t pid;

	pid = fork();
	switch(pid){
		case -1:
		perror("fork error");
		exit(1);
		break;
		case 0: 
			
		a=open(FIFO_NAME, O_RDONLY);
			do{
				int nread;
				nread = read(a, &z, sizeof(z));
				if(nread == -1)
				{
				perror("blad odczytu");
				exit(-2);
				} else if(nread == 0)
				{ 
				break;
				} else 
				{
				printf("konsument otrzymuje %d\n", z);
				sleep(rand() % 2);
				}
			}while(1);
			close(a);
			break;
		default:
			a=open(FIFO_NAME, O_WRONLY|O_CREAT, 0644);
			
			for(i = 0; i < 5; i++){
				z = 100 + i;
				write(a, &z, sizeof(z));
				printf("Producent przeslal %d\n", z);
			}
			close(a);
			wait(NULL);
			sleep(2);
			unlink(FIFO_NAME); 
			break;
	}

	return(0);
}
