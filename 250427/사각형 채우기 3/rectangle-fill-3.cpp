#include <bits/stdc++.h>
using namespace std;


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int N;
   int MOD = 1000000007;
   cin >> N;
   long long dp[N+1];
   memset(dp, 0, sizeof(dp));

   dp[0] = 1, dp[1] = 2;
   for (int i = 2; i <= N; ++i) {
      dp[i] = ((2 * dp[i-1]) % MOD + (3*dp[i-2]) % MOD) % MOD;
      for (int j = 3; j <= i; ++j) {
         dp[i] += 2 * dp[i-j];
         dp[i] %= MOD;
      }
   }

   cout << dp[N];

   return 0;
}

