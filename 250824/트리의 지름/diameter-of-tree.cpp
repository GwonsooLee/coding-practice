#include <bits/stdc++.h>
using namespace std;

int N;
unordered_map<int, vector<pair<int,int>>> G;

pair<int,int> func(int startNode) {    
    vector<int> d(N+1, -1);
    d[startNode] = 0;
    queue<int> q;
    q.push(startNode);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto & x:G[node]) {
            if (d[x.first] == -1) {
               d[x.first] = d[node] + x.second;
               q.push(x.first);
            }
        }
    }

    int farNode = -1, dist = -1;
    for (int i = 1; i <= N; ++i) {
        if (i != startNode && dist < d[i]) {
            dist = d[i];
            farNode = i;
        }
    }
    return {farNode, dist};
}

int main() {
    cin >> N;

    for (int i = 0; i < N-1; ++i) {
        int u, v, d;
        cin >>u>>v>>d;
        G[u].push_back({v,d});
        G[v].push_back({u,d});
    }

    auto p = func(1);
    auto ans = func(p.first);

    cout << ans.second << "\n";
    return 0;
}