#ifndef datamanager.h
#define datamanager.h
void admin_login(){

cout<<"********************************************************************************"<<endl;
  cout<<"                                ::ADMIN LOGIN::                                 "<<endl;
  cout<<"********************************************************************************"<<endl;
  cout<<"ENTER ADMIN PASSWORD:";
  gets_s(pass,10);
  if(strcmp(pass,password)==0)
  {

    cout<<"********************************************************************************"<<endl;
    cout<<"                         ::WELCOME TO THE ADMIN PANEL::                         "<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"1. SHOW APPLICANT DATABASE"<<endl;
    cout<<"2. GET APPLICANT RESULT"<<endl;
    cout<<"3. EDIT APPLICANT DETAILS"<<endl;
    cout<<"4. ENTER QUESTIONS"<<endl;
    cout<<"5. SHOW QUESTIONS DATABASE"<<endl;
    cout<<"6. SETTINGS"<<endl;
    cout<<"7. GO BACK TO MAIN MENU"<<endl<<endl;
    cout<<"********************************************************************************"<<endl;
    cout<<"ENTER YOUR CHOICE (1 - 7):";
    cin>>admin_menu_choice;
    switch(admin_menu_choice){
      case 1 : show_applicant_database();
	      break;
      case 2 : get_result();
	      break;
      case 3: edit_applicant();
	      break;
      case 4: enter_questions();
	    break;
      case 5 : show_questions_database();
	      break;
      case 6 : settings();
	      break;
      case 7 : main();
	      break;
      default: cout<<"WRONG CHOICE!";
      cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
	getch();
	 main();
    }
  }
  else
  {

  cout<<"********************************************************************************"<<endl;
	cout<<"ACCESS DENIED!"<<endl;
  cout<<"********************************************************************************"<<endl;
	cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
	  getch();
	   main();
  }
  getch();
  main();
  }

  void show_applicant_database(){
    Students t3_applicant;
    ifstream fin;
    fin.open(app_file_name, ios::binary|ios::in);
    calc_no_of_applicants();

  cout<<"TOTAL:"<<no_of_applicants<<endl;
  cout.setf(ios::left);
  cout<<setw(3)<<"NO"<<setw(16)<<"NAME"<<setw(16)<<"F_NAME"<<setw(16)<<"M_NAME"<<setw(11)<<" DOB"<<setw(5)<<"RANK"<<setw(5)<<"MARK"<<endl;
    while(fin.read((char*)&t3_applicant,sizeof(t3_applicant)))
    {
      cout<<setw(3)<<t3_applicant.get_applicant_no();
      cout<<setw(16);
      t3_applicant.get_short_name();
      cout<<' ';
      cout<<setw(16);
      t3_applicant.get_short_faname();
	 cout<<setw(16);
   cout<<' ';
      t3_applicant.get_short_maname();
      cout<<' ';
        cout.setf(ios::right);
      cout<<' '<<setw(2)<<setfill('0')<<t3_applicant.get_dob_d()<<"-"<<setw(2)<<setfill('0')<<t3_applicant.get_dob_m()<<"-"<<setw(4)<<setfill('0')<<t3_applicant.get_dob_y()<<' '<<setfill(' ');
  cout.setf(ios::left);
      if(t3_applicant.get_rank()!=-1)
      {   cout<<setw(5)<<t3_applicant.get_rank();  }
      else  {  cout<<setw(5)<<"N/A";  }
      if(t3_applicant.get_marks()!=-500)
	{  cout<<setw(4)<<t3_applicant.get_marks()<<endl;  }
      else  {  cout<<setw(4)<<"N/A"<<endl;  }
    }
    fin.close();
    cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
    getch();
    admin_login();
  }

  void edit_applicant(){
Students ed_obj;
  fstream ed_file;
  ed_file.open(app_file_name,ios::in|ios::out|ios::binary);

cout<<"ENTER APPLICANT NO:";
cin>>ed_apno;
int flag_ed=0;
while(!ed_file.eof())
{
pos=ed_file.tellg();
ed_file.read((char*)&ed_obj,sizeof(ed_obj));
   if(ed_obj.get_applicant_no()==ed_apno)
{
  cout<<"ENTER NEW APPLICANT NAME OR ENTER X TO DO NOT CHANGE:";
  gets(ed_new_name);
  if((strcmp(ed_new_name,"x")!=0)&&(strcmp(ed_new_name,"X")!=0))
  {
    ed_obj.set_name(ed_new_name);
  }
  cout<<"ENTER NEW FIRST NAME OR ENTER X TO DO NOT CHANGE:";
  gets(ed_new_faname);
  if((strcmp(ed_new_faname,"x")!=0)&&(strcmp(ed_new_faname,"X")!=0))
  {
    ed_obj.set_faname(ed_new_faname);
  }
  cout<<"ENTER NEW LAST NAME OR ENTER X TO DO NOT CHANGE:";
  gets(ed_new_maname);
  if((strcmp(ed_new_maname,"x")!=0)&&(strcmp(ed_new_maname,"X")!=0))
  {
    ed_obj.set_maname(ed_new_maname);
  }
  cout<<"ENTER NEW DATE OF BIRTH OR 0 TO DO NOT CHANGE"<<endl;
  cout<<"DATE:";
  cin>>ed_new_dob_d;
  if(ed_new_dob_d!=0)
  {
    ed_obj.set_dob_d(ed_new_dob_d);
  }
  cout<<"MONTH:";
  cin>>ed_new_dob_m;
  if(ed_new_dob_m!=0)
  {
    ed_obj.set_dob_m(ed_new_dob_m);
  }
  cout<<"YEAR:";
  cin>>ed_new_dob_y;
  if(ed_new_dob_y!=0)
  {
    ed_obj.set_dob_y(ed_new_dob_y);
  }
  ed_file.seekg(pos);
  ed_file.write((char*)&ed_obj, sizeof(ed_obj));
  flag_ed=1;

  cout<<"APPLICANT DETAILS SUCCESSFULLY CHANGED!"<<endl;
  break;
}
}
if(!flag_ed)
{

cout<<"********************************************************************************"<<endl;
cout<<"APPLICANT NOT FOUND!"<<endl;
cout<<"********************************************************************************"<<endl;
}
ed_file.close();

cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
getch();
admin_login();
}

