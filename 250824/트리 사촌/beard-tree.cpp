#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000
int N, K, u, v;
int childCnt[MAX_N+1], deg[MAX_N+1], parents[MAX_N+1];
unordered_map<int, int> degCnt;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   memset(childCnt, 0, sizeof(childCnt));
   memset(deg, -1, sizeof(deg));
   memset(parents, -1, sizeof(parents));

   cin >> N >> K;
   vector<int> A(N);
   for (int i = 0; i < N; ++i) {
      cin >> A[i];
   }

   queue<int> q;
   q.push(A[0]);
   deg[A[0]] = 0;
   int i = 1;
   while(i < N) {
      int j = i;
      while(j+1 < N && A[j] +1 == A[j+1]) ++j;
      // register i to j to parent;
      int p = q.front();
      q.pop();
      int d = deg[p]+1;
      for (int k = i; k <= j; ++k) {
         q.push(A[k]);
         parents[A[k]] = p;
         deg[A[k]] = d;
         degCnt[d]++;
      }
      i = j+1;
   }

   int ans = degCnt[deg[K]];
   int kth_parent = parents[K];
   for (int i = 0; i < N; ++i) {
      if (parents[A[i]] == kth_parent) ans--;
   }

   cout << ans << "\n";

   return 0;
}

