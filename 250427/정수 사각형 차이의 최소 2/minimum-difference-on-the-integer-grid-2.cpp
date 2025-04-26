#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100

int N;
int A[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int func(int x, int y, int L) {
   if (x < 0 || y < 0 || x >= N || y >= N || A[x][y] > L) return -1e9;

   if (x == N-1 && y == N-1) {
      return A[x][y];
   }

   int maxVal = max(func(x+1, y, L), func(x, y+1, L));
   return min(maxVal, A[x][y]);
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);


   cin >> N;
   for (int i = 0; i < N; ++i) {
      for (int j = 0; j<N; ++j) {
         cin >> A[i][j];
      }
   }

   int ans = 1e9;
   for (int L = 1; L <= 100; ++L) {
      int v = func(0, 0, L);
      ans = min(ans, L - v);
   }

   cout << ans << "\n";


   return 0;
}

