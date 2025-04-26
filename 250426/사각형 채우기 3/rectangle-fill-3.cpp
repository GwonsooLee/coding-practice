#include <bits/stdc++.h>
using namespace std;


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int N;
   int MOD = 1000000007;
   cin >> N;
   long long d[N+1][3];
   memset(d, 0LL, sizeof(d));

   d[0][0] = 1;
   for (int i = 1; i <= N; ++i) {
      d[i][0] += (2 * d[i-1][0]) % MOD;
      d[i][0] %= MOD;
      d[i][0] += d[i-1][1];
      d[i][0] %= MOD;
      d[i][0] += d[i-1][2];
      d[i][0] %= MOD;
      if (i > 1) {
         d[i][0] += d[i-2][0] % MOD;
         d[i][0] %= MOD;
      }

      d[i][1] += d[i-1][0] + d[i-1][2];
      d[i][1] %= MOD;

      d[i][2] += d[i-1][0] + d[i-1][1];
   }

   cout << d[N][0] << "\n";

   return 0;
}

