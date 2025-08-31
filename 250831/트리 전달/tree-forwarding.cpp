#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,M,u,v;
vector<int> G[MAX_N+1];
long long dp[MAX_N+1];

void dfs(int node) {
   for (auto & x:G[node]) {
      dp[x] += dp[node];
      dfs(x);
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N >> M;

   memset(dp, 0LL, sizeof(dp));
   for (int i = 1; i <= N; ++i) {
      cin >> u;
      if (u == -1) continue;
      G[u].push_back(i);
   }

   for (int i = 0; i < M; ++i) {
      cin >> u >> v;
      dp[u] += v;
   }

   dfs(1);

   for (int i = 1; i <= N; ++i) {
      cout << dp[i] <<" ";
   }

   return 0;
}

