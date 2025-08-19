#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;


class Person {
protected:
    string name;
    int age;
    int cur_id;
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};

class Professor : public Person{
private:
    int publications;
public:
    void getdata() override;
    void putdata() override;
    static int id;
};

class Student: public Person{
private:
    vector<int> marks;
public:
    void getdata() override;
    void putdata() override;
    static int id;
};

int Student::id = 0;
int Professor::id = 0;

void Professor::getdata()
{
    cin >> this->name >> this->age >> this->publications;
    this->cur_id = ++Professor::id;
}

void Professor::putdata()
{
    cout << this->name << " " << this->age 
    << " " << this->publications  << " " << this->cur_id << endl;
}

void Student::getdata()
{
    cin >> this->name >> this->age;
    for (int i=0; i<6; i++){
        int mark;
        cin >> mark;
        marks.push_back(mark);
    }
    this->cur_id = ++Student::id;
}

void Student::putdata()
{
    cout << this->name << " " <<this->age << " " 
    << accumulate(marks.begin(), marks.end(), 0) << " " << this->cur_id << endl;
}

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}