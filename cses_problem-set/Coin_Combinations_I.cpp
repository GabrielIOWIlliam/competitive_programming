#include <bits/stdc++.h>
using namespace std;
#define int long long
const int X = 1e6+4, N = 103, MOD = 1e9 + 7;
int coins[N], ans[X];

int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, x; cin >> n >> x;
  for (int i=0; i<n; ++i) cin >> coins[i];
  ans[0] = 1;
  for (int i=1; i<=x; ++i)   
  {
    for (int c=0; c<n; ++c)
    {
      if (i >= coins[c]) ans[i] = (ans[i] + ans[i - coins[c]]) % MOD;
    }
  }
  cout << ans[x] << endl;
  return 0;
}