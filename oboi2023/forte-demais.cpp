#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  int e,d; long long sume = 0, sumd = 0, cnt = 0;
  cin >> e >>d;
  
  queue<int> qe; stack<int> stkd;
  for (int i=0; i<e; ++i)
  {
    int a; cin >> a; qe.push(a); sume += a;
  }
  for (int i=0; i<d; ++i)
  {
    int a; cin >> a; stkd.push(a); sumd += a;
  }
  
  while (sume != sumd)
  {
    if (sume > sumd)
    {
      sume -= qe.front(); qe.pop();
    }
    else if (sumd > sume)
    {
      sumd -= stkd.top(); stkd.pop();
    }
    cnt++;
  }

  cout << cnt << endl;
  return 0;
}