void enter_questions(){
Questions t_question;
ofstream fout;
char ask='y';
calc_no_of_questions();

fout.open(ques_file_name, ios::app|ios::binary);
cout<<"********************************************************************************"<<endl;
cout<<"                              ::ENTER QUESTIONS::                               "<<endl<<endl;
cout<<"********************************************************************************"<<endl;
while(ask!='n'){
cout<<"ENTER QUESTION OR x TO STOP:";
gets(add_q);
if(strcmp(add_q,"X")==0)
{
  ask='n';
  continue;
}
if(strcmp(add_q,"x")==0)
{
  ask='n';
  continue;
}
t_question.set_ques(add_q);
cout<<"OPTION 1:";
gets(add_o1);
t_question.set_opt1(add_o1);
cout<<"OPTION 2:";
gets(add_o2);
t_question.set_opt2(add_o2);
cout<<"OPTION 3:";
gets(add_o3);
t_question.set_opt3(add_o3);
cout<<"OPTION 4:";
gets(add_o4);
t_question.set_opt4(add_o4);
cout<<"ANSWER:";
cin>>add_a;
t_question.set_ans(add_a);
t_question.set_id(++no_of_questions);
fout.write((char*)&t_question, sizeof(t_question));
}
fout.close();
calc_no_of_questions();

cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
getch();
admin_login();
}

void show_questions_database(){
  Questions t3_question;
  ifstream fin;
  fin.open(ques_file_name, ios::binary|ios::in);
  calc_no_of_questions();

  cout<<"TOTAL:"<<no_of_questions<<endl;
  cout.setf(ios::left);
  cout<<setfill(' ')<<setw(3)<<"ID"<<setw(16)<<"QUES"<<setw(11)<<"OPT1"<<setw(11)<<"OPT2"<<setw(11)<<"OPT3"<<setw(11)<<"OPT4"<<setw(2)<<"ANS"<<endl;
  while(fin.read((char*)&t3_question,sizeof(t3_question)))
  {
    cout<<setw(3)<<t3_question.get_id();
    cout<<setw(16);
     t3_question.get_short_ques();
     cout<<' ';
     cout<<setw(11);
     t3_question.get_short_opt1();
        cout<<' ';
     cout<<setw(11);
     t3_question.get_short_opt2();
        cout<<' ';
    cout<<setw(11);
     t3_question.get_short_opt3();
        cout<<' ';
  cout<<setw(11);
     t3_question.get_short_opt4();
        cout<<' ';
  cout<<setw(2);
     cout<<t3_question.get_ans()<<endl;
  }
fin.close();
  cout<<"PRESS ANY KEY TO RETURN TO THE ADMIN PANEL";
  getch();
  admin_login();
}


#endif // datamanager
