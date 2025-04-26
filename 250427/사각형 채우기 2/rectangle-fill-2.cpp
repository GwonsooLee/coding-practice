#include <bits/stdc++.h>
using namespace std;
#define MAX_N 1000
#define MOD 10007

long long dp[MAX_N+1];

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int N;
   cin >> N;

   dp[0] = 1;
   dp[1] = 1;

   for (int i = 2; i <= N; ++i) {
      dp[i] = ((dp[i-1] % MOD) + (2 * dp[i-2]) % MOD) % MOD;
   }

   cout << dp[N];

   return 0;
}

