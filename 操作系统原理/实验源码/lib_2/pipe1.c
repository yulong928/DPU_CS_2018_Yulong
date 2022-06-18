#include <stdio.h>
#include <stdlib.h>
main()
{
  int i,p1,p2,fd[2];
  char buf1[50],buf2[50],s[50];
  pipe(fd);
  while((p1=fork())== -1);
  if(p1==0)
 {
   sprintf(buf1, "This is child1! \n");
     write(fd[1],buf1, 50);
     exit(0);
 }
  else
  {
    wait(0);
     read(fd[0],s,50);
     printf("%s",s);
  }
  while((p2=fork())== -1);
  if(p2==0)
 {
   sprintf(buf2, "This is child2! \n");
     write(fd[1],buf2, 50);
          exit(0);
 }
else
{
     wait(1);
     read(fd[0],s,50);
     printf("%s",s);
  }
}
                                           
