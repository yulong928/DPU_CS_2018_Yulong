#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
main()
{
  int i, p1, p2;
  while ((p1 = fork()) == -1);
  if (p1 == 0)
    for (i = 0; i < 10; i++)
    {
      printf("son%d\n", i);
      sleep(1);
    }
  else
  {
    while ((p2 = fork()) == -1);
    if (p2 == 0)
      for (i = 0; i < 10; i++)
      {
        printf("daughter%d\n", i);
        sleep(1);
      }
    else
      for (i = 0; i < 10; i++)
        printf("father%d\n", i);
  }
}