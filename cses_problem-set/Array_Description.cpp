#include <bits/stdc++.h>

using namespace std;
#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 4, M = 102;
int dp[N][M], arr[N];

int32_t main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(0);

  int n, m; 
  cin >> n >> m;
  for (int i = 0; i < n; ++i) 
    cin >> arr[i];

  if (arr[0] == 0) {
    for (int i = 1; i <= m; ++i) 
      dp[0][i] = 1;
  } else {
    dp[0][arr[0]] = 1;
  }

  for (int i = 1; i < n; ++i) {
    if (arr[i]) { 
      dp[i][arr[i]] = ((arr[i] > 1 ? dp[i-1][arr[i]-1] : 0) 
                    + dp[i-1][arr[i]] 
                    + (arr[i] < m ? dp[i-1][arr[i]+1] : 0)) % MOD;
    } else {
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = ((j > 1 ? dp[i-1][j-1] : 0) 
                  + dp[i-1][j]
                  + (j < m ? dp[i-1][j+1] : 0)) % MOD;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; ++i) {
    ans = (ans + dp[n-1][i]) % MOD;
  }
  cout << ans << endl;
  return 0;
}
