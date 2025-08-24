#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500
int N,M,u,v;
int parent[MAX_N+1];
int edges[MAX_N+1];
int nodes[MAX_N+1];

int find(int x) {
   if (parent[x] == -1) return x;
   return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
   int X = find(x), Y = find(y);
   parent[X] = Y;
   edges[Y] += edges[X] + 1;
   nodes[Y] += nodes[X];
}


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N >> M;
   memset(parent, -1, sizeof(parent));
   memset(edges, 0, sizeof(edges));
   for (int i = 1; i <= N; ++i) nodes[i] = 1;

   for (int i = 0; i < M; ++i) {
      cin >> u >> v;

      int X = find(u);
      int Y = find(v);
      if (X == Y) {
         edges[X]++;
      } else {
         unite(X, Y);
      }
   }

   int ans = 0;
   for (int i = 1; i <= N; ++i) {
      if (parent[i] == -1 && edges[i] + 1 == nodes[i]) {
         ans++;
      }
   }

   cout << ans << "\n";

   return 0;
}

