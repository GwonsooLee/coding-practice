#include <iostream>
#include <vector>
using namespace std;

int N;
int A[10001];
vector<int> G[10001];

pair<int,int> dfs(int node, int parent) {
    int select = A[node], not_select = 0;

    for (auto & x:G[node]) {
        if (x == parent) continue;
        auto child = dfs(x, node);
        select += child.second;
        not_select += max(child.first, child.second);
    }

    return {select, not_select};
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int u, v;
    for (int i = 0; i < N-1; ++i) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto ans = dfs(1, -1);

    cout << max(ans.first, ans.second);
    return 0;
}