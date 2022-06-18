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
  for (i = 1; i < argc; i++)
  {
    if (access(argv[i], F_OK) == 0)
    {
      remove(argv[i]);
      printf("%s is deleted successed!\n", argv[i]);
    }
    else
      printf("file doesn't exit!\n", argv[i]);
  }
}
