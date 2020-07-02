#include<bits/stdc++.h>
using namespace std;

class Student{
    private:
        string name;
        int id;

    public:
        void setStudentDetails(string n, int num){
            name = n;
            id = num;
        }
        void getStudentName(){
            cout<<"Student Name: "<<name<<endl;
        }
        void getStudentID(){
            cout<<"Student ID: "<<id<<endl;
        }
};

class Theory: public virtual Student{
    public:
        string subjectName;
        int score;

        void setTheoryScores(string subName, int marks){
            subjectName = subName;
            score = marks;
        }
        void getTheoryResults(){
            cout<<"----------Theory---------"<<endl;
            getStudentName();
            cout<<"Subject Name: "<<subjectName<<" => Marks: "<<score<<endl;
        }
};

class Practical: virtual public Student{
    public:
        string subjectName;
        int score;

        void setPracticalScores(string subName, int marks){
            subjectName = subName;
            score = marks;
        }
        void getPracticalResults(){
            cout<<"----------Practical---------"<<endl;
            getStudentName();
            cout<<"Subject Name: "<<subjectName<<" => Marks: "<<score<<endl;
        }
};

class ReportCard: public Theory, public Practical{
    private:
        int totalMarks;

    public:
        void setTotalMarks(){
            totalMarks = Theory::score + Practical::score;
        }
        void getResult(){
            getStudentName();
            getStudentID();
            getTheoryResults();
            getPracticalResults();
        }
};

int main(){
    ReportCard r;
    r.setStudentDetails("John Wick", 12428);
    r.setTheoryScores("Chemistry", 98);
    r.setPracticalScores("Chem Lab", 96);
    r.setTotalMarks();
    r.getResult();

    return 0;
}
/*
Output: 

Student Name: John Wick
Student ID: 12428
----------Theory---------
Student Name: John Wick
Subject Name: Chemistry => Marks: 98
----------Practical---------
Student Name: John Wick
Subject Name: Chem Lab => Marks: 96
*/