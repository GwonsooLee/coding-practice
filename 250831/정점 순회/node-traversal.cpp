#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,S,D,u,v;
vector<int> G[MAX_N+1];
int dp[MAX_N+1];
int depth[MAX_N+1];

void countMaxDepth(int node, int parent) {
   depth[node] = 0;
   for (auto &x:G[node]) {
      if (x == parent) continue;
      countMaxDepth(x, node);
      depth[node] = max(depth[node], depth[x] + 1);
   }
}

pair<bool,int> dfs(int node, int parent) {
   if (depth[node] == D) return {true, 0};

   int target_nodes = 0;
   int tot_dis = 0;
   for (auto & x:G[node]) {
      if (x == parent) continue;
      auto p = dfs(x, node);
      target_nodes += p.first;
      tot_dis += p.second;
   }

   tot_dis += target_nodes * 2;
   if (tot_dis > 0) {
      return {true, tot_dis};
   }
   return {false, 0};
}


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N >> S >> D;
   memset(dp, 0, sizeof(dp));
   memset(depth, 0 , sizeof(depth));
   for (int i = 0; i < N-1; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }

   countMaxDepth(S, -1);
   auto ans = dfs(S, -1);

   cout << ans.second << "\n";

   return 0;
}

