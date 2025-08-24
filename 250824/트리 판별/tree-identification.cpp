#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
int N; 

int find(vector<int> & parent,int x) {
   if (parent[x] == -1) return x;
   return parent[x] = find(parent, parent[x]);
}

void unite(vector<int> & parent, int x, int y) {
   int X = find(parent, x);
   int Y = find(parent, y);
   parent[X] = Y;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N;
   vector<pair<int,int>> edges(N);
   set<int> nodes;
   for (int i = 0; i < N; ++i) {
      cin >> edges[i].first >> edges[i].second;
      nodes.insert(edges[i].first);
      nodes.insert(edges[i].second);
   }

   int totalNodes = nodes.size();
   vector<int> parent(MAX_N+1, -1);

   int u, v;
   for (auto &edge:edges) {
      tie(u, v) = edge;
      if (find(parent, u) != find(parent, v)) {
         unite(parent, u, v);
      }
   }
   int rootCnt = 0;
   for (int i = 1; i <= MAX_N; ++i) {
      if (nodes.find(i) != nodes.end() && parent[i] == -1) rootCnt++;
   }
   if (rootCnt != 1 || N != totalNodes -1) {
      cout << 0 << "\n";
   } else {
      cout << 1 << "\n";
   }
   return 0;
}

