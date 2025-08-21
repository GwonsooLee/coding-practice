#include <bits/stdc++.h>
using namespace std;
unordered_map<int,vector<int>> G;
vector<int> p;

void dfs(int node, int parent) {
    if (parent != -1) {
        p[node] = parent;
    }
    for (auto & x:G[node]){
        if (x == parent) continue;
        dfs(x, node);
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }    
    p = vector<int>(N+1, -1);
    dfs(1, -1);

    for (int i = 2; i <= N; ++i) {
        cout << p[i] << "\n";
    }
    return 0;
}