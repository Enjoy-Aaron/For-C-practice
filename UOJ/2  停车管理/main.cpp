#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

typedef struct Event {
    int time;
    int type;
    int car_id;

    bool operator <(const Event &order) const{
        if (time != order.time) return time>order.time;
        return type>order.type;
    }
}Event;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> arrive(m);
    vector<int> service(m);
    vector<int> in_time(m);
    vector<int> leave_time(m);
    vector<int> status(m,0);
    priority_queue<Event> pq;
    for (int i=0;i<m;++i) {
        cin >> arrive[i] >> service[i];
        pq.push({arrive[i], 1, i});
    }
    stack<int> park;
    queue<int> wait;
    while (!pq.empty()) {
        Event e = pq.top(); pq.pop();
        int car = e.car_id, cur_time = e.time;
        if (e.type == 1) {
            if (park.size() < n) {
                status[car] = 2;
                park.push(car);
                int finish_time = cur_time + service[car];
                pq.push({finish_time, 0, car});
            }
            else {
                status[car] = 1;
                wait.push(car);
            }
        }
        else {
            status[car] = 3;
            while (!park.empty() && status[park.top()] == 3) {
                int leave_car = park.top();
                park.pop();
                status[leave_car] = 4;
                leave_time[leave_car] = cur_time;
            }
            while (park.size() < n && !wait.empty()) {
                int wait_car = wait.front();
                wait.pop();
                status[wait_car] = 2;
                park.push(wait_car);
                int finish_time = cur_time + service[wait_car];
                pq.push({finish_time, 0, wait_car});
            }
        }
    }
    for (int i=0; i<m; ++i) {
        cout << leave_time[i] - arrive[i] << endl;
    }
    return 0;
}
