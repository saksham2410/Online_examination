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

void assign_rank(){
int big, pos, temp;
Students t_app_obj;
fstream t_app_file;
t_app_file.open(app_file_name, ios::in|ios::out|ios::binary);
int i=0;
int marks_array[100];
while(t_app_file.read((char*)&t_app_obj, sizeof(t_app_obj)))
{
marks_array[i]=t_app_obj.get_marks();
i++;
}
calc_no_of_applicants();
for(i=0;i<no_of_applicants;i++)
{
big = marks_array[i];
pos=i;
	for(int j=i+1;j<no_of_applicants;j++)
	    {
		 if(marks_array[j]>big)
			{ big = marks_array[j];
			  pos=j;
			}
	    }
	    if(i!=pos)
	    { temp = marks_array[i];
	      marks_array[i] = marks_array[pos];
	      marks_array[pos] = temp;
	    }
}
t_app_file.clear();
t_app_file.seekg(0);
while (!t_app_file.eof()) {
pos3=t_app_file.tellg();
t_app_file.read((char*)&t_app_obj, sizeof(t_app_obj));
for(i = no_of_applicants; i>-1;i--)
{
  if(t_app_obj.get_marks()==-500)
  {
     t_app_obj.set_rank(-1);
     break;
  }
   else if(t_app_obj.get_marks()==marks_array[i])
   {
     t_app_obj.set_rank(i+1);
     break;
   }
}
t_app_file.seekg(pos3);
t_app_file.write((char*)&t_app_obj, sizeof(t_app_obj));
}
t_app_file.close();
}

#endif // result
