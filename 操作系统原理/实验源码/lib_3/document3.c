#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
main(argc, argv)
{
  int argc;
  char *argv[];
  {
    int fd1, fd2, n;
    fd1 = unlink(argv[1]);
    fd2 = rename(argv[2], argv[3]);
    close(fd2);
  }
}