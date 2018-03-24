#ifndef applicants.h
#define applicants.h

class Students {
int applicant_no;
char name[50];
char first_name[50];
char last_name[50];
int dob_day;
int dob_mon;
int dob_year;
int marks;
int rank;
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
void calc_no_of_applicants(

                           //Define this function
                           );
#endif // applicants
