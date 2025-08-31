#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,R,Q,u,v;
vector<int> G[MAX_N+1];
int dp[MAX_N+1];

void dfs(int node, int par) {
   if (G[node].size() == 1 && G[node][0] == par) {
      dp[node] = 1;
      return;
   }

   int ans = 1;
   for (auto & x:G[node]){
      if (x != par) {
         dfs(x,node);
         ans += dp[x];
      }
   }
   dp[node] = ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N >> R >> Q;
   for (int i  =0 ; i < N-1; ++i) {
      cin >> u >> v;
      G[u].push_back(v);
      G[v].push_back(u);
   }

   memset(dp, 0, sizeof(dp));
   dfs(R,-1);
   for (int i = 0; i < Q; ++i) {
      cin >> u;
      cout << dp[u] << "\n";
   }

   return 0;
}

