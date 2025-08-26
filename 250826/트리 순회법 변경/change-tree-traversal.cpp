#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000000
int preorder[MAX_N];
int N;
int L[MAX_N+1], R[MAX_N];

int build(int s, int e) {
   if (s > e) return -1;
   if (s == e) return preorder[s];

   int root = preorder[s];
   int right_start = s+1;
   while(right_start <= e && preorder[right_start] < root) right_start++;
   L[root] = build(s+1, right_start-1);
   R[root] = build(right_start, e);
   return root;
}

void postorder(int node) {
   if (node == -1) return;
   postorder(L[node]);
   postorder(R[node]);
   cout << node << "\n";
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      cin >> preorder[i];
   }

   memset(L, -1, sizeof(L));
   memset(R, -1, sizeof(R));

   int root = build(0, N-1);
   postorder(root);

   return 0;
}

