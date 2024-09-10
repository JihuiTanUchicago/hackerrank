#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshop{
  int start_time;
  int duration;
  int end_time;  
};
struct Available_Workshops{
    int n;
    vector<Workshop> vec;
};

Available_Workshops* initialize(int start_time[], int duration[], int n){
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    aw->vec.resize(n);
    for(int i = 0; i < aw->n; i++){
        aw->vec[i] = {start_time[i], duration[i], start_time[i] + duration[i]};
    }
    return aw;
}
int CalculateMaxWorkshops(Available_Workshops* ptr){
    sort(ptr->vec.begin(), ptr->vec.end(), [](const Workshop& a, const Workshop& b){
        if(a.end_time == b.end_time){
            return a.start_time < b.start_time;
        }
        return a.end_time < b.end_time;
    });
    int count = 1;
    int end_time = ptr->vec[0].end_time;
    for(int i = 1; i < ptr->n; i++){
        if(ptr->vec[i].start_time >= end_time){
            count++;
            end_time = ptr->vec[i].end_time;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
