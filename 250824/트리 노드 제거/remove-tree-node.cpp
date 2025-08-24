#include <bits/stdc++.h>
using namespace std;
#define MAX_N 300000
int N; 

unordered_map<int,vector<int>> G;

int dfs(int node, int removed) {

   if (node == removed) return 0;

   if (G[node].size() == 0 || G[node].size() == 1 && G[node][0] == removed) return 1;

   int ans = 0;
   for (auto & x:G[node]) {
      ans += dfs(x, removed);
   }
   return ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N;
   vector<int>parent(N);
   int rootNode = -1;
   for (int i = 0; i < N; ++i) {
      cin >> parent[i];
      G[parent[i]].push_back(i);
      if (parent[i] == -1) {
         rootNode = i;
      }
   }
   int x;
   cin >> x;
   cout << dfs(rootNode, x) << "\n";

   return 0;
}

