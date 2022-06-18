#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
main(argc, argv) int argc;
char *argv[];
{
  int fd1, i;
  if (access(argv[1], F_OK) == 0)
  {
    rename(argv[1], argv[2]);
    printf("%s is rename successed!\n", argv[1]);
  }
  else
    printf("%s file doesn't exit!\n", argv[1]);
}
