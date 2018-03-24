#ifndef settings.h
#define settings.h
void configure(){
//Define functions here
//Add functions to implement the file


}

void settings(){

  cout<<"********************************************************************************"<<endl;
cout<<"                                  ::SETTINGS::                                  "<<endl<<endl;
cout<<"********************************************************************************"<<endl;
cout<<"CURRENT SETTINGS:"<<endl;
cout<<"ADMIN PASSWORD:"<<password<<endl;
cout<<"APPLICANT DATABASE FILENAME:"<<app_file_name<<endl;
cout<<"QUESTIONS DATABASE FILENAME:"<<ques_file_name<<endl;
cout<<"MARKS AWARDED FOR RIGHT ANSWER:"<<positive_mark<<endl;
cout<<"MARKS DEDUCTED FOR WRONG ANSWER:"<<negative_mark<<endl;
cout<<"NUMBER OF QUESTIONS TO BE ASKED IN THE TEST:"<<no_of_ques_to_ask<<endl;
cout<<"DO YOU WANT TO CHANGE THE SETTINGS?: y/n";
cin.get();
}
#endif // settings
