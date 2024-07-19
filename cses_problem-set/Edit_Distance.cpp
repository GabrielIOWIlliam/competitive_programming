#include <bits/stdc++.h>

const int M = 8000;
using namespace std;
int dp[M][M];
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string a,b; cin >> a >> b; int n = a.length(), m = b.length();
  for (int i=0; i<=n;++i) dp[i][0] = i;
  for (int i=0; i<=m; ++i) dp[0][i] = i;

  for (int i=1; i<=n; ++i)
  {
    for (int j=1; j<=m; ++j)
    {
      if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
      else dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
    }
  }
  cout << dp[n][m] << endl;
  return 0;
}