#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

int i;
for(i=1; i<4; i++)
{
switch (fork())
{
   case -1:
      	perror("fork error");
      	exit(1);
   case 0:
	sleep(1);
      	printf("uid %d\ngid %d\npid %d\nppid %d\npgid %d\n---------\n", getuid(), getgid(), getpid(),getppid(), getpgid(getpid()));
	break;
   default:
	sleep(1);
      	break;
}
sleep(1);
}

return(0);
}




