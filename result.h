#ifndef result.h
#define result.h
void get_result(){
  Students t2_applicant;
  ifstream fin;
  fin.open(app_file_name,ios::in|ios::binary);

  cout<<"ENTER YOUR APPLICANT NUMBER:"<<endl;
  cin>>apno;
  cout<<"ENTER DATE OF BIRTH"<<endl;
  cout<<"ENTER DAY:";
  cin>>get_d;
  cout<<"ENTER MONTH:";
  cin>>get_m;
  cout<<"ENTER YEAR:";
  cin>>get_y;
  int flag=0;
while(fin.read((char *)&t2_applicant,sizeof(t2_applicant))){
if(t2_applicant.get_applicant_no()==apno&&t2_applicant.get_dob_d()==get_d&&t2_applicant.get_dob_m()==get_m&&t2_applicant.get_dob_y()==get_y)
{

  cout<<"********************************************************************************"<<endl;
  cout<<"                                   ::RESULT::                                   "<<endl<<endl;
  cout<<"********************************************************************************"<<endl;
  cout<<"APPLICANT NUMBER:"<<t2_applicant.get_applicant_no()<<endl;
  cout<<"APPLICANT'S NAME:";
  t2_applicant.get_name();
    cout<<endl;
  cout<<"FIRST NAME:";
  t2_applicant.get_faname();
    cout<<endl;
  cout<<"LAST NAME:";
  t2_applicant.get_maname();
  cout<<endl;
  cout<<"DATE OF BIRTH:"<<t2_applicant.get_dob_d()<<"-"<<t2_applicant.get_dob_m()<<"-"<<t2_applicant.get_dob_y()<<endl;
  if(t2_applicant.get_rank()!=-1)
  {  calc_no_of_applicants();
  cout<<"RANK:"<<t2_applicant.get_rank()<<" OUT OF "<<no_of_applicants<<endl;  }
  else  {  cout<<"RANK NOT ASSIGNED"<<endl;  }
  if(t2_applicant.get_marks()!=-500)
    {  cout<<"MARKS:"<<t2_applicant.get_marks()<<" OUT OF "<<no_of_ques_to_ask*positive_mark<<endl;
    cout<<"********************************************************************************"<<endl;
}
  else  {  cout<<"MARKS NOT ASSIGNED"<<endl;
  cout<<"********************************************************************************"<<endl;
  }
    flag=1;
 break;
}
}
if(!flag){

  cout<<"********************************************************************************"<<endl;
  cout<<"APPLICANT NOT FOUND!"<<endl;
  cout<<"********************************************************************************"<<endl;
}
fin.close();
cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
 getch(); main();
}
#endif // result
