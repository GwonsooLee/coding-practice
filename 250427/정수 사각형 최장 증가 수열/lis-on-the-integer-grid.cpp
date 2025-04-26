#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500

int N;
int A[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int dfs(int x, int y) {
   if (dp[x][y] != -1) return dp[x][y];

   int & ans = dp[x][y];
   ans= 1;
   for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx <0 || ny <0 || nx >= N || ny >= N) continue;
      if (A[nx][ny] < A[x][y]) {
         ans = max(ans, dfs(nx, ny) + 1);
      }
   }
   return ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   
   cin >> N;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         cin >> A[i][j];
      }
   }

   int ans = 0;
   memset(dp, -1, sizeof(dp));
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
         if (dp[i][j] == -1) {
            dp[i][j] = dfs(i, j);
            ans = max(ans, dp[i][j]);
         }
      }
   }


   cout << ans << "\n";


   return 0;
}

