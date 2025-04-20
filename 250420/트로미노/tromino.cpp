#include <bits/stdc++.h>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int M, N;
   cin >> N >> M;
   int A[N][M];
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         cin >> A[i][j];
      }
   }

   int dx[4] = {-1,0,1,0};
   int dy[4] = {0,1,0,-1};


   int ans = 0;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
         if (j + 2 < M) ans = max(ans, A[i][j] + A[i][j+1] + A[i][j+2]);
         if (i + 2 < N) ans = max(ans, A[i][j] + A[i+1][j] + A[i+2][j]);
         for (int k = 0; k < 4; ++k){
            int nx = i + dx[k], ny = j + dy[k];
            if (nx <0 || ny < 0 || nx >= N || ny >= M) continue;
            int kk = (k+1) % 4;
            int nxx = i + dx[kk], nyy = j + dy[kk];
            if (nxx <0 || nyy < 0 || nxx >= N || nyy >= M) continue;
            ans = max(ans, A[i][j] + A[nx][ny] + A[nxx][nyy]);
         }
      }
   }

   cout << ans << "\n";
            

   return 0;
}

