#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<Workshop> vW;
};

Available_Workshops * initialize(int* start_time, int* duration, int n)
{
    Available_Workshops * p = new Available_Workshops();
    p->n = n;
    for (int i = 0; i < n; i++){
        Workshop ws;
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = start_time[i] + duration[i];
        p->vW.push_back(ws);
    }
    return p;
}

bool comp(Workshop w1, Workshop w2)
{
    return w2.start_time > w1.start_time;
}

// workshops not overlapping
// we can attend a workshop if its start time is greater than or equal to the last end time
int CalculateMaxWorkshops(Available_Workshops* ptr){
    vector<Workshop> vW = ptr->vW;
    int n = ptr->n;

    // sort the workshops by their end time
    sort(vW.begin(), vW.end(), [](Workshop w1, Workshop w2) {
        return w1.end_time < w2.end_time;
    });

    int count = 0;
    int last_end_time = -1;

    for (int i = 0; i < n; i++) {
        if (vW[i].start_time >= last_end_time) {
            count++;
            last_end_time = vW[i].end_time;
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
