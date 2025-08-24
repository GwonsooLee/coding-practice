#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000
int N, K, u, v;
vector<int> G[MAX_N+1];
int deg[MAX_N+1];
int parent[MAX_N+1];

void markDegree(int node, int degree) {
   deg[node] = degree;
   for (auto & x:G[node]) {
      markDegree(x, degree+1);
   }
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   memset(deg, 0, sizeof(deg));
   memset(parent, -1, sizeof(parent));

   cin >> N >> K;
   vector<int> A(N);
   for (int i = 0; i < N; ++i) {
      cin >> A[i];
   }

   if (K == A[0]) {
      cout << 0 << "\n";
      return 0;
   }

   queue<int> q;
   q.push(A[0]);
   int i = 1;
   while(i < N) {
      int j = i;
      while(j+1 < N && A[j] +1 == A[j+1]) ++j;
      // register i to j to parent;
      int p = q.front();
      q.pop();
      for (int k = i; k <= j; ++k) {
         q.push(A[k]);
         G[p].push_back(A[k]);
         parent[A[k]] = p;
      }
      i = j+1;
   }

   markDegree(A[0], 0);

   int ans = 0;
   for (int i = 0; i < N; ++i) {
      if (parent[parent[K]] == parent[parent[A[i]]] && parent[A[i]] != parent[K] && deg[A[i]] == deg[K]) {
         ans++;
      }
   }
   cout << ans << "\n";

   return 0;
}

