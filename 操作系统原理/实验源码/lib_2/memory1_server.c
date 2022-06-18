#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#define SHMKEY 75
#define K 1024
int shmid;
main()
{
  int i, *pint;
  char *addr;
  extern void *shmat();
  shmid = shmget(SHMKEY, 8 * K, 0777);
  addr = shmat(shmid, 0, 0);
  pint = (int *)addr;
  while (*pint == 0);
  for (i = 0; i <= 256; i++)
    printf("%d\n", *pint++);
}