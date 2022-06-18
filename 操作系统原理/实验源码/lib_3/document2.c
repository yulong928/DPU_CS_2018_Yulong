#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void main(int argc, char **argv)
{
   {
      int fd1, fd2, fd3, n;
      char buf[512], ch = '\n';
      fd1 = open(argv[1], 0);
      fd2 = open(argv[2], 0);
      fd3 = creat(argv[3], 0644);
      while ((n = read(fd1, buf, 512)) > 0)
         write(fd3, buf, n);
      write(fd3, &ch, 1);
      while ((n = read(fd2, buf, 512)) > 0)
         write(fd3, buf, n);
      close(fd1);
      close(fd2);
      close(fd3);
   }
}