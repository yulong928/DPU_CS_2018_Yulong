#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct line{										//定义line链表作为头指针分行和行内字符输入
	char *data;
	struct line *next;
};
int StrLength(char *str){							//该函数用来计算字符串的长度
	int i=0;
	while(str[i]!='\0'){							//以字符串结尾标识“\0”作为结束标志
		i++;
	};
	return i;
}
char *strAssign(char *s,char *t){					//将输入的字符串存储进文章中
	int i,j;
	int len=StrLength(t);
	s=(char*)malloc((len+1)*sizeof(char));			//根据字符串长度动态开辟连续存储单元
	if(s!=NULL){
		for(i=0;i<len;i++){
			s[i]=t[i];
		}
		s[len]='\0';								//存储结束以“\0”结尾
	}
	return s;
}
int *GetNext(char *t){								//该函数计算子串的next值
	int *nextj;
	int i=1,j=0;
	nextj=(int *)malloc((StrLength(t)-1)*sizeof(int));	//根据字符串长度动态开辟连续存储单元
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
int Index_KMP(char *s,char *t,int pos,int *nextj){		//该函数用KMP算法计算子串在母本中的所在位置
	int i=pos,j=1,count=1;
	while(i<=s[0]&&j<=t[0]){							//进行子串与母本的匹配
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
struct line *Creat(){									//进行文章创建函数
	struct line *p,*head;
	char q[50];
	int c,i=1;
	printf("请输入一页文章，以#结尾（每行最多50字符）：\n");
	p=(struct line *)malloc(sizeof(struct line));		//开辟存储每一行的索引结点
	head=p;
	while(1){
		fflush(stdin);
		i=1;
		while((c=getchar())!='\n'){						//输入行内元素
			q[i]=c;
			i++;
		}
		q[i]='\0';
		q[0]=StrLength(q)-1;
		if(StrLength(q)>50){
			printf("每行最多输入50字符！");
			break;
		}
		if(q[0]==35)break;														//如果发现#退出输入 
		p->next=(struct line*)malloc(sizeof(struct line));						//将指针指向下一行头指针
		p=p->next;
		p->data=strAssign(p->data,q);											//将输入内容存入头指针中
		if(q[StrLength(q)-1]==35){
			p->data[StrLength(q)-1]='\0';
			break;
		}
	}
	p->next=NULL;
	head=head->next;
	return head;
}
void Letter(struct line*head){													//进行文章的计数功能
	struct line *p=head;
	int i,let=0,num=0,spa=0,all=0;
	while(p!=NULL){
		for(i=1;i<=StrLength(p->data);i++){
			if((p->data[i]>='a'&&p->data[i]<='z')||(p->data[i]>='A'&&p->data[i]<='Z')){		//判断该字符为字母
				let++;all++; 
			}
			else if(p->data[i]>=48&&p->data[i]<=57){							//判断该字符为数字
				num++;all++;
			}
			else if(p->data[i]==32){											//判断该字符为空格
				spa++;
			}
		}
		p=p->next;
	}
	printf("\n全部字母数为%d\n",let);
	printf("\n数字个数为%d\n",num);
	printf("\n空格个数为%d\n",spa);
	printf("\n文章总字数为%d\n",all);
}
int SearchStr(char *data,char *str){											//进行子串在母本出现次数查询算法
	int j=StrLength(str)-1;
	int i;
	int time=0;
	int result;
	int k,count=1;
	int *nextj;
	do{
		nextj=GetNext(str);														//计算子串字符的next值
		result=Index_KMP(data,str,1,nextj);
		while(result!=0){
			time++;
			result=Index_KMP(data,str,result+StrLength(str)-1,nextj);			//利用KMP算法找到子串所在位置
		}
	}while(result<StrLength(data)-1&&result!=0);								//当没有全部执行完时循环执行方便查找
	return time;
}
void DeleteStr(char *data,char *str){											//进行目标子串在母本中的删除操作
	int j=StrLength(str)-1;
	int i;
	int result;
	int k,count=1;
	int *nextj;
	do{
		nextj=GetNext(str);														//求出子串字符的next值
		result=Index_KMP(data,str,1,nextj);										//利用KMP算法找到子串所在位置
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
	}while(result<StrLength(data)-1&&result!=0);								//遍历所有字符，当没有全部执行完时循环执行方便查找
}
int main(){
	int i,c;
	struct line *head,*p;
	char str[50],str1[50],str2[50];
	int *next,*nextval,*result;
	head=Creat();																//引入creat函数创建文章链表
	printf("\n输出的文章为：\n");
	p=head;
	while(p!=NULL){
		for(i=1;i<=p->data[0];i++){
			printf("%c",p->data[i]);
		}
		printf("\n");
		p=p->next;
	}																			//对文章进行输出
	Letter(head);
	printf("\n请输入要查找的字符串：");
	fflush(stdin);																//删除键盘缓冲符
	i=1;
	while((c=getchar())!='\n'){													//进行子串输入操作
		str[i]=c;
		i++;
	} 
	str[i]='\0';
	str[0]=StrLength(str)-1;
	p=head;
	int allnum=0; 
	while(p!=NULL){
		allnum+=SearchStr(p->data,str);											//搜索每一行子串出现次数
		p=p->next;
	}
	printf("\n目标字符串出现次数为%d\n",allnum);
	p=head;
	printf("\n请输入要删除的某一字符串：");
	fflush(stdin);
	i=1;
	while((c=getchar())!='\n'){													//输入子串
		str[i]=c;
		i++;
	} 
	str[i]='\0';																//使子串以“\0”结尾
	str[0]=StrLength(str)-1;
	p=head;
	while(p!=NULL){																//进行子串删除操作
		DeleteStr(p->data,str);
		p=p->next;
	}
	p=head;
	printf("\n删除后的文章为：\n");												//输出删除后的文章
	while(p!=NULL){
		for(i=1;i<=p->data[0];i++){
			printf("%c",p->data[i]);
		}
		printf("\n");
		p=p->next;
	}
	return 0;
}
