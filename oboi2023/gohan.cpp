#include <iostream>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int n; cin >> n;
  
  int n1 = 0, n2 = 0;
  for (int i=0; i<n; ++i)
  { 
    int a,b;
    cin >> a >> b;
    n1 += a; n2 += b;
  }
  n1 /= n; n2 /= n;

  if (n1 > n2)
  {
    cout << ":0 <-X- Gohan e Feijao" << endl;
  }
  else if (n2 > n1)
    cout << ":0 <- Gohan e Feijao" << endl;
  else
    cout << "Impasse" << endl;
  return 0;
}
