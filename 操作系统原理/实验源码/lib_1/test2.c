#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int i;
    while ((i = fork()) == -1);
    printf("i=%d\n", i);
    if (i)
        printf("It is a parent process!\n");
    else
        printf("It is a child process!\n");
}