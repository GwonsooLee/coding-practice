#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,u,v;
vector<int> G[MAX_N+1];

vector<int> getDistFromNode(int start) {
   vector<int> dist(MAX_N+1, -1);
   dist[start] = 0;
   queue<int> q;
   q.push(start);
   while(!q.empty()) {
      int node = q.front();
      q.pop();
      for (auto &x:G[node]) {
         if (dist[x] == -1) {
            dist[x] = dist[node] +1;
            q.push(x);
         }
      }
   }
   return dist;
}


int findFarNode(int start) {
   vector<int> dist = getDistFromNode(start);
   int farNode = -1, maxLen = 0;
   for (int i = 1; i <= N; ++i) {
      if (maxLen < dist[i]) {
         maxLen = dist[i];
         farNode = i;
      }
   }
   return farNode;
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

   int x = findFarNode(1);
   int y = findFarNode(x);

   auto p = getDistFromNode(x);
   auto q = getDistFromNode(y);
   int ans = 1e9;
   for (int i = 1; i <= N; ++i) {
      int t = max(p[i], q[i]);
      ans = min(ans, t);
   }
   cout << ans;

   return 0;
}

