#include <stdio.h>
#include <stdlib.h>
typedef struct pro
{
	int num;
	int time;
} Pro;
int pageNum;
int memoryNum;
void print(Pro *page1);
int Search(int num1, Pro *memory1);

int main(void)
{
	int i;
	int curmemory;
	int missNum;
	float missRate;
	char c;
	Pro *page;
	Pro *memory;
	printf("��������Ϊ:");
	scanf("%d", &memoryNum);
	printf("�����ʵ�ҳ�����Ϊ:");
	scanf("%d", &pageNum);
	page = (Pro *)malloc(sizeof(Pro) * pageNum);
	memory = (Pro *)malloc(sizeof(Pro) * memoryNum);

	for (i = 0; i < pageNum; i++)
	{
		scanf("%d", &page[i].num);
		page[i].time = 0;
	}
	do
	{
		for (i = 0; i < memoryNum; i++)
		{
			memory[i].num = -1;
			memory[i].time = -1;
		}
		printf("\nPlease select  1:FIFO�㷨\n        2:OPT�㷨\n        3:LRU�㷨\n        4:CLOCK�㷨\n        5:�˳�������\n");
		getchar();
		scanf("%c", &c);
		i = 0;
		curmemory = 0;
		if (c == '1')
		{
			missNum = 0;
			printf("FIFO�㷨�û����:   \n");
			for (i = 0; i < pageNum; i++)
			{
				if (Search(page[i].num, memory) < 0)
				{
					missNum++;
					memory[curmemory].num = page[i].num;
					curmemory = (curmemory + 1) % memoryNum;
				}
				print(memory);
			}
			missRate = (float)missNum / pageNum;
			printf("ȱҳ������%d\n", missNum);
			printf("ȱҳ��:  %f\n", missRate);
		}

		if (c == '2')
		{
			missNum = 0;
			curmemory = 0;
			printf("OPT�㷨�û����:   \n");
			for (i = 0; i < pageNum; i++)
			{
				if (Search(page[i].num, memory) < 0)
				{
					int tem;
					int opt = 0;
					int k;
					for (k = 0; k < memoryNum; k++)
					{
						if (memory[k].num == -1)
						{
							curmemory = k;
							break;
						}
						tem = 0;
						int j;
						for (j = i + 1; j < pageNum; j++)
						{
							if (page[j].num == memory[k].num)
							{
								if (tem > opt)
								{
									opt = tem;
									curmemory = k;
								}
								break;
							}
							else
								tem++;
						}
						if (j == pageNum)
						{
							opt = tem;
							curmemory = k;
						}
					}
					missNum++;
					memory[curmemory].num = page[i].num;
				}
				print(memory);
			}
			missRate = (float)missNum / pageNum;
			printf("ȱҳ������%d\n", missNum);
			printf("ȱҳ��:  %f\n", missRate);
		}

		if (c == '3')
		{
			missNum = 0;
			curmemory = 0;
			printf("LRU�㷨�û����: \n");
			for (i = 0; i < pageNum; i++)
			{
				int rec = Search(page[i].num, memory);
				if (rec < 0)
				{
					missNum++;
					int j;
					for (j = 0; j < memoryNum; j++)
						if (memory[j].time == -1)
						{
							curmemory = j;
							break;
						}
						else if (memory[j].time > memory[curmemory].time)
							curmemory = j;

					memory[curmemory].num = page[i].num;
					memory[curmemory].time = 0;
				}
				else
					memory[rec].time = 0;
				int j;
				for (j = 0; j < memoryNum; j++)
					if (memory[j].num != -1)
						memory[j].time++;
				print(memory);
			}
			missRate = (float)missNum / pageNum;
			printf("ȱҳ������%d\n", missNum);
			printf("ȱҳ��:  %f\n", missRate);
		}
		if (c == '4')
		{
			missNum = 0;
			printf("CLOCK�㷨�û����:   \n");
			int *flags;
			flags = (int *)malloc(sizeof(int *) * memoryNum);
			for (i = 0; i < memoryNum; i++)
				flags[i] = 0;
			int s;
			for (s = 0; s < pageNum; s++)
			{
				if (Search(page[s].num, memory) < 0)
				{
					missNum++;
					int t;
					if (flags[memoryNum - 1] == 1)
					{
						int m;
						for (m = 0; m < memoryNum; m++)
							flags[m] = 0;
					}
					for (t = 0; t < memoryNum; t++)
					{
						if (flags[t] == 0)
						{
							memory[t].num = page[s].num;
							flags[t] = 1;
							break;
						}
					}
				}
				int j;
				for (j = 0; j < memoryNum; j++)
					printf("%d ", memory[j].num);
				printf("\n");
			}
			missRate = (float)missNum / pageNum;
			printf("ȱҳ������%d\n", missNum);
			printf("ȱҳ��:  %f\n", missRate);
		}
	} while (c == '1' || c == '2' || c == '3' || c == '4');
	return 0;
}

void print(Pro *memory1)
{
	int j;

	for (j = 0; j < memoryNum; j++)
		printf("%d ", memory1[j].num);
	printf("\n");
}

int Search(int num1, Pro *memory1)
{
	int j;

	for (j = 0; j < memoryNum; j++)
	{
		if (num1 == memory1[j].num)
			return j;
	}
	return -1;
}