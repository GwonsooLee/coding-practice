#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[21][21];

int func(int x, int y, int k) {

   int gold = 0;
   for (int i = x-k, l = y, cnt = 1; i <= x; ++i, l--, cnt+=2) {
      if (i < 0 || i >= N) continue;
      for (int j = 0; j < cnt; ++j) {
         if (l+j < 0 || l+j >= N) continue;
         if (A[i][l+j] == 1) gold++;
      }
   }

   for (int i = x + k, l = y, cnt = 1; i > x; --i, --l, cnt += 2) {
      if (i < 0 || i >= N) continue;
      for (int j = 0; j < cnt; ++j) {
         if (l+j < 0 || l+j >= N) continue;
         if (A[i][l+j] == 1) gold++;
      }
   }  

   if (gold *M >= k*k + (k+1) * (k+1)) {
      return gold;
   }

   return 0;
}


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   
   cin >> N >> M;

   
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         cin >> A[i][j];
      }
   }

   int ans = 0;
   for (int k = 1; k <= N; ++k) {
      for (int i = 0; i < N; ++i) {
         for (int j = 0; j < N; ++j) {
            ans = max(ans, func(i, j, k));
         }
      }
   }

   cout << ans << "\n";

   return 0;
}

