#include <bits/stdc++.h>
using namespace std;
#define MAX_N 500
int N, Q;
bool vis[(1<<20)+1];

int findLCA(int x, int y) {
   unordered_set<int> tmp;
   while(x > 0) {
      tmp.insert(x);
      x /= 2;
   }

   while(y > 0) {
      if (tmp.find(y) != tmp.end()) return y;
      y /= 2;
   }
   return -1;
}


int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   cin >> N >> Q;

   memset(vis, false, sizeof(vis));
   int curr = 1;
   for (int i = 0; i < Q; ++i) {
      int target;
      cin >> target;

      int lca = findLCA(curr, target);
      // cout << curr << "->" << target << "==>" << lca << "\n";
      int now = curr;
      while(now / 2 >= lca && vis[now/2] == false){
         now /= 2;
      }
      if (now != lca) {
         curr = now;
         cout << curr << "\n";
         continue;
      }

      now = target;
      bool found = false;
      while(now / 2 >= lca) {
         now /= 2;
         if (vis[now]) {
            curr = now;
            found = true;
         }
      }

      if (found) {
         cout << curr << "\n";
         continue;
      } else {
         vis[target] = true;
         curr = target;
         cout << 0 << "\n";
      }
   }


   return 0;
}

