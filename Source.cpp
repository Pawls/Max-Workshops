#define watch(x) cout << (#x) << " is " << (x) << endl;
#include<iostream>
#include<vector>
#include <algorithm>
#include <iterator>
using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop {
    int start_time, duration, end_time;
};
struct Available_Workshops {
    int n;
    vector<Workshop> arr;
    Available_Workshops(int size) { n = size; }
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* ptr = new Available_Workshops(n);
    for (int i = 0; i < n; i++) {
        Workshop temp;
        ptr->arr.push_back(temp);
        ptr->arr[i].start_time = start_time[i];
        ptr->arr[i].duration = duration[i];
        ptr->arr[i].end_time = start_time[i] + duration[i];
    }
    return ptr;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    vector<Workshop> v(ptr->arr.begin(), ptr->arr.end());
    sort(v.begin(), v.end(), [](Workshop a, Workshop b){return a.end_time < b.end_time; });
    vector<Workshop>::iterator left_itr = v.begin();
    vector<Workshop>::iterator right_itr = v.begin();
    right_itr++;
    while(right_itr != v.end()) {
        if (left_itr->end_time > right_itr->start_time) {
            right_itr = v.erase(right_itr);
        }
        else {
            left_itr++;
            right_itr++;
        }
    }
    return v.size();
}
/*Returns the maximum number of workshops the student can attend—without overlap. The next workshop cannot be attended until the previous workshop ends.*/

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    system("Pause");
    return 0;
}
