#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+4;
int dp[N];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  fill(dp, dp + n + 2, N);
  dp[0] = 0; 
  for (int i=1; i<=n; ++i)
  {
    string s = to_string(i);
    for (char c: s)
    {
      int k = c - '0';
      if (i >= k) dp[i] = min(dp[i], dp[i - k] + 1);
    }
  }
  cout << dp[n] << '\n';
  return 0;
}
