#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,R,u,v;
vector<int> G[MAX_N+1];
int dp[MAX_N+1];
int C[MAX_N+1];
int ans = 0;

void dfs(int node, int parent, int v) {
   dp[node] = 1;
   for (auto & x:G[node]) {
      if (x == parent) continue;
      dfs(x, node, v+1);
      dp[node] += dp[x];
      C[node] += 1;
   }
   if (C[node] >= 2) {
      int maxVal = 0, minVal = 1e9;
      for (auto & x:G[node]) {
         if (x == parent) continue;
         maxVal = max(maxVal, dp[x]);
         minVal = min(minVal, dp[x]);
      }
      
      if (v > 0) {
         maxVal = max(maxVal, v);
         minVal = min(minVal, v);
      }
      ans = maxVal - minVal;
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   memset(dp, 0, sizeof(dp));
   memset(C, 0, sizeof(C));
   cin >> N >> R;
   for (int i = 0; i < N-1; ++i) {
      cin >> u>>v;
      G[u].push_back(v);
      G[v].push_back(u);
   }

   dfs(R, -1, 0);
   cout << ans << "\n";

   return 0;
}

