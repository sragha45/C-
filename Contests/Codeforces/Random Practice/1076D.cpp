#include <bits/stdc++.h>
using namespace std;


struct triple {
    long long first, second, index;
};

vector<vector<triple> > graph;
long long n, m, k;

const long long INF = 2e18;

int main() {
    cin >> n >> m >> k;
    if(k == 0) {
        cout << 0;
        return 0;
    }
    graph.resize(n + 1, vector<triple> ());
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w, i + 1});
        graph[v].push_back({u, w, i + 1});
    }

    //    dijikstra
    vector<long long> dist(n + 1, INF), ans;
    priority_queue<pair<long long, long long>, 
                   vector<pair<long long, long long> >,
                   greater<pair<long long, long long> > > pq;
    
    pq.push({0, 1});
    dist[1] = 0;

    while(!pq.empty()) {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if(w > dist[u]) continue;
        for(auto x : graph[u]) {
            int v = x.first, wv = x.second, idx = x.index;
            if(dist[u] + wv < dist[v]) {
                dist[v] = dist[u] + wv;
                pq.push({dist[v], v});
            }
        }
    }

    pq.push({0, 1});
    vector<long long> dist2(n + 1, INF);
    dist2[1] = 0;

    while(!pq.empty()) {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if(w > dist2[u]) continue;
        for(auto x: graph[u]) {
            int v = x.first, wv = x.second, idx = x.index;
            if(dist2[u] + wv < dist2[v]) {
                dist2[v] = dist2[u] + wv;
                pq.push({dist2[v], v});
                if(dist[v] == dist2[v]) {
                    ans.push_back(idx);
                    k--;
                    if(k == 0) {
                        goto last;
                    }
                }
            }
        }
    }
    last:
    cout << ans.size() << endl;
    for(auto x: ans) {
        cout << x << ' ';
    }
    cout << endl;

/*
    for(int i = 1; i <= n; i++) {
        cerr << dist[i] << ' ';
    }
    */
}
