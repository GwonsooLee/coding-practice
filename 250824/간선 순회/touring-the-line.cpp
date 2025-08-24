#include <bits/stdc++.h>
using namespace std;
#define MAX_N 50000
int N, D, u,v,d;
vector<pair<int,int>> G[MAX_N+1];

vector<int> getFarNode(int start) {
   vector<int> dist(N+1, -1);
   dist[start] = 0;
   queue<int> q;
   q.push(start);
   while(!q.empty()) {
      int node = q.front();
      q.pop();
      for(auto &x:G[node]) {
         if (dist[x.first] == -1) {
            dist[x.first] = dist[node] + 1;
            q.push(x.first);
         }
      }
   }

   vector<int> ans;
   int f = 0, m = 0;
   for (int i = 1; i <= N; ++i) {
      if (m < dist[i]) {
         ans.clear();
         m = dist[i];
         f = i;
         ans.push_back(i);
      }  else if (m == dist[i]) {
         ans.push_back(i);
      }
   }
   return ans;
}

int getSmallestFarDist(int start) {
   vector<int> dist(N+1, -1);
   vector<int> steps(N+1, -1);
   dist[start] = 0;
   steps[start] = 0;
   queue<int> q;
   q.push(start);
   while(!q.empty()) {
      int node = q.front();
      q.pop();
      for(auto &x:G[node]) {
         if (dist[x.first] == -1) {
            dist[x.first] = dist[node] + x.second;
            steps[x.first] = steps[node] + 1;
            q.push(x.first);
         }
      }
   }
   int f = 0, m = 1e9, s = 0;
   for (int i = 1; i <= N; ++i) {
      if (steps[i] > s) {
         s = steps[i];
         m = dist[i];
         f = i;
      } else if (steps[i] == s && dist[i] < m) {
         m = dist[i];
         f = i;
      }
   }
   return m;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N >> D;

   for (int i = 0; i < N-1; ++i) {
      cin >> u >> v >> d;
      G[u].push_back({v,d});
      G[v].push_back({u,d});
   }
   
   auto p = getFarNode(getFarNode(1)[0]);
   int ans = 1e9;
   for (auto & x:p) {
      ans = min(ans, getSmallestFarDist(x));
   }

   cout << int((ans + D -1) / D) << "\n";
   return 0;
}

