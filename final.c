#include<stdio.h>
#include<math.h>
#include<windows.h>
#define maxmember 200
#define maxcourse 15
int realnumber=0,realcourse=0;
struct student
{char num[13];
char name[20];
char sex[4];
char grade[5];
char college[3];
char major[3];
float score[maxcourse];
float aver;
float total;};
struct course  
{int num;
char name[20];
int credit;};
struct student member[maxmember];
struct course curriculum[maxcourse];
main()
{
	void title(char *s); 
	void inputmember(struct student *p,int*a,int*c);
	void inputcourse(struct student *p1,struct course *p,int*b,int*c); 
	void inputscore(struct student *p,struct course *p1,int *a,int *b,int*c);
	void revise(struct student *p,struct course *p1); 
	void cutout(struct student *p);
	void add(struct student *p,struct course *p1,int *a,int*b,int*c);
	void coursebase(struct student *p1,struct course*p,int *a,int *b,int*c);
	void sequence(struct student *p,struct course *p1,int *a,int *b,int*c);
	void statistics(struct student *p,struct course *p1,int *a,int *b,int*c);
	void lookup(struct student *p,struct course *p1,int *a,int *b,int*c);
	void printall(struct student *p,struct course *p1,int *a,int *b,int*c);
	char choose;int flag1=0,flag2=0,flag3=0; int *a=&flag1,*b=&flag2,*c=&flag3;
	title("ѧ���ɼ�����ϵͳ1.0\n\n\t\t\t\t\t\t\tProgrammed by WangYulong\n\n\t\t\t\t\t\t\tthe member of the Cooprative Team of C Programming Language \n");
 	printf("\n\n\t\t\t\t\t\t\tΪ����ʹ���߿����˽�ϵͳ����������������ϵͳ��˵����\n\n"); 
	printf("\t\t\t\t\t\t\t*��ϵͳĬ��ѧ��1-4λ���꼶��5-6λ��ѧԺ��7-8λ��רҵ\n\n"); 
 	printf("\t\t\t\t\t\t\t*ǰ�������빦����ʹ���������ܵĻ�����Ӧ������ѡ��\n\n"); 
 	printf("\t\t\t\t\t\t\t*ѡ��˵��е���ĸѡ��ʱ��СдЧ����ͬ\n\n"); 
 	printf("\t\t\t\t\t\t\t*ϵͳ�����в˵���back������ĸb��B��Ϊ����\n\n"); 
 	printf("\t\t\t\t\t\t\t*��ӡ������print������ĸp��P��ʾ\n\n"); 
 	printf("\t\t\t\t\t\t\t*��ʱһ���˵�ѡ����Ҫ�������鷽��ִ������\n\n"); 
	printf("\t\t\t\t\t\t\t*���������ֶѵ�ʱ����ȫ����ʾ����\n\n");
 	printf("\n\n\n"); 
 	printf("���س�������ϵͳ...\n");
 	getchar();
	do{
 		title("ѧ���ɼ�����ϵͳ1.0\n\n\n");
 		printf("\t\t\t\t\t\t\t���ܴ�ȫ��\n\n");
		printf("\t\t\t\t\t\t\t1.¼��ѧ����Ϣ\n\n");
		printf("\t\t\t\t\t\t\t2.¼��γ���Ϣ\n\n");
		printf("\t\t\t\t\t\t\t3.¼�����\n\n"); 
		printf("\t\t\t\t\t\t\t4.�޸�ѧ����¼\n\n");
		printf("\t\t\t\t\t\t\t5.ɾ��ѧ����¼\n\n"); 
	 	printf("\t\t\t\t\t\t\t6.���ѧ����Ϣ\n\n"); 
 		printf("\t\t\t\t\t\t\t7.�γ̿�\n\n");
  		printf("\t\t\t\t\t\t\t8.����\n\n");
   		printf("\t\t\t\t\t\t\t9.ͳ��\n\n");
	    printf("\t\t\t\t\t\t\ta.��ѯ\n\n"); 
		printf("\t\t\t\t\t\t\tp.��ӡ������Ϣ\n\n");
		printf("\t\t\t\t\t\t\tb.�˳�\n\n");
		printf("\n\n\n");
		scanf("%c",&choose);
		getchar();
		switch(choose)
		{
		case '1':inputmember(member,a,c);flag1++;getchar();break;
		case '2':inputcourse(member,curriculum,b,c);flag2++;getchar();break;
		case '3':inputscore(member,curriculum,a,b,c);flag3++;getchar();break;
		case '4':revise(member,curriculum);getchar();break;
		case '5':cutout(member);break;
		case '6':add(member,curriculum,a,b,c);break;
		case '7':coursebase(member,curriculum,a,b,c);getchar();break;
		case '8':sequence(member,curriculum,a,b,c);break;
		case '9':statistics(member,curriculum,a,b,c);getchar();break;
		case 'A':
		case 'a':lookup(member,curriculum,a,b,c);break;
		case 'P':
		case 'p':printall(member,curriculum,a,b,c);getchar();break;
		case 'B':
		case 'b':exit(0);
		default:printf("ѡ����ڣ����س�������...\n");getchar();break;
		}
	}while(choose!='b'&&choose!='B');
}
void title(char *s)
{
	system("cls");
	printf("\t\t\t\t\t\t\t%s\n\n\n",s);
}
void titleforsequence(char *s,char *s2)
{
	system("cls");
	printf("\t\t\t\t\t\t��һ�ֶ�Ϊ%s���ڶ��ֶ�Ϊ%s�γ�����\n\n\n",s,s2);
}
void extract( struct student *p)
{
	int i;
	for(i=1;i<=4;i++)
	p->grade[i-1]=p->num[i-1];p->grade[4]='\0';
	for(i=1;i<=2;i++)
	p->college[i-1]=p->num[i+3];p->college[2]='\0';
	for(i=1;i<=2;i++)
	p->major[i-1]=p->num[i+5];p->major[2]='\0';
} 
void average(struct student *p)
{
	int j;
	p->total=0;
	for(j=1;j<=realcourse;j++)
	{
		p->total+=p->score[j-1];
	}
	p->aver=p->total/realcourse;
}
void delete1(struct student *p) 
{
	title("��ѧ��ɾ����¼");
	char deletenum[13]; 
	int i,j;
	printf("��������Ҫɾ����¼��ѧ��ѧ��:\n");
	scanf("%s",deletenum);
	title("��ѧ��ɾ����¼");
	for(i=0;i<=realnumber-1;i++)
	{
		if(strcmp(deletenum,p[i].num)==0)
		{
			if(i!=realnumber-1)
			{
				for(j=i;j<=realnumber-2;j++)
				p[j]=p[j+1];
			} 
			realnumber--;
			printf("ɾ���ɹ�,���س�������\n");
			getchar(); 
			return; 
		}	
	}
	printf("û�и�ѧ����Ϣ\n");
	getchar();
	printf("\n\n\n���س�������");
}
void delete5(struct student *p) 
{
	title("������ɾ����¼");
	char deletename[13]; 
	int i,j;
	printf("��������Ҫɾ����¼��ѧ��ѧ��:\n");
	scanf("%s",deletename);
	title("������ɾ����¼");
	for(i=0;i<=realnumber-1;i++)
	{
		if(strcmp(deletename,p[i].name)==0)
		{
			if(i!=realnumber-1)
			{
				for(j=i;j<=realnumber-2;j++)
				p[j]=p[j+1];
			} 
			realnumber--;
			printf("ɾ���ɹ�,���س�������\n");
			getchar(); 
			return; 
		}	
	}
	printf("û�и�ѧ����Ϣ\n");
	getchar();
	printf("\n\n\n���س�������");
}
void delete2(struct student *p) 
{
	title("���꼶ɾ����¼");
	char deletegrade[5];
	int i,j,successdeletenum=0;
	printf("��������Ҫɾ�����꼶�ţ�\n"); 
	scanf("%s",deletegrade);
	for(i=0;i<=realnumber-1;i++)
	{
		if(strcmp(deletegrade,p[i].grade)==0)
		{
			if(i!=realnumber-1)
			{
				for(j=i;j<=realnumber-2;j++)
				p[j]=p[j+1];
			} 
			realnumber--;
			successdeletenum++;
		}	
	}
	if(successdeletenum==0){
	printf("û�и��꼶��Ϣ\n");
	getchar();
	printf("\n\n\n���س�������");}
	else {getchar();printf("�ɹ�ɾ��%d����¼�����س�������...\n",successdeletenum); }
}
void delete3(struct student *p) 
{
	title("��רҵɾ����¼");
	char deletemajor[3]; 
	int i,j,successdeletenum=0;
	printf("��������Ҫɾ����רҵ��:\n");
	scanf("%s",deletemajor);
	for(i=0;i<=realnumber-1;i++)
	{
		if(strcmp(deletemajor,p[i].major)==0)
		{
			if(i!=realnumber-1)
			{
				for(j=i;j<=realnumber-2;j++)
				p[j]=p[j+1];
				realnumber--;
				successdeletenum++;
			} else{realnumber--;
				successdeletenum++;
			} 	
		}	
	}
	if(successdeletenum==0){
	printf("û�и�רҵ��Ϣ\n");
	getchar();
	printf("\n\n\n���س�������");}
	else {getchar();printf("�ɹ�ɾ��%d����¼�����س�������...\n",successdeletenum); }
}
void delete4(struct student *p)
{
	title("��ѧԺɾ����¼");
	char deletecollege[3];
	int i,j,successdeletenum=0;
	printf("��������Ҫɾ����ѧԺ�ţ�\n"); 
	scanf("%s",deletecollege);
	for(i=0;i<=realnumber-1;i++)
	{
		if(strcmp(deletecollege,p[i].college)==0)
		{
			if(i!=realnumber-1)
			{
				for(j=i;j<=realnumber-2;j++)
				p[j]=p[j+1];
			} 
			realnumber--;
			successdeletenum++;
		}	
	}
	if(successdeletenum==0){
	printf("û�и�ѧԺ��Ϣ\n");
	getchar();
	printf("\n\n\n���س�������");}
	else {getchar();printf("�ɹ�ɾ��%d����¼�����س�������...\n",successdeletenum); }
}
void add1(struct student *p,struct course *p1)
{
	void inputcorepart(struct student *p,struct course *p1,int n);
	title("���һ��ѧ����Ϣ");
	printf("����������ѧ�ţ��������Ա�\n");
 	scanf("%s %s %s",p[realnumber].num,p[realnumber].name,p[realnumber].sex);
 	extract(p+realnumber);
 	inputcorepart(p+realnumber,p1,1); 
	realnumber++;
	getchar();
	printf("\n\n\n���س�������");
}
void add2(struct student *p,struct course *p1)
{
	void inputcorepart(struct student *p,struct course *p1,int n);
	title("��Ӷ��ѧ����Ϣ");
	int number,i;
	printf("��Ҫ��ӵ�ѧ������Ϊ��\n");
	scanf("%d",&number);
	title("��Ӷ��ѧ����Ϣ");
	for(i=1;i<=number;i++)
	{
		printf("�������%d�����ѧ����ѧ�ţ��������Ա�\n",i);
 		scanf("%s %s %s",(p+realnumber+i-1)->num,(p+realnumber+i-1)->name,(p+realnumber+i-1)->sex);
 		extract(p+realnumber+i-1);
	}
	inputcorepart(p+realnumber,p1,number);
	realnumber+=number;
	getchar();
	printf("\n\n\n���س�������");
}
void add3(struct student *p,struct course *p1)
{
	void inputcorepart(struct student *p,struct course *p1,int n);
	title("��Ӳ�������ѧ����Ϣ");
	int i;char s[20]; 
	title("��Ӳ�������ѧ����Ϣ");
	printf("���뵥��stop���س���ֹͣ�������\n");
	for(i=1;i>=1;i++)
	{
		printf("�������%d�����ѧ����ѧ�ţ��������Ա�\n",i);
		scanf("%s",(p+realnumber+i-1)->num);
		if(strcmp((p+realnumber+i-1)->num,"stop")!=0){ 
		scanf("%s",(p+realnumber+i-1)->name);if(strcmp((p+realnumber+i-1)->name,"stop")!=0){scanf("%s",(p+realnumber+i-1)->sex);if(strcmp((p+realnumber+i-1)->sex,"stop")==0)break;}else break;} 
		else break;
	}
	inputcorepart(p+realnumber,p1,i-1);
	realnumber+=(i-1);
	getchar();
	printf("\n\n\n���س�������");
}
void addcourse(struct student *p1,struct course *p)
{
	title("��ӿγ�");
	int i;
	realcourse++;
	printf("����������γ̺š��γ�����ѧ��\n");
	scanf("%d %s %d",&p[realcourse-1].num,p[realcourse-1].name,&p[realcourse-1].credit); 
	for(i=0;i<=realnumber-1;i++)
	{
		printf("������%s��%s�Ŀγ̷�����\n",p1[i].name,p[realcourse].name);
		scanf("%f",&p1[i].score[realcourse-1]);
		average(p1+i);
	}
	printf("\n\n\n���س�������");
}
void deletecourse(struct student *p1,struct course *p)
{
	title("ɾ���γ�");
	int i,j,recording;
	char name[20];
	printf("������Ҫɾ���γ̵Ŀγ���\n");
	scanf("%s",name);
	for(j=0;j<=realcourse-1;j++)
	{
		if(strcmp(name,p[j].name)==0); 
		{
			for(i=j;i<=realcourse-2;i++)
			p[i]=p[i+1];
			break;
		}
	}
	for(i=0;i<=realnumber-1;i++)
	{
		for(;j<=realcourse-2;j++)
		{
			p1[i].score[j]=p1[i].score[j+1];
		}
	}
	realcourse--;
	getchar();
	printf("\n\n\n���س�������");
}
void revisecourse(struct course *p)
{
	title("�޸Ŀγ���Ϣ");
	char name[20];
	int j,credit,flag=0,storage;
	printf("������Ҫ�޸ĵĿγ̵Ŀγ�����\n");
	scanf("%s",name);
	for(j=0;j<=realcourse-1;j++)
	{
		if(strcmp(name,p[j].name)==0)
		break;
		else flag++;
	}
	if(flag==realcourse)
	{printf("δ�ҵ��˿γ�\n");return;}
	else printf("�����������޸ĺ�Ŀγ̺š��γ��������γ�ѧ�֣�\n");
	scanf("%d %s %d",&p[j].num,p[j].name,&p[j].credit);
	getchar();
	printf("\n\n\n�޸ĳɹ������س�������");
}
void viewcourse(struct student *p1,struct course *p,int *a,int *b,int*c)
{
	void statcourse(struct student *p,struct course *p1,int*a,int*b,int*c); 
	title("�鿴���пγ���Ϣ");
	int i;
	statcourse(p1,p,a,b,c);
	printf("\n\n\n���س�������");
}
void printjgt(struct student *p,struct course*p1)
{
	int creditcal(struct student p,struct course*p1);
	int i;
	printf("%-16s%-8s%-8s",p->num,p->name,p->sex);
	for(i=1;i<=realcourse;i++)
	printf("%-8.2f",p->score[i-1]);
	printf("%-8.2f%-8.2f%-8d",p->total,p->aver,creditcal(*p,p1));
	printf("%-8s%-8s%-8s\n",p->grade,p->college,p->major);
}
void changejgt(struct student *p1,struct student *p2)
{
struct student p;
p=*p1;
*p1=*p2;
*p2=p;
}
void printfiguretitle(struct course *p)
{
	int i;
	printf("ѧ��\t\t����\t�Ա�\t");
	for(i=0;i<=realcourse-1;i++)
	{
		printf("%-8s",p[i].name);
	}	
	printf("�ܷ�\tƽ����\tѧ��\t�꼶\tѧԺ\tרҵ\t"); 
	printf("\n");
}
void numsequence(struct student *p,struct course *p1)
{
	title("��ѧ������");
	int i,j,k;
	struct student *storage;
	storage=p;
	printfiguretitle(p1);
	for(i=0;i<=realnumber-2;i++,p++)
	{
		for(j=i+1;j<=realnumber-1;j++)
		{
			if(strcmp(p->num,(storage+j)->num)>0)//���ڸ�С���������� 
			{
				changejgt(p,storage+j);
			}
		} 
	}
	for(k=0;k<=realnumber-1;k++)
	printjgt(storage+k,p1);
}
void totalsequence(struct student *p,struct course *p1)
{
	title("���ܷ�����");
	int i,j,k;
	struct student *storage;
	storage=p;
	printf("���\t"); 
	printfiguretitle(p1);
	for(i=0;i<=realnumber-2;i++,p++)
	{
		for(j=i+1;j<=realnumber-1;j++)
		{
			if(p->aver<(storage+j)->aver)
			{
				changejgt(p,storage+j);
			}
			else if(p->aver==(storage+j)->aver)
			{
				if(strcmp(p->num,(storage+j)->num)>0)
				changejgt(p,storage+j);
			}
		} 
	}
	printf("%-8d",1);
	printjgt(storage,p1);
	for(i=2,k=1;i<=realnumber;i++)
	{
		k++;
		if((storage+i-1)->aver==(storage+i-2)->aver)//���ڸ�С���������� 
		k--;
		printf("%-8d",k);
		printjgt(storage+i-1,p1);
	}
}
void grasubsequence(struct student *p,struct course *p1)
{
	title("��һ�ֶ�Ϊ�꼶���ڶ��ֶ�Ϊ�γ�����");
	int i,j,k,l,flag=0;char sub[20];
	struct student *storage;
	storage=p;
	printf("������ڶ��ֶογ����ƣ�\n"); 
	scanf("%s",sub);
	getchar();
	for(l=0;l<=realcourse-1;l++)
	{
		if(strcmp(sub,p1[l].name)==0){
			flag++;
			break;
		}
	}
	if(flag==0){
		getchar();
		printf("û�и�ѧ�ƣ����س�������...\n");
		return;
	}
	titleforsequence("�꼶",sub); 
	printfiguretitle(p1);
	for(i=0;i<=realnumber-2;i++,p++)
	{
		for(j=i+1;j<=realnumber-1;j++)
		{
			if(strcmp(p->grade,(storage+j)->grade)>0)
			{
				changejgt(p,storage+j);
			}
			else if(strcmp(p->grade,(storage+j)->grade)==0)
			{
				if(p->score[l]<(storage+j)->score[l])
				changejgt(p,storage+j);
			}
		} 
	}
	for(k=0;k<=realnumber-1;k++)
	printjgt(storage+k,p1);	
}

