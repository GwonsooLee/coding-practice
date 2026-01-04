#include <bits/stdc++.h>
using namespace std;

int N;
int A[30001];
vector<int> G[30001];
int ans = INT_MIN;

int dfs(int node, int parent) {

    int max_length = 0;
    int sum_length = 0;
    for (auto & x:G[node] ){
        if (x == parent) continue;

        int child = dfs(x, node);
        max_length = max(max_length, child);
        sum_length += max(0, child);
    }

    ans = max(ans, sum_length + A[node]);

    return A[node] + max_length;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    int u, v;
    for (int i = 0; i < N-1; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    dfs(1, -1);
    
    cout << ans << "\n";

    return 0;
}