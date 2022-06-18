#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
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
 int i;
  msgqid=msgget(MSGKEY,0777);
  for(i=10;i>=1;i--)
  {
     msg.mtype=i;
     gets(msg.mtext);
    msgsnd(msgqid,&msg,1024,0);
  }
  exit(0);
}
