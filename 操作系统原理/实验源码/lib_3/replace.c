#include <stdio.h>
#include <stdlib.h>
int list[20] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1};
int memery[3] = {-1, -1, -1};
void opt(int *list, int *memery)
{
    int full_num = 0;
    int checkNum, fre, time, pointer, a, b, c;
    time = 0;
    pointer = 0;
    for (int i = 0; i < 20; i++)
    {
        if (full_num < 3)
        {
            memery[full_num] = list[time];
            full_num++;
        }
        else
        {
            if (list[time] == memery[0] || list[time] == memery[1] || list[time] == memery[2])
            {
            }
            else
            {
                checkNum = 3;
                fre = 2;
                a = 0;
                b = 0;
                c = 0;
                for (int j = time; j < 20 && fre != 0; j++)
                {
                    if (list[j] == memery[0] && !a)
                    {
                        fre--;
                        a++;
                    }
                    if (list[j] == memery[1] && !b)
                    {
                        fre--;
                        checkNum -= 1;
                        b++;
                    }
                    if (list[j] == memery[2] && !c)
                    {
                        fre--;
                        checkNum -= 2;
                        c++;
                    }
                }
                if (fre == 0)
                {
                    memery[checkNum] = list[time];
                }
            }
        }
        pointer++;
        time++;
        if (pointer == 3)
            pointer = 0;
        for (int t = 0; t < 3; t++)
        {
            printf("%d ", memery[t]);
        }
        printf("\n");
    }
}
void filo(int *list, int *memery)
{
    int full_num = 0;
    int pointer = 0;
    for (int i = 0; i < 20; i++)
    {
        if (full_num < 3)
        {
            memery[full_num] = list[i];
            full_num++;
        }
        else
        {
            if (list[i] == memery[0] || list[i] == memery[1] || list[i] == memery[2])
            {
                pointer--;
            }
            else
            {
                memery[pointer] = list[i];
            }
        }
        pointer++;
        if (pointer == 3)
            pointer = 0;
        for (int t = 0; t < 3; t++)
        {
            printf("%d ", memery[t]);
        }
        printf("\n");
    }
}
void flu(int *list, int *memery)
{
    int full_num = 0;
    int checkNum, fre, time, pointer, a, b, c;
    time = 0;
    pointer = 0;
    for (int i = 0; i < 20; i++)
    {
        if (full_num < 3)
        {
            memery[full_num] = list[time];
            full_num++;
        }
        else
        {
            if (list[time] == memery[0] || list[time] == memery[1] || list[time] == memery[2])
            {
            }
            else
            {
                checkNum = 3;
                fre = 2;
                a = 0;
                b = 0;
                c = 0;
                for (int j = time; j >= 0 && fre != 0; j--)
                {
                    if (list[j] == memery[0] && !a)
                    {
                        fre--;
                        a++;
                    }
                    if (list[j] == memery[1] && !b)
                    {
                        fre--;
                        checkNum -= 1;
                        b++;
                    }
                    if (list[j] == memery[2] && !c)
                    {
                        fre--;
                        checkNum -= 2;
                        c++;
                    }
                }
                if (fre == 0)
                {
                    memery[checkNum] = list[time];
                }
            }
        }
        pointer++;
        time++;
        if (pointer == 3)
            pointer = 0;
        for (int t = 0; t < 3; t++)
        {
            printf("%d ", memery[t]);
        }
        printf("\n");
    }
}
void clock(int *list, int *memery)
{
    int full_num = 0;
    int pointer = 0;
    int clock[3]={0,0,0};
    for (int i = 0; i < 20; i++)
    {
        if (full_num < 3)
        {
            memery[full_num] = list[i];
            full_num++;
        }
        else
        {
            if (list[i] == memery[0] || list[i] == memery[1] || list[i] == memery[2])
            {
                pointer--;
            }
            else
            {
                while(clock[pointer]==1){
                    pointer++;
                    if(pointer==3){
                        pointer=0;
                    }
                }
                memery[pointer] = list[i];
                for(int t=0;t<3;t++)
                {
                    if(t!=pointer)
                    {
                        clock[t]=0;
                    }
                    else{
                        clock[t]=1;
                    }
                }
            }
        }
        pointer++;
        if (pointer == 3)
            pointer = 0;
        for (int t = 0; t < 3; t++)
        {
            printf("%d ", memery[t]);
        }
        printf("\n");
    }
}
int main()
{
    opt(list, memery);
    //filo(list,memery);
    //flu(list, memery);
    //clock(list, memery);
    return 0;
}