#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a,v;
  cin >> a >> v;
  
  vector<int> va(a), vv(v);
  for (int i=0; i<a; ++i)
  {
    cin >> va[i];
  }
  for (int i=0; i<v; ++i)
  {
    cin >> vv[i];
  }
  sort(va.begin(), va.end());
  sort(vv.begin(), vv.end());
  if (va[a-1] > vv[v-1])
  {
    cout << (va.end() - upper_bound(va.begin(), va.end(), vv[v-1])) - 1;
  }
  else
  {
    cout << (vv.end() - upper_bound(vv.begin(), vv.end(), va[a-1])) - 1;
  }
  cout << endl;
  return 0;
}
