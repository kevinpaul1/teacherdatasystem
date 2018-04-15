#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<dos.h>
using namespace std;
class kuet
{	protected:	char name[30],adress[30],dept[30];
			float emp_id;
	public:		void input()
			{	cout<<"\n\n\tEnter name:";gets(name);
				cout<<"\n\n\tEnter address:";gets(adress);
				cout<<"\n\n\tEnter department:";gets(dept);
				cout<<"\n\n\tEnter EMP ID:";cin>>emp_id;
			}
			void display()
			{	cout<<"\n\tName: "<<name<<"\n\tEmployee Id= "<<emp_id<<"\n\tAddress: "<<adress<<"\n\tDepartment: "<<dept;
			}
};
class un_graduate:virtual public kuet
{	float cgpa;
	char colname[30],degree[30];
	public:	int a;
		void inputu()
		{	input();
			cout<<"\n\n\tTeacher's Degree ";gets(degree);
			cout<<"\n\n\tName of the university studied in ";gets(colname);
			cout<<"\n\n\tCGPA of UG degree ";cin>>cgpa;
		}
		void inputu(float)
		{	cout<<"\n\n\tYou have four options.\n\t\t1)Degree\n\t\t2)Name of the College\n\t\t3)CGPA\n\t\t4)All\n\n\t\tWhat's your choice>\t";
			int ui;
			cin>>ui;
			if(ui==1||ui==4)
			{	cout<<"\n\n\tTeacher's changed Degree ";gets(degree);
			}
			if(ui==2||ui==4)
			{	cout<<"\n\n\tChanged name of the university ";gets(colname);
			}
			if(ui==3||ui==4)
			{	cout<<"\n\n\tChanged CGPA of UG degree ";cin>>cgpa;
			}
		}
		void displayu()
		{	display();
			cout<<"\n\tThe degree which the teacher has specialised in is ";puts(degree);
			cout<<"\n\tThe name of the university is ";puts(colname);
			cout<<"\n\tThe CGPA is "<<cgpa;
		}
};
class masters:virtual public kuet
{	float year;
	char result[30],subject[30];
	public:	int a;
		void inputm()
		{	cout<<"\n\n\tMaster's teacher subject: ";gets(subject);
			cout<<"\n\n\tMaster's teacher result: ";gets(result);
		}
		void inputm(float)
		{	cout<<"\nYou have two options.\n\t1)Subject\t2)Result\t3)Both\nWhat's your choice?\t";
			int mi;
			cin>>mi;
			if(mi==1||mi==3)
			{
				cout<<"\n\n\tMaster's changed subject: ";gets(subject);
			}
			if(mi==2||mi==3)
			{
				cout<<"\n\n\tMaster's changed result: ";gets(result);
			}
		}
		void displaym()
		{	cout<<"\n\n\tTeachers(Masters) Subject: "<<subject;
			cout<<"\n\n\tTeacchers(Masters) Result: "<<result;
		}
		void searchm(float m)
		{	if(m==emp_id)
				a=1;
			else
				a=0;
		}
};
class phd:virtual public kuet
{	char topic[30];
	public:	int a;
		void inputp()
		{	cout<<"\n\n\tWhich topic? ";gets(topic);
		}
		void inputp(float)
		{	cout<<"\n\n\tWhat is the changed topic? ";gets(topic);
		}
		void displayp()
		{	cout<<"\n\tTopic: "<<topic;
		}
		void searchp(float p)
		{	if(p==emp_id)
				a=1;
			else
				a=0;
		}
};
class teacher:virtual protected kuet,virtual public un_graduate
{	private:	float sal,exp;
			int wno;
			int cno;
			float cmarks[10],cavg;
	public:		int a;
			void inputt();
			void calcavg();
			void inputt(float);
			void displayt()
			{	displayu();
				cout<<"\n\tMonthly Salary= "<<sal;
				cout<<"\n\tThe experience of the teacher is= "<<exp;
				cout<<"\n\tThe average marks scored by the teacher's students is "<<cavg;
				cout<<"\n\tThe number of workshops attended by the teacher is "<<wno;
			}
			void searcht(float t)
			{	if(t==emp_id)
					a=1;
				else
					a=0;
			}
			void updatesal();
};
void teacher::inputt()
{	inputu();
	cout<<"\n\n\tGive monthly salary= ";cin>>sal;
	cout<<"\n\n\tExperience of the teacher= ";cin>>exp;
	cout<<"\n\n\tEnter the number of classes being taught ";cin>>cno;
	cout<<"\n\n\tEnter the average marks of each class ";
	int d=0;
	for(d=0;d<cno;d++)
	{	cin>>cmarks[d];
	}
	cout<<"\n\n\tEnter the number of workshops attended ";
	cin>>wno;
	calcavg();
}
void teacher::calcavg()
{ 	float total=0;
	for(int d=0;d<cno;d++)
	{	total+=cmarks[d];
	}
	cavg=total/cno;
}
void teacher::inputt(float)
{	cout<<"\n\n\tGive changed monthly salary= ";cin>>sal;
	cout<<"\n\n\tEnter changed experience= ";cin>>exp;
	cout<<"\n\n\tEnter the changed number of classes teaught= ";cin>>cno;
	cout<<"\n\n\tEnter the changed average marks of each class ";
	for(int d=0;d<cno;d++)
	{       cin>>cmarks[d];
	}
	calcavg();
	cout<<"\n\n\tEnter the changed number of workshops attended ";cin>>wno;
}
void teacher::updatesal()
{	while(wno>5)
	{
		if(cavg>85)
		{
			sal=sal+0.35*sal;
		}
		else if(cavg>60)
		{
			sal=sal+sal*0.20;
		}
		else
		{
			sal=sal+sal*0.15;
		}
	}
	while(wno<5)
	{
		if(cavg>85)
		{
			sal=sal+0.30*sal;
		}
		else if(cavg>60)
		{
			sal=sal+0.15*sal;
		}                            
		else
		{
		sal=sal+0.10*sal;
		}
	}
	cout<<"\n\n\tThe new Salary after increments is "<<sal;
}
class teastd:virtual public teacher,virtual public masters,virtual public phd
{	public:		int a;
			void inputts()
			{	inputt();
			}
			void inputts(float sid)
			{       inputu(sid);
				inputt(sid);
			}
			void displayts()
			{	displayt();
			}
			void searchts(float ts)
			{	if(ts==emp_id)
					a=1;
				else
					a=0;
			}
			void searchts(float ts,teastd &tp)
			{	if(ts==tp.emp_id)
					a=1;
				else
					a=0;
			}
};
int main()
{	clrscr();
	masters m[20];
	phd p[20];
	teacher t[20];
	teastd ts[20];
	un_graduate u[20];
	char ch[20],c[20],ca[20];
	int index,i,j,k,x,ids,idt;
	int tc=1,tsc=1;
	float id;
	while(1)
	{	textcolor(114);
		textbackground(4);
		clrscr();
		cout<<"\n\n\t1:OPENING ID FOR TEACHERS\n2:DISPLAY\n3:EDITING INFORMATION\n4:SEARCHING\n5:DELETING\n6:INCREMENT SALARY(ONLY DONE ANNUALLY)\n7:EXIT\n\n";
		for(int e=0;e<3;e++)
		{	delay(500);
			cout<<".";
		}
		cout<<"\n\n\tWhat is your option?";
		cin>>index;
		switch(index)
		{	case 1:		clrscr();
					cout<<"\n\n\tHOW MANY IDS for TEACHERS\n\n\t\t";
					cin>>idt;
					for(j=0;j<idt;j++)
					{	cout<<"\n\n\tIF THE TEACHER IS A STUDENT OF MASTERS OR PHD,\n,\tTHEN PRESS 's' FOR MASTERS AND 'h' FOR PHD \n\tAND IF ONLY TEACHER THEN,PRESS 't'\n\n\t\t\t\t";
						cin>>ch[j];
						if(ch[j]=='t')
						{	clrscr();
							t[j].inputt();
							tc++;
						}
						if(ch[j]=='s')
						{	clrscr();
							ts[j].inputts();
							ts[j].inputm();
							tsc++;
						}
						if(ch[j]=='h')
						{	clrscr();
							ts[j].inputts();
							ts[j].inputp();
							tsc++;
						}
					}
					break;
			case 2:		cout<<"\n\tYOU MAY SEE INFORMATION OF TEACHERS NOW \n\t";
					for(j=0;j<idt;j++)
					{	if(ch[j]=='t')
							t[j].displayt();
						if(ch[j]=='s')
						{	ts[j].displayts();
							ts[j].displaym();
						}
						if(ch[j]=='h')
						{	ts[j].displayts();
							ts[j].displayp();
						}
					}
					getch();
					break;
			 case 3:	cout<<"\n\tEnter Employee id: ";
					cin>>id;
					for(j=0;j<idt;j++)
					{	t[j].searcht(id);
						if(t[j].a==1)
						{	t[j].inputt(id);
							goto y;
						}
						ts[j].searchts(id);
						if(ts[j].a==1)
						{       ts[j].inputts(id);
							ts[j].inputm(id);
							goto y;
						}
						ts[j].searchts(id,ts[j]);
						if(ts[j].a==1)
						{	ts[j].inputts(id);
							ts[j].inputp(id);
							goto y;
						}
					}
					y:break;
			 case 4:        clrscr();
					cout<<"\n\n\tGive Employee ID: ";
					cin>>id;
					for(j=0;j<idt;j++)
					{
						t[j].searcht(id);
						{
							if(t[j].a==1)
							{
								cout<<"\n\tSEARCHING";
								for(int e=0;e<8;e++)
								{
									delay(500);
									cout<<".";
								}
								t[j].displayt();
								getch();
								goto z;
							}
						}
						ts[j].searchts(id);
						{
							if(ts[j].a==1)
							{
								cout<<"\n\tSEARCCHING";
								for(int e=0;e<8;e++)
								{
									delay(500);
									cout<<".";
								}
								ts[j].displayts();
								ts[j].displaym();
								getch();
								goto z;
							}
						}
						ts[j].searchts(id,ts[j]);
						{
							if(ts[j].a==1)
							{
								cout<<"\n\tSEARCHING";
								for(int e=0;e<8;e++)
								{
									delay(500);
									cout<<".";
								}
								ts[j].displayts();
								ts[j].displayp();
								getch();
								goto z;
							}
						}
					}
					cout<<"\n\n Not found ";
					z:break;
			 case 5:        clrscr();
					cout<<"\n\n\tEnter Employee ID to delete: ";
					cin>>id;
					for(j=0;j<idt;j++)
					{	t[j].searcht(id);
						{	if(t[j].a==1)
							{	cout<<"\n\tSEARCHING";
								for(int e=0;e<8;e++)
								{	delay(500);
									cout<<".";
								}
								cout<<"\n\n\tThis teacher's information has been removed from the system ";
								t[j].displayt();
								for(int b=j;b<tc;b++)
								{	t[b]=t[b+1];
								}
								tc--;
								getch();
								goto c;
							}
						}
						ts[j].searchts(id);
						{	if(ts[j].a==1)
							{	cout<<"\n\tSEARCHING";
								for(int e=0;e<8;e++)
								{	delay(500);
									cout<<".";
								}
								cout<<"\n\n\tThis teacher's information has been removed from the system";
								ts[j].displayts();
								ts[j].displaym();
								for(int b=j;b<tsc;b++)
								{	ts[b]=ts[b+1];
								}
								tsc--;
								getch();
								goto c;
							}
						}
						ts[j].searchts(id,ts[j]);
						{	if(ts[j].a==1)
							{	cout<<"\n\tSEARCHING ";
								for(int e=0;e<8;e++)
								{	delay(500);
									cout<<".";
								}
								cout<<"\n\n\tThis teacher's information is now removed from the system";
								ts[j].displayts();
								ts[j].displayp();
								for(int b=j;b<tsc;b++)
								{	ts[b]=ts[b+1];
								}
								tsc--;
								getch();
								goto c;
							}
						}
					}
					cout<<"\n\n\tGiven teacher ID not found.Unable to delete.\nEnter valid ID";
					c:break;
			 case 6:	char str[]="daftpunk";char str1[20];
					cout<<"\n\n\tEnter the password: ";gets(str1);
					if(strcmp(str,str1)==0)
					{	for(j=0;j<idt;j++)
						{	if(ch[j]=='t')
							{	t[j].updatesal();
							}
							if(ch[j]=='s')
							{	ts[j].updatesal();
							}
							if(ch[j]=='h')
							{
								ts[j].updatesal();
							}
						}
					}
					else
					{	cout<<"\n\tTry Again! ";
						break;
					}
					break;
			 case 7:	break;
			 default:	cout<<"\n\n\n\tWRONG INPUT,PLEASE TRY AGAIN \n";
					getch();
					break;
		}
		if(index==7)
		break;
	}
	return 0;
}


