#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student {
    private:
        int age;
        string first_name;
        string last_name;
        int standard;
    public:
        int get_age(){return age;}
        void set_age(int a){age = a;}
        string get_first_name(){return first_name;}
        void set_first_name(string n){first_name = n;}
        string get_last_name(){return last_name;}
        void set_last_name(string n){last_name = n;}
        int get_standard(){return standard;}
        void set_standard(int s){standard = s;}
        
        string to_string(){
            string student_age, student_standard;
            stringstream ss;
            ss << age;
            ss >> student_age;
            ss.clear();
            ss << standard;
            ss >> student_standard;
            string results = student_age + ","+first_name+","+last_name+","+student_standard;
            return results;
        }
};
int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}