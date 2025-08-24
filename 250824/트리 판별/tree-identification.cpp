#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
int N; 
bool vis[MAX_N+1];
int in[MAX_N+1];
unordered_map<int,vector<int>> G;

void dfs(int node) {
   vis[node] = true;
   for (auto &x:G[node]) {
      dfs(x);
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   memset(in, 0, sizeof(in));
   memset(vis, false, sizeof(vis));

   cin >> N;
   set<int> nodes;
   for (int i = 0; i < N; ++i) {
      int u, v;
      cin >> u >> v;
      nodes.insert(u);
      nodes.insert(v);
      G[u].push_back(v);
      in[v]++;
   }

   int root = 0, rootCnt = 0;
   for (auto & node:nodes) {
      if (in[node] == 0) {
         root = node;
         rootCnt++;
      }
   }

   if (rootCnt > 1 || nodes.size() != N+1) {
      cout << 0 << "\n";
      return 0;
   }

   dfs(root);

   for (auto & node:nodes) {
      if (vis[node] == false) {
         cout << 0 << "\n";
         return 0;
      }
   }

   cout << 1 << "\n";

   return 0;
}

