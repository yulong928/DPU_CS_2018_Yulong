#include <stdio.h>
#include <stdlib.h>
int i;
struct node {
	int data;
	struct node* next;
};
void add(struct node* head) {
	struct node* p = head;
	printf("����������λ�ã�");
	int pos;
	scanf("%d", &pos);
	printf("\n");
	printf("������Ҫ�����Ԫ�أ�");
	int x;
	scanf("%d", &x);
	printf("\n");
	struct node* q;
	for (i = 0; i < pos - 1; i++) {
		p = p->next;
	}
	q = p->next;
	p->next = (struct node*)malloc(1 * sizeof(struct node));
	p = p->next;
	p->data = x;
	p->next = q;
	p = head->next;
	printf("�����ĺ�Ľ��Ϊ��");
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	};
	printf("\n");
}
void clear(struct node* head) {
	struct node* p = head;
	printf("������ɾ����λ�ã�");
	int pos;
	scanf("%d", &pos);
	printf("\n");
	struct node* q;
	for (i = 0; i < pos - 1; i++) {
		p = p->next;
	}
	q = p->next;
	p->next = p->next->next;
	free(q);
	p = head->next;
	printf("�����ĺ�Ľ��Ϊ��");
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	};
	printf("\n");
}
void clearmr(struct node* head) {
	struct node* p = head;
	printf("������ɾ�������䣺");
	int pos1, pos2;
	scanf("%d,%d", &pos1, &pos2);
	printf("\n");
	struct node* q;
	for (i = 0; i < pos1 - 1; i++) {
		p = p->next;
	}
	for (i = pos1 - 1; i < pos2; i++) {
		q = p->next;
		p->next = p->next->next;
		free(q);
	}
	p = head->next;
	printf("�����ĺ�Ľ��Ϊ��");
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	};
	printf("\n");
}
void clearnum(struct node* head) {
	struct node* p;
	printf("������Ҫȡֵ�ķ�Χ��");
	int num1, num2;
	scanf("%d,%d", &num1, &num2);
	printf("\n");
	struct node* q;
	p = head;
	while (p->next != NULL) {
		q = p->next;
		if (p->next->next == NULL) {
			break;
		}
		if ((q->data) >= num1 && (q->data) <= num2) {
			p->next = q->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}
	q = p->next;
	if ((q->data) >= num1 && (q->data) <= num2) {
		p->next = NULL;
		free(q);
	}
	p = head->next;
	printf("�����ĺ�Ľ��Ϊ��");
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	};
	printf("\n");
}
int main() {
	int n;
	printf("������Ԫ�ظ���n ��");
	scanf("%d", &n);
	printf("\n");
	struct node* head = (struct node*)malloc(1 * sizeof(struct node));
	struct node* p = head;
	printf("������n��Ԫ�أ�");
	for (i = 0; i < n; i++) {
		p->next = (struct node*)malloc(1 * sizeof(struct node));
		p = p->next;
		scanf("%d", &p->data);
	}
	p->next = NULL;
	p = head->next;
	printf("\n");
	printf("�������Ԫ��Ϊ��");
	while (p != NULL) {
		printf("%d  ", p->data);
		p = p->next;
	};
	printf("\n");
	printf("\n");
	clearnum(head);
	printf("\n");
	return 0;
}
