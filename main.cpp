#include <iostream>
#include <string.h>

//Hello Gupta :)
using namespace std;

int i;
const char courses[6][6] = {'english','maths','physics','chemistry','HSS','CSE','Electrical','Mechanical'};

class Index{

public:
        void mainPage();
        void welcome(char *text);

};

void homePageText()
{

    cout<<"Online Test Examination"<<endl<<"Created By"<<endl<<"B16CS025 -- Shreya Patel && B16CS030 -- Saksham Gupta"<<endl;
}


class user{
private:
    string UserId;
    string Password;
    string FirstName;
    string LastName;
public:
    void login(){};
    void viewProfile(){};
    void register1(){ };
};

class Student : public user {
private:
    struct appearedTest;
public:
    int getUserId(){};
    void attemptTest(){};
    void getReport(){};
    void studentMenu(){};

};

class Professor : public user {
private:
    int courseID;
public:
    int getCourse(){};
    void addQuestion(){};
    void editQuestion(){};
    void viewQuestion(){};
    void professorMenu(){};
    void getReport(){};
};

class Test{
private:
    int testID;
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
    double Posmarks;
    double Negmarks;
public:
    void printQues(){};
    int getCorrectAns(){};
    int getQuesType(){};
};

class DatabaseManager{

public:
    //struct getDetails(int){};;
    //struct getReport(int){};;
    int getProfCourseId(int);
    bool validate(int);
    bool validate (int,string);
    void updateMarks(int,int,int);
    bool addStudent(Student);


};










int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
