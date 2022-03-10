#include <iostream>
#pragma once

class Student{
    public:
        Student(const std::string& n="", float g=0.0, int s=0);
        std::string getName() const;
        float getGPA() const;
        int getSemester() const;
        void setName(std::string valueName);
        void setGPA(float valueGPA);
        void setSemester(int valueSemester);
        void insertionSort();
        //~Student();
        std::string name {};
        float gpa {};
        int semester {};
};
