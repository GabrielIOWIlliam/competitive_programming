#include <iostream>

using namespace std;

int mtx[25][25];

int query(int l, int c, int n, int m)
{
  int sum = 0;
  for (int i=1; i<=n; ++i)
  {
    sum += mtx[i][c];
    mtx[i][c] = 0;
  }
  for (int i=1;i<=m;++i)
  {
    sum += mtx[l][i];
    mtx[l][i] = 0;
  }
  return sum;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m,p;
  cin >> n >> m >> p;
  for (int i=1; i<=n; ++i)
  {
    for (int j=1; j<=m;++j)
    {
      cin >> mtx[i][j];
    }
  }
  int enzo = 0, lobo = 0;
  for (int i=1; i<=p; ++i)
  {
    int l,c;
    cin >> l >> c;
    
    int pts = query(l, c, n, m);
    if (i & 1) enzo += pts;
    else lobo += pts;
  }

  if (enzo > lobo) cout << "Enzo";
  else if (lobo > enzo) cout << "Lobo";
  else cout << "Empate";

  cout << endl;
  return 0;
}
