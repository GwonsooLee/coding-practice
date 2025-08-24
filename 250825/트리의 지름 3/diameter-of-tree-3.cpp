#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N, u,v,d;
vector<pair<int,int>> G[MAX_N+1];

vector<long long> getDistFromNode(int start) {
   vector<long long> dist(N+1, -1LL);
   dist[start] = 0;
   queue<int> q;
   q.push(start);
   while(!q.empty()) {
      int node = q.front();
      q.pop();
      for(auto &x:G[node]) {
         if (dist[x.first] == -1) {
            dist[x.first] = dist[node] + x.second;
            q.push(x.first);
         }
      }
   }

   return dist;
}

int getFarNode(int start) {
   auto dist = getDistFromNode(start);
   int f = 0, m = 0;
   for (int i = 1; i <= N; ++i) {
      if (m < dist[i]) {
         m = dist[i];
         f = i;
      } 
   }
   return f;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;

   for (int i = 0; i < N-1; ++i) {
      cin >> u >> v >> d;
      G[u].push_back({v,d});
      G[v].push_back({u,d});
   }
   
   int x = getFarNode(1);
   int y = getFarNode(x);

   auto p = getDistFromNode(x);
   auto q = getDistFromNode(y);

   sort(p.rbegin(), p.rend());
   sort(q.rbegin(), q.rend());
   cout << max(p[1], q[1]);

   return 0;
}

