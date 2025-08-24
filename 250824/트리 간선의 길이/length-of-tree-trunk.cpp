#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000
int N,u,v,d;
vector<pair<int,int>> G[MAX_N+1];

pair<int,int> find(int start) {
   vector<int> dist(N+1, -1);
   dist[start] = 0;
   queue<int> q;
   q.push(start);
   while(!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto &x:G[node]) {
         if (dist[x.first] != -1) continue;
         dist[x.first] = dist[node] + x.second;
         q.push(x.first);
      }
   }

   int farNode = 0, farLen = 0;
   for (int i = 1; i <= N; ++i) {
      if (farLen < dist[i]) {
         farLen = dist[i];
         farNode = i;
      }
   }

   return {farNode, farLen};
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;

   int s = 0;
   for (int i = 0; i < N-1; ++i) {
      cin >> u >> v >> d;
      G[u].push_back({v,d});
      G[v].push_back({u,d});
      s = u;
   }

   auto p = find(s);
   auto ans = find(p.first);

   cout << ans.second << "\n";

   return 0;
}

