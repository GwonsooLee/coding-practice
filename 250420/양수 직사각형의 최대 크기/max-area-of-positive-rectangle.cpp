#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[21][21];

int func(int x1, int y1, int x2, int y2) {
   int ans = 0;

   for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
         if (A[i][j] <= 0) return -1;
         ans++;
      }
   }
   return ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   cin >> N >> M;

   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         cin >> A[i][j];
      }
   }


   int ans = -1;
   for (int x1 = 0; x1 < N; ++x1) {
      for (int y1 = 0; y1 < M; ++y1) {
         for (int x2 = x1; x2 < N; ++x2) {
            for (int y2 = y1; y2 < M; ++y2) {
               ans = max(ans, func(x1,y1,x2,y2));
            }
         }
      }
   }

   cout << ans << "\n";

   return 0;
}

