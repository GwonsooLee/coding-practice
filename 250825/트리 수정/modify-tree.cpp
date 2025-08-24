#include <bits/stdc++.h>
using namespace std;
#define MAX_N 2000
int N, u,v,d;
set<pair<int,int>> G[MAX_N+1];

pair<long long,long long> getFarInfoFromNode(int start) {
   vector<long long> dist(N, -1LL);
   queue<int> q;
   q.push(start);
   dist[start] = 0LL;
   while(!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto & x:G[node]) {
         if (dist[x.first] == -1LL) {
            dist[x.first] = dist[node] + x.second;
            q.push(x.first);
         }
      }
   }

   long long f = -1, m = -1;
   for (int i = 0; i < N; ++i) {
      if (m < dist[i]) {
         m = dist[i];
         f = i;
      }
   }
   return {f, m};
}

long long getMaxDistFromNode(int start) {
   return getFarInfoFromNode(start).second;
}

long long getDiameter(int start) {
   auto x = getFarInfoFromNode(start);
   return getMaxDistFromNode(x.first);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;
   vector<tuple<int,int,int>> edges(N-1);

   for (int i = 0; i < N-1; ++i) {
      cin >> u >> v >> d;
      G[u].insert({v,d});
      G[v].insert({u,d});
      edges[i] = make_tuple(u,v,d);
   }

   long long ans = 0LL;
   for (int i = 0; i < N-1; ++i) {
      tie(u, v, d) = edges[i];
      G[u].erase({v, d});
      G[v].erase({u, d});

      long long a = getDiameter(u);
      long long b = getDiameter(v);
      long long aa = getMaxDistFromNode(u);
      long long bb = getMaxDistFromNode(v);

      ans = max(ans, max(a + bb + d, b + aa + d));

      G[u].insert({v,d});
      G[v].insert({u,d});
   }

   cout << ans << "\n";


   return 0;
}

