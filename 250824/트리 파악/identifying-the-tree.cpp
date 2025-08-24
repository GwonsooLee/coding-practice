#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N, u, v;

vector<int> G[MAX_N+1];

long long tot = 0LL;
void dfs(int node, int parent, int depth) {
   if (G[node].size() == 1 && parent != -1) {
      tot += depth;
      return;
   }
   for (auto & x:G[node]) {
      if (x != parent) {
         dfs(x, node, depth + 1);
      }
   }
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

   dfs(1, -1, 0);

   cout << (tot % 2 != 0) << "\n";

   return 0;
}

