#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, h;

const ll MAXN = 123456;

pair<ll, ll> a[MAXN];
ll ps[MAXN];


bool compare(pair<ll, ll> a, ll b) {
    return a.second < b;
}

ll getHeight(ll from, ll to, ll fromIndex) {
    function<bool(pair<ll, ll>, ll)> cmp = compare;

    ll l = lower_bound(a, a + n, pair<ll, ll>({to, -1})) - a;
    ll r = lower_bound(a, a + n, to, cmp) - a;

    //cout << l << ' ' << r << endl;

    ll free = 0;
  //  cout << a[l].first << ' ' << a[r].second << endl;
    free = ps[l] - ps[fromIndex - 1];
        //cout << ps[l] << ' ' << a[l - 1].second << ' ' << ps[from - 1] << endl;

   // cout << free << endl;
    return h - to + from + free;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> h;

    for(ll i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    ps[1] = a[0].second - a[0].first;
    for(ll i = 2; i <= n; i++) {
        ps[i] = ps[i - 1] + a[i - 1].second - a[i - 1].first;
    }
    ll ans = 0;
    for(ll i = 0; i < n; i++) {
        ll x = a[i].first;
        ll l = a[i].first, r = 2e9;
        ll mid;
        while(r - l > 0) {
            mid = l + (r - l) / 2;
            ll xH = getHeight(x, mid, i + 1);
       //     cout << x << ' ' << mid << ' ' << i + 1 << endl;
        //    cout << xH << endl;
            if(xH <= 0) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
       // cout << r << endl;
        ans = max(ans, l - x);
   //     cout << "Ans: " << r - x << endl;
    }

    cout << ans;
	return 0;
}
