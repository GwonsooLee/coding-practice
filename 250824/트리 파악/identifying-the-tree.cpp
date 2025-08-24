#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N, u, v;

vector<int> G[MAX_N+1];

int dfs(int node, int parent) {
   if (G[node].size() == 1) return 1;
   int ans = 0;
   for (auto & x:G[node]) {
      if (x != parent) {
         ans += dfs(x, node);
      }
   }
   return ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;

   for (int i = 0; i < N-1; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }

   int tot = dfs(1, 0);

   cout << (tot % 2 == 0 ? 0 : 1) << "\n";

   return 0;
}

