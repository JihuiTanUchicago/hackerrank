#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int N; cin >> N;
    vector<int> vec(N);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
    }  
    int Q; cin >> Q;
    for(int i = 0; i < Q; i ++){
        int num; cin >> num;
        int upper_index = distance(vec.begin(), lower_bound(vec.begin(), vec.end(), num));
        if(upper_index != vec.size() && vec[upper_index] == num){
            cout << "Yes " << upper_index + 1 << endl;
        }else{
            cout << "No " << upper_index + 1 << endl;
        }
    }
    return 0;
}
