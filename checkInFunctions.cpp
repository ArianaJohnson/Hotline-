#include "checkIn.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

/* ------------------------------- GETTERS - this will display the data in the varaible of the student class when called-------------------------------------------*/

string student:: getName() {
return name;
  }

int student :: getID()  {
return idNumber;
}
  
int student :: getRating()  {
return rating;
}

string student :: getDescription() {
return description;
}
/* storeData function stores the public variables into private members to be called in the get function */
void student ::  storeData(string n, int id, int r, string d) {
name = n; //declares name variable
idNumber = id; //decalres ID number
rating = r; //declares emotion ratng 
description = d; //declare descirption of emotion
}

/* createProfile Function - will create the users profile, promptting the user to input the variables of their name, id number, rating, and any extra information the user wants the people reading the information to know */

student student :: createProfile() {
string n, d; //n= mane, d= descrption
int id, r;//id= id, r= rating
student s; // student class s

/* user is prompted to enter the data that pertains to their information and feeling */

  cin.ignore();

cout << "Enter your name please" << endl;
getline(cin, n);


cout << "What is your ID number?" << endl;
cin >>  id;

cout << "How are you doing on a scale of 1 - 10, one being sad, ten being great." << endl;
cin >> r;
cin.ignore();

cout << "Please give a brief description on how you are feeling" << endl;
getline(cin, d);
cout<< "" << endl;
cout << "" << endl;

s.storeData(n,id,r,d); //this function stores the data into the storeData constructor
s.exportInfo(s); //this function will export the data in the student class 

return s;
  }

/* this functions export the information stored in the student class PASSED BY REFERENCE and exports it to the studentData file */
void student::  exportInfo(student &s) { 
int contactAnswer; //will give console the answer in which the getContact function will be called 
bool contact; //if the contactAnswer is "1" , the boolean variable contact will be set to true and the test will run
ofstream studentData;
studentData.open("studentData.txt" ,ios_base::app); //opens the file and is appended so that the information is accumulated
  
/* Calls the getter function to display values to the file */
studentData << "Student name: " << s.getName() << endl;
studentData << "ID number:" << s.getID() << endl;
studentData << "Rating " << s.getRating()<<  endl;
studentData<< "DESCRTIPTION: " << s.getDescription() << endl;
s.displayMessage(s);
studentData<< " " << endl;
studentData << " -----NEXT ENTRY-----" << endl;

/* Prompts user to enter whether or not they want to leave general information for them to contact them regarding how they are feeling*/
cout << " Press 1 if you would like to leave your contact information for someone to reach out to you, press any other key to continue your entry." << endl;

 cin >> contactAnswer;
  if (contactAnswer == 1)  {
  /*if they want to be contact, the contact varaible is set to true,is PASSED BY VARIABLE to the getContact function will run based on the answer given as true or false by the user. */
  contact = true;
  s.getContact(contact); //calls the getContact function if true 
}
  else {
    return 0;
  }
}

/* This function will collect the users contact information and export it to the pleaseContact file */
void student :: getContact(bool a) {

/* initialize variables*/ 
string name , description, phone; //string variables that the user will input to be stored in the pleaseContact file

 /* User is prompted to enter any contact information for someone to contact them */
cout << "Thank you for reaching out, please tell us your name once more" << endl;
cin >> name;
cout << "What is your phone number?" << endl;
cin >> phone;
cout << "Is there anything else you want to tell us?" << endl;
getline(cin,description);
cin.ignore();

  string contact[3][2] = {{"-----Name-----", name}, {"-----Phone:-----",phone}, {"-----Extra Info:----- ",description}}; //information is stored into a double array and exported to a file in a DOUBLE ARRAY 
  int l = 1;
  
    /* Opens file to store into the pleaseContact file */
    ofstream file;
    file.open("pleaseContact.txt", ios_base :: app);
  
   for (int i = 0; i <= 2; i++)
    {
      int j= 0;
        {
          file << "!!!!!!!!!!!!!!!! PLEASE CONTACT !!!!!!!!!!!!!!!! " << endl;
          file << contact[i][j] << contact[i][j+1]<<endl;
          j++;
         }    
    }
  
file <<  "" << endl;
cout << "Thank you, someone will be contacting you shortly. You got this! - " << endl;
  }

/*displayMessage function will display a mesage based on the student answer given in the RATING function */

void student :: displayMessage(student &s) {

   switch(s.getRating())  {
   case 1: {
        cout<<setw(10)<< s.getName() << ", Things will start to look up, you can do         this!"<<":)"<<endl;
        break;
            }
     
    case 2: {
         cout<<setw(10)<<s.getName()<<", We're so proud of you for reaching out"             <<":)" <<endl;
         break;
            }
     
    case 3: {
         cout<<setw(10)<<s.getName()<<", You're amazing, keep up the hard work"              <<":)"<<endl;
          break;
            }
  
    case 4: {
         cout<<setw(10)<<s.getName()<<", Might not be the best day, but we believe           in you!"<<":)"<<endl;
         break;
           }
     
    case 5: {
         cout<<setw(10)<<s.getName()<<", We know things will start to look up for            you!"<<":)"<<endl;
         break;
            }
    
    case 6: {
         cout<<setw(10)<<s.getName()<<", You got this!"<<":)"<<endl;
         break;
             }
    
    case 7: {
         cout<<setw(10)<<s.getName()<<", Today will only get better!"<<":)"<<endl;
         break;
             }
    
    case 8: {
         cout<<setw(10)<<s.getName()<<", We hope you have a fabulous rest of your day!"<<":)"<<endl;
         break;
             }
     
    case 9: {
         cout<<setw(10)<<s.getName()<<", Live everyday to the fullest!"<<":)"<<endl;
         break;
             }
    
    case 10: {
        cout<<setw(10)<<s.getName()<<", We're glad your having an amazing day!"             <<":)"<<endl;
        break;
             }
   
    default :
             {
       cout<<s.getName()<<", Have a great day!"<<endl;
       break;
       }
  
    }
  }







  


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
