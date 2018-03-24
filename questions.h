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
#endif // questions
