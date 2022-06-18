#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid[3];
    int count = 0;
    pid[0] = fork();
    pid[1] = fork();
    pid[2] = fork();
    printf("hello word! pid:%d uid:%d euid:%d\n", getpid(), getuid(), geteuid());
    return 0;
}