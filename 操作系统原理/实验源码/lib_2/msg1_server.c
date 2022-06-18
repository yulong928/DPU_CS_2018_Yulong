#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#define MSGKEY 75
struct msgform
{
  long mtype;
  char mtext[1024];
};
int msgqid;
main()
{
 struct msgform msg;
 int i,pid,*pint;
 extern cleanup();
 for(i=1;i<20;i++)
   signal(i,cleanup);
  msgqid=msgget(MSGKEY,0777|IPC_CREAT);
  for(;;)
  {
     msgrcv(msgqid,&msg,1024,1,0);
     pint=(int*)msg.mtext;
     pid=*pint;
     printf("server:receive from pid %d\n",pid);
     msg.mtype=pid;
     *pint=getpid();
    msgsnd(msgqid,&msg,sizeof(pint),0);
  }
}
cleanup()
{
  msgctl(msgqid,IPC_RMID,0);
  exit(0);
}
