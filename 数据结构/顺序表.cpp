#include <stdio.h>
#include <stdlib.h>
int i;
void add(int* p, int n) {
	printf("����������λ�ã�");
	int pos;
	scanf("%d", &pos);
	printf("\n");
	printf("������Ҫ�����Ԫ�أ�");
	int x;
	scanf("%d", &x);
	printf("\n");
	int* q;
	q = (int*)realloc(p, (n + 1) * sizeof(int));
	for (i = n; i >= pos - 1; i--) {
		q[i + 1] = q[i];
	}
	q[pos - 1] = x;
	printf("�����ĵ�Ԫ����Ϊ��");
	for (i = 0; i < n + 1; i++) {
		printf("%d  ", q[i]);
	}
	printf("\n");
}
void clear(int* p, int n) {
	printf("������ɾ����λ�ã�");
	int pos;
	scanf("%d", &pos);
	printf("\n");
	int* q;
	q = (int*)realloc(p, (n - 1) * sizeof(int));
	for (i = pos - 1; i < n; i++) {
		q[i] = q[i+1];
	}
	printf("�����ĵ�Ԫ����Ϊ��");
	for (i = 0; i < n - 1; i++) {
		printf("%d  ", q[i]);
	}
	printf("\n");
}
int main() {
	int n;
	int* p;
	p = (int*)malloc(n * sizeof(int));
	printf("������Ԫ�ظ�����");
	scanf("%d", &n);
	printf("\n");
	printf("����n��Ԫ�أ�");
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
	printf("\n");
	printf("�������Ԫ��Ϊ��");
	for (i = 0; i < n; i++) {
		printf("%d  ", p[i]);
	}
	printf("\n");
	printf("\n");
	clear(p, n);
	printf("\n");
	return 0;
}
