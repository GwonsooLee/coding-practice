#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500
int N;
char L[26], R[26];

void preorder(char c) {
   if (c == '.') return;
   cout << c;
   preorder(L[c-'A']);
   preorder(R[c-'A']);
}

void inorder(char c) {
   if (c == '.') return;
   inorder(L[c-'A']);
   cout << c;
   inorder(R[c-'A']);
}

void postorder(char c) {
   if (c == '.') return;
   postorder(L[c-'A']);
   postorder(R[c-'A']);
   cout << c;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N;

   char a,b,c;
   for (int i = 0; i < N; ++i) {
      cin >> a >> b >> c;
      L[a-'A'] = b;
      R[a-'A'] = c;
   }

   preorder('A');
   cout << "\n";
   inorder('A');
   cout << "\n";
   postorder('A');

   return 0;
}

