#ifndef applicants.h
#define applicants.h

class Students {

char name[50];
char first_name[50];
char last_name[50];
int dob_day;
int dob_mon;
int dob_year;
int marks;

public:
    int get_applicant_no(){return applicant_no;}
    int get_dob_d(){return dob_day;}
    int get_dob_m(){return dob_mon;}
    int get_dob_y(){return dob_year;}
    void get_name(){cout<<name;}
    void get_fname(){cout<<first_name;}
    void get_lname(){cout<<last_name;}
    int get_marks(){return marks;}
    int get_rank(){return rank;}
    void set_marks(int mk) {marks=mk;}
    void set_rank(int rn){rank=rn;}
    void set_applicant_no(int ap){applicant_no=ap;}
    void set_dob_d(int dd){dob_day=dd;}
    void set_dob_m(int dm){dob_mon=dm;}
    void set_dob_y(int dy){dob_year=dy;}
    void set_name(char na[]){strcpy(name,na);}
    void set_lname(char ma[]){strcpy(last_name,ma);}
    void set_fname(char fa[]){strcpy(first_name,fa);}
    void get_short_name(){
if(strlen(name)<15)
  {  cout.width(15); cout.fill(' '); cout<<name; }
else
    cout.write(name,15);
  }
void get_short_faname(){
  if(strlen(first_name)<15)
     {  cout.width(15); cout.fill(' '); cout<<first_name;  }
    else
      cout.write(first_name,15);
    }
  void get_short_maname(){
    if(strlen(last_name)<15)
      {  cout.width(15); cout.fill(' '); cout<<last_name;   }
      else
        cout.write(last_name,15);
       }
};


// Function to register new candidate

void apply_now() {
Applicants t_applicant;
ofstream fout;
 t_applicant.set_marks(-500);
 t_applicant.set_rank(-1);

fout.open(app_file_name, ios::app|ios::binary);
cout<<"********************************************************************************"<<endl;
cout<<"                              ::APPLICATION FORM::                              "<<endl;
cout<<"********************************************************************************"<<endl;
cout<<"NAME:";
gets(na);
t_applicant.set_name(na);
cout<<"FIRST NAME:";
gets(fa);
t_applicant.set_faname(fa);
cout<<"LAST NAME:";
gets(ma);
t_applicant.set_maname(ma);
cout<<"DATE OF BIRTH"<<endl;
do{
cout<<"DAY (e.g., 1, 2, 3, 4, ....30, 31 )"<<endl;
cin>>dd;
 }
while(!((dd>0)&&(dd<32)));
t_applicant.set_dob_d(dd);
do{
cout<<"MONTH (e.g., 1, 2, 3, 4, ....11, 12 )"<<endl;
cin>>dm;
}
while(!((dm>0)&&(dm<13)));
t_applicant.set_dob_m(dm);
do{
cout<<"YEAR (e.g., 1901, ...2015, 2016 )"<<endl;
cin>>dy;
}
while(!((dy>1900)&&(dy<3000)));
t_applicant.set_dob_y(dy);
calc_no_of_applicants();
t_applicant.set_applicant_no(no_of_applicants+1);
fout.write((char*)&t_applicant, sizeof(t_applicant));
fout.close();
calc_no_of_applicants();

cout<<"********************************************************************************"<<endl;
cout<<"                                ::YOUR DETAILS::                                "<<endl;
cout<<"********************************************************************************"<<endl;
cout<<"FORM SUCCESSFULLY SUBMITTED!"<<endl;
cout<<"APPLICANT NUMBER:"<<t_applicant.get_applicant_no()<<endl;
cout<<"APPLICANT'S NAME:";
t_applicant.get_name();
  cout<<endl;
cout<<"FIRST NAME:";
t_applicant.get_faname();
  cout<<endl;
cout<<"LAST NAME:";
t_applicant.get_maname();
  cout<<endl;
cout<<"DATE OF BIRTH:"<<t_applicant.get_dob_d()<<"-"<<t_applicant.get_dob_m()<<"-"<<t_applicant.get_dob_y()<<endl;
cout<<"********************************************************************************"<<endl;
cout<<"PRESS ANY KEY TO RETURN TO THE MAIN MENU";
getch();
main();
}

void calc_no_of_applicants(

                           //Define this function
                           );
#endif // applicants
