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
    for(int i=0; i < size; i++){
        int num;
        cin >> num;
        vec[i] = num;
    }
    sort(vec.begin(), vec.end());
    for(int i=0; i < size; i++){
        if(i == size-1){
            cout << vec[i];
        }else{
            cout << vec[i] << " ";
        }
    }
    return 0;
}
