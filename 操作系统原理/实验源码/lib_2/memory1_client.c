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
  int i,*pint;
  char *addr;
  extern void *shmat();
  extern cleanup();
  for(i=0;i<20;i++)
   signal(i,cleanup);
  shmid=shmget(SHMKEY,16*K,0777|IPC_CREAT);
  addr=shmat(shmid,0,0);
  printf("addr 0x%x\n",addr);
  pint=(int*)addr;
  for(i=0;i<256;i++)
    *++pint=i;
   pint=(int*)addr;
   *pint=256;
   pause();
}
cleanup()
{
  shmctl(shmid,IPC_RMID,0);
  exit(0);
}