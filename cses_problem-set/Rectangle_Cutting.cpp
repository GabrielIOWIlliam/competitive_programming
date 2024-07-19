#include <bits/stdc++.h>

using namespace std;
const int N = 503;
#define int long long


int dp[N][N];

int32_t main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int a,b; cin >> a >> b;

  for (int i=0; i<N; ++i)
  {
    for (int j=0; j<N; ++j)
      dp[i][j] = INT_MAX;
  }  
  for (int i=1; i<N; ++i) dp[i][i] = 0;

  for (int i=1; i<=501; ++i)
  {
    for (int j=1; j<=501; ++j)
    {
      if (i!=j)
      {
        for (int k=1; k<j; ++k)
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        for (int k=1; k<i; ++k)
          dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
      }
    
    }
  }
  cout << dp[a][b] << endl;
  return 0;
}