#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    if (argv[2] != 0) 
    {
        //rename
        if(access(argv[1],F_OK) == 0){
            rename(argv[1],argv[2]);
        }
    }
    else{
        //remove
        if(access(argv[1],F_OK) == 0){
            remove(argv[1]);
        }
    }
    return 0;
}
