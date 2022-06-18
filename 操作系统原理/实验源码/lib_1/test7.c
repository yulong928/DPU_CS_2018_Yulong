#include <stdio.h>
#include <unistd.h>
main()
{
   char command1[32];
   char command2[32];
   char *prompt = "$";
   while (printf("%s", prompt), gets(command1) != NULL, gets(command2) != NULL)
   {
      if (fork() == 0)
         execlp(command1, command1, command2, (char *)0);
      else
         wait(0);
   }
}
