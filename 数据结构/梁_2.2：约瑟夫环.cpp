#include<stdio.h>
#include<stdlib.h>
struct node{														//定义单链表的每个结点结构
	int data;
	struct node* next;
};
void result(struct node*p,int m){									//进行约瑟夫环输出
	printf("\n约瑟夫环输出结果：");
	while(p->next!=p){
		for(int i=1;i<m-1;i++){										//使指针指向目标结点的前一个节点
			p=p->next;
		}
		printf("%d  ",p->next->data);								//输出目标结点的值
		p->next=p->next->next;										//将输出结点移除出单链表
		p=p->next;
	}
	printf("%d\n",p->data);
}
struct node* creat(int n){											//进行循环单链表的创建
	struct node *p,*L;
	for(int i=1;i<=n;i++){
		if(i==1){													//判断如果是第一个开辟的结点，则将头指针赋值给该节点
			L=(struct node*)malloc(1*sizeof(struct node));
			p=L;
			p->data=i;
		}
		else{
			p->next=(struct node*)malloc(1*sizeof(struct node));	//根据结点个数动态开辟结点
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
	printf("请输入总人数n：");										//进行总人数输入
	scanf("%d",&n);	
	while(n<=0){													//如果输入不符合规则，进行重新输入
		printf("\n总人数出错,请重新输入："); 
		scanf("%d",&n);
	}
	struct node* p=creat(n);										//根据总人数n开辟n个结点的循环单链表
	printf("\n请输入炸弹数字m：");
	int m;
	scanf("%d",&m); 
	while(m<=0){													//如果输入不符合规则，进行重新输入
		printf("\n炸弹数字出错,请重新输入："); 
		scanf("%d",&m);
	}
	printf("\n请输入起始人k：");
	int k;
	scanf("%d",&k);
	while(k<=0||k>=n){												//如果输入不符合规则，进行重新输入
		printf("\n起始人出错,请重新输入："); 
		scanf("%d",&k);
	} 
	while(p->data!=k){
		p=p->next;
	} 
	result(p,m); 
	return 0;
} 
