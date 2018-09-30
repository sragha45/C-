#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


int main() {
    int s, x, n;
    cin >> s >> x >> n;
    map<int, int> obstacles;
    
    vector<int> days;
    for(int i = 0; i < n; i++) {
        int day, distance;
        cin >> day >> distance;
        if(obstacles.find(day) == obstacles.end()) {
            obstacles[day] = distance;
        }   
        else {
            obstacles[day] = max(obstacles[day], distance);
        }
        days.push_back(day);
    }
    sort(days.begin(), days.end());
    int start = 1;
    int current = 0;
    int days_t = 0;
    for(int i = 0; i < n; i++) {
        current += (days[i] - start) * x;
        days_t += days[i] - start;
        if(current >= s) {
            days_t -= (current - s) / x;
            // cout << days_t << ' '  << current << endl;
            break;
        }
        current += obstacles[days[i]];

        if(current >= s) {
            if(current - obstacles[days[i]] <= s) {
                current -= obstacles[days[i]];
                if(current < s) {
                    current += obstacles[days[i]];
                    days_t++;
                }
                // cout << days_t << ' ' << current << endl;
                break;       
            }

        }
        days_t++;
        start = days[i] + 1;
        // cout << days_t << ' ' << current << endl;
    }
    if(current < s) {
        days_t += ceil((double)(s - current) / x);
    }
    cout << days_t;

}
