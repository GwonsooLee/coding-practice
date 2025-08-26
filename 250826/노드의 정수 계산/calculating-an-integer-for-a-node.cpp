#include <bits/stdc++.h>
using namespace std;
#define MAX_N 100000
int N,a,p,t;
int V[MAX_N+1];
vector<int> G[MAX_N+1];

int get(int node) {  
   int ans = V[node];
   for (auto & x:G[node]) {
      int c = get(x);
      if (c > 0) ans += c;
   }
   return ans;
}

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

   memset(V, 0, sizeof(V));

   cin >> N;

   for (int i = 2; i <= N; i++) {
      cin >> t >> a >> p;
      if (t == 0) a *= -1;
      V[i] = a;
      G[p].push_back(i);
   }

   cout << get(1) << "\n";

   return 0;
}

