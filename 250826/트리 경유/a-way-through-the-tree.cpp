#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500
int N, Q;
bool vis[(1<<20)+1];


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N >> Q;

   memset(vis, false, sizeof(vis));
   for (int i = 0; i < Q; ++i) {
      int target;
      cin >> target;
      int ans = 0;
      int now = target;
      while(now > 0) {
         if (vis[now]) {
            ans = now;
         }
         now /= 2;
      }
      cout << ans << "\n";

      if (ans == 0) {
         vis[target] = true;
      }
   }


   return 0;
}

