#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
void service();
int find=0,dfind,zx=0;
void quit();
struct bank
{
	char name[20];			//�û���
	char password[7];		//����
	int account;			//�˺�
	double money;			//���
	double dmoney; 
	int time;
	int nian;
	int yue;
	int ri;
}kehu;  
FILE *fp;	
struct bank t;
//���뺯�� 
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
//ע�ắ��																							
void regist()				//����������
{
	char password1[7];		//ȷ������
	fp=fopen("atm.txt","ab+");
	if(fp==NULL)
	{
		printf("\n\n\t\t\t���ļ�ʧ��");
		return;
	}
	printf("\n\n\n\t\t\t�������û�����");
	fflush(stdin);
	gets(kehu.name);
	printf("\n\n\n\t\t\t����û����ǣ�%s\n", kehu.name);
	while(1)
	{
		while(1)
		{
			printf("\n\n\n\t\t\t�������û����룺");
			fflush(stdin);
			inputPassword(kehu.password) ;
			int length=strlen(kehu.password);
			if(length==6)break;
			else
				printf("\n\n\t\t\t�û����볤�ȱ�����6λ");
		}
		printf("\n\n\n\t\t\t��ȷ�����룺");
		fflush(stdin);
		inputPassword(password1) ;
		if(strcmp(kehu.password,password1)==0)break;
		else
			printf("\n\n\n\t\t\t���벻һ�£�����������");
	}
	rewind(fp);														//���ļ�ָ�붨λ���ļ���ͷ 
	if(fread(&t,sizeof(t),1,fp)==1) 
	{
		fseek(fp,-sizeof(kehu),2);
		fread(&t,sizeof(t),1,fp);//��ȡ���һ����¼ 
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
	printf("\n\n\n\t\t\tע��ɹ�");
	printf("\n\n\n\t\t\t�����˺�Ϊ��%d\n\n\n\n",kehu.account);
}
//��¼����
void login()
{
	fp=fopen("atm.txt","rb+");
	if(fp==NULL)
	{
		printf("\n\n\t\t\t��ʧ��");
		return;
	}
	int zhanghao,f=0,i=0;
	int j;
	char password1[7];
	printf("\n\n\n\t\t\t�����������˺ţ�");
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
			printf("\n\n\n\t\t\t������������룺");
			inputPassword(password1);
			if(strcmp(password1,t.password)==0)
			{
				printf("\n\n\n\t\t\t��¼�ɹ�");	 
				service();
				break;
			}
		}
		if( j==3 )
		{
			printf("\n\n\n\t\t\t����������֤�����ɹ����̿���......");
		}	
	}
	else
	{
		printf("\n\n\n\t\t\tû�д��˺�"); 
	}
	fflush(stdin);
	fclose(fp);
}
void selectMoney()
{
	system("cls");
	printf("\n\n\t\t\t����ʹ�ò�ѯ������");
	printf("\n\n\t\t\t�����˻����Ϊ��%.2lf\n",t.money+t.dmoney);
	printf("\n\n\t\t\t�����˻��������Ϊ��%.2lf",t.money);
	printf("\n\n\t\t\t�����˻��������Ϊ��%.2lf",t.dmoney);
	printf("\n\t\t\t���ڴ������%d��%d��%d�պ����ȡ��",t.nian,t.yue,t.ri);
}
void saveMoney()
{
	system("cls");
	int qian; 
	while(1)
	{
		printf("\n\n\t\t\t����ʹ�ô�����");
		printf("\n\n\t\t\t����������");
		scanf("%d",&qian);
		if(qian>0&&qian<=100000)
		{
			break;
		} 
		else
		{
			system("cls"); 
			printf("\n\n\n\t\t\t���ʧ��"); 
		}
	}
	t.money= t.money+qian;
	fseek(fp,-sizeof(t),1);
	fwrite(&t,sizeof(t),1,fp);
	printf("\n\n\t\t\t���ɹ�");
}
void savedMoney()
{
	system("cls");
	int qian; 
	while(1)
	{
		printf("\n\n\t\t\t����ʹ�ô�����");
		printf("\n\n\t\t\t����������:");
		scanf("%d",&qian);
		printf("\n\n\t\t\t������������:");
		scanf("%d",&t.time);
		printf("\n\n\t\t\t������������:");
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
			printf("\n\n\n\t\t\t���ʧ��"); 
		}
	}
	t.dmoney= t.dmoney+qian;
	t.nian+=1;
	fseek(fp,-sizeof(t),1);
	fwrite(&t,sizeof(t),1,fp);
	printf("\n\n\t\t\t���ڴ��ɹ�");
	printf("\n\n\t\t\t�ÿ�����%d��%d��%d�պ����ȡ��",t.nian,t.yue,t.ri);
}
void getMoney()
{
	system("cls");
	int qian;
	while(1)
	{
		printf("\n\n\t\t\t����ʹ��ȡ�����");
		printf("\n\n\t\t\t�����˻��������Ϊ��%.2lf",t.money);
		printf("\n\n\t\t\t������ȡ����");
		scanf("%d",&qian);
		if(qian>0&&qian<=100000)
		{
			break;
		}
		else
		{
			system("cls"); 
			printf("\n\n\n\t\t\tȡ��ʧ��");
		}
	}
	if(t.money>=qian)
	{
		t.money= t.money-qian;
		fseek(fp,-sizeof(t),1);
		fwrite(&t,sizeof(t),1,fp);
		printf("\n\n\t\t\tȡ��ɹ�");
	} 
	else
	{
		printf("\n\n\t\t\t����"); 
	}
}
void getdMoney()
{
	system("cls");
	int qian;
	char s; 
	while(1)
	{
		printf("\n\n\t\t\t����ʹ��ȡ�����");
		printf("\n\n\t\t\t�����˻��������Ϊ��%.2lf",t.dmoney);
		printf("\n\t\t\t���ڴ������%d��%d��%d�պ����ȡ��",t.nian,t.yue,t.ri);
		printf("\n\n\t\t\t��ȷ���Ƿ�ȡ��\n\n\t\t\tȷ�ϡ�Y��   ȡ����N��");
		fflush(stdin);
		scanf("%c",&s);
		if(s=='y'||s=='Y');
		else
		{
			return; 
		}
		printf("\n\n\t\t\t������ȡ����");
		scanf("%d",&qian);
		if(qian>0&&qian<=100000)
		{
			break;
		}
		else
		{
			system("cls"); 
			printf("\n\n\n\t\t\tȡ��ʧ��");
		}
	}
	if(t.dmoney>=qian)
	{
		t.dmoney= t.dmoney-qian;
		fseek(fp,-sizeof(t),1);
		fwrite(&t,sizeof(t),1,fp);
		printf("\n\n\t\t\tȡ��ɹ�");
	} 
	else
	{
		printf("\n\n\t\t\t����"); 
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
		printf("\n\n\t\t\t������ʹ��ת�˷���");
		printf("\n\n\t\t\t������Է��˺�");
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
			printf("\n\n\t\t\t������ת�˽��");
			scanf("%d",&qian); 
			if(qian>0&&qian<=100000)
			{
				break;
			}
			else
			{
				system("cls"); 
				printf("\n\n\n\t\t\tת��ʧ��");
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
			printf("\n\n\t\t\tת�˳ɹ�");
		}
		else
		{
			printf("\n\n\t\t\t����"); 
		}
	}
	else
	{
		printf("\n\n\t\t\t�����ڸ��˺�"); 
	}
	
}
void updatePassword()
{
	system("cls"); 
	int i; 
	char password1[20],password2[20],password3[20] ;
	printf("\n\n\t\t\t�������޸�����");
	for(i=0;i<3;i++)
	{ 
		printf("\n\n\t\t\t�����������");
		inputPassword(password1) ;
		if(strcmp(password1,t.password)==0)
		{
			break; 
		}
		else
		{
			printf("\n\n\t\t\t������������������������");
		}
	} 
	if(i<3)
	{
		while(1)
		{ 
			printf("\n\n\t\t\t�����������룺");
			inputPassword(password2) ;
			printf("\n\n\t\t\t��ȷ�������룺");
			inputPassword(password3) ;
			if(strcmp(password2,password3)==0)
			{
				strcpy(t.password,password2);
				fseek(fp,-sizeof(t),1);
				fwrite(&t,sizeof(t),1,fp);
				printf("\n\n\t\t\t�޸ĳɹ�");
				break; 
			}
			else
			{
				printf("\n\n\t\t\t�������벻һ�£�����������");
			} 
		} 
	}
	else
	{
		printf("\n\n\n\t\t\t����������֤�����ɹ����̿���......");	
	}
}
int zhuxiao()
{
	system("cls"); 
	char sf; 
	printf("\n\n\t\t\t������ע���û�");
	printf("\n\n\t\t\t��Ҫע���Ŀͻ��˺��ǣ�%d\n",t.account);
	printf("\n\n\t\t\t��ȷ���Ƿ�ע���û���\n\n\t\t\tע����Y��   ȡ����N��");
	fflush(stdin);
	scanf("%c",&sf);
	if(sf=='y'||sf=='Y')
	{
		printf("\n\n\t\t\t����ע��%d�û�",t.account); 
		zx=1; 
	}
	else
	{
		printf("\n\n\t\t\tȡ��ע��%d�û������ط������",t.account); 
	}
	return zx;
}
//������� 
void service()
{
	char xz;
	while(1)
	{
		system("cls");
		printf("\n\n\t\t\t������ʹ�÷������"); 
		printf("\n\n\t\t\tA.��ѯ���"); 
		printf("\n\n\t\t\tB.���ڴ��"); 
		printf("\n\n\t\t\tQ.���ڴ��"); 		
		printf("\n\n\t\t\tC.����ȡ��"); 
		printf("\n\n\t\t\tW.����ȡ��"); 
		printf("\n\n\t\t\tD.ת��"); 
		printf("\n\n\t\t\tE.�޸�����"); 
		printf("\n\n\t\t\tF.ע��"); 
		printf("\n\n\t\t\tG.�˳�ϵͳ"); 
		printf("\n\n\t\t\t��ѡ��������ࣺ");
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
		printf("\n\n\t\t\t�����������......");
		getch();
	}
}
//�˳�ϵͳ����
void quit()
{
	system("cls");
	printf("\n\n\n\t\t\tATMΪ������");
	printf("\n\t\t\t�����˳������Ժ�\n\n\n");
	exit(0);												//�˳�ϵͳ����
}

