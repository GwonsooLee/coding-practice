#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500
int K;

int L[1<<11], R[1<<11];

int build(vector<int> &A, int l, int r) {
   if (l == r) return A[l];
   int mid = (l + r) / 2;
   int node = A[mid];
   L[node] = build(A, l, mid-1);
   R[node] = build(A, mid+1, r);
   return node;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> K;

   int size = (1<<K) -1;
   vector<int> A(size);
   for (int i = 0; i < size; ++i) {
      cin >> A[i];
   }

   memset(L, -1, sizeof(L));
   memset(R, -1, sizeof(R));
   int root = build(A, 0, size-1);

   queue<int> q;
   q.push(root);
   while(!q.empty()) {
      int s = q.size();
      for (int i = 0; i < s; ++i) {
         int node = q.front();
         q.pop();
         cout << node << " ";
         if (L[node] != -1) q.push(L[node]);
         if (R[node] != -1) q.push(R[node]);
      }
      cout << "\n";
   }

   return 0;
}

