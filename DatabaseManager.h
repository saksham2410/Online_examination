#ifndef DatabaseManager
#define DatabaseManager

struct details
{
    int userID;
    string firstname;
    string lastname;
};
struct report
{

};
class DatabaseManager
{
public:
    details getDetails(int userID)
    {
        //fetch details from the database of user with given userID
    }
    struct getReport(int)
    {

    }
    int getProfCourseID(int userID)
    {
        //fetch courseID of professor with given userID
    }
    bool validate(int userID)
    {
        //check whether userID exists in the database
    }
    bool validate(int userID, string password)
    {
        //check whether userID and password exist in the database and are matched
    }
    void updateMarks(int userID, int testID, int marks)
    {
        //add the marks and testId to the appeared test attribute of the student with given userID
    }
    Question getQues(int courseID)
    {
        //fetch question of given course
    }
    void displayAllQues(int courseID)
    {
        //displays all the questions in the database
    }
    bool addQues(Question Q)
    {

    }
    bool editQues(Question Q)
    {

    }

};

#endif // DatabaseManager
