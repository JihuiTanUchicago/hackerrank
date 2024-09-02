#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
    public:
        string name;
        int age;
        virtual void getdata()  = 0;
        virtual void putdata() const = 0;
};
class Professor : public Person{
    private:
        int publications;
        static int counter;
        int cur_id;
    public:
        Professor(): cur_id(counter){
            counter++;
        }
        void getdata() override{
            string name; int age, publications;
            cin >> name >> age >> publications;
            this->name = name;
            this->age = age;
            this->publications = publications;
        }
        void putdata() const override{
            cout << name << " " << age << " " << publications << " " << cur_id << endl;
        }
};
int Professor :: counter = 1;
class Student : public Person{
    private:
        vector<int>marks;
        int sum;
        static int counter;
        int cur_id;
    public:
        Student() : marks(6), cur_id(counter), sum(0){
            counter++;
        }
        void getdata() override{
            cin >> name >> age;
            for(int i = 0; i < marks.size(); i++){
                cin >> marks[i];
                sum += marks[i];
            }
        }
        void putdata() const override{
            cout << name << " " << age << " " << sum << " " << cur_id << endl;
        }
};
int Student :: counter = 1;
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
