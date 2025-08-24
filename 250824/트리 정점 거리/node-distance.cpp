#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000
int N, M, u, v, c;
int dis[MAX_N+1][MAX_N+1];
vector<pair<int,int>> G[MAX_N+1];

void getDist(int start) {
   queue<int> q;
   q.push(start);
   dis[start][start] = 0;
   while(!q.empty()) {
      int node = q.front();
      q.pop();

      for (auto & x:G[node]) {
         if (x.first != node && dis[start][x.first] == -1) {
            dis[start][x.first] = dis[start][node] + x.second;
            q.push(x.first);
         }
      }
   }
}
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   memset(dis, -1, sizeof(dis));
   cin >> N >> M;

   for (int i = 0;i < N-1; ++i) {
      cin >> u >> v >> c;
      G[u].push_back(make_pair(v,c));
      G[v].push_back(make_pair(u,c));
   }
   for (int i = 1; i <= N; ++i) {
      getDist(i);
   }

   for (int i = 0; i < M; ++i) {
      cin >> u >> v;
      cout << dis[u][v] << "\n";
   }

   return 0;
}

