#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int M, N;
   cin >> N >> M;
   int A[N][N];
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         cin >> A[i][j];
      }
   }

   int ans = 0;
   for (int i = 0; i < N; ++i) {
      int cnt = 1;
      bool found = false;
      for (int j = 1; j < N; ++j) {
         if (A[i][j] == A[i][j-1])cnt++;
         else cnt = 1;
         if (cnt == M) {
            found = true;
            break;
         }
      }
      if (found)ans++;
   }
   for (int i = 0; i < N; ++i) {
      int cnt = 1;
      bool found = false;
      for (int j = 1; j < N; ++j) {
         if (A[j][i] == A[j-1][i])cnt++;
         else cnt = 1;
         if (cnt == M) {
            found = true;
            break;
         }
      }
      if (found)ans++;
   }

   cout << ans << "\n";

   return 0;
}

