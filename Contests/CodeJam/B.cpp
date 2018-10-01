#include<stdio.h>  
#include <bits/stdc++.h>
#include<stdlib.h>

using namespace std;

const int INF = 1e9;

int graph[12][12], n;

vector<double> ans;

// Generate all possible combinations and compute the average distance
// Time complexity is pretty dirty

void go(int cur, vector<bool> choice) {
    if(cur == n + 1) {
        double total = 0;
        for(int i = 1; i <= n; i++) {
            int minimum_dist = INF;     
            for(int j = 1; j <= n; j++) {
                if(choice[i] != choice[j]) {
                    minimum_dist = min(minimum_dist, graph[i][j]);
                }
            }
            if(minimum_dist != INF)
                total += minimum_dist;
            else
                return;
        }
       // cout << total << endl;
        // cout << (double)total / n << endl;
        ans.push_back((double)total / n);
        return;
    }
    go(cur + 1, choice);
    choice[cur] = true;
    go(cur + 1, choice);
    choice[cur] = false; 
}

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
}

int solve() {
    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            graph[i][j] = INF;
        }
    }
    int e;
    cin >> n >> e;
    for(int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; 
    }
    floyd();
    vector<bool> choice(n + 1, false);
    // for(int i = 0; i < 12; i++) {
    //     for(int j = 0; j < 12; j++) {
    //         if(graph[i][j] == INF) {
    //             cout << "I";
    //         }
    //         else {
    //             cout << graph[i][j];
    //         }
    //         cout << ' ';
            // cout << (graph[i][j] == INF ? ("I") : graph[i][j]) << ' ';
    //     }
    //     cout << endl;
    // }
    go(1, choice);
    sort(ans.begin(), ans.end());
    int res = 1;
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i] == ans[i - 1]) {
            res++;
        }
        else break;
    }
    return res;
}


int main() {
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        ans.clear();
        cout << "Case #" << i << ": " << solve() << endl;
    }
    // cout << (int)'a';
}
