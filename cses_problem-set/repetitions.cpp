#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  string s; cin >> s;
  int cnt = 1, max_cnt = -1;
  for (int i=1; i<s.length(); ++i)
  {
    if (s[i] == s[i-1]) cnt++;
    else { max_cnt = max(max_cnt, cnt); cnt = 1; }
  }
  max_cnt = max(max_cnt, cnt); 
  cout << max_cnt << endl;
  return 0;
}
