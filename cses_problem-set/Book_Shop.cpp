#include <bits/stdc++.h>

#define int long long
using namespace std;
const int X = 1e6+4, N = 1e3 + 4;
int dp[X], pages[N], prices[N];
int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, x; cin >> n >> x;

  for (int i=0; i<n; ++i) cin >> prices[i];
  for (int i=0; i<n; ++i) cin >> pages[i];
  dp[0] = 0;
  for (int i=0; i<n; ++i)
  {
    for (int j=x; j>0; --j)
    {
      if (prices[i] > j) continue;

      dp[j] = max(dp[j], dp[j - prices[i]] + pages[i]);
    }
  }
  cout << dp[x] << '\n';
  return 0;
}