int main()
{
	int t = 1;
	char xz;
	for (int i = 1; i <= 100; i++)
	{
		printf("\n\n\n\n\t\t\t��ӭʹ��ATMϵͳ\n\n");
		printf("\t\t     ���ڽ�����ҳ�棬���Ե�");
		for (int j = 1; j <= t; j++)
		{
			printf(".");
		}
		t++;
		if (t == 6)t = 1;
		printf("\n\n\n\t\t\t\t%d%%", i);
		for (int m = 0; m <= 5000; m++);																	//�ӳ�
		system("cls");																						//��������
	}
	while (1)
	{
		printf("\n\n\n\t\t\tATMϵͳ����Ϊ������\n\n");
		printf("\t\t\t����A�����û�ע��\n\n");
		printf("\t\t\t����B�����û���¼\n\n");
		printf("\t\t\t����C�����˳�ϵͳ\n\n");
		printf("\t\t\t��ѡ�����");
		fflush(stdin);																		//������̻������Ļس���
		scanf("%c", &xz);
		if (xz == 'A' || xz == 'a')
		{
			regist();																		//���ĵ��þ����ķ���
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
			printf("\n\t\t\t����ѡ����������������\n");
		}
		printf("\n\t\t\t�����������......");
		getchar();																		  //�����������ǻ��������ַ����뺯��
		system("cls");
	}
	return 0;
}
