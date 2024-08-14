#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip> 

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int T; cin >> T;
    while(T--) {
        double A; cin >> A;
        double B; cin >> B;
        double C; cin >> C;
        ios_base::fmtflags f( cout.flags() );
        // Process A
        long long A_ = trunc(A);
        cout << left << showbase << hex << A_ << endl;
        string b; stringstream ss;
        // Process B
        cout << right << setw(15) << setfill('_') << showpos << fixed << setprecision(2) << B << endl;
        
        // Process C
        cout << noshowpos << fixed << setprecision(9);
        cout << scientific << uppercase << C << endl;
        
        cout.flags(f);
    }
    return 0;
}
