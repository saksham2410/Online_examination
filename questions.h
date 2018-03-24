#ifndef questions.h
#define questions.h
class Questions{
int id;
char ques[100];
char opt1[100];
char opt2[100];
char opt3[100];
char opt4[100];
int ans;
public:
void set_id(int i) { id=i; }
void set_ques(char q[]) { strcpy(ques,q); }
void set_opt1(char o1[]) { strcpy(opt1,o1); }
void set_opt2(char o2[]) { strcpy(opt2,o2); }
void set_opt3(char o3[]) { strcpy(opt3,o3); }
void set_opt4(char o4[]) { strcpy(opt4,o4); }
void set_ans(int a) { ans=a; }
int get_id() { return id; }
void get_ques() { cout<<ques;}
void get_opt1() { cout<<opt1; }
void get_opt2() { cout<<opt2; }
void get_opt3() { cout<<opt3; }
void get_opt4() { cout<<opt4; }
int get_ans() { return ans; }
void get_short_ques(){
  if(strlen(ques)<15)
   {  cout.width(15); cout.fill(' '); cout<<ques;  }
  else
    cout.write(ques,15);
 }
void get_short_opt1(){
  if(strlen(opt1)<10)
   {  cout.width(10); cout.fill(' '); cout<<opt1;  }
  else
    cout.write(opt1,10);
 }
void get_short_opt2(){  if(strlen(opt2)<10)
   {  cout.width(10); cout.fill(' '); cout<<opt2;  }
  else
    cout.write(opt2,10);
   }
void get_short_opt3(){
  if(strlen(opt3)<10)
   {  cout.width(10); cout.fill(' '); cout<<opt3;  }
  else
    cout.write(opt3,10);
 }
void get_short_opt4(){  if(strlen(opt4)<10)
   {  cout.width(10); cout.fill(' '); cout<<opt4;  }
  else
    cout.write(opt4,10);
   }
};

class State{
int max_marks;
int negative_mark;
int positive_mark;
int no_of_ques_to_ask;
char password[30];
char app_file_name[30];
char ques_file_name[30];
public:
int get_negative_mark(){ return negative_mark; }
int get_positive_mark(){ return positive_mark; }
int get_no_of_ques_to_ask(){ return no_of_ques_to_ask; }
char* get_password(){ return password; }
char* get_app_file_name(){ return app_file_name; }
char* get_ques_file_name(){ return ques_file_name; }
void set_negative_mark(int nm){  negative_mark=nm;}
void set_positive_mark(int pm){  positive_mark=pm;}
void set_no_of_ques_to_ask(int nq){ no_of_ques_to_ask=nq;}
void set_password(char pw[]){ strcpy(password, pw); }
void set_app_file_name(char af[]){ strcpy(app_file_name, af); }
void set_ques_file_name(char qf[]){ strcpy(ques_file_name, qf); }
};


void give_test(){
Students test_applicant;
  fstream fin;
  fin.open(app_file_name,ios::in|ios::out|ios::binary);

  calc_no_of_questions();
  if(no_of_questions<no_of_ques_to_ask)
  {
    cout<<"********************************************************************************"<<endl;
    cout<<"INSUFFICIENT QUESTION IN DATABASE. CONTACT ADMINISTRATOR"<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
    getch();
    main();
  }
  cout<<"ENTER YOUR APPLICANT NUMBER:"<<endl;
  cin>>t_apno;
  cout<<"ENTER DATE OF BIRTH"<<endl;
  cout<<"ENTER DAY:";
  cin>>t_dob_d;
  cout<<"ENTER MONTH:";
  cin>>t_dob_m;
  cout<<"ENTER YEAR:";
  cin>>t_dob_y;
  int flag=0;
  while (!fin.eof())
  {
    pos2=fin.tellg();
    fin.read((char*)&test_applicant,sizeof(test_applicant));
if(test_applicant.get_applicant_no()==t_apno&&test_applicant.get_dob_d()==t_dob_d&&test_applicant.get_dob_m()==t_dob_m&&test_applicant.get_dob_y()==t_dob_y)
  {
    flag=1;

    cout<<endl;
    break;
  }
  }
  if(flag==1)
  {
    Questions t_obj;
    ifstream t_ques;
    t_ques.open(ques_file_name,ios::in|ios::binary);
    time_t t;
      int seedval= (unsigned) time (&t);
       srand(seedval);
    int marks=0;
    int qno;
    int ans;
    for(int i=0; i<no_of_ques_to_ask;i++)
    {
      qno=rand()%no_of_questions+1;
	    while(t_ques.read((char*)&t_obj, sizeof(t_obj)))
	    {
	      if(t_obj.get_id()==qno)
	      {

     cout<<"********************************************************************************"<<endl;
		cout<<"Q"<<i+1<<". ";
		t_obj.get_ques();
    cout<<endl;
    cout<<"********************************************************************************"<<endl;
		cout<<endl;
		cout<<"OPTIONS"<<endl<<"1. ";
		t_obj.get_opt1();
		cout<<endl;
		cout<<"2. ";
		t_obj.get_opt2();
		cout<<endl;
		cout<<"3. ";
		t_obj.get_opt3();
		cout<<endl;
		cout<<"4. ";
		t_obj.get_opt4();
		cout<<endl;
		cout<<"ENTER ANSWER: ( 1, 2, 3, 4 ) OR 0(ZERO TO SKIP THIS QUESTION:";
		cin>>ans;
		if (ans==0)
		{
		  ;
		}
		else if(t_obj.get_ans()==ans)
		{ marks = marks + positive_mark;}
		else{ marks = marks - negative_mark;}
		break;
	      }
	    }
      t_ques.seekg(0);
    }
    test_applicant.set_marks(marks);
    fin.seekg(pos2);
    fin.write((char*)&test_applicant,sizeof(test_applicant));
    t_ques.close();
    fin.close();
  }
  if(flag==0)
  {

    cout<<"********************************************************************************"<<endl;
    cout<<"APPLICANT NOT FOUND!"<<endl;
    cout<<"********************************************************************************"<<endl;
  }
  assign_rank();
  cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
   getch(); main();
 }


void calc_no_of_questions(){

    //Define the function
}
#endif // questions
