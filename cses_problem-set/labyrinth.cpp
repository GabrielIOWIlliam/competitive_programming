#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
 
using namespace std;
const int N = 1e3 + 4;
vector<pair<int,int>> mov = {{1,0}, {-1,0}, {0,-1}, {0,1}};
vector<char> dir = {'U', 'D', 'R', 'L'};
char mp[N][N];
bool visited[N][N];
pair<int,int> parent[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  
  for (int i=0; i<n+4; ++i)
  {
    for (int j=0; j<m+4; ++j)
      parent[i][j] = {-1, -1};
  }

  pair<int,int> startp = {0,0};
  pair<int,int> endp = {n-1, m-1};
  for (int i=0 ; i<n; ++i) {
    for (int j=0; j<m; ++j) {
      char k;
      cin >> k;
      mp[i][j] = k;
 
      if (k == 'A') 
        startp = make_pair(i,j);
      else if (k == 'B')
        endp = make_pair(i,j);
    }
  }
 
  queue<pair<int,int>> q;
  q.push(startp);
  
  bool flag = false;
  while (!q.empty()) {
    pair<int,int> coord = q.front();
    q.pop();
    visited[coord.first][coord.second] = true;
    for (int i=0; i<4; ++i) {
      int x = mov[i].first + coord.first;
      int y = mov[i].second + coord.second;
      if (x < 0 || y < 0 || x >= n || y >= m || mp[x][y] == '#' || visited[x][y]) continue;
      parent[x][y] = coord;
      q.push(make_pair(x,y));
      if (mp[x][y] == 'B') {
        flag = true;
        goto end_of_loops;
      }
    }
 
  }
  
  end_of_loops:
  if (flag)
    cout << "YES" << '\n';
  else {
    cout << "NO" << '\n';
    return 0;
  }
  int coordX = endp.first;
  int coordY = endp.second;
  string res = "";
  while (parent[coordX][coordY] != make_pair(-1,-1)) {
 
    for (int i=0; i<4; ++i) {
      if (parent[coordX][coordY] == make_pair(coordX + mov[i].first, coordY + mov[i].second)) {
        res += dir[i];
        coordX += mov[i].first;
        coordY += mov[i].second;
        break;
     } 
    }
  }
  cout << res.length() << '\n';
  for (int i=res.length()-1; i>=0; --i) {
    cout << res[i];
  }
  cout << '\n';
  return 0;
}
