#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+3;
int a[N], n;

int solve()
{
  vector<int> dp;
  for (int i=0; i<n; ++i) 
  {
    int num = a[i];    
    auto it = lower_bound(dp.begin(), dp.end(), num);
    if (it != dp.end()) *it = num;
    else dp.push_back(num);   
  }
  return dp.size();
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;  
    for (int i=0; i<n; ++i) cin >> a[i];
    int ans = solve();
    cout << ans << endl;
    return 0;
}