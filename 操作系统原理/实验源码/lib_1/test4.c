#include <stdio.h>
#include <pthread.h>
void *ptest(void *arg)
{
  printf("This is the new thread!");
  return (NULL);
}
void main()
{
  pthread_t tid;
  printf("This is the parent process!");
  pthread_create(&tid, NULL, ptest, NULL);
  sleep(1);
}