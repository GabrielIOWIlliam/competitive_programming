#include <iostream>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  long long sum = 0, n; cin >> n;
  for (int i=0; i<n-1; ++i)
  {
    int a; cin >> a; sum += a;
  }
  cout << ((1+n)*n/2LL - sum) << endl;
  return 0; 
}
