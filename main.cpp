#include <iostream>
#include <string.h>

//Hello Gupta :)
using namespace std;
/*
class Index{
public:
        void mainPage();
        void welcome(char *text);
};

void homePageText()
{
    cout<<"Online Test Examination"<<endl<<"Created By"<<endl<<"B16CS025 -- Shreya Patel && B16CS030 -- Saksham Gupta"<<end;
}

void Index2::mainPage()
{
    textbackground(GREEN);
    textcolor(RED);
}
*/

//const char courses[4][2] = {'english','maths','physics','chemistry'};
int i;

class DatabaseManager{
public:
    struct getDetails(int);
    struct getReport(int);
    int getProfCourseId(int);
    bool validate(int);
    bool validate (int,string);
    void updateMarks(int,int,int);
    bool addStudent(Student);
    test generateTest(int);
    question getQues(int);
    void dispAllQues(int);
    bool addQues(question);
    bool editQues(question);
};
DatabaseManager db;

class user{
private:
    int UserId;
    string Password;
    string FirstName;
    string LastName;
public:
    void login();
    void viewProfile();
    void register();
};
user globalUser;

void user :: login ()
{
    int _id;
    string _pwd;
    int c=0;

    retry: cout<<"\nEnter UserId : ";
    cin>>_id;
    cout<<"\nEnter Password : ";
    cin>>_pwd;
    if(validate(_id,_pwd))
    {
        if(student)
        {
            student S;
            S.studentMenu();
        }
        if(professor)
        {
            professor P;
            P.professorMenu();
        }
    }
    else{
        c++;
        if(c<3)
        {
          cout<<"\n Incorrect credentials \n Please try again";
          goto  retry;
        }
        cout<<"Three incorrect attempts\n";
        cover();
    }
}

void user:: viewProfile()
{
    cout<<"USERID     : "<<UserId<<endl;
    cout<<"FIRST_NAME : "<<FirstName<<endl;
    cout<<"LAST_NAME  : "<<LastName<<endl;
}

void user :: register()
{
    string f_name,l_name,pwd;
    cout<<"\nENTER FIRSTNAME : ";
    cin>>f_name;
    cout<<"\nENTER LASTNAME : ";
    cin>>l_name;
    cout<<"\nENTER PASSWORD : ";
    cin>>pwd;
    student S(f_name,l_name,pwd);
    if(db.addStudent(S))
    {
     cout<<"SUCCESSFUL REGISTRATION";
     cout<<"YOUR USERID IS "<<S.getUserId()<<endl;
     S.studentMenu();
    }
    else
    {
        throw "Unsuccessful registration due to Invalid credentials\n\n";
    }
}

struct appearedTest
{
    vector <int> testID;
    vector <int> course;
    vector <int> marks;
    //vector <int> score_rate;
};
class student :: user {
private:
    appearedTest T;
public:
    int getUserId();
    void attemptTest();
    void getReport();
    void studentMenu();
};

int student :: getUserId()
{
    return UserId;
}

void student :: attemptTest()
{
    cout<<"SELECT THE COURSE :\n\n";
    cout<<"1.ENGLISH\n;";
    cout<<"2.PHYSICS\n;";
    cout<<"3.CHEMISTRY\n;";
    cout<<"4.MATHS\n;";
    cout<<"\nEnter the course number : ";
    int n;
    cin>>n;
    if(n<1 || n>4)
    {
        cout<<"Please enter a valid course number (between 1-4) :";
        cin>>n;
        if(cin.fail()){
            cin.clear();
            cout<<"Sorry you have entered invalid course number\n\n";
            studentMenu();
        }
    }
    if(cin.fail()){
        cin.clear();
        cout<<"Sorry you have entered invalid course number\n\n";
        studentMenu();
    }
}
void student :: getReport()
{
    viewprofile();
    cout<<endl;
    cout<<"SCORESHEET\n\n";
    cout<<"S.no \t\tTestID \t\tCourse \t\tMarks obtained\n\n;
    for(int i=0;i<T.testID.size();i++)
    {
        cout<<i+1<<"   \t\t";
        cout<<T.testID[i]<<"   \t\t";

        if(T.course[i]==1) cout<<"ENGLISH\t\t";
        if(T.course[i]==2) cout<<"PHYSICS\t\t";
        if(T.course[i]==3) cout<<"CHEMISTRY\t\t";
        if(T.course[i]==4) cout<<"MATHS\t\t";

        cout<<T.marks[i]<<"   \t\t";
    }

    //overall performance       extra h agr add karna ho to
}

class Professor :: user {
private:
    int courseID;
public:
    int getCourse();
    void addQuestion();
    void editQuestion();
    void viewQuestion();
    void professorMenu();
    void getReport();
};

class Test{
    int testID;
    double marks;

public:
    question testQuestions[15];

    Test()
    {
        //generating test of given course
        //initialize testID
    }
    void setTime();                                 //ye functions define kardena
    void setTestID();
    int getTestID(){return testID;}
};

class Question{
private:
    int questionNumber;
    int type;
    string question;
    string choice1;
    string choice2;
    string choice3;
    string choice4;
    int correctAns;
    double PosMarks;
    double NegMarks;
public:
    question(int t=0,string Q,string C1,string C2,string C3,string C4,int A,double P=10,double N=5)
    {
        type=t;
        question=Q;
        choice1=C1;
        choice2=C2;
        choice3=C3;
        choice4=C4;
        correctAns=A;
        posMarks=P;
        negMarks=N;
    }
    void printQues(){
        cout<<"Q: "<<question<<endl;
        cout<<"1. "<<choice1<<endl;
        cout<<"2. "<<choice2<<endl;
        cout<<"3. "<<choice3<<endl;
        cout<<"4. "<<choice4<<endl;
    }

    int getCorrectAns(){return correctAns;}
    int getQuesType(){return type;}
    double getPosMarks(){return PosMarks;}
    double getNegMarks(){return NegMarks;}
};

/***********************************************************************************/

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}


