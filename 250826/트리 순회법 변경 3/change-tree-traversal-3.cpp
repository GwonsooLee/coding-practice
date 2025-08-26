#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int inorder[MAX_N];
int postorder[MAX_N];
int N;
int L[MAX_N+1], R[MAX_N];

int find(int target, int s, int e) {
   for (int i = s; i <= e; ++i) {
      if (inorder[i] == target) return i;
   }
   return -1;
}

int build(int post_s, int post_e, int in_s , int in_e) {
   if (post_s > post_e) return -1;
   if (post_s == post_e) return postorder[post_e];

   int root = postorder[post_e];
   int pivot = find(root, in_s, in_e);
   int left_size = pivot - in_s;
   int right_size = in_e - pivot;
   L[root] = build(post_s, post_s + left_size-1, in_s, pivot-1);
   R[root] = build(post_s+left_size, post_e-1, pivot+1, in_e);
   return root;
}

void preorder(int node) {
   if (node == -1) return;
   cout << node << " ";
   preorder(L[node]);
   preorder(R[node]);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;
   for (int i = 0; i < N; ++i) {
      cin >> inorder[i];
   }
   for (int i = 0; i < N; ++i) {
      cin >> postorder[i];
   }

   memset(L, -1, sizeof(L));
   memset(R, -1, sizeof(R));

   int root = build(0, N-1, 0, N-1);
   preorder(root);

   return 0;
}

