#include <bits/stdc++.h>

const int N = 104, X = 1e5+3;
using namespace std;
bool dp[N][X]; int coins[N];

int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  for (int i=0; i<n; ++i) cin >> coins[i];
  dp[0][0] = true;

  for (int i=1;i<N; ++i)
  {
    for (int j=0; j<X; ++j)
    {
      dp[i][j] = dp[i-1][j];
      if (j >= coins[i-1] && dp[i-1][j - coins[i-1]]) dp[i][j] = true;
    }
  }
  vector<int> ans;
  for (int i=1; i<X; ++i)
  {
    if (dp[n][i]) ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (int i: ans) cout << i << ' '; cout << endl;
  return 0;
}