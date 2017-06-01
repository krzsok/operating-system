#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
    if(mkfifo("asd2",0777)==-1)
	{
		printf("Utworzenie potoku niemozliwe\n");
		return;
    }
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
			
		a=open("asd2", O_RDONLY);
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
			a=open("asd2", O_WRONLY|O_CREAT, 0777);
			
			for(i = 0; i < 5; i++){
				z = 100 + i;
				write(a, &z, sizeof(z));
				printf("Producent przeslal %d\n", z);
			}
			close(a);
			wait(NULL);
			sleep(2);
		    break;
	}

	return(0);
}

