#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED

class Question
{
    int questionNumber;
    int type;
    string question;
    string choice1;
    string choice2;
    string choice3;
    string choice4;
    int correctAns;
public:
    double posMarks;
    double negMarks;
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
    int getCorrectAns(){
        return correctAns;
    }
    int getQuestionType(){
        return type;
    }
};

#endif // QUESTION_H_INCLUDED
