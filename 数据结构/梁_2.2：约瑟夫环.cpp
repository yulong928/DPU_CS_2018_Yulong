#include<stdio.h>
#include<stdlib.h>
struct node{														//���嵥�����ÿ�����ṹ
	int data;
	struct node* next;
};
void result(struct node*p,int m){									//����Լɪ�����
	printf("\nԼɪ����������");
	while(p->next!=p){
		for(int i=1;i<m-1;i++){										//ʹָ��ָ��Ŀ�����ǰһ���ڵ�
			p=p->next;
		}
		printf("%d  ",p->next->data);								//���Ŀ�����ֵ
		p->next=p->next->next;										//���������Ƴ���������
		p=p->next;
	}
	printf("%d\n",p->data);
}
struct node* creat(int n){											//����ѭ��������Ĵ���
	struct node *p,*L;
	for(int i=1;i<=n;i++){
		if(i==1){													//�ж�����ǵ�һ�����ٵĽ�㣬��ͷָ�븳ֵ���ýڵ�
			L=(struct node*)malloc(1*sizeof(struct node));
			p=L;
			p->data=i;
		}
		else{
			p->next=(struct node*)malloc(1*sizeof(struct node));	//���ݽ�������̬���ٽ��
			p->next->data=i;
			p=p->next;
		}
	}
	p->next=L;
	p=p->next;
	return p;
}
int main(){
	int n;
	printf("������������n��");										//��������������
	scanf("%d",&n);	
	while(n<=0){													//������벻���Ϲ��򣬽�����������
		printf("\n����������,���������룺"); 
		scanf("%d",&n);
	}
	struct node* p=creat(n);										//����������n����n������ѭ��������
	printf("\n������ը������m��");
	int m;
	scanf("%d",&m); 
	while(m<=0){													//������벻���Ϲ��򣬽�����������
		printf("\nը�����ֳ���,���������룺"); 
		scanf("%d",&m);
	}
	printf("\n��������ʼ��k��");
	int k;
	scanf("%d",&k);
	while(k<=0||k>=n){												//������벻���Ϲ��򣬽�����������
		printf("\n��ʼ�˳���,���������룺"); 
		scanf("%d",&k);
	} 
	while(p->data!=k){
		p=p->next;
	} 
	result(p,m); 
	return 0;
} 
