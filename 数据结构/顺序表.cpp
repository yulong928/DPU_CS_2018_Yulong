#include <stdio.h>
#include <stdlib.h>
int i;
void add(int* p, int n) {
	printf("请输入插入的位置：");
	int pos;
	scanf("%d", &pos);
	printf("\n");
	printf("请输入要插入的元素：");
	int x;
	scanf("%d", &x);
	printf("\n");
	int* q;
	q = (int*)realloc(p, (n + 1) * sizeof(int));
	for (i = n; i >= pos - 1; i--) {
		q[i + 1] = q[i];
	}
	q[pos - 1] = x;
	printf("您更改的元素列为：");
	for (i = 0; i < n + 1; i++) {
		printf("%d  ", q[i]);
	}
	printf("\n");
}
void clear(int* p, int n) {
	printf("请输入删除的位置：");
	int pos;
	scanf("%d", &pos);
	printf("\n");
	int* q;
	q = (int*)realloc(p, (n - 1) * sizeof(int));
	for (i = pos - 1; i < n; i++) {
		q[i] = q[i+1];
	}
	printf("您更改的元素列为：");
	for (i = 0; i < n - 1; i++) {
		printf("%d  ", q[i]);
	}
	printf("\n");
}
int main() {
	int n;
	int* p;
	p = (int*)malloc(n * sizeof(int));
	printf("请输入元素个数：");
	scanf("%d", &n);
	printf("\n");
	printf("输入n个元素：");
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	printf("\n");
	printf("您输入的元素为：");
	for (i = 0; i < n; i++) {
		printf("%d  ", p[i]);
	}
	printf("\n");
	printf("\n");
	clear(p, n);
	printf("\n");
	return 0;
}
