#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,u,v;
vector<int> G[MAX_N+1];
int cnt[MAX_N+1];

pair<int,int> dfs(int node, int parent) {
   int curr_cnt = cnt[node];
   int curr_ops = 0;
   for (auto & x:G[node]) {
      if (x == parent) continue;
      auto p = dfs(x, node);
      curr_cnt += p.first;
      curr_ops += p.second;
   }

   if (curr_cnt != 1) {
      curr_ops += abs(curr_cnt - 1);
   }
   curr_cnt--;
   return {curr_cnt, curr_ops};
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N;
   for (int i = 1; i <= N; ++i) {
      cin >> cnt[i];
   }

   for (int i = 0; i < N-1; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }

   auto ans = dfs(1, -1);

   cout << ans.second << "\n";

   return 0;
}

