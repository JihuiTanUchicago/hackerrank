#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template<> struct Traits<Color>{
    static string name(int index){
        Color c = static_cast<Color>(index);
        if(c == Color::red){return "red";}
        else if(c == Color::green){return "green";}
        else if(c == Color::orange){return "orange";}
        else{return "unknown";}
    }
};

template<> struct Traits<Fruit>{
    static string name(int index){
        Fruit f = static_cast<Fruit>(index);
        if(f == Fruit::apple){return "apple";}
        else if(f == Fruit::orange){return "orange";}
        else if(f == Fruit::pear){return "pear";}
        else{return "unknown";}
    }
};

int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
