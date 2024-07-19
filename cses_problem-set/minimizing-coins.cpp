#include <bits/stdc++.h>

using namespace std;
#define int long long
const int X = 1e6+4; const int N = 103;
int dp[X], coins[N];

int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, x; cin >> n >> x;
  for (int i=0; i<n; ++i) cin >> coins[i];
  
  fill(dp, dp+x+3, INT_MAX);
  dp[0] = 0;

  for (int i=1; i<=x; ++i)
  {
    for (int c=0; c<n; ++c)
    {
        if (coins[c] <= i) dp[i] = min(dp[i], dp[i-coins[c]] + 1);
    }
  }
  cout << ((dp[x] == INT_MAX)?-1:dp[x]) << endl;
  return 0;
}