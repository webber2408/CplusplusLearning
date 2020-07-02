#include<bits/stdc++.h>
using namespace std;

class Person{
    private:
        string name;
        int age;
    
    public:
        Person(string name, int age): name{name}, age{age}{
            //Base parameterized constructor initialised using memeber initializer list
        }
        void getName(){
            cout<<"Name: "<<name<<endl;
        }
        void getAge(){
            cout<<"Age: "<<age<<endl;
        }
};

class Employee: private Person{ //Default inheritance type is private
    private:
        int employeeID;
    public:
        Employee(string name, int age, int id) : Person(name, age){  //Derived parameterized constructor
            employeeID = id;
        }
        void getEmployeeDetails(){
            getName();
            getAge();
            cout<<"Employee ID: "<<employeeID<<endl;
        }
};

int main(){
    Employee* e = new Employee("John", 24, 14298);
    e->getEmployeeDetails();
    return 0;
}

/*
Output:

Name: John
Age: 24
Employee ID: 14298
*/
