/*--------------------------------------------------------------------------------------

 * Program Name: mentalHealthCheckIn.cpp

* Programmer Name: Ariana Johnson

* Description: This program is a mental health check designed for students of a university (though may be changed to reflect community use). It prompts the user to input how many users are using the program, and has them give some information on how they are doing. At the end of each entry, the console will ask the user if they want someone to contact them regarding their well being. All this data will be exported to two different files. One holding all the data, and one specifically for the students who wish to be contacted



--------------------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <string>
#include "checkIn.h"
#include <iomanip> 

using namespace std;

int main() {
student s; //artitrary student class letter
int numberOfStudents; // shows number of students that we are inputing information for
bool contact; // yes or no should we contact them
int studentOption; // does the student want to continue

/* ------------------------------- MENU -------------------------------------------*/
cout<<"-----------------------\n"<<"Hello! This is the Student Hotline\n"<<"We want to check in with how you are doing\n"<< "Press 1 to Continue\n"<<"Press 0 to Exit\n"<<"-----------------------\n";
  cin>>studentOption;
  if(studentOption==0)
  {
    cout<<"Have a Great Day!"<<endl;
    s.storeData(); //if user does not want to enter data, the DEFAULT CONSTRUCTOR is excecuted 
    exit(0);
    
  }

 while (studentOption!=0 && studentOption!=1) {
   
cout << "INVALID input, please try again!" << endl;
cin >> studentOption; 
  }

cout << "How many student entries are we inputting? " << endl; //prompts user to enter a value 
cin >> numberOfStudents;
student data[numberOfStudents]; //initialzes the amount of entries being inputted into an ARRAY 
  
  for(int i = 0; i < numberOfStudents; i++) {
   data[i].createProfile(); //runs the specific amount of tests that the user says they will input
   }

 }