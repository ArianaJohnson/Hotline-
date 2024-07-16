/* ------ CLASS HEADER AND FUNCTION DECLATATION ------- */

#include <string>
#include <iostream>
using namespace std;
/* header guard */
#ifndef CHECKIN_H 
#define CHECKIN_H

class student { 

private: //public member variables 

string name; // student name
int idNumber; //student id number
int rating;//students mental health on scale from 1-10
string description; //student desciption of health
bool contact;//true or false if they want us to contact them

public: //private member variables

string getName() ;
int getID();
int getRating();
string getDescription();
void storeData(string n, int id, int r, string d); //paramaterized constructor 
student createProfile();
void  exportInfo(student&);
void getContact(bool);
void displayMessage(student&);

void storeData() { //default constructor
  cout << "Thank you!" << endl;
}
~student() { //deconstructor
cout << "New Data Entry:" << endl;
   }

};

#endif


 
