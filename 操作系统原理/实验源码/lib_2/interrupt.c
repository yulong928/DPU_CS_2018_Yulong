#include <sys/file.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
void waiting();
void stop();
int wait_mark;
main()
{
  signal(SIGINT, stop);
  int p1, p2, stdout;
  while ((p1 = fork()) == -1);
  if (p1 > 0)
  {
    while ((p2 = fork()) == -1);
    if (p2 > 0)
    {
      wait_mark = 1;
      waiting();
      kill(p1, 10);
      kill(p2, 12);
      wait(0);
      printf("parent process is killed!\n");
      exit(0);
      exit(0);
    }
  }
}
void waiting()
{
  while (wait_mark == 1);
}
void stop()
{
  wait_mark = 0;
}