#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void service();
int find=0,dfind,zx=0;
void quit();
struct bank
{
	char name[20];			//用户名
	char password[7];		//密码
	int account;			//账号
	double money;			//余额
	double dmoney; 
	int time;
	int nian;
	int yue;
	int ri;
}kehu;  
FILE *fp;	
struct bank t;
//密码函数 
void inputPassword(char mima[])
{
    int i=0;
    char ch;
    while(1)
    {
     	ch=getch();
    	if(ch!='\r')
	    {
	       	if(ch!='\b')
	      	{
		    	mima[i]=ch;
		        i++;
		    	printf("*");
		    }
		    else
			{
				if(i>0)
				{
			     	i--;
		   		    printf("\b \b");	
				}
			} 
	    }
	    else
		{
			break;
		}
	}
	mima[i]='\0';
	printf("\n");
}
//注册函数																							
void regist()				//函数的声明
{
	char password1[7];		//确认密码
	fp=fopen("atm.txt","ab+");
	if(fp==NULL)
	{
		printf("\n\n\t\t\t打开文件失败");
		return;
	}
	printf("\n\n\n\t\t\t请输入用户名：");
	fflush(stdin);
	gets(kehu.name);
	printf("\n\n\n\t\t\t这个用户名是：%s\n", kehu.name);
	while(1)
	{
		while(1)
		{
			printf("\n\n\n\t\t\t请输入用户密码：");
			fflush(stdin);
			inputPassword(kehu.password) ;
			int length=strlen(kehu.password);
			if(length==6)break;
			else
				printf("\n\n\t\t\t用户密码长度必须是6位");
		}
		printf("\n\n\n\t\t\t请确认密码：");
		fflush(stdin);
		inputPassword(password1) ;
		if(strcmp(kehu.password,password1)==0)break;
		else
			printf("\n\n\n\t\t\t密码不一致，请重新输入");
	}
	rewind(fp);														//将文件指针定位到文件开头 
	if(fread(&t,sizeof(t),1,fp)==1) 
	{
		fseek(fp,-sizeof(kehu),2);
		fread(&t,sizeof(t),1,fp);//读取最后一条记录 
		kehu.account=t.account+1; 
	}
	else
	{
		kehu.account=20180001; 
	} 
	kehu.money=0;
	fseek(fp,0,2);
	fwrite(&kehu,sizeof(struct bank),1,fp);
	fclose(fp);
	printf("\n\n\n\t\t\t注册成功");
	printf("\n\n\n\t\t\t您的账号为：%d\n\n\n\n",kehu.account);
}
//登录函数
void login()
{
	fp=fopen("atm.txt","rb+");
	if(fp==NULL)
	{
		printf("\n\n\t\t\t打开失败");
		return;
	}
	int zhanghao,f=0,i=0;
	int j;
	char password1[7];
	printf("\n\n\n\t\t\t请输入您的账号：");
	scanf("%d",&zhanghao);
	while(fread(&t,sizeof(t),1,fp)==1)
	{
		if(zhanghao==t.account)
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		for(j=0;j<3;j++)
		{
			printf("\n\n\n\t\t\t请输入你的密码：");
			inputPassword(password1);
			if(strcmp(password1,t.password)==0)
			{
				printf("\n\n\n\t\t\t登录成功");	 
				service();
				break;
			}
		}
		if( j==3 )
		{
			printf("\n\n\n\t\t\t三次密码验证都不成功，吞卡中......");
		}	
	}
	else
	{
		printf("\n\n\n\t\t\t没有此账号"); 
	}
	fflush(stdin);
	fclose(fp);
}
void selectMoney()
{
	system("cls");
	printf("\n\n\t\t\t正在使用查询余额服务");
	printf("\n\n\t\t\t您的账户余额为：%.2lf\n",t.money+t.dmoney);
	printf("\n\n\t\t\t您的账户活期余额为：%.2lf",t.money);
	printf("\n\n\t\t\t您的账户定期余额为：%.2lf",t.dmoney);
	printf("\n\t\t\t定期存款须在%d年%d月%d日后进行取款",t.nian,t.yue,t.ri);
}
void saveMoney()
{
	system("cls");
	int qian; 
	while(1)
	{
		printf("\n\n\t\t\t正在使用存款服务");
		printf("\n\n\t\t\t请输入存款金额");
		scanf("%d",&qian);
		if(qian>0&&qian<=100000)
		{
			break;
		} 
		else
		{
			system("cls"); 
			printf("\n\n\n\t\t\t存款失败"); 
		}
	}
	t.money= t.money+qian;
	fseek(fp,-sizeof(t),1);
	fwrite(&t,sizeof(t),1,fp);
	printf("\n\n\t\t\t存款成功");
}
void savedMoney()
{
	system("cls");
	int qian; 
	while(1)
	{
		printf("\n\n\t\t\t正在使用存款服务");
		printf("\n\n\t\t\t请输入存款金额:");
		scanf("%d",&qian);
		printf("\n\n\t\t\t请输入存款年限:");
		scanf("%d",&t.time);
		printf("\n\n\t\t\t请输入存款日期:");
		scanf("%d",&t.nian);
		scanf("%d",&t.yue);
		scanf("%d",&t.ri);
		if(qian>0&&qian<=100000)
		{
			break;
		} 
		else
		{
			system("cls"); 
			printf("\n\n\n\t\t\t存款失败"); 
		}
	}
	t.dmoney= t.dmoney+qian;
	t.nian+=1;
	fseek(fp,-sizeof(t),1);
	fwrite(&t,sizeof(t),1,fp);
	printf("\n\n\t\t\t定期存款成功");
	printf("\n\n\t\t\t该款须在%d年%d月%d日后进行取款",t.nian,t.yue,t.ri);
}
void getMoney()
{
	system("cls");
	int qian;
	while(1)
	{
		printf("\n\n\t\t\t正在使用取款服务");
		printf("\n\n\t\t\t您的账户活期余额为：%.2lf",t.money);
		printf("\n\n\t\t\t请输入取款金额");
		scanf("%d",&qian);
		if(qian>0&&qian<=100000)
		{
			break;
		}
		else
		{
			system("cls"); 
			printf("\n\n\n\t\t\t取款失败");
		}
	}
	if(t.money>=qian)
	{
		t.money= t.money-qian;
		fseek(fp,-sizeof(t),1);
		fwrite(&t,sizeof(t),1,fp);
		printf("\n\n\t\t\t取款成功");
	} 
	else
	{
		printf("\n\n\t\t\t余额不足"); 
	}
}
void getdMoney()
{
	system("cls");
	int qian;
	char s; 
	while(1)
	{
		printf("\n\n\t\t\t正在使用取款服务");
		printf("\n\n\t\t\t您的账户定期余额为：%.2lf",t.dmoney);
		printf("\n\t\t\t定期存款须在%d年%d月%d日后进行取款",t.nian,t.yue,t.ri);
		printf("\n\n\t\t\t请确认是否取款\n\n\t\t\t确认【Y】   取消【N】");
		fflush(stdin);
		scanf("%c",&s);
		if(s=='y'||s=='Y');
		else
		{
			return; 
		}
		printf("\n\n\t\t\t请输入取款金额");
		scanf("%d",&qian);
		if(qian>0&&qian<=100000)
		{
			break;
		}
		else
		{
			system("cls"); 
			printf("\n\n\n\t\t\t取款失败");
		}
	}
	if(t.dmoney>=qian)
	{
		t.dmoney= t.dmoney-qian;
		fseek(fp,-sizeof(t),1);
		fwrite(&t,sizeof(t),1,fp);
		printf("\n\n\t\t\t取款成功");
	} 
	else
	{
		printf("\n\n\t\t\t余额不足"); 
	}
}
void zhuanzhang()
{
	system("cls");
	int zhanghao,qian,i,f;
	struct bank temp;
	int n=ftell(fp);
	while(1)
	{
		printf("\n\n\t\t\t您正在使用转账服务");
		printf("\n\n\t\t\t请输入对方账号");
		scanf("%d",&zhanghao);
		rewind(fp);
		while(fread(&temp,sizeof(temp),1,fp)==1)
		{
			if(zhanghao==temp.account)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			printf("\n\n\t\t\t请输入转账金额");
			scanf("%d",&qian); 
			if(qian>0&&qian<=100000)
			{
				break;
			}
			else
			{
				system("cls"); 
				printf("\n\n\n\t\t\t转账失败");
			}
		}
	} 
	if(f==1)
	{
		if(t.money>=qian)
		{
			t.money= t.money-qian;
			temp.money= temp.money+qian;
			fseek(fp,-sizeof(t),1);
			fwrite(&temp,sizeof(t),1,fp);
			fseek(fp,n-sizeof(t),0);
			fwrite(&t,sizeof(t),1,fp);
			printf("\n\n\t\t\t转账成功");
		}
		else
		{
			printf("\n\n\t\t\t余额不足"); 
		}
	}
	else
	{
		printf("\n\n\t\t\t不存在该账号"); 
	}
	
}
void updatePassword()
{
	system("cls"); 
	int i; 
	char password1[20],password2[20],password3[20] ;
	printf("\n\n\t\t\t您正在修改密码");
	for(i=0;i<3;i++)
	{ 
		printf("\n\n\t\t\t请输入旧密码");
		inputPassword(password1) ;
		if(strcmp(password1,t.password)==0)
		{
			break; 
		}
		else
		{
			printf("\n\n\t\t\t旧密码输入有误，请重新输入");
		}
	} 
	if(i<3)
	{
		while(1)
		{ 
			printf("\n\n\t\t\t请输入新密码：");
			inputPassword(password2) ;
			printf("\n\n\t\t\t请确认新密码：");
			inputPassword(password3) ;
			if(strcmp(password2,password3)==0)
			{
				strcpy(t.password,password2);
				fseek(fp,-sizeof(t),1);
				fwrite(&t,sizeof(t),1,fp);
				printf("\n\n\t\t\t修改成功");
				break; 
			}
			else
			{
				printf("\n\n\t\t\t两次密码不一致，请重新输入");
			} 
		} 
	}
	else
	{
		printf("\n\n\n\t\t\t三次密码验证都不成功，吞卡中......");	
	}
}
int zhuxiao()
{
	system("cls"); 
	char sf; 
	printf("\n\n\t\t\t您正在注销用户");
	printf("\n\n\t\t\t您要注销的客户账号是：%d\n",t.account);
	printf("\n\n\t\t\t请确认是否注销用户。\n\n\t\t\t注销【Y】   取消【N】");
	fflush(stdin);
	scanf("%c",&sf);
	if(sf=='y'||sf=='Y')
	{
		printf("\n\n\t\t\t正在注销%d用户",t.account); 
		zx=1; 
	}
	else
	{
		printf("\n\n\t\t\t取消注销%d用户，返回服务界面",t.account); 
	}
	return zx;
}
//服务界面 
void service()
{
	char xz;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t\t您正在使用服务界面"); 
		printf("\n\n\t\t\tA.查询余额"); 
		printf("\n\n\t\t\tB.活期存款"); 
		printf("\n\n\t\t\tQ.定期存款"); 		
		printf("\n\n\t\t\tC.活期取款"); 
		printf("\n\n\t\t\tW.定期取款"); 
		printf("\n\n\t\t\tD.转账"); 
		printf("\n\n\t\t\tE.修改密码"); 
		printf("\n\n\t\t\tF.注销"); 
		printf("\n\n\t\t\tG.退出系统"); 
		printf("\n\n\t\t\t请选择服务种类：");
		fflush(stdin);
		scanf("%c",&xz);
		switch(xz)
		{
			case'a':
			case'A':selectMoney();break;
			case'b':
			case'B':saveMoney();break;
			case'q':
			case'Q':savedMoney();break;
			case'c':
			case'C':getMoney();break;
			case'w':
			case'W':getdMoney();break;
			case'd':
			case'D':zhuanzhang();break;
			case'e':
			case'E':updatePassword();break;
			case'f':
			case'F':
			{
				int zx;
				zx=zhuxiao();
				if(zx==1) 
					return;	
				break;
			} 
			case'g':
			case'G':quit();break;
		} 
		printf("\n\n\t\t\t按任意键继续......");
		getch();
	}
}
//退出系统函数
void quit()
{
	system("cls");
	printf("\n\n\n\t\t\tATM为您服务");
	printf("\n\t\t\t正在退出，请稍后\n\n\n");
	exit(0);												//退出系统函数
}

