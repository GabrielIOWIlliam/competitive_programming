#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+4;
const int MOD = 1e9 + 7;
#define int long long

int dp[N][N]; 
char grid[N][N];

int32_t main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    
    int n; 
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    if (grid[n-1][n-1] == '*') {cout << 0 << endl;return 0;}
    
    dp[n-1][n-1] = 1;
    for (int i = n-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
            if (grid[i][j] == '*') 
                dp[i][j] = 0; 
            else 
            {
                if (i < n-1) dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
                if (j < n-1) dp[i][j] = (dp[i][j] + dp[i][j+1]) % MOD;
            }
        }
    }

    cout << dp[0][0] << endl;
    return 0;
}