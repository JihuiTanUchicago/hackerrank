#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int size;
    cin >> size;
    vector<int> vec(size);
    for(int i = 0; i < size; i++){
        cin >> vec[i];
    }
    int remove_index;
    cin >> remove_index;
    remove_index -= 1;
    int range_left, range_right;
    cin >> range_left >> range_right;
    range_left -= 1; range_right -= 1;
    vec.erase(vec.begin()+remove_index);
    vec.erase(vec.begin()+range_left, vec.begin()+range_right);
    cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); i++){
        if(i == vec.size() - 1){
            cout << vec[i];
        }else{
           cout << vec[i] << " "; 
        }
    }
    return 0;
}
