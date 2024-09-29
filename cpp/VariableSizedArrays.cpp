#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int row, query_num;
    cin >> row >> query_num;
    vector<vector<int>> vec(row);
    
    for(int i = 0; i < row; i++){
        int size;
        cin >> size;
        vec[i] = vector<int>(size);
        for(int j = 0; j < size; j++){
            cin >> vec[i][j];
        }  
    }
    
    
    for(int i = 0; i < query_num; i++){
        int r,c;
        cin >> r >> c;
        cout << vec[r][c] << endl;
    }
}
