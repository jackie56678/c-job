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
void main()
{
	SetConsoleOutputCP(65001);//防止中文乱码
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
	title("学生成绩管理系统1.0\n\n\t\t\t\t\t\t\tProgrammed by WangYulong\n\n\t\t\t\t\t\t\tthe member of the Cooprative Team of C Programming Language \n");
 	printf("\n\n\t\t\t\t\t\t\t为方便使用者快速了解系统，这里给出几点关于系统的说明：\n\n"); 
	printf("\t\t\t\t\t\t\t*本系统默认学号1-4位是年级、5-6位是学院、7-8位是专业\n\n"); 
 	printf("\t\t\t\t\t\t\t*前三个输入功能是使用其他功能的基础，应当优先选择\n\n"); 
 	printf("\t\t\t\t\t\t\t*选择菜单中的字母选项时大小写效果相同\n\n"); 
 	printf("\t\t\t\t\t\t\t*系统内所有菜单用back的首字母b或B作为返回\n\n"); 
 	printf("\t\t\t\t\t\t\t*打印功能用print的首字母p或P表示\n\n"); 
 	printf("\t\t\t\t\t\t\t*有时一个菜单选项需要输入两遍方才执行命令\n\n"); 
	printf("\t\t\t\t\t\t\t*当出现数字堆叠时采用全屏显示即可\n\n");
 	printf("\n\n\n"); 
 	printf("按回车键进入系统...\n");
 	getchar();
	do{
 		title("学生成绩管理系统1.0\n\n\n");
 		printf("\t\t\t\t\t\t\t功能大全：\n\n");
		printf("\t\t\t\t\t\t\t1.录入学生信息\n\n");
		printf("\t\t\t\t\t\t\t2.录入课程信息\n\n");
		printf("\t\t\t\t\t\t\t3.录入分数\n\n"); 
		printf("\t\t\t\t\t\t\t4.修改学生记录\n\n");
		printf("\t\t\t\t\t\t\t5.删除学生记录\n\n"); 
	 	printf("\t\t\t\t\t\t\t6.添加学生信息\n\n"); 
 		printf("\t\t\t\t\t\t\t7.课程库\n\n");
  		printf("\t\t\t\t\t\t\t8.排序\n\n");
   		printf("\t\t\t\t\t\t\t9.统计\n\n");
	    	printf("\t\t\t\t\t\t\ta.查询\n\n"); 
		printf("\t\t\t\t\t\t\tp.打印所有信息\n\n");
		printf("\t\t\t\t\t\t\tb.退出\n\n");
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
		default:printf("选项不存在，按回车键继续...\n");getchar();break;
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
	printf("\t\t\t\t\t\t第一字段为%s，第二字段为%s课程排序\n\n\n",s,s2);
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
	title("按学号删除记录");
	char deletenum[13]; 
	int i,j;
	printf("请输入需要删除记录的学生学号:\n");
	scanf("%s",deletenum);
	title("按学号删除记录");
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
			printf("删除成功,按回车键返回\n");
			getchar(); 
			return; 
		}	
	}
	printf("没有该学生信息\n");
	getchar();
	printf("\n\n\n按回车键返回");
}
void delete5(struct student *p) 
{
	title("按姓名删除记录");
	char deletename[13]; 
	int i,j;
	printf("请输入需要删除记录的学生学号:\n");
	scanf("%s",deletename);
	title("按姓名删除记录");
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
			printf("删除成功,按回车键返回\n");
			getchar(); 
			return; 
		}	
	}
	printf("没有该学生信息\n");
	getchar();
	printf("\n\n\n按回车键返回");
}
void delete2(struct student *p) 
{
	title("按年级删除记录");
	char deletegrade[5];
	int i,j,successdeletenum=0;
	printf("请输入需要删除的年级号：\n"); 
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
	printf("没有该年级信息\n");
	getchar();
	printf("\n\n\n按回车键返回");}
	else {getchar();printf("成功删除%d条记录，按回车键返回...\n",successdeletenum); }
}
void delete3(struct student *p) 
{
	title("按专业删除记录");
	char deletemajor[3]; 
	int i,j,successdeletenum=0;
	printf("请输入需要删除的专业号:\n");
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
	printf("没有该专业信息\n");
	getchar();
	printf("\n\n\n按回车键返回");}
	else {getchar();printf("成功删除%d条记录，按回车键返回...\n",successdeletenum); }
}
void delete4(struct student *p)
{
	title("按学院删除记录");
	char deletecollege[3];
	int i,j,successdeletenum=0;
	printf("请输入需要删除的学院号：\n"); 
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
	printf("没有该学院信息\n");
	getchar();
	printf("\n\n\n按回车键返回");}
	else {getchar();printf("成功删除%d条记录，按回车键返回...\n",successdeletenum); }
}
void add1(struct student *p,struct course *p1)
{
	void inputcorepart(struct student *p,struct course *p1,int n);
	title("添加一个学生信息");
	printf("请依次输入学号，姓名，性别\n");
 	scanf("%s %s %s",p[realnumber].num,p[realnumber].name,p[realnumber].sex);
 	extract(p+realnumber);
 	inputcorepart(p+realnumber,p1,1); 
	realnumber++;
	getchar();
	printf("\n\n\n按回车键返回");
}
void add2(struct student *p,struct course *p1)
{
	void inputcorepart(struct student *p,struct course *p1,int n);
	title("添加多个学生信息");
	int number,i;
	printf("需要添加的学生人数为：\n");
	scanf("%d",&number);
	title("添加多个学生信息");
	for(i=1;i<=number;i++)
	{
		printf("请输入第%d个添加学生的学号，姓名，性别\n",i);
 		scanf("%s %s %s",(p+realnumber+i-1)->num,(p+realnumber+i-1)->name,(p+realnumber+i-1)->sex);
 		extract(p+realnumber+i-1);
	}
	inputcorepart(p+realnumber,p1,number);
	realnumber+=number;
	getchar();
	printf("\n\n\n按回车键返回");
}
void add3(struct student *p,struct course *p1)
{
	void inputcorepart(struct student *p,struct course *p1,int n);
	title("添加不定人数学生信息");
	int i;char s[20]; 
	title("添加不定人数学生信息");
	printf("输入单词stop并回车则停止添加新人\n");
	for(i=1;i>=1;i++)
	{
		printf("请输入第%d个添加学生的学号，姓名，性别\n",i);
		scanf("%s",(p+realnumber+i-1)->num);
		if(strcmp((p+realnumber+i-1)->num,"stop")!=0){ 
		scanf("%s",(p+realnumber+i-1)->name);if(strcmp((p+realnumber+i-1)->name,"stop")!=0){scanf("%s",(p+realnumber+i-1)->sex);if(strcmp((p+realnumber+i-1)->sex,"stop")==0)break;}else break;} 
		else break;
	}
	inputcorepart(p+realnumber,p1,i-1);
	realnumber+=(i-1);
	getchar();
	printf("\n\n\n按回车键返回");
}
void addcourse(struct student *p1,struct course *p)
{
	title("添加课程");
	int i;
	realcourse++;
	printf("请依次输入课程号、课程名、学分\n");
	scanf("%d %s %d",&p[realcourse-1].num,p[realcourse-1].name,&p[realcourse-1].credit); 
	for(i=0;i<=realnumber-1;i++)
	{
		printf("请输入%s的%s的课程分数：\n",p1[i].name,p[realcourse].name);
		scanf("%f",&p1[i].score[realcourse-1]);
		average(p1+i);
	}
	printf("\n\n\n按回车键返回");
}
void deletecourse(struct student *p1,struct course *p)
{
	title("删除课程");
	int i,j,recording;
	char name[20];
	printf("请输入要删除课程的课程名\n");
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
	printf("\n\n\n按回车键返回");
}
void revisecourse(struct course *p)
{
	title("修改课程信息");
	char name[20];
	int j,credit,flag=0,storage;
	printf("输入需要修改的课程的课程名：\n");
	scanf("%s",name);
	for(j=0;j<=realcourse-1;j++)
	{
		if(strcmp(name,p[j].name)==0)
		break;
		else flag++;
	}
	if(flag==realcourse)
	{printf("未找到此课程\n");return;}
	else printf("请依次输入修改后的课程号、课程新名、课程学分：\n");
	scanf("%d %s %d",&p[j].num,p[j].name,&p[j].credit);
	getchar();
	printf("\n\n\n修改成功，按回车键返回");
}
void viewcourse(struct student *p1,struct course *p,int *a,int *b,int*c)
{
	void statcourse(struct student *p,struct course *p1,int*a,int*b,int*c); 
	title("查看所有课程信息");
	int i;
	statcourse(p1,p,a,b,c);
	printf("\n\n\n按回车键返回");
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
	printf("学号\t\t姓名\t性别\t");
	for(i=0;i<=realcourse-1;i++)
	{
		printf("%-8s",p[i].name);
	}	
	printf("总分\t平均分\t学分\t年级\t学院\t专业\t"); 
	printf("\n");
}
void numsequence(struct student *p,struct course *p1)
{
	title("按学号排序");
	int i,j,k;
	struct student *storage;
	storage=p;
	printfiguretitle(p1);
	for(i=0;i<=realnumber-2;i++,p++)
	{
		for(j=i+1;j<=realnumber-1;j++)
		{
			if(strcmp(p->num,(storage+j)->num)>0)//大于改小于则反序排列 
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
	title("按总分排名");
	int i,j,k;
	struct student *storage;
	storage=p;
	printf("序号\t"); 
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
		if((storage+i-1)->aver==(storage+i-2)->aver)//大于改小于则反序排列 
		k--;
		printf("%-8d",k);
		printjgt(storage+i-1,p1);
	}
}
void grasubsequence(struct student *p,struct course *p1)
{
	title("第一字段为年级，第二字段为课程排序");
	int i,j,k,l,flag=0;char sub[20];
	struct student *storage;
	storage=p;
	printf("请输入第二字段课程名称：\n"); 
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
		printf("没有该学科，按回车键返回...\n");
		return;
	}
	titleforsequence("年级",sub); 
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
	title("第一字段为专业，第二字段为课程排序");
	int i,j,k,l,flag=0;char sub[20];
	struct student *storage;
	storage=p;
	printf("请输入第二字段课程名称：\n"); 
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
		printf("没有该学科，按回车键返回...\n");
		return;
	}
	titleforsequence("专业",sub); 
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
	title("第一字段为学院，第二字段为课程排序");
	int i,j,k,l,flag=0;char sub[20];
	struct student *storage;
	storage=p;
	printf("请输入第二字段课程名称：\n"); 
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
		printf("没有该学科，按回车键返回...\n");
		return;
	}
	titleforsequence("学院",sub); 
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
	title("按学科排序");
	printf("请输入学科名称:");
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
			system("cls");printf("\t\t\t\t\t\t\t\t按%s学科排序\n\n\n",subject);
			printfiguretitle(p1);
			for(k=0;k<=realnumber-1;k++)
			printjgt(p+k,p1);
			getchar();
			printf("\n\n\n按回车键返回");
			return;	
		}
	}
	getchar();
	printf("没有该学科，按回车键返回...\n");
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
	title("按学号查询");
	char lookupnum[13]; 
	int i,j;
	printf("请输入需要查找的学生的12位学号:\n");
	scanf("%s",lookupnum);
	title("按学号查询");
	for(i=0;i<=realnumber-1;i++,p++)
	{
		if(strcmp(lookupnum,p->num)==0)
		{
			printfiguretitle(p1);
			printjgt(p,p1);
			getchar();
			printf("\n\n\n按回车键返回");
			return;
		}
	}
	getchar();
	printf("\n\n\n没有该生信息，请按回车键返回...");
}
void namelookup(struct student *p,struct course *p1)
{
	title("按姓名查询");
	char lookupname[20]; 
	int i,j,successlookupnum=0;
	printf("请输入需要查找的学生姓名:\n");
	scanf("%s",lookupname);
	title("按姓名查询");
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
	printf("没有该姓名信息\n");
	getchar();
	printf("\n\n\n请按回车键返回");}
	else {getchar();printf("请按回车键返回...\n"); }
}
void gradelookup(struct student *p,struct course *p1)
{
	title("按年级查询");
	char lookupgrade[5]; 
	int i,j,successlookupnum=0;
	printf("请输入需要查找的年级:\n");
	scanf("%s",lookupgrade);
	title("按年级查询");
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
	printf("\n\n\n没有该年级信息\n");
	getchar();
	printf("\n\n\n请按回车键返回");}
	else {getchar();printf("\n\n\n请按回车键返回...\n"); }
}
void majorlookup(struct student *p,struct course *p1)
{
	title("按专业查询");
	char lookupmajor[3]; 
	int i,j,successlookupnum=0;
	printf("请输入需要查找的专业:\n");
	scanf("%s",lookupmajor);
	title("按专业查询");
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
	printf("\n\n\n没有该专业信息\n");
	getchar();
	printf("\n\n\n请按回车键返回");}
	else {getchar();printf("\n\n\n请按回车键返回...\n"); }
}
void collegelookup(struct student *p,struct course *p1)
{
	title("按学院查询");
	char lookupcollege[3]; 
	int i,j,successlookupnum=0;
	printf("请输入需要查找的学院:\n");
	scanf("%s",lookupcollege);
	title("按学院查询");
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
	printf("\n\n\n没有该学院信息\n");
	getchar();
	printf("\n\n\n请按回车键返回");}
	else {getchar();printf("\n\n\n请按回车键返回...\n"); }
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
	{title("学生成绩管理系统1.0\n\n\n");printf("已输入学生信息，是否决定重新输入？\n如果是请输入yes进行确认，不是则输入其他字符\n");
	scanf("%s",choice);
	if(strcmp(choice,"Yes")!=0&&strcmp(choice,"yes")!=0)
	return;
	}
	do{
	title("输入学生信息");
	printf("\t\t\t\t\t\t\t1.人数确定\n\n\t\t\t\t\t\t\t2.人数不确定\n\n");
	scanf("%c",&choose);
	getchar();
	switch (choose){
	case '1': *c=0;title("输入学生信息");printf("请输入学生人数："); 
	scanf("%d",&realnumber);
	for(i=1;i<=realnumber;i++)
	{
		title("输入学生信息");
		printf("\n\n请依次输入第%d位学生的12位学号，姓名，性别。（未输入人数：%d）\n",i,realnumber-i+1);
		scanf("%s %s %s",p[i-1].num,p[i-1].name,p[i-1].sex);
		clearstuinf(p+i-1);
		extract(p+i-1);
	}
	getchar();
	printf("\n\n\n输入完成，请按任意键返回");getchar();break;
	case '2':*c=0;title("输入学生信息");printf("输入单词stop并回车则停止\n");realnumber=0;
	for(i=1;i>=1;i++)
	{
		printf("请输入第%d个添加学生的学号，姓名，性别\n",i);
		scanf("%s",(p+i-1)->num);
		if(strcmp((p+i-1)->num,"stop")!=0){ 
		scanf("%s",(p+i-1)->name);if(strcmp((p+i-1)->name,"stop")!=0){scanf("%s",(p+i-1)->sex);if(strcmp((p+i-1)->sex,"stop")==0){printf("输入完成，请按回车键继续...");getchar();return;}}else {printf("输入完成，请按回车键继续...");getchar();return;}} 
		else {printf("输入完成，请按回车键继续...");getchar();getchar();return;}
		clearstuinf(p+i-1);
		extract(p+i-1);
		realnumber++;
	}
	default:printf("没有该选项，请按回车继续...");getchar();break;} 
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
	{title("学生成绩管理系统1.0\n\n\n");printf("已输入课程信息，是否决定重新输入？\n如果是请输入yes进行确认，不是则输入其他字符\n");
	scanf("%s",choice);
	if(strcmp(choice,"Yes")!=0&&strcmp(choice,"yes")!=0)
	return;
	}
 	*c=0;
	title("输入课程信息");
	printf("课程数为:");
	scanf("%d",&realcourse);
	int i;
	for(i=1;i<=realcourse;i++)
	{
		title("输入课程信息");
		printf("请依次输入第%d门课程的课程号，课程名和学分。（待输入课程数量：%d）\n",i,realcourse-i+1); 
		scanf("%d %s %d",&p[i-1].num,p[i-1].name,&p[i-1].credit);
		clearcouinf(p1,i-1);
	}
	printf("\n\n\n输入完成，请按回车键返回");
	getchar(); 
}
void inputcorepart(struct student *p,struct course *p1,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		title("输入学生成绩");
		printf("请依次输入%s的",p[i-1].name);
		for(j=0;j<=realcourse-2;j++)//
		printf("%s、",p1[j].name);
		printf("%s成绩：（还有%d条待输入）\n",p1[realcourse-1].name,n-i+1);
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
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	char choice[20];
	if(*c>0)
	{title("学生成绩管理系统1.0\n\n\n");printf("已输入分数，是否决定重新输入？\n如果是请输入yes进行确认，不是则输入其他字符\n");
	scanf("%s",choice);
	if(strcmp(choice,"Yes")!=0&&strcmp(choice,"yes")!=0)
	return;
	}
	title("输入学生成绩");
	inputcorepart(p,p1,realnumber);
	getchar();
	printf("\n\n\n输入完成，按任意键返回...");
}
void reviseatnum(struct student *p,struct course *p1)
{
	title("按学号修改信息");
	int i,j;
	char errornum[13];
	printf("请输入学号：\n");
	scanf("%s",errornum);
	title("修改学生信息");
	for(i=1;i<=realnumber;i++)
	{
		if(strcmp(errornum,p->num)==0)
		{
			printf("请依次输入修改后的学号，姓名，性别\n");
			scanf("%s %s %s",p->num,p->name,p->sex);
			extract(p);
			printf("请依次输入修改后的");
			for(j=0;j<=realcourse-2;j++)
			printf("%s、",p1[j].name);
			printf("%s成绩：\n",p1[realcourse-1].name);
			p->aver=0;
	 		for(j=1;j<=realcourse;j++)
		 	{
 				scanf("%f",&p->score[j-1]);
 				p->aver+=p->score[j-1];
 			}
			average(p);
			printf("修改完成，请按回车键继续...");
			return;
		}
		p++; 
	}
	getchar();
	printf("系统中没有该学号的学生\n\n\n请按回车键返回");
} 
void reviseatname(struct student *p,struct course *p1)
{
	title("按姓名修改信息");
	int i,j;
	char errorname[20];
	printf("请输入学生姓名：\n");
	scanf("%s",errorname);
	title("修改学生信息");
	for(i=1;i<=realnumber;i++)
	{
		if(strcmp(errorname,p->name)==0)
		{
			printf("请依次输入修改后的学号，姓名，性别\n");
			scanf("%s %s %s",p->num,p->name,p->sex);
			extract(p);
			printf("请依次输入修改后的");
			for(j=0;j<=realcourse-2;j++)
			printf("%s、",p1[j].name);
			printf("%s成绩：\n",p1[realcourse-1].name);
			p->aver=0;
	 		for(j=1;j<=realcourse;j++)
		 	{
 				scanf("%f",&p->score[j-1]);
 				p->aver+=p->score[j-1];
 			}
			average(p);
			printf("修改完成，请按回车键继续...");
			return;
		}
		p++; 
	}
	getchar();
	printf("系统中没有该姓名的学生\n\n\n请按回车键返回");
} 
void revise(struct student *p,struct course *p1) 
{
	title("修改学生记录");
	char choose;
	do{
	title("修改学生记录");
	printf("\t\t\t\t\t\t\t1.按学号修改记录\n\n\t\t\t\t\t\t\t2.按姓名修改记录\n\n\t\t\t\t\t\t\tb.返回上级菜单\n");
	scanf("%c",&choose);
	switch(choose){
		case '1':reviseatnum(p,p1);getchar();break;
		case '2':reviseatname(p,p1);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("选项不存在，按回车键继续...\n");getchar();break;
	}
	}while(choose!='b'&&choose!='B');
} 
void cutout(struct student *p)
{
	title("删除学生记录");
	char choose;
	do{
	title("删除学生记录");
	printf("\t\t\t\t\t\t\t1.按学号删除一个学生的记录\n\n\t\t\t\t\t\t\t2.按姓名删除一个学生的记录\n\n\t\t\t\t\t\t\t3.删除某年级的记录\n\n\t\t\t\t\t\t\t4.删除某专业的记录\n\n\t\t\t\t\t\t\t5.删除某学院的记录\n\n\t\t\t\t\t\t\tb.返回上级菜单\n");
	scanf("%c",&choose);
	switch(choose){
		case '1':delete1(p);getchar();break;
		case '2':delete5(p);getchar();break;
		case '3':delete2(p);getchar();break;
		case '4':delete3(p);getchar();break;
		case '5':delete4(p);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("选项不存在，按回车键继续...\n");getchar();break;
	}
	}while(choose!='b'&&choose!='B');
}
void add(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	title("添加学生信息");
	int i,j;
	char choose;
	do{
	title("添加学生信息");
	printf("\t\t\t\t\t\t\t1.增加单个学生信息\n\n\t\t\t\t\t\t\t2.增加一定人数学生信息\n\n\t\t\t\t\t\t\t3.增加不定人数学生信息\n\n\t\t\t\t\t\t\tb.返回上一级菜单\n");
	scanf("%c",&choose);
	getchar();
 	switch(choose){
		case'1':add1(p,p1);getchar();break;
 		case'2':add2(p,p1);getchar();break;
 		case'3':add3(p,p1);getchar();break;
	 	case 'b':
	 	case 'B':break;
 		default:printf("选项不存在，按回车键继续\n");getchar();break;
 	}
	}while(choose!='b'&&choose!='B');
}
void coursebase(struct student *p1,struct course *p,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p1,a,c);(*a)++;}
		if(*b==0){inputcourse(p1,p,b,c);(*b)++;}
	}
	title("课程库");
	char choose; 
	do{
	title("课程库");
	printf("\t\t\t\t\t\t\t1.添加课程\n\n\t\t\t\t\t\t\t2.删除课程\n\n\t\t\t\t\t\t\t3.修改课程信息\n\n\t\t\t\t\t\t\t4.浏览所有课程\n\n\t\t\t\t\t\t\tb.返回上级菜单\n");
	scanf("%c",&choose);
	getchar();
	switch(choose)
	{
		title("课程库");
		case '1':addcourse(p1,p);getchar();break;
		case '2':deletecourse(p1,p);getchar();break;
		case '3':revisecourse(p);getchar();break;
		case '4':viewcourse(p1,p,a,b,c);getchar();break;
	 	case 'b':
	 	case 'B':break;
		default:printf("选项不存在，按回车键继续...\n");getchar();break;
	}
	}while(choose!='b'&&choose!='B');
}
void sequence(struct student *p,struct course *p1,int *a,int *b,int*c)//默认升序排列,分数按降序排列，默认打印学号，姓名，各科分数，总分，默认第二关键词为学号 
{	
	if(*a==0||*b==0)
	{
		title("学生成绩管理系统1.0\n\n\n");
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
		if(*c==0){inputscore(p,p1,a,b,c);(*c)++;}
	}
	title("排序");
	char choose;
	do{
	title("排序");
	printf("\t\t\t\t\t\t\t1.按总分排序\n\n");
	printf("\t\t\t\t\t\t\t2.按学号排序\n\n");
	printf("\t\t\t\t\t\t\t3.第一字段为年级，第二字段为课程排序\n\n");
	printf("\t\t\t\t\t\t\t4.第一字段为专业，第二字段为课程排序\n\n");
	printf("\t\t\t\t\t\t\t5.第一字段为学院，第二字段为课程排序\n\n");
	printf("\t\t\t\t\t\t\t6.第一字段为课程，第二字段为学号排序\n\n");
	printf("\t\t\t\t\t\t\tb.返回上一级菜单\n");
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
		default:printf("选项不存在，按回车键继续...\n");getchar();break;
	 	}
 	}while(choose!='b'&&choose!='B');
}
void statcourse(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		title("学生成绩管理系统1.0\n\n\n");
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	int i,j,k; 
	float aver,variance,sum,max,min;
	int n1=0,n2=0,n3=0,n4=0,n5=0;
	double std;
	printf("\n\n\n");
	printf("课程号  课程名  学分\t90~100\t80~90\t70~80\t60~70\t0~60\t平均分\t方差\t标准差\t最高分\t最低分\n");
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
		title("学生成绩管理系统1.0\n\n\n");
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	title("统计");
	int i,j,k,credit;
	float aver,variance,sum;
	double std;
	printf("\n\n");
	printf("学号\t\t姓名\t总分\t平均分\t总学分\t\n");
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
	printf("\n\n\n按回车键返回");
}
void lookup(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		title("学生成绩管理系统1.0\n\n\n");
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	title("查询信息");
	char choose;
	do{
	title("查询信息");	
	printf("\t\t\t\t\t\t\t1.按学号查询\n\n");
	printf("\t\t\t\t\t\t\t2.按姓名查询\n\n");
	printf("\t\t\t\t\t\t\t3.按年级查询\n\n");
	printf("\t\t\t\t\t\t\t4.按专业查询\n\n");
	printf("\t\t\t\t\t\t\t5.按学院排序\n\n");
	printf("\t\t\t\t\t\t\tb.返回上一级菜单\n");
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
		default:printf("选项不存在，按回车键继续...\n");getchar();break;
	 	}
 	}while(choose!='b'&&choose!='B');
}
void printall(struct student *p,struct course *p1,int *a,int *b,int*c)
{
	if(*a==0||*b==0)
	{
		title("学生成绩管理系统1.0\n\n\n");
		printf("请先输入学生信息和课程信息\n按回车确认\n");
		getchar();
		if(*a==0){inputmember(p,a,c);(*a)++;}
		if(*b==0){inputcourse(p,p1,b,c);(*b)++;}
	}
	int i,j;
	title("打印所有信息");
	printf("序号\t学号\t\t姓名\t性别\t");
	for(i=1;i<=realcourse;i++)
	printf("%-8s",p1[i-1].name);
	printf("总分\t平均分\t获得学分  年级\t  学院\t  专业\t\n");
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
	printf("\n\n\n按回车键返回");
}
