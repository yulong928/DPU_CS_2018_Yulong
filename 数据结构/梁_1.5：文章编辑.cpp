#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line{										//����line������Ϊͷָ����к������ַ�����
	char *data;
	struct line *next;
};
int StrLength(char *str){							//�ú������������ַ����ĳ���
	int i=0;
	while(str[i]!='\0'){							//���ַ�����β��ʶ��\0����Ϊ������־
		i++;
	};
	return i;
}
char *strAssign(char *s,char *t){					//��������ַ����洢��������
	int i,j;
	int len=StrLength(t);
	s=(char*)malloc((len+1)*sizeof(char));			//�����ַ������ȶ�̬���������洢��Ԫ
	if(s!=NULL){
		for(i=0;i<len;i++){
			s[i]=t[i];
		}
		s[len]='\0';								//�洢�����ԡ�\0����β
	}
	return s;
}
int *GetNext(char *t){								//�ú��������Ӵ���nextֵ
	int *nextj;
	int i=1,j=0;
	nextj=(int *)malloc((StrLength(t)-1)*sizeof(int));	//�����ַ������ȶ�̬���������洢��Ԫ
	nextj[1]=0;
	while(i<t[0]){
		if(j==0||t[i]==t[j]){
			++i;++j;
			nextj[i]=j;
		}
		else{
			j=nextj[j];
		}
	}
	return nextj;
}
int Index_KMP(char *s,char *t,int pos,int *nextj){		//�ú�����KMP�㷨�����Ӵ���ĸ���е�����λ��
	int i=pos,j=1,count=1;
	while(i<=s[0]&&j<=t[0]){							//�����Ӵ���ĸ����ƥ��
		if(j==0||s[i]==t[j]){
			++i;++j;
		}
		else{
			j=nextj[j];
		}
	}
	if(j>t[0]){
		return i-t[0];
	}
	else{
		return 0;
	}
}
struct line *Creat(){									//�������´�������
	struct line *p,*head;
	char q[50];
	int c,i=1;
	printf("������һҳ���£���#��β��ÿ�����50�ַ�����\n");
	p=(struct line *)malloc(sizeof(struct line));		//���ٴ洢ÿһ�е��������
	head=p;
	while(1){
		fflush(stdin);
		i=1;
		while((c=getchar())!='\n'){						//��������Ԫ��
			q[i]=c;
			i++;
		}
		q[i]='\0';
		q[0]=StrLength(q)-1;
		if(StrLength(q)>50){
			printf("ÿ���������50�ַ���");
			break;
		}
		if(q[0]==35)break;														//�������#�˳����� 
		p->next=(struct line*)malloc(sizeof(struct line));						//��ָ��ָ����һ��ͷָ��
		p=p->next;
		p->data=strAssign(p->data,q);											//���������ݴ���ͷָ����
		if(q[StrLength(q)-1]==35){
			p->data[StrLength(q)-1]='\0';
			break;
		}
	}
	p->next=NULL;
	head=head->next;
	return head;
}
void Letter(struct line*head){													//�������µļ�������
	struct line *p=head;
	int i,let=0,num=0,spa=0,all=0;
	while(p!=NULL){
		for(i=1;i<=StrLength(p->data);i++){
			if((p->data[i]>='a'&&p->data[i]<='z')||(p->data[i]>='A'&&p->data[i]<='Z')){		//�жϸ��ַ�Ϊ��ĸ
				let++;all++; 
			}
			else if(p->data[i]>=48&&p->data[i]<=57){							//�жϸ��ַ�Ϊ����
				num++;all++;
			}
			else if(p->data[i]==32){											//�жϸ��ַ�Ϊ�ո�
				spa++;
			}
		}
		p=p->next;
	}
	printf("\nȫ����ĸ��Ϊ%d\n",let);
	printf("\n���ָ���Ϊ%d\n",num);
	printf("\n�ո����Ϊ%d\n",spa);
	printf("\n����������Ϊ%d\n",all);
}
int SearchStr(char *data,char *str){											//�����Ӵ���ĸ�����ִ�����ѯ�㷨
	int j=StrLength(str)-1;
	int i;
	int time=0;
	int result;
	int k,count=1;
	int *nextj;
	do{
		nextj=GetNext(str);														//�����Ӵ��ַ���nextֵ
		result=Index_KMP(data,str,1,nextj);
		while(result!=0){
			time++;
			result=Index_KMP(data,str,result+StrLength(str)-1,nextj);			//����KMP�㷨�ҵ��Ӵ�����λ��
		}
	}while(result<StrLength(data)-1&&result!=0);								//��û��ȫ��ִ����ʱѭ��ִ�з������
	return time;
}
void DeleteStr(char *data,char *str){											//����Ŀ���Ӵ���ĸ���е�ɾ������
	int j=StrLength(str)-1;
	int i;
	int result;
	int k,count=1;
	int *nextj;
	do{
		nextj=GetNext(str);														//����Ӵ��ַ���nextֵ
		result=Index_KMP(data,str,1,nextj);										//����KMP�㷨�ҵ��Ӵ�����λ��
		if(result!=0){
			i=StrLength(data)-1;
			if((result+j)>i){
				data[result]='\0';
			}
			else{
				for(k=result+j;k<=i;k++){
					data[k-j]=data[k];
				}
				data[i-j+1]='\0';
			}
			data[0]=i-j;
		}
	}while(result<StrLength(data)-1&&result!=0);								//���������ַ�����û��ȫ��ִ����ʱѭ��ִ�з������
}
int main(){
	int i,c;
	struct line *head,*p;
	char str[50],str1[50],str2[50];
	int *next,*nextval,*result;
	head=Creat();																//����creat����������������
	printf("\n���������Ϊ��\n");
	p=head;
	while(p!=NULL){
		for(i=1;i<=p->data[0];i++){
			printf("%c",p->data[i]);
		}
		printf("\n");
		p=p->next;
	}																			//�����½������
	Letter(head);
	printf("\n������Ҫ���ҵ��ַ�����");
	fflush(stdin);																//ɾ�����̻����
	i=1;
	while((c=getchar())!='\n'){													//�����Ӵ��������
		str[i]=c;
		i++;
	} 
	str[i]='\0';
	str[0]=StrLength(str)-1;
	p=head;
	int allnum=0; 
	while(p!=NULL){
		allnum+=SearchStr(p->data,str);											//����ÿһ���Ӵ����ִ���
		p=p->next;
	}
	printf("\nĿ���ַ������ִ���Ϊ%d\n",allnum);
	p=head;
	printf("\n������Ҫɾ����ĳһ�ַ�����");
	fflush(stdin);
	i=1;
	while((c=getchar())!='\n'){													//�����Ӵ�
		str[i]=c;
		i++;
	} 
	str[i]='\0';																//ʹ�Ӵ��ԡ�\0����β
	str[0]=StrLength(str)-1;
	p=head;
	while(p!=NULL){																//�����Ӵ�ɾ������
		DeleteStr(p->data,str);
		p=p->next;
	}
	p=head;
	printf("\nɾ���������Ϊ��\n");												//���ɾ���������
	while(p!=NULL){
		for(i=1;i<=p->data[0];i++){
			printf("%c",p->data[i]);
		}
		printf("\n");
		p=p->next;
	}
	return 0;
}
