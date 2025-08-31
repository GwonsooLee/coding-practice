#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,u,v;
vector<int> G[MAX_N+1];
int dp[MAX_N+1][2];

void dfs(int node, int parent) {
   if (G[node].size() == 1 && G[node][0] == parent) {
      dp[node][1] = 1;
      dp[node][0] = 0;
      return;
   }

   int all_min = 0;
   int all_excluded = 0;
   int min_included = 1e9;
   int y = -1;
   for (auto &x:G[node]) {
      if (x == parent) continue;
      dfs(x, node);
      all_min += min(dp[x][0], dp[x][1]);
      all_excluded += dp[x][0];
      if (dp[x][1] < min_included) {
         min_included = dp[x][1];
         y = x;
      }
   }

   dp[node][1] = all_min+1;
   dp[node][0] = all_min;
   if (all_min == all_excluded) {
      dp[node][0] = all_min + dp[y][1] - dp[y][0];
   }
}


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   memset(dp, 0x23, sizeof(dp));
   cin >> N;

   for (int i =0; i < N-1; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }

   dfs(1,-1);

   cout << min(dp[1][0], dp[1][0]) << "\n";

   return 0;
}

