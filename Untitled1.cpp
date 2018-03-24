#include <iostream>
#include<conio.h>
#include<fstream>
#include<graphics.h>
#include<stdio.h>
#include<ctype.h>
#include<string>
#include<stddef.h>
#define first_rollno 2013000001
using namespace std;
int gd=DETECT,gm,r;
struct date
{
	int dd, mm, yyyy;
};
/*****************************************************/
/*                   CLASS STUDENT                   */
/*****************************************************/
class student
{
	public:
	void accept();
	void display_details(int);
	int match_rollno(unsigned long);
	~student() {;}
	int marks, hasappeared;
	char name[50], fathersname[50], email[30], gender;
	char address[50], city[30], phoneno[11];
	date dob;
	unsigned long rollno;
	float percent;
	private:
	void assign_rollno(int);
	void putfile();
	protected:
	void assign_marks(int, float);
}s1,s2,s3;
/******************************************************/
/*         CLASS EXAM (DERIVED FROM STUDENT)          */
/******************************************************/
class exam:public student
{
	public:
	void screen_one(int);
	void instructions(int);
	void display_question();
	private:
	int q_no, marks;
	float percent;
	char question[350], choices[100], choice, label[26], correct;
	void iscorrect(char, int);
	void sections(int, char[]);
	void sectionA();
	void sectionB();
	void sectionC();
	void sectionD();
	void sectionE();
	void calculate_marks();
};
struct ranks
{
	student info;
	ranks *next;
}*start=NULL, *ptr, *newptr, *save, *saveprev;
/**********************************************/
/*         FUNCTIONS TO PERFORM CHECKS        */
/**********************************************/
int check_name(char chk_str[])
{
	int flag, i;
	for(i=0; i<strlen(chk_str); ++i)
	{
		if(islower(chk_str[i]) || !isalpha(chk_str[i]))
		{
			if(chk_str[i]==' ')
			flag=1;
			else
			{
				flag=0;
				break;
			}
		}
		else
		flag=1;
	}
	return flag;
}
int check_date(date d)
{
	int days31[7]={1,3,5,7,8,10,12}; //Months having 31 days
	int  days30[4]={4,6,9,11};       //Months having 30 days
	int flag=1,i;
	if(d.yyyy<1995 || d.yyyy>1997)
	flag=0;
	if(d.mm<1 || d.mm>12)
	flag=0;
	for(i=0; i<7; ++i)
	{
		if(d.mm==days31[i])
		{
			if(d.dd<1 || d.dd>31)
			{
				flag=0;
				break;
			}
		}
	}
	for(i=0; i<4; ++i)
	{
		if(d.mm==days30[i])
		{
			if(d.dd<1 || d.dd>30)
			{
				flag=0;
				break;
			}
		}
	}
	if(d.mm==2)
	{
		if(d.yyyy==1996)
		{
			if(d.dd<1 || d.dd>29)
			flag=0;
		}
		else if(d.dd<1 || d.dd>28)
		flag=0;
	}
	return flag;
}
int check_phone(char phone[])
{
	int flag=1;
	for(int i=0; i<strlen(phone); ++i)
	{
		if(!isdigit(phone[i]) || strlen(phone)!=10)
		{
			flag=0;
			break;
		}
	}
	return flag;
}
int check_email(char email[])
{
	int flag=0,i;
	for(i=0; i<strlen(email); ++i)
	{
		if(email[i]=='@')
		for(int j=i+2; j<strlen(email); ++j)
		{
			if(email[j]=='.')
			{
				flag=1;
				break;
			}
		}
	}
	for(i=0; i<strlen(email); ++i)
	{
		if(isalpha(email[i]) && islower(email[i]))
		{
			flag=0;
			break;
		}
	}
	return flag;
}
/**************************************/
/*     FUNCTIONS OF STUDENT CLASS     */
/**************************************/
void student::accept()
{
	int ret;
	hasappeared=0;  //The student has not appeared for the exam
	initgraph(&gd,&gm,"c:\\tc\\bgi\\");
	cout<<"\n\n\n\n\t\t\t\tAPPLICATION FORM ";
	cout<<"\n\n\t\t\t    STATE LEVEL COMPUTER QUIZ";
	cout<<"\n\n\n\t\t   NOTE: ENTER DETAILS IN BLOCK LETTERS ONLY";
	line(0,175,640,175);
	cout<<"\n\n\nENTER NAME:\t";
	do
	{
		gets(name);
		ret=check_name(name);
		if(!ret)
		cout<<"\n\nPLEASE ENTER A VALID NAME:\t";
		else
		break;
	}while(!ret);
	cout<<"\n\nENTER GENDER (M/F):\t";
	do
	{
		cin>>gender;
		if(gender!='M' && gender!='F')
		{
			ret=0;
			cout<<"\n\nPLEASE ENTER A VALID GENDER (M/F):\t";
		}
		else
		break;
	}while(!ret);
	cout<<"\n\nENTER DATE OF BIRTH-\n";
	do
	{
		cout<<"\n1. Date (1-31):\t";
		cin>>dob.dd;
		cout<<"\n2. Month (1-12):\t";
		cin>>dob.mm;
		cout<<"\n3. Year (1995-1997):\t";
		cin>>dob.yyyy;
		ret=check_date(dob);
		if(ret==0)
		cout<<"\n\nPLEASE ENTER A VALID DATE OF BIRTH:\n";
	}while(!ret);
	cout<<"\n\nENTER FATHER'S NAME:\t";
	do
	{
		gets(fathersname);
		ret=check_name(fathersname);
		if(!ret)
		cout<<"\n\nPLEASE ENTER A VALID NAME:\t";
		else
		break;
	}while(!ret);
	cout<<"\n\nENTER ADDRESS:\t";
	gets(address);
	cout<<"\n\nENTER CITY:\t";
	do
	{
		gets(city);
		ret=check_name(city);
		if(!ret)
		cout<<"\n\nPLEASE ENTER A VALID CITY NAME:\t";
		else
		break;
	}while(!ret);
	cout<<"\n\nENTER PHONE NUMBER (10-DIGIT):\t";
	do
	{
		cin>>phoneno;
		ret=check_phone(phoneno);
		if(!ret)
		cout<<"\n\nPLEASE ENTER A VALID 10-DIGIT PHONE NUMBER:\t";
		else
		break;
	}while(!ret);
	cout<<"\n\nENTER E-MAIL ID:\t";
	do
	{
		cin>>email;
		ret=check_email(email);
		if(!ret)
		cout<<"\n\nPLEASE ENTER A VALID E-MAIL:\t";
		else
		break;
	}while(!ret);
	ifstream fin("ROLL_NO.TXT", ios::in);
	long beg, last;
	fin.seekg(0, ios::beg);
	beg=fin.tellg();
	fin.seekg(0, ios::end);
	last=fin.tellg();
	if(beg==last)  //i.e., if the file is blank
	assign_rollno(0);
	else
	assign_rollno(1);
	fin.close();
	closegraph();
	r=rollno%1000000;
	display_details(r);
}
void student::assign_rollno(int a)
{
	fstream fobj("ROLL_NO.TXT", ios::in|ios::out);
	if(a==0)
	rollno=first_rollno;
	else
	{
		fobj>>rollno;
		++rollno;

	}
	fobj.seekg(0);
	fobj<<rollno;
	fobj.close();
	putfile();
}
void student::putfile()
{
	ofstream fout("PROJECT.TXT", ios::app|ios::binary);
	fout.write((char*)&s3, sizeof(s3));
	fout.close();
}
void student::display_details(int n)
{
	ifstream fin("PROJECT.TXT", ios::in|ios::binary);
	fin.seekg(0);
	int i=1;
	while(!fin.eof())
	{
		fin.read((char*)&s3, sizeof(s3));
		if(i==n)
		{
			cout<<"\n\n\t\t\t\tYOUR DETAILS ARE:";
			cout<<"\n\n\t\t     ROLL NUMBER:\t\t"<<rollno;
			cout<<"\n\n\t\t     NAME:\t\t\t"<<name;
			cout<<"\n\n\t\t     GENDER:\t\t\t"<<gender;
			cout<<"\n\n\t\t     DATE OF BIRTH:\t\t";
			cout<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yyyy;
			cout<<"\n\n\t\t     FATHER'S NAME:\t\t"<<fathersname;
			cout<<"\n\n\t\t     ADDRESS:\t\t\t"<<address;
			cout<<"\n\n\t\t     CITY:\t\t\t"<<city;
			cout<<"\n\n\t\t     PHONE NUMBER:\t\t"<<phoneno;
			cout<<"\n\n\t\t     EMAIL ID:\t\t\t"<<email;
			if(hasappeared)
			{
				cout<<"\n\n\n\t\t\t";
				cout<<"  PRESS ANY KEY TO VIEW RESULT...";
				getch();
				initgraph(&gd, &gm, "c:\\tc\\bgi\\");
				setbkcolor(15);
				setcolor(8);
				settextstyle(1,0,3);
				outtextxy(230,80,"YOUR RESULT IS");
				cout<<"\n\n\n\n\n\n\n\n\t\t\t\tMARKS:\t"<<marks<<"/125";
				cout<<"\n\n\t\t\t\tPERCENTAGE:\t"<<percent<<"%";
				setcolor(15);
				rectangle(270,250,270+percent,270); //green
				rectangle(270+percent, 250, 370, 270);     //red
				if(percent>0)
				{
					if(percent>50)
					cout<<"\n\n\t\t\t\t     PASSED";
					else
					cout<<"\n\n\t\t\t\t     FAILED";
					setfillstyle(1,4);
					floodfill(369,260,15);
					setfillstyle(1,2);
					floodfill(271,260,15);
				}
				else
				{
					setfillstyle(1,4);
					floodfill(369,260,15);
				}
				getch();
			}
			getch();
			break;
		}
		else
		++i;
	}
	fin.close();
	closegraph();
}
int student::match_rollno(unsigned long roll_no)
{
	int flag=-1;
	ifstream fin;
	fin.open("PROJECT.TXT", ios::in|ios::binary);
	fin.seekg(0, ios::beg);
	while(!fin.eof())
	{
		fin.read((char*)&s1, sizeof(s1));
		if(s1.rollno==roll_no)
		{
			flag=1;
			break;
		}
	}
	if(flag==1 && s1.hasappeared==1)
	flag=0;
	fin.close();
	r=roll_no%1000000;
	if(flag==1)
	s1.display_details(r);
	return flag;
}
void student::assign_marks(int m, float p)
{
	fstream fout("PROJECT.TXT", ios::in|ios::out|ios::binary);
	fout.seekg((r-1)*sizeof(s1));
	s1.hasappeared=1, s1.marks=m, s1.percent=p;
	fout.write((char*)&s1, sizeof(s1));
	fout.close();
	s1.display_details(r);
}
/***********************************/
/*     FUNCTIONS OF CLASS EXAM     */
/***********************************/
void exam::screen_one(int c1)
{
	initgraph(&gd,&gm,"c:\\tc\\bgi\\");
	setbkcolor(c1);
	setcolor(15);
	settextstyle(1,0,4);
	outtextxy(90,200,"STATE LEVEL COMPUTER QUIZ");
	getch();
}
void exam::instructions(int c2)
{

	initgraph(&gd,&gm,"c:\\tc\\bgi\\");
	setbkcolor(c2);
	setcolor(15);
	settextstyle(1,0,5);
	outtextxy(200,35 , "INSTRUCTIONS");
	setcolor(1);
	settextstyle(1,0,1);
	outtextxy(20, 110, "1. There are 25 multiple choice questions.");
	outtextxy(20, 140, "2. The questions have been divided into 5 sections, each ");
	outtextxy(50, 170,     "section containing 5 questions.");
	outtextxy(20, 200, "3. Each question has four options out of which ONLY ONE");
	outtextxy(50, 230,     "is correct.");
	outtextxy(20, 260, "4. You are awarded +5 marks for every correct answer.");
	outtextxy(20, 290, "5. 1 mark is deducted for every incorrect answer.");
	outtextxy(20, 320, "6. To leave a question unattempted, enter 'U' as your choice.");
	outtextxy(20, 350, "7. Once you answer a question, you are not allowed to change");
	outtextxy(50, 380,     "your answer.");
	outtextxy(20, 410, "8. Enter all choices with CAPS LOCK on. There is negative ");
	outtextxy(50, 440,     "marking for giving answers with caps lock off.");
	getch();
	closegraph();
	sectionA();
}
/*-------------# SECTION A: NETWORKING #-------------*/
void exam::sectionA()
{
	ofstream fout;
	fout.open("QUESTION.TXT",ios::out);
	/*------------------------QUESTION 1-------------------------*/
	fout<<"Your company has a LAN in its downtown office and has now ";
	fout<<"set up a LAN in a     manufacturing plant in the suburbs. To ";
	fout<<"enable everyone to share data and        resources between ";
	fout<<"the two LANs, what type of device is needed to connect them? ";
	fout<<" Choose the most correct answer."<<endl;
	fout<<"A. Modem"<<endl;
	fout<<"B. Cable"<<endl;
	fout<<"C. Hub"<<endl;
	fout<<"D. Router"<<endl;
	/*------------------------QUESTION 2-------------------------*/
	fout<<"Which of the following is a disadvantage of wireless ";
	fout<<"LAN?"<<endl;
	fout<<"A. Slower data transmission"<<endl;
	fout<<"B. Higher error rate"<<endl;
	fout<<"C. Interference of transmissions from different ";
	fout<<"computers"<<endl;
	fout<<"D. None of these"<<endl;
	/*------------------------QUESTION 3-------------------------*/
	fout<<"Which of the following device is used to connect two systems, ";
	fout<<"especially if the systems use different protocols?"<<endl;
	fout<<"A. Hub"<<endl;
	fout<<"B. Bridge"<<endl;
	fout<<"C. Router"<<endl;
	fout<<"D. Repeater"<<endl;
	/*------------------------QUESTION 4-------------------------*/
	fout<<"A distributed network configuration in which all data/";
	fout<<"information passes through a central computer is:"<<endl;
	fout<<"A. Bus network"<<endl;
	fout<<"B. Star network"<<endl;
	fout<<"C. Ring network"<<endl;
	fout<<"D. Point-to-point network"<<endl;
	/*------------------------QUESTION 5-------------------------*/
	fout<<"Which of the following is the most expensive amongst";
	fout<<" guided media?"<<endl;
	fout<<"A. Optical fibre"<<endl;
	fout<<"B. Coaxial cable"<<endl;
	fout<<"C. Twisted pair cable"<<endl;
	fout<<"D. Both (B) and (C)"<<endl;
	fout.close();
	sectionB();
}
/*---# SECTION B: DIGITAL COMPUTER ELECTRONICS #---*/
void exam::sectionB()
{
	ofstream fout;
	fout.open("QUESTION.TXT", ios::app);
	/*------------------------QUESTION 6-------------------------*/
	fout<<"The binary equivalent of the decimal number 61 is:"<<endl;
	fout<<"A. 110011"<<endl;
	fout<<"B. 11001110"<<endl;
	fout<<"C. 111101"<<endl;
	fout<<"D. 11111"<<endl;
	/*------------------------QUESTION 7-------------------------*/
	fout<<"The OR gate can be imagined as:"<<endl;
	fout<<"A. Switches  connected in series"<<endl;
	fout<<"B. Switches connected in parallel"<<endl;
	fout<<"C. Metal oxide semiconductor (MOS) transistors connected ";
	fout<<"in series"<<endl;
	fout<<"D. None of the above"<<endl;
	/*------------------------QUESTION 8-------------------------*/
	fout<<"Which of the following gates is called universal gate?"<<endl;
	fout<<"A. XOR"<<endl;
	fout<<"B. OR"<<endl;
	fout<<"C. NAND"<<endl;
	fout<<"D. AND"<<endl;
	/*------------------------QUESTION 9-------------------------*/
	fout<<"What is the ASCII value of 'T'?"<<endl;
	fout<<"A. 81"<<endl;
	fout<<"B. 82"<<endl;
	fout<<"C. 83"<<endl;
	fout<<"D. 84"<<endl;
	/*------------------------QUESTION 10------------------------*/
	fout<<"A diagram that illustrates the ore (logic) of functions in a ";
	fout<<"program is called a _____________."<<endl;
	fout<<"A. Flowchart"<<endl;
	fout<<"B. Sequence of steps"<<endl;
	fout<<"C. Direction of flow"<<endl;
	fout<<"D. All of the above"<<endl;
	fout.close();
	sectionC();
}
/*---# SECTION C: PROGRAMMING USING C++ #----*/
void exam::sectionC()
{
	ofstream fout;
	fout.open("QUESTION.TXT", ios::app);
	/*------------------------QUESTION 11------------------------*/
	fout<<"Which of the following are valid characters for a ";
	fout<<"numerical literal constant?"<<endl;
	fout<<"A. Comma (,)"<<endl;
	fout<<"B. Dollar ($)"<<endl;
	fout<<"C. Percent (%)"<<endl;
	fout<<"D. None of the above"<<endl;
	/*------------------------QUESTION 12------------------------*/
	fout<<"When the compiler cannot differentiate between two overloaded ";
	fout<<"constructors, they are called:"<<endl;
	fout<<"A. Overloaded"<<endl;
	fout<<"B. Destructed"<<endl;
	fout<<"C. Ambiguous"<<endl;
	fout<<"D. Dubious"<<endl;
	/*------------------------QUESTION 13------------------------*/
	fout<<"A function that returns no values to the program that calls";
	fout<<" it is:"<<endl;
	fout<<"A. Not allowed in C++"<<endl;
	fout<<"B. Type void"<<endl;
	fout<<"C. Type empty"<<endl;
	fout<<"D. Type barren"<<endl;
	/*------------------------QUESTION 14------------------------*/
	fout<<"Which of the following statements are syntactically wrong?"<<endl;
	fout<<"A. cin>>name;"<<endl;
	fout<<"B. cout<<name;"<<endl;
	fout<<"C. cout<<\"endl\";"<<endl;
	fout<<"D. None of the above"<<endl;
	/*------------------------QUESTION 15------------------------*/
	fout<<"What does C++ append to the end of a string literal constant?"<<endl;
	fout<<"A. Null character"<<endl;
	fout<<"B. Space"<<endl;
	fout<<"C. Number sign (#)"<<endl;
	fout<<"D. Asterisk (*)"<<endl;
	fout.close();
	sectionD();
}
/*--------# SECTION D: DATABASE SYSTEMS #--------*/
void exam::sectionD()
{
	ofstream fout;
	fout.open("QUESTION.TXT", ios::app);
	/*------------------------QUESTION 16------------------------*/
	fout<<"Periodically adding, changing and deleting file records is ";
	fout<<"called:"<<endl;
	fout<<"A. Updating"<<endl;
	fout<<"B. Upgrading"<<endl;
	fout<<"C. Renewing"<<endl;
	fout<<"D. Restructuring"<<endl;
	/*------------------------QUESTION 17------------------------*/
	fout<<"In the relational model, a tuple is equivalent to a:"<<endl;
	fout<<"A. Field"<<endl;
	fout<<"B. Record"<<endl;
	fout<<"C. File"<<endl;
	fout<<"D. Data item"<<endl;
	/*------------------------QUESTION 18------------------------*/
	fout<<"A top-to-bottom relationship among the items in a database ";
	fout<<"is established by a:"<<endl;
	fout<<"A. Network schema"<<endl;
	fout<<"B. Hierarchial schema"<<endl;
	fout<<"C. Relational schema"<<endl;
	fout<<"D. All of the above"<<endl;
	/*------------------------QUESTION 19------------------------*/
	fout<<"A network schema"<<endl;
	fout<<"A. Restricts the structure to a one-to-many relationship"<<endl;
	fout<<"B. Stores data in tables"<<endl;
	fout<<"C. Permits many-to-many relationships"<<endl;
	fout<<"D. None of the above"<<endl;
	/*------------------------QUESTION 20------------------------*/
	fout<<"Which command is used to remove a table from the database in SQL?"<<endl;
	fout<<"A. DELETE TABLE"<<endl;
	fout<<"B. ERASE TABLE"<<endl;
	fout<<"C. UNATTACH TABLE"<<endl;
	fout<<"D. DROP TABLE"<<endl;
	fout.close();
	sectionE();
}
/*--------# SECTION E: COMPUTER HARDWARE #---------*/
void exam::sectionE()
{
	ofstream fout;
	fout.open("QUESTION.TXT", ios::app);
	/*------------------------QUESTION 21------------------------*/
	fout<<"A hard disk is divided into tracks which are further ";
	fout<<"subdivided into:"<<endl;
	fout<<"A. Sectors"<<endl;
	fout<<"B. Clusters"<<endl;
	fout<<"C. Vectors"<<endl;
	fout<<"D. Heads"<<endl;
	/*------------------------QUESTION 22------------------------*/
	fout<<"If the mouse pointer moves erratically, what is the ";
	fout<<"possible cause?"<<endl;
	fout<<"A. The driver is not installed"<<endl;
	fout<<"B. The mouse is not connected"<<endl;
	fout<<"C. The mouse ball is dirty"<<endl;
	fout<<"D. All of the above"<<endl;
	/*------------------------QUESTION 23------------------------*/
	fout<<"What is the best way to protect your hard drive data?"<<endl;
	fout<<"A. Periodically defragment it"<<endl;
	fout<<"B. Run CHKDSK at least once a week"<<endl;
	fout<<"C. Run ScanDisk at least once aweek"<<endl;
	fout<<"D. Regular back-ups"<<endl;
	/*------------------------QUESTION 24------------------------*/
	fout<<"What would you do first when troubleshooting a faulty monitor?"<<endl;
	fout<<"A. Check its connections to the computer and ";
	fout<<"power source"<<endl;
	fout<<"B. Use a meter to check the CRT and internal circuitry for ";
	fout<<"continuity"<<endl;
	fout<<"C. Power down the monitor, then turn it on again to see ";
	fout<<"if that corrects the    problem"<<endl;
	fout<<"D. None of the above"<<endl;
	/*------------------------QUESTION 25------------------------*/
	fout<<"A customer attached an external drive to his notebook but ";
	fout<<"the computer is not   recognizing it. What should be checked?"<<endl;
	fout<<"A. The cables are attached firmly"<<endl;
	fout<<"B. The external drive has been pre-loaded with the appropriate";
	fout<<" software"<<endl;
	fout<<"C. The external drive is turned on"<<endl;
	fout<<"D. All of the above"<<endl;
	fout.close();
}
void exam::display_question()
{
	ifstream fin;
	for(int i=1; i<=25; ++i)
	label[i]='U';
	fin.open("QUESTION.TXT",ios::in);
	for(q_no=1; q_no<=25; ++q_no)
	{
		if(q_no==1)
		sections(q_no, "NETWORKING");
		else if(q_no==6)
		sections(q_no, "DIGITAL COMPUTER ELECTRONICS");
		else if(q_no==11)
		sections(q_no, "PROGRAMMING USING C++");
		else if(q_no==16)
		sections(q_no, "DATABASE SYSTEMS");
		else if(q_no==21)
		sections(q_no, "COMPUTER HARDWARE");
		fin.getline(question, 350, '\n');
		cout<<"\n\n\n\n\t\t\t\tQUESTION "<<q_no;
		cout<<"\n\n\n"<<question;
		for(int i=1; i<=4; ++i)
		{
			fin.getline(choices, 100, '\n');
			cout<<"\n"<<choices;
		}
		cout<<"\n\nENTER YOUR CHOICE (A/B/C/D):\t";
		cin>>choice;
		iscorrect(choice, q_no);

	}
	fin.close();
	calculate_marks();
}
void exam::sections(int qno, char description[35])
{
	int xpixel;
	initgraph(&gd, &gm, "c:\\tc\\bgi\\");
	setbkcolor(7);
	setcolor(15);
	settextstyle(1,0,4);
	outtextxy(210, 150, "SECTION  -");
	switch(qno)
	{
		case 1:  outtextxy(400, 150, "A");
			 xpixel=215;
			 break;
		case 6:  outtextxy(400, 150, "B");
			 xpixel=75;
			 break;
		case 11: outtextxy(400, 150, "C");
			 xpixel=120;
			 break;
		case 16: outtextxy(400, 150, "D");
			 xpixel=170;
			 break;
		case 21: outtextxy(400, 150, "E");
			 xpixel=150;
			 break;
	}
	setcolor(1);
	outtextxy(xpixel, 200, description);
	getch();

	closegraph();
}
void exam::iscorrect(char c, int q)  //Contains correct answers
{
	switch(q)
	{
		case 1:  correct='D';
			 break;
		case 2:  correct='D';
			 break;
		case 3:  correct='C';
			 break;
		case 4:  correct='B';
			 break;
		case 5:  correct='A';
			 break;
		case 6:  correct='C';
			 break;
		case 7:  correct='B';
			 break;
		case 8:  correct='C';
			 break;
		case 9:  correct='D';
			 break;
		case 10: correct='A';
			 break;
		case 11: correct='D';
			 break;
		case 12: correct='C';
			 break;
		case 13: correct='B';
			 break;
		case 14: correct='D';
			 break;
		case 15: correct='A';
			 break;
		case 16: correct='A';
			 break;
		case 17: correct='B';
			 break;
		case 18: correct='B';
			 break;
		case 19: correct='C';
			 break;
		case 20: correct='D';
			 break;
		case 21: correct='A';
			 break;
		case 22: correct='C';
			 break;
		case 23: correct='D';
			 break;
		case 24: correct='A';
			 break;
		case 25: correct='D';
			 break;
	}
	if(c=='U')
	{
		;
	}
	else if(c==correct)
	{
		label[q_no]='C';   //Correct
	}
	else
	{
		label[q_no]='W';    //Wrong
	}
}
void exam::calculate_marks()
{
	marks=0;
	for(int i=1; i<=25; ++i)
	{
		if(label[i]=='C')
		marks+=5;
		else if(label[i]=='W')
		marks--;
		else if(label[i]=='U')
		continue;
	}
	percent=((float)marks/125)*100;
	assign_marks(marks, percent);
}
/*************************************/
/*     FUNCTIONS TO DECIDE RANKS     */
/*************************************/
ranks *create_node(student);
void insert_node(ranks  *);
void decide_ranks()
{
	ptr=newptr=save=saveprev=NULL;
	ifstream fin("PROJECT.TXT", ios::in|ios::binary);
	while(!fin.eof())
	{
		fin.read((char*)&s1, sizeof(s1));
		if(fin.eof())
		break;
		if(s1.hasappeared)
		{
			newptr=create_node(s1);
			if(newptr==NULL)
			{
				cout<<"\n\n CANNOT COMPUTE RANKS AT THE MOMENT!!";
				cout<<" PLEASE TRY AGAIN LATER!";
				getch();
				break;
			}
			insert_node(newptr);
		}
	}
	fin.close();
}
ranks *create_node(student s1)
{
	ptr=new ranks;
	ptr->info=s1;
	ptr->next=NULL;
	return ptr;
}
void insert_node(ranks *r)
{
	if(start==NULL)
	{
		start=r;
		start->next=NULL;
	}
	else
	{
		save=start;
		while(save!=NULL)
		{
			if(r->info.marks > save->info.marks)
			{
				if(start==save)
				{
					start=r;
					start->next=save;
					break;
				}
				else
				{
					saveprev->next=r;
					r->next=save;
					break;
				}
			}
			else
			{
				saveprev=save;
				save=save->next;
			}
		}
		if(save==NULL)
		{
			saveprev->next=r;
			r->next=NULL;
		}
	}
}
void display_ranks()
{

	initgraph(&gd, &gm, "c:\\tc\\bgi\\");
	setbkcolor(0);
	setcolor(10);
	settextstyle(1,0,4);
	outtextxy(225,50,"SCORE BOARD");
	int i=1;
	ptr=start;
	cout<<"\n\n\n\n\n\n\n";
	while(ptr!=NULL)
	{
		cout<<"\n\t   "<<i<<". "<<ptr->info.rollno<<"\t";
		cout<<ptr->info.name;
		if(ptr->info.percent>50)
		cout<<"\t   PASSED";
		else
		cout<<"\t   FAILED";
		cout<<"\t"<<ptr->info.percent<<"%\n";
		for(int j=0; j<80; ++j)
		cout<<"-";
		++i;
		ptr=ptr->next;
		getch();
	}
	delete ptr,newptr,saveprev,save,start;

}
/*******************************/
/*          LAST PAGE          */
/*******************************/
void thank_you()
{
	closegraph();
	initgraph(&gd, &gm, "c:\\tc\\bgi\\");
	setbkcolor(9);
	for(int i=5; i<=100; i+=5)
	{
		circle(0,0,i);
		circle(640,0,i);
		circle(0,480,i);
		circle(640,480,i);
	}
	settextstyle(5,0,4);
	outtextxy(60, 130, "This project is a combined effort of:");
	settextstyle(3,0,2);
	outtextxy(250, 220, "Ananya Pandey");
	outtextxy(260, 270, "Shruti Shukla");
	outtextxy(250, 320, "Shweta Pandey");
	getch();
}
/**************************/
/*-----BODY OF main()-----*/
/**************************/
int main()
{

	char reply;
	do
	{
		initgraph(&gd, &gm, "c:\\tc\\bgi\\");
		setbkcolor(15);
		setcolor(5);
		settextstyle(1,0,3);
		outtextxy(110,200,"Do you want to enter records? (Y/N)");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
		cin>>reply;
		if(reply!='y' && reply!='Y')
		break;
		else
		s3.accept();
		closegraph();
	}while(reply=='y' || reply=='Y');
	exam EXAM;
	unsigned long Rollno;
	int isfound;
	do
	{
		initgraph(&gd, &gm, "c:\\tc\\bgi\\");
		setbkcolor(15);
		setcolor(3);
		settextstyle(1,0,3);
		outtextxy(60,200,"Do you want to appear for the exam? (Y/N)");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
		cin>>reply;
		if(reply!='y' && reply!='Y')
		break;
		closegraph();
		initgraph(&gd,&gm,"c:\\tc\\bgi\\");
		setbkcolor(1);
		setcolor(9);
		settextstyle(1,0,4);
		outtextxy(45,50,"PLEASE ENTER YOUR ROLL NUMBER:");
		cout<<"\n\n\n\n\n\n\t\t\t\t   ";
		cin>>Rollno;
		settextstyle(1,0,2);
		setcolor(14);
		isfound=EXAM.match_rollno(Rollno);
		if(isfound==-1)
		{
			outtextxy(152,300,"RECORD NOT FOUND IN DATABASE!");
			outtextxy(140,350,"YOU CANNOT APPEAR FOR THE QUIZ.");
			getch();
			break;
		}
		else if(isfound==0)
		{
			outtextxy(135,300,"YOU CANNOT REAPPEAR FOR THE QUIZ");
			getch();
			break;
		}
		closegraph();
		EXAM.screen_one(7);
		EXAM.instructions(7);
		EXAM.display_question();
	}while(reply=='y' || reply=='Y');
	closegraph();
	decide_ranks();
	display_ranks();
	thank_you();
}
