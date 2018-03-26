#include <iostream>
#include <string.h>

//Hello Gupta :)
using namespace std;

<<<<<<< HEAD
int i;
//const char courses[4][2] = {'english','maths','physics','chemistry'};
char *student

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
    dispAllQues(int);
    bool addQues(question);
    bool editQues(question);
};

DatabaseManager db;

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

}

class student :: user {
private:
    struct appearedTest;
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
private:
    int testID;
    question testQuestions[];
    double marks;
public:
    void setTime(){};
    void setTestID(){};
    void getTestID(){};
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
    void printQues();
    int getCorrectAns();
    int getQuesType();
};

void Question :: printQues()
{
    cout<<question<<endl;
    cout<<"1. "<<choice1<<endl;
    cout<<"2. "<<choice2<<endl;
    cout<<"3. "<<choice3<<endl;
    cout<<"4. "<<choice4<<endl;
}
int Question :: getCorrectAns()
{
    return correctAns;
}
int Question :: getQuesType()
{
    return type;
}

=======
>>>>>>> c9eb6cae575e52764313f35416cd6de70f38b9bc
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
