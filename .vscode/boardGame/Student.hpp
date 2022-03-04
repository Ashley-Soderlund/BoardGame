#include <iostream>
#pragma once
using namespace std;

class Student{
    public:
        Student(const string& n="", float g=0.0, int s=0);
        string getName();
        void output(Student& person);
        ~Student();
    private:
        string name;
        float gpa;
        int semester;
};