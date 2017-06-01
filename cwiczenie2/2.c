#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{

printf("uid %d\ngid %d\npid %d\nppid %d\npgid %d\n", getuid(), getgid(), getpid(),getppid(), getpgid(getpid()));
 
perror("czy errno jest wolne od kodow bledow?");

switch (fork())
{
   case -1:
      perror("fork error");
      exit(1);
   case 0: /* proces potomny */
      execl("./3.x","3.x",NULL);
      perror("execl error");
      exit(2);
   default: 
	sleep(1);
	break;
};






return(0);
}




