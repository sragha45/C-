#include <bits/stdc++.h>
using namespace std;

int trie[10007][2], nxt = 1;

string to_binary_string(int x) {
    bitset<32> b(x);
    int i = 31;
    while(b[i] == 0 and i >= 0) i--;
    string res;
    for(; i >= 0; i--)
        res += '0' + b[i];
    return res;
}

void build(int x) {
    //string bx = to_binary_string(x);
    int v = 0;

    for(int i = 31; i >= 0; i--) {
        int parity = (((1 << i) & x) != 0);
        if(trie[v][parity] == -1) {
            v = trie[v][parity] = nxt ++;
        }
        else {
            v = trie[v][parity];
        }
    }
}
        
int query(int x) {
    int v = 0;
    int i = 31;
    int parity;
    do {
        parity = (((1 << i) & x) != 0);
//        cout << v << ' ' << parity << endl;
        if(trie[v][!parity] != -1) {
            if(!parity != 0)
                x ^= ((1 << i));
            v = trie[v][!parity];
        }
        else if(trie[v][parity] != -1) {
            if(parity != 0)
                x ^= ((1 << i));
            v = trie[v][parity];
        }
        else{
            break;
        }
        i--;
      }while(i >= 0);
    cout << x << endl;
}   

int main() {
    int n;
    cin >> n;

    memset(trie, -1, sizeof trie);

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        build(x);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        query(x);
    }

/*    for(int i = 0; i < 32; i++) {
        cout << i << ": ";
        for(int j = 0; j < 2; j++) {
            cout << trie[i][j] << " \n"[j == 1];
        }
    }
*/    
}
