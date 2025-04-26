#include <bits/stdc++.h>
using namespace std;
#define MAX_N 20
#define MOD 1000000007

long long dp[MAX_N+1];

long long func(int N) {
   if (N <= 1) return 1;

   if (dp[N] != -1) return dp[N];

   int ans = 0;
   for (int i = 1; i <= N; ++i) {
      ans += func(i-1) * func(N-i);
   }
   return dp[N] = ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   int N;
   cin >> N;

   memset(dp, -1, sizeof(dp));
   
   cout << func(N) << "\n";

   return 0;
}

