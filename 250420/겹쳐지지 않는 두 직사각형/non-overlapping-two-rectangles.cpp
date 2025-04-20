#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[6][6];
bool vis[6][6];

int func(int x1, int y1, int x2, int y2) {
   int ans = 0;
   for (int i = x1; i <= x2; ++i) {
      for (int j = y1; j <= y2; ++j) {
         if (vis[i][j]) return -1e9;
         vis[i][j] = true;
         ans+= A[i][j];
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


   int ans = INT_MIN;
   for (int x1 = 0; x1 < N; ++x1) {
      for (int y1 = 0; y1 < M; ++y1) {
         for (int x2 = x1; x2 < N; ++x2) {
            for (int y2 = y1; y2 < M; ++y2) {
               for (int x3 = 0; x3 < N; ++x3) {
                  for (int y3 = 0; y3 < M; ++y3) {
                     for (int x4 = x3; x4 < N; ++x4) {
                        for (int y4 = y3; y4 < M; ++y4) {
                           memset(vis, false,sizeof(vis));
                           int values = func(x1,y1,x2,y2);
                           values += func(x3,y3,x4,y4);
                           ans = max(ans, values);
                        }
                     }
                  }
               }
            }
         }
      }
   }

   cout << ans << "\n";

   return 0;
}

