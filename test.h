#ifndef test
#define test

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
    void setTime();
    void setTestID();
    int getTestID(){return testID;}

};

#endif // test
