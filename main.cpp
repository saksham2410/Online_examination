#include <iostream>
#include <string.h>
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
static int user_count=0;

class DatabaseManager{
public:
    struct getDetails(int);
    struct getReport(int);
    int getProfCourseId(int);
    bool validate(int);
    bool validate (int,string);
    void updateMarks(int,int,double);
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

    retry: cout<<"\nEnter UserId : ";                   //what if input fails
    cin>>_id;
    /*if(cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Sorry you have entered invalid userId\n\n";
        cout<<"Please
    }
    */
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
          cout<<"\n\n Incorrect credentials \n Please try again\n\n";
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
    //cout<<"\n\nPress any key to go back :";
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

class student :: public user {
private:
    appearedTest T;
public:
    student(string f_name,string l_name,string pwd)
    {
        FirstName = f_name;
        LastName = l_name;
        Password = pwd;
        UserId = user_count;
        user_count++;
        //initialize T
    }
    int getUserId(){return UserId}
    void attemptTest();
    void getReport();
    void studentMenu();
};

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
    if(cin.fail()){
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Sorry you have entered invalid course number\n\n";
        studentMenu();
    }
    if(n<1 || n>4)
    {
        cout<<"Please enter a valid course number (between 1-4) :";
        cin>>n;
        if(cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout<<"Sorry you have entered invalid course number\n\n";
            studentMenu();
        }
    }
    Test T
    T=db.generateTest(n);
    int testId = T.getTestId();
    cout<<"TEST INSTRUCTIONS\n\n";          //yet to be written
    int answer=0;
    double score=0;
    int c=0;
    for(int i=0;i<T.testQuestions.size();i++)
    {
        T.testQuestion[i].printQues();
        cout<<"ENTER YOUR ANSWER : ";
        cin>>answer;
        if(!cin.fail() && answer>0 && answer<5){
            if(answer==testQuestion[i].getCorrectAns()){
                    score=score+getPosMarks();
                    c++;
            }
            else
                score=score-getNegMarks();
        }
        else{
            score=score-getNegMarks();
        }
    }
    cout<<"\n\nTEST ATTEMPTED SUCCESSFULLY";
    cout<<"\n\nTOTAL SCORE         : "<<score;
    cout<<"\nTOTAL CORRECT ANSWERS : "<<c;
    //cout<<"\nPERFORMANCE           : ";
    db.updateMarks(userId,testId,score);
    cout<<"\n\n\n\n\n";
    studentMenu();
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
void student :: studentMenu()
{
    cout<<"1. ATTEMPT TEST\n";
    cout<<"2. GET REPORT\n";
    cout<<"3. LOGOUT\n";
    int n;
    cout<<"\nEnter your choice : ";
    cin>>n;
    cin.ignore();
    clrscr();
    switch(n)
    {
    case 1:
        attemptTest();
    case 2:
        getReport();
    case 3:
        cover();
    }
}

class Professor :: public user {
private:
    int courseID;
public:
    int getCourse(){return courseID;}
    void viewQuestion();
    void addQuestion();
    void editQuestion();
    void professorMenu();
    void getReport();
};


void Professor :: viewQuestion()
{
    db.dispAllQues(courseID);
}

void Professor :: addQuestion()
{
    string Q, c1,c2,c3,c4;
    int A;
    double p,n;

    cout<<"\n\nEnter the question to be added : ";
    cin>>Q;
    cout<<"\nEnter Choice 1 : ";
    cin>>c1;
    cout<<"\nEnter Choice 2 : ";
    cin>>c2;
    cout<<"\nEnter Choice 3 : ";
    cin>>c3;
    cout<<"\nEnter Choice 4 : ";
    cin>>c4;
    cout<<"\n\nEnter Correct Choice out of 1,2,3,4 : ";
    cin>>A;
    cout<<"\n\nEnter the positive marks for the question : ";
    cin>>p;
    cout<<"\n\nEnter the negative marks for the question : ";
    cin>>n;
    Question Ques(courseID,Q,c1,c2,c3,c4,A,p,n);
    if(db.addQues(Ques))
    {
        clrscr();
        cout<<"\n\n\nQUESTION ADDED SUCCESSFULLY\n\n";
        professorMenu();
    }
    else{
        clrscr();
        cout<<"\n\n\nERROR WHILE ADDING QUESTION\n\n\n";
        professorMenu();
    }
}
void Professor :: editQuestion()
{
    viewQuestion();
    int no;
    cout<<"\n\nENTER THE QUESTION NUMBER TO BE EDITED : ";
    re-enter: cin>>no;
    if(no is present)                                           //a function to check whether question exists in the database
    {
        string Q, c1,c2,c3,c4;
        int A;
        double p,n;

        cout<<"\n\nEnter the question to be edited : ";
        cin>>Q;
        cout<<"\nEnter Choice 1 : ";
        cin>>c1;
        cout<<"\nEnter Choice 2 : ";
        cin>>c2;
        cout<<"\nEnter Choice 3 : ";
        cin>>c3;
        cout<<"\nEnter Choice 4 : ";
        cin>>c4;
        cout<<"\n\nEnter Correct Choice out of 1,2,3,4 : ";
        cin>>A;
        cout<<"\n\nEnter the positive marks for the question : ";
        cin>>p;
        cout<<"\n\nEnter the negative marks for the question : ";
        cin>>n;
        Question Ques(courseID,Q,c1,c2,c3,c4,A,p,n);
        if(db.editQues(Ques,no))
        {
            clrscr();
            cout<<"\n\n\nQUESTION EDITED SUCCESSFULLY\n\n";
            professorMenu();
        }
        else{
            clrscr();
            cout<<"\n\n\nERROR WHILE EDITING QUESTION\n\n\n";
            professorMenu();
        }

    }
    else{
        cout<<"\n\nYOU HAVE ENTERED AN INVALID QUESTION NUMBER";
        cout<<"\n\nRE-ENTER THE QUESTION NUMBER TO BE EDITED : ";
        goto re-enter;
    }
}
void Professor :: professorMenu()
{
    cout<<"\n\n\n\n";
    cout<<"1. VIEW PROFILE\n";
    cout<<"2. VIEW QUESTIONS\n";
    cout<<"3. ADD QUESTION\n";
    cout<<"4. EDIT QUESTION\n";
    cout<<"5. GET REPORT\n";
    cout<<"6. LOGOUT\n";
    int n;
    cout<<"\nEnter your choice : ";
    cin>>n;
    cin.ignore();
    clrscr();
    switch(n)
    {
    case 1:
        viewProfile();
        break;
    case 2:
        viewQuestion();
        break;
    case 3:
        addQuestion();
        break;
    case 4:
        editQuestion();
        break;
    case 5:
        getReport();
        break;
    case 6:
        cover();
        break;
    default:
        break;
    }
}
void Professor :: getReport()
{
    //to be defined
}
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


