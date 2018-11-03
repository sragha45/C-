#include <bits/stdc++.h>
using namespace std;

int to_int(int start, int end, string s) {
    stringstream ss;
    for(int i = start; i <= end; i++) {
        ss << s[i];
    }
    int res = 0;
    ss >> res;
    return res;
}

bool f(int start, int end, int f1, int f2, string s) {
    int target_sum = 0;

    if(f1 != -1 and f2 != -1) {
        target_sum = f1 + f2;
    }
    cout << f1 << ' ' << f2 << ' ';
    for(int i = start; i < end; i++) {
        if(f1 == -1) {
            cout << endl;
            f1 = to_int(start, i, s);
            f(i + 1, end, f1, f2, s);
        }
        else if(f2 == -1) {
            cout << endl;
            f2 = to_int(start, i, s);
            f(i + 1, end, f1, f2, s);
        }
        else {
            cout << to_int(start, i, s);
            cout << endl;
            if(f1 + f2 == to_int(start, i, s)) {
                f(i + 1, end, f2, to_int(start, i, s), s); 
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
//    cout << to_int(0, 3, s);
    f(0, s.length(), -1, -1, s);
}
