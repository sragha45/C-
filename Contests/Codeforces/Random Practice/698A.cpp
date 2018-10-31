#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    pair<int, int> task[n];
    task[0].first = (a[0] == 0 or a[0] == 2);
    task[0].second = (a[0] == 1 or a[0] == 0);
    for(int i = 1; i < n; i++) {
        if(a[i] == 3) {
            task[i].first = task[i - 1].second;
            task[i].second = task[i - 1].first;
        }
        if(a[i] == 2) {
            task[i].second = task[i - 1].first;
            task[i].first = task[i - 1].second + 1;
        }
        if(a[i] == 1) {
            task[i].first = task[i - 1].second;
            task[i].second = task[i - 1].first + 1;
        }
        if(a[i] == 0) {
            task[i].first = task[i - 1].first + 1;
            task[i].second = task[i - 1].second + 1;
        }
     //   task[i].first = min(task[i].first, task[i].second);
     //   task[i].second = min(task[i].second, task[i].first);
    }
    for(int i = 0; i < n; i++) {
        cout << task[i].first << ' ' << task[i].second << endl;
    }
  
    cout << min(task[n - 1].first, task[n - 1].second) << endl;
    return 0;
}


