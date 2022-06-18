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
main()
 {
   struct msgform msg;
   int msgqid;
   msgqid=msgget(MSGKEY,0777|IPC_CREAT);
  while(msg.mtype!=1)
{
  msgrcv(msgqid,&msg,1024,0,0);
  printf("server :%s\n",msg.mtext);
 }
 msgctl(msgqid,IPC_RMID,0);
 exit(0);
}

