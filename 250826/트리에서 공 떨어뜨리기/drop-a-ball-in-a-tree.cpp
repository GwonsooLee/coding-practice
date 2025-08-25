#include <bits/stdc++.h>
using namespace std;
#define MAX_N 200000
long long N, K;
int L[MAX_N+1], R[MAX_N+1];

int search(int node, long long k) {
   if (L[node] == -1 && R[node] == -1) return node;
   long long done = k-1;
   long long next = done / 2 + 1;
   if (done % 2 ==0) {
      return search(L[node], next);
   }
   return search(R[node], next);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N;
   for (int i = 1; i <= N; ++i) {
      cin >> L[i] >> R[i];
   }

   cin >> K;

   cout << search(1, K);


   return 0;
}