int main()
{
	int t = 1;
	char xz;
	for (int i = 1; i <= 100; i++)
	{
		printf("\n\n\n\n\t\t\t欢迎使用ATM系统\n\n");
		printf("\t\t     正在进入主页面，请稍等");
		for (int j = 1; j <= t; j++)
		{
			printf(".");
		}
		t++;
		if (t == 6)t = 1;
		printf("\n\n\n\t\t\t\t%d%%", i);
		for (int m = 0; m <= 5000; m++);																	//延迟
		system("cls");																						//清屏函数
	}
	while (1)
	{
		printf("\n\n\n\t\t\tATM系统正在为您服务\n\n");
		printf("\t\t\t服务【A】：用户注册\n\n");
		printf("\t\t\t服务【B】：用户登录\n\n");
		printf("\t\t\t服务【C】：退出系统\n\n");
		printf("\t\t\t请选择服务：");
		fflush(stdin);																		//清除键盘缓冲区的回车符
		scanf("%c", &xz);
		if (xz == 'A' || xz == 'a')
		{
			regist();																		//在哪调用就在哪返回
		}
		else if (xz == 'B' || xz == 'b')
		{
			login();
		}
		else if (xz == 'C' || xz == 'c')
		{
			quit();
		}
		else
		{
			printf("\n\t\t\t输入选择有误，请重新输入\n");
		}
		printf("\n\t\t\t按任意键继续......");
		getchar();																		  //不经过键盘那缓冲区的字符输入函数
		system("cls");
	}
	return 0;
}
