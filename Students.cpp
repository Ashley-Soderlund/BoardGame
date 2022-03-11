#include <iostream>
#include "Students.hpp"

Student::Student(const std::string& n, float g, int s): name(n), gpa(g), semester(s){}                  //constructor

std::string Student::getName() const {return name;}                      //gets the name parameter of Student object
float Student::getGPA() const {return gpa;}                         //gets the gpa parameter of Student object
int Student::getSemester() const {return semester;}                 //gets the semester parameter of Student object

void Student::setName(std::string valueName){                            //sets the name value of Student object
    name = valueName;
}

void Student::setGPA(float valueGPA){                               //sets the gpa value of Student object
    gpa = valueGPA;
}

void Student::setSemester(int valueSemester){                       //sets the semester value of Student object
    semester = valueSemester;
}

//void Student::insertionSort(const GameEntry& players){              Attempted in separate program, unable to impliment here
    //if players[i].getGPA() 

//}



//int i = 1;
  //  while(i<v.size()){
    //    int j=i;
      //  while(j>0 && v[j-i] > v[j]){
        //    swap(v[j], v[j-1]);
          //  j -= 1;
        //}
        //i += 1;
    //}
    


//Student::~Student(){
  //  delete[] &name, gpa, semester;
//}
