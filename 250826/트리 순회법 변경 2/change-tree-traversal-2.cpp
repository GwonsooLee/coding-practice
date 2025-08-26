#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int inorder[MAX_N];
int preorder[MAX_N];
int N;
int L[MAX_N+1], R[MAX_N];

int find(int target, int s, int e) {
   for (int i = s; i <= e; ++i) {
      if (inorder[i] == target) return i;
   }
   return -1;
}

int build(int pre_s, int pre_e, int in_s , int in_e) {
   if (pre_s > pre_e) return -1;
   if (pre_s == pre_e) return preorder[pre_s];

   int root = preorder[pre_s];
   int pivot = find(root, in_s, in_e);
   int left_size = pivot - in_s;
   int right_size = in_e - pivot;
   L[root] = build(pre_s+1, pre_s + left_size, in_s, pivot-1);
   R[root] = build(pre_s+left_size+1, pre_e, pivot+1, in_e);
   return root;
}

void postorder(int node) {
   if (node == -1) return;
   postorder(L[node]);
   postorder(R[node]);
   cout << node << " ";
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      cin >> preorder[i];
   }
   for (int i = 0; i < N; ++i) {
      cin >> inorder[i];
   }

   memset(L, -1, sizeof(L));
   memset(R, -1, sizeof(R));

   int root = build(0, N-1, 0, N-1);
   postorder(root);

   return 0;
}

