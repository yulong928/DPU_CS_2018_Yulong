#include <stdio.h>
#include <pthread.h>
void *even(void *arg)
{
  int i;
  for (i = 0; i <= 30; i = i + 2)
    printf("%d\n", i);
  return (NULL);
}
void *odd(void *arg)
{
  int i;
  for (i = 1; i <= 30; i = i + 2)
    printf("%d\n", i);
  return (NULL);
}
main()
{
  pthread_t tid1;
  pthread_t tid2;
  pthread_create(&tid1, NULL, odd, NULL);
  pthread_create(&tid2, NULL, even, NULL);
  sleep(1);
  return;
}