void majsubsequence(struct student *p,struct course *p1)
{
	title("��һ�ֶ�Ϊרҵ���ڶ��ֶ�Ϊ�γ�����");
	int i,j,k,l,flag=0;char sub[20];
	struct student *storage;
	storage=p;
	printf("������ڶ��ֶογ����ƣ�\n"); 
	scanf("%s",sub);
	getchar();
	for(l=0;l<=realcourse-1;l++)
	{
		if(strcmp(sub,p1[l].name)==0){
			flag++;
			break;
		}
	}
	if(flag==0){
		getchar();
		printf("û�и�ѧ�ƣ����س�������...\n");
		return;
	}
	titleforsequence("רҵ",sub); 
	printfiguretitle(p1);
	for(i=0;i<=realnumber-2;i++,p++)
	{
		for(j=i+1;j<=realnumber-1;j++)
		{
			if(strcmp(p->major,(storage+j)->major)>0)
			{
				changejgt(p,storage+j);
			}
			else if(strcmp(p->major,(storage+j)->major)==0)
			{
				if(p->score[l]<(storage+j)->score[l])
				changejgt(p,storage+j);
			}
		}
	}
	for(k=0;k<=realnumber-1;k++)
	printjgt(storage+k,p1);	
}
void colsubsequence(struct student *p,struct course *p1)
{
	title("��һ�ֶ�ΪѧԺ���ڶ��ֶ�Ϊ�γ�����");
	int i,j,k,l,flag=0;char sub[20];
	struct student *storage;
	storage=p;
	printf("������ڶ��ֶογ����ƣ�\n"); 
	scanf("%s",sub);
	getchar();
	for(l=0;l<=realcourse-1;l++)
	{
		if(strcmp(sub,p1[l].name)==0){
			flag++;
			break;
		}
	}
	if(flag==0){
		getchar();
		printf("û�и�ѧ�ƣ����س�������...\n");
		return;
	}
	titleforsequence("ѧԺ",sub); 
	printfiguretitle(p1);
	for(i=0;i<=realnumber-2;i++,p++)
	{
		for(j=i+1;j<=realnumber-1;j++)
		{
			if(strcmp(p->college,(storage+j)->college)>0)
			{
				changejgt(p,storage+j);
			}
			else if(strcmp(p->college,(storage+j)->college)==0)
			{
				if(p->score[l]<(storage+j)->score[l])
				changejgt(p,storage+j);
			}
		} 
	}
	for(k=0;k<=realnumber-1;k++)
	printjgt(storage+k,p1);	
}
void subjectsequence(struct student *p,struct course *p1)
{
	char subject[20];
	int i,j,k;
	title("��ѧ������");
	printf("������ѧ������:");
	scanf("%s",subject);
	for(j=0;j<=realcourse-1;j++)
	{
		if(strcmp(subject,p1[j].name)==0)
		{
			for(i=0;i<=realnumber-2;i++)
			{
				for(k=i+1;k<=realnumber-1;k++)
				{
					if(p[i].score[j]<p[k].score[j])
					changejgt(p+i,p+k);
					else if(p[i].score[j]==p[k].score[j])
					{
						if(strcmp(p[i].num,p[k].num)>0) 
						changejgt(p+i,p+k);
					}
				}
			}
			system("cls");printf("\t\t\t\t\t\t\t\t��%sѧ������\n\n\n",subject);
			printfiguretitle(p1);
			for(k=0;k<=realnumber-1;k++)
			printjgt(p+k,p1);
			getchar();
			printf("\n\n\n���س�������");
			return;	
		}
	}
	getchar();
	printf("û�и�ѧ�ƣ����س�������...\n");
}
int creditcal(struct student p,struct course*p1)
{
	int j,sum=0;
	for(j=0;j<=realcourse-1;j++)
	{
		if(p.score[j]>=60)
		sum+=p1[j].credit;		
	}
	return sum;
}
void numberlookup(struct student *p,struct course*p1)
{
	title("��ѧ�Ų�ѯ");
	char lookupnum[13]; 
	int i,j;
	printf("��������Ҫ���ҵ�ѧ����12λѧ��:\n");
	scanf("%s",lookupnum);
	title("��ѧ�Ų�ѯ");
	for(i=0;i<=realnumber-1;i++,p++)
	{
		if(strcmp(lookupnum,p->num)==0)
		{
			printfiguretitle(p1);
			printjgt(p,p1);
			getchar();
			printf("\n\n\n���س�������");
			return;
		}
	}
	getchar();
	printf("\n\n\nû�и�����Ϣ���밴�س�������...");
}
void namelookup(struct student *p,struct course *p1)
{
	title("��������ѯ");
	char lookupname[20]; 
	int i,j,successlookupnum=0;
	printf("��������Ҫ���ҵ�ѧ������:\n");
	scanf("%s",lookupname);
	title("��������ѯ");
	printfiguretitle(p1);
	for(i=0;i<=realnumber-1;i++,p++)
	{
		if(strcmp(lookupname,p->name)==0)
		{
			printjgt(p,p1);
			successlookupnum++;
		}
	}
	if(successlookupnum==0){
	printf("û�и�������Ϣ\n");
	getchar();
	printf("\n\n\n�밴�س�������");}
	else {getchar();printf("�밴�س�������...\n"); }
}
void gradelookup(struct student *p,struct course *p1)
{
	title("���꼶��ѯ");
	char lookupgrade[5]; 
	int i,j,successlookupnum=0;
	printf("��������Ҫ���ҵ��꼶:\n");
	scanf("%s",lookupgrade);
	title("���꼶��ѯ");
	printfiguretitle(p1);
	for(i=0;i<=realnumber-1;i++,p++)
	{
		if(strcmp(lookupgrade,p->grade)==0)
		{
			printjgt(p,p1);
			successlookupnum++;
		}
	}
	if(successlookupnum==0){
	printf("\n\n\nû�и��꼶��Ϣ\n");
	getchar();
	printf("\n\n\n�밴�س�������");}
	else {getchar();printf("\n\n\n�밴�س�������...\n"); }
}
void majorlookup(struct student *p,struct course *p1)
{
	title("��רҵ��ѯ");
	char lookupmajor[3]; 
	int i,j,successlookupnum=0;
	printf("��������Ҫ���ҵ�רҵ:\n");
	scanf("%s",lookupmajor);
	title("��רҵ��ѯ");
	printfiguretitle(p1);
	for(i=0;i<=realnumber-1;i++,p++)
	{
		if(strcmp(lookupmajor,p->major)==0)
		{
			printjgt(p,p1);
			successlookupnum++;
		}
	}
	if(successlookupnum==0){
	printf("\n\n\nû�и�רҵ��Ϣ\n");
	getchar();
	printf("\n\n\n�밴�س�������");}
	else {getchar();printf("\n\n\n�밴�س�������...\n"); }
}
void collegelookup(struct student *p,struct course *p1)
{
	title("��ѧԺ��ѯ");
	char lookupcollege[3]; 
	int i,j,successlookupnum=0;
	printf("��������Ҫ���ҵ�ѧԺ:\n");
	scanf("%s",lookupcollege);
	title("��ѧԺ��ѯ");
	printfiguretitle(p1);
	for(i=0;i<=realnumber-1;i++,p++)
	{
		if(strcmp(lookupcollege,p->college)==0)
		{
			printjgt(p,p1);
			successlookupnum++;
		}
	}
	if(successlookupnum==0){
	printf("\n\n\nû�и�ѧԺ��Ϣ\n");
	getchar();
	printf("\n\n\n�밴�س�������");}
	else {getchar();printf("\n\n\n�밴�س�������...\n"); }
}
void clearstuinf(struct student *p)
{
	int j;
	p[0].grade[0]='\0';p[0].major[0]='\0';p[0].college[0]='\0';p[0].aver=0;p[0].total=0;
	for(j=0;j<=realcourse-1;j++)
	{p->score[j]=0;}
}
void inputmember(struct student *p,int *a,int*c)
{
	char choice[20];char choose;int i,j;
	if(*a>0)
	{title("ѧ���ɼ�����ϵͳ1.0\n\n\n");printf("������ѧ����Ϣ���Ƿ�����������룿\n�����������yes����ȷ�ϣ����������������ַ�\n");
	scanf("%s",choice);
	if(strcmp(choice,"Yes")!=0&&strcmp(choice,"yes")!=0)
	return;
	}
	do{
	title("����ѧ����Ϣ");
	printf("\t\t\t\t\t\t\t1.����ȷ��\n\n\t\t\t\t\t\t\t2.������ȷ��\n\n");
	scanf("%c",&choose);
	getchar();
	switch (choose){
	case '1': *c=0;title("����ѧ����Ϣ");printf("������ѧ��������"); 
	scanf("%d",&realnumber);
	for(i=1;i<=realnumber;i++)
	{
		title("����ѧ����Ϣ");
		printf("\n\n�����������%dλѧ����12λѧ�ţ��������Ա𡣣�δ����������%d��\n",i,realnumber-i+1);
		scanf("%s %s %s",p[i-1].num,p[i-1].name,p[i-1].sex);
		clearstuinf(p+i-1);
		extract(p+i-1);
	}
	getchar();
	printf("\n\n\n������ɣ��밴���������");getchar();break;
	case '2':*c=0;title("����ѧ����Ϣ");printf("���뵥��stop���س���ֹͣ\n");realnumber=0;
	for(i=1;i>=1;i++)
	{
		printf("�������%d�����ѧ����ѧ�ţ��������Ա�\n",i);
		scanf("%s",(p+i-1)->num);
		if(strcmp((p+i-1)->num,"stop")!=0){ 
		scanf("%s",(p+i-1)->name);if(strcmp((p+i-1)->name,"stop")!=0){scanf("%s",(p+i-1)->sex);if(strcmp((p+i-1)->sex,"stop")==0){printf("������ɣ��밴�س�������...");getchar();return;}}else {printf("������ɣ��밴�س�������...");getchar();return;}} 
		else {printf("������ɣ��밴�س�������...");getchar();getchar();return;}
		clearstuinf(p+i-1);
		extract(p+i-1);
		realnumber++;
	}
	default:printf("û�и�ѡ��밴�س�����...");getchar();break;} 
	}while(choose!='1'&&choose!='2');
}
void clearcouinf(struct student *p,int j)
{
	int i;
	for(i=0;i<=realnumber-1;i++)
		{p[i].total-=p[i].score[j];p[i].aver=p[i].total/realnumber;p[i].score[j]=0;}
}
void inputcourse(struct student *p1,struct course *p,int *b,int*c)
{
	char choice[20];
	if(*b>0)
	{title("ѧ���ɼ�����ϵͳ1.0\n\n\n");printf("������γ���Ϣ���Ƿ�����������룿\n�����������yes����ȷ�ϣ����������������ַ�\n");
	scanf("%s",choice);
	if(strcmp(choice,"Yes")!=0&&strcmp(choice,"yes")!=0)
	return;
	}
 	*c=0;
	title("����γ���Ϣ");
	printf("�γ���Ϊ:");
	scanf("%d",&realcourse);
	int i;
	for(i=1;i<=realcourse;i++)
	{
		title("����γ���Ϣ");
		printf("�����������%d�ſγ̵Ŀγ̺ţ��γ�����ѧ�֡���������γ�������%d��\n",i,realcourse-i+1); 
		scanf("%d %s %d",&p[i-1].num,p[i-1].name,&p[i-1].credit);
		clearcouinf(p1,i-1);
	}
	printf("\n\n\n������ɣ��밴�س�������");
	getchar(); 
}
void inputcorepart(struct student *p,struct course *p1,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		title("����ѧ���ɼ�");
		printf("����������%s��",p[i-1].name);
		for(j=0;j<=realcourse-2;j++)//
		printf("%s��",p1[j].name);
		printf("%s�ɼ���������%d�������룩\n",p1[realcourse-1].name,n-i+1);
		for(j=1;j<=realcourse;j++)
		{
			scanf("%f",&p[i-1].score[j-1]);
		}
		average(p+i-1);
	}
}
void inputscore(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	char choice[20];
	if(*c>0)
	{title("ѧ���ɼ�����ϵͳ1.0\n\n\n");printf("������������Ƿ�����������룿\n�����������yes����ȷ�ϣ����������������ַ�\n");
	scanf("%s",choice);
	if(strcmp(choice,"Yes")!=0&&strcmp(choice,"yes")!=0)
	return;
	}
	title("����ѧ���ɼ�");
	inputcorepart(p,p1,realnumber);
	getchar();
	printf("\n\n\n������ɣ������������...");
}
void reviseatnum(struct student *p,struct course *p1)
{
	title("��ѧ���޸���Ϣ");
	int i,j;
	char errornum[13];
	printf("������ѧ�ţ�\n");
	scanf("%s",errornum);
	title("�޸�ѧ����Ϣ");
	for(i=1;i<=realnumber;i++)
	{
		if(strcmp(errornum,p->num)==0)
		{
			printf("�����������޸ĺ��ѧ�ţ��������Ա�\n");
			scanf("%s %s %s",p->num,p->name,p->sex);
			extract(p);
			printf("�����������޸ĺ��");
			for(j=0;j<=realcourse-2;j++)
			printf("%s��",p1[j].name);
			printf("%s�ɼ���\n",p1[realcourse-1].name);
			p->aver=0;
	 		for(j=1;j<=realcourse;j++)
		 	{
 				scanf("%f",&p->score[j-1]);
 				p->aver+=p->score[j-1];
 			}
			average(p);
			printf("�޸���ɣ��밴�س�������...");
			return;
		}
		p++; 
	}
	getchar();
	printf("ϵͳ��û�и�ѧ�ŵ�ѧ��\n\n\n�밴�س�������");
} 
void reviseatname(struct student *p,struct course *p1)
{
	title("�������޸���Ϣ");
	int i,j;
	char errorname[20];
	printf("������ѧ��������\n");
	scanf("%s",errorname);
	title("�޸�ѧ����Ϣ");
	for(i=1;i<=realnumber;i++)
	{
		if(strcmp(errorname,p->name)==0)
		{
			printf("�����������޸ĺ��ѧ�ţ��������Ա�\n");
			scanf("%s %s %s",p->num,p->name,p->sex);
			extract(p);
			printf("�����������޸ĺ��");
			for(j=0;j<=realcourse-2;j++)
			printf("%s��",p1[j].name);
			printf("%s�ɼ���\n",p1[realcourse-1].name);
			p->aver=0;
	 		for(j=1;j<=realcourse;j++)
		 	{
 				scanf("%f",&p->score[j-1]);
 				p->aver+=p->score[j-1];
 			}
			average(p);
			printf("�޸���ɣ��밴�س�������...");
			return;
		}
		p++; 
	}
	getchar();
	printf("ϵͳ��û�и�������ѧ��\n\n\n�밴�س�������");
} 
void revise(struct student *p,struct course *p1) 
{
	title("�޸�ѧ����¼");
	char choose;
	do{
	title("�޸�ѧ����¼");
	printf("\t\t\t\t\t\t\t1.��ѧ���޸ļ�¼\n\n\t\t\t\t\t\t\t2.�������޸ļ�¼\n\n\t\t\t\t\t\t\tb.�����ϼ��˵�\n");
	scanf("%c",&choose);
	switch(choose){
		case '1':reviseatnum(p,p1);getchar();break;
		case '2':reviseatname(p,p1);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("ѡ����ڣ����س�������...\n");getchar();break;
	}
	}while(choose!='b'&&choose!='B');
} 
void cutout(struct student *p)
{
	title("ɾ��ѧ����¼");
	char choose;
	do{
	title("ɾ��ѧ����¼");
	printf("\t\t\t\t\t\t\t1.��ѧ��ɾ��һ��ѧ���ļ�¼\n\n\t\t\t\t\t\t\t2.������ɾ��һ��ѧ���ļ�¼\n\n\t\t\t\t\t\t\t3.ɾ��ĳ�꼶�ļ�¼\n\n\t\t\t\t\t\t\t4.ɾ��ĳרҵ�ļ�¼\n\n\t\t\t\t\t\t\t5.ɾ��ĳѧԺ�ļ�¼\n\n\t\t\t\t\t\t\tb.�����ϼ��˵�\n");
	scanf("%c",&choose);
	switch(choose){
		case '1':delete1(p);getchar();break;
		case '2':delete5(p);getchar();break;
		case '3':delete2(p);getchar();break;
		case '4':delete3(p);getchar();break;
		case '5':delete4(p);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("ѡ����ڣ����س�������...\n");getchar();break;
	}
	}while(choose!='b'&&choose!='B');
}
void add(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	title("���ѧ����Ϣ");
	int i,j;
	char choose;
	do{
	title("���ѧ����Ϣ");
	printf("\t\t\t\t\t\t\t1.���ӵ���ѧ����Ϣ\n\n\t\t\t\t\t\t\t2.����һ������ѧ����Ϣ\n\n\t\t\t\t\t\t\t3.���Ӳ�������ѧ����Ϣ\n\n\t\t\t\t\t\t\tb.������һ���˵�\n");
	scanf("%c",&choose);
	getchar();
 	switch(choose){
		case'1':add1(p,p1);getchar();break;
 		case'2':add2(p,p1);getchar();break;
 		case'3':add3(p,p1);getchar();break;
	 	case 'b':
	 	case 'B':break;
 		default:printf("ѡ����ڣ����س�������\n");getchar();break;
 	}
	}while(choose!='b'&&choose!='B');
}
void coursebase(struct student *p1,struct course *p,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p1,a,c);(*a)++;}
		if(*b==0){inputcourse(p1,p,b,c);(*b)++;}
	}
	title("�γ̿�");
	char choose; 
	do{
	title("�γ̿�");
	printf("\t\t\t\t\t\t\t1.��ӿγ�\n\n\t\t\t\t\t\t\t2.ɾ���γ�\n\n\t\t\t\t\t\t\t3.�޸Ŀγ���Ϣ\n\n\t\t\t\t\t\t\t4.������пγ�\n\n\t\t\t\t\t\t\tb.�����ϼ��˵�\n");
	scanf("%c",&choose);
	getchar();
	switch(choose)
	{
		title("�γ̿�");
		case '1':addcourse(p1,p);getchar();break;
		case '2':deletecourse(p1,p);getchar();break;
		case '3':revisecourse(p);getchar();break;
		case '4':viewcourse(p1,p,a,b,c);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("ѡ����ڣ����س�������...\n");getchar();break;
	}
	}while(choose!='b'&&choose!='B');
}
void sequence(struct student *p,struct course *p1,int *a,int *b,int*c)//Ĭ����������,�������������У�Ĭ�ϴ�ӡѧ�ţ����������Ʒ������ܷ֣�Ĭ�ϵڶ��ؼ���Ϊѧ�� 
{	
	if(*a==0||*b==0)
	{
		title("ѧ���ɼ�����ϵͳ1.0\n\n\n");
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
		if(*c==0){inputscore(p,p1,a,b,c);(*c)++;}
	}
	title("����");
	char choose;
	do{
	title("����");
	printf("\t\t\t\t\t\t\t1.���ܷ�����\n\n");
	printf("\t\t\t\t\t\t\t2.��ѧ������\n\n");
	printf("\t\t\t\t\t\t\t3.��һ�ֶ�Ϊ�꼶���ڶ��ֶ�Ϊ�γ�����\n\n");
	printf("\t\t\t\t\t\t\t4.��һ�ֶ�Ϊרҵ���ڶ��ֶ�Ϊ�γ�����\n\n");
	printf("\t\t\t\t\t\t\t5.��һ�ֶ�ΪѧԺ���ڶ��ֶ�Ϊ�γ�����\n\n");
	printf("\t\t\t\t\t\t\t6.��һ�ֶ�Ϊ�γ̣��ڶ��ֶ�Ϊѧ������\n\n");
	printf("\t\t\t\t\t\t\tb.������һ���˵�\n");
 	scanf("%c",&choose);
 	getchar();
 	switch(choose)
	 	{
 		case '1':totalsequence(p,p1);getchar();break;
 		case '2':numsequence(p,p1);getchar();break;
		case '3':grasubsequence(p,p1);getchar();break;
	 	case '4':majsubsequence(p,p1);getchar();break;
	 	case '5':colsubsequence(p,p1);getchar();break;
	 	case '6':subjectsequence(p,p1);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("ѡ����ڣ����س�������...\n");getchar();break;
	 	}
 	}while(choose!='b'&&choose!='B');
}
void statcourse(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		title("ѧ���ɼ�����ϵͳ1.0\n\n\n");
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	int i,j,k; 
	float aver,variance,sum,max,min;
	int n1=0,n2=0,n3=0,n4=0,n5=0;
	double std;
	printf("\n\n\n");
	printf("�γ̺�  �γ���  ѧ��\t90~100\t80~90\t70~80\t60~70\t0~60\tƽ����\t����\t��׼��\t��߷�\t��ͷ�\n");
	for(j=1;j<=realcourse;j++,p1++)
	{
		aver=0.0;sum=0.0;n1=0;n2=0;n3=0;n4=0;n5=0;max=p[0].score[j-1];min=p[0].score[j-1];
		for(i=0;i<=realnumber-1;i++)
		{
			if(p[i].score[j-1]>=90)n1++;
			else if(p[i].score[j-1]>=80)n2++;
			else if(p[i].score[j-1]>=70)n3++;
			else if(p[i].score[j-1]>=60)n4++;
			else n5++;
			if(p[i].score[j-1]>max)max=p[i].score[j-1];
			else if(p[i].score[j-1]<min)min=p[i].score[j-1];
			else{}
			aver=aver+p[i].score[j-1]/realnumber;
		}
		for(k=0;k<=realnumber-1;k++)
		{
			sum+=(p[k].score[j-1]-aver)*(p[k].score[j-1]-aver);
		}
		variance=sum/realnumber;
		std=sqrt(variance);
		printf("%-8d%-8s%-8d  %-6d  %-6d  %-6d  %-6d  %-6d%-8.2f%-8.2f%-8.2lf%-8.2f%-8.2f\n",p1->num,p1->name,p1->credit,n1,n2,n3,n4,n5,aver,variance,std,max,min);
	}
} 
void statistics(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		title("ѧ���ɼ�����ϵͳ1.0\n\n\n");
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	title("ͳ��");
	int i,j,k,credit;
	float aver,variance,sum;
	double std;
	printf("\n\n");
	printf("ѧ��\t\t����\t�ܷ�\tƽ����\t��ѧ��\t\n");
	for(i=1;i<=realnumber;i++,p++)
	{
		credit=0;
		for(j=1;j<=realcourse;j++)
		{
			if(p->score[j-1]>60)
			credit+=(p1+j-1)->credit;
		}
		printf("%-16s%-8s%-8.2f%-8.2f%-8d%\n",p->num,p->name,p->total,p->aver,credit);
	}
	p=p-realnumber;
	statcourse(p,p1,a,b,c);
	printf("\n\n\n���س�������");
}
void lookup(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		title("ѧ���ɼ�����ϵͳ1.0\n\n\n");
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	title("��ѯ��Ϣ");
	char choose;
	do{
	title("��ѯ��Ϣ");	
	printf("\t\t\t\t\t\t\t1.��ѧ�Ų�ѯ\n\n");
	printf("\t\t\t\t\t\t\t2.��������ѯ\n\n");
	printf("\t\t\t\t\t\t\t3.���꼶��ѯ\n\n");
	printf("\t\t\t\t\t\t\t4.��רҵ��ѯ\n\n");
	printf("\t\t\t\t\t\t\t5.��ѧԺ����\n\n");
	printf("\t\t\t\t\t\t\tb.������һ���˵�\n");
 	scanf("%c",&choose);
 	getchar();
 	switch(choose)
	 	{
 		case '1':numberlookup(p,p1);getchar();break;
	 	case '2':namelookup(p,p1);getchar();break;
	 	case '3':gradelookup(p,p1);getchar();break;
	 	case '4':majorlookup(p,p1);getchar();break;
	 	case '5':collegelookup(p,p1);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("ѡ����ڣ����س�������...\n");getchar();break;
	 	}
 	}while(choose!='b'&&choose!='B');
}
void printall(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		title("ѧ���ɼ�����ϵͳ1.0\n\n\n");
		printf("��������ѧ����Ϣ�Ϳγ���Ϣ\n���س�ȷ��\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	int i,j;
	title("��ӡ������Ϣ");
	printf("���\tѧ��\t\t����\t�Ա�\t");
	for(i=1;i<=realcourse;i++)
	printf("%-8s",p1[i-1].name);
	printf("�ܷ�\tƽ����\t���ѧ��  �꼶\t  ѧԺ\t  רҵ\t\n");
	for(i=1;i<=realnumber;i++)
	{
		printf("%-8d%-16s%-8s%-8s%",i,p[i-1].num,p[i-1].name,p[i-1].sex);
		for(j=1;j<=realcourse;j++)
		{
			printf("%-8.2f",p[i-1].score[j-1]);
		}
		printf("%-8.2f%-8.2f%-10d%-8s%-8s%-8s\n",p[i-1].total,p[i-1].aver,creditcal(p[i-1],p1),p[i-1].grade,p[i-1].college,p[i-1].major);
	}
	statcourse(p,p1,a,b,c);
	printf("\n\n\n���س�������");
}
