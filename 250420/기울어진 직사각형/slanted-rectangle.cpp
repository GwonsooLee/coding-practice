#include <bits/stdc++.h>
using namespace std;

int N;
int A[21][21];

bool invalid(int x, int y) {
   return x < 0 || y < 0 || x >= N || y >= N;
}

int func(int x, int y, int w, int h) {
   int ans = 0;

   int dx[4] = {-1,-1,1,1};
   int dy[4] = {1,-1,-1,1};
   int moves[4] = {w,h,w,h};
   for (int d = 0; d < 4; ++d) {
      for (int q = 0; q < moves[d]; ++q) {
         x += dx[d], y += dy[d];
         if (invalid(x,y)) return 0;
         ans += A[x][y];
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
   for(int w = 1; w <= N; ++w) {
      for (int h = 1; h <= N; ++h) {
         for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
               ans = max(ans, func(i, j, w, h));
            }
         }
      }
   }

   cout << ans << "\n";

   return 0;
}

