#include <stdio.h>
#include <unistd.h>
main()
{
   char command[32];
   char *prompt = "$";
   while (printf("%s", prompt), gets(command) != NULL)
   {
      if (fork() == 0)
         execlp(command, command, (char *)0);
      else
         wait(0);
   }
}