//http://codeforces.com/problemset/problem/1042/A
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
   // freopen("input.txt", "r", stdin);

   int n, m;
   cin >> n >> m;
   int a[n];

   for(int i = 0; i < n; i++) {
        cin >> a[i];
   }

   sort(a, a + n);
   int sum = 0;
   for(int i = 0; i < n and sum < m; i++) {        
        sum += a[n - 1] - a[i];
   }
   if(sum >= m) cout << a[n - 1];
   else {
    
    cout << ceil((double)(m - sum) / n) + a[n - 1];
   }
   cout << ' ' << a[n - 1] + m;
   return 0;
}

