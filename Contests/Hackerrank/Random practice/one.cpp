#include <bits/stdc++.h>

using namespace std;

#define LOCAL

string to_string(string s) {
      return '"' + s + '"';
}

string to_string(const char* s) {
      return to_string((string) s);
}

string to_string(bool b) {
      return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
      return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
      bool first = true;
        string res = "{";
          for (const auto &x : v) {
                  if (!first) {
                            res += ", ";
                                }
                      first = false;
                          res += to_string(x);
                            }
            res += "}";
              return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
      cerr << " " << to_string(H);
        debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
    string s = "kjflds";
    vector<int> a = {1, 2, 3, 4};
    debug(a);
}
