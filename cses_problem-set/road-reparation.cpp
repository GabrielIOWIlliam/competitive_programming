#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
using namespace std;
 
const int MAXN = 3e5;
vector<pair<int,int>> roads[MAXN];
 
 
long long int mst(int n)
{
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  unordered_set<int> vis;
  pq.push({0, 1});
 
  long long int cost = 0;
  while (vis.size() < n)
  {
    if (pq.empty()) return -1;
    pair<int,int> road = pq.top();
    pq.pop();
    
    if (vis.find(road.second) != vis.end())
      continue;
 
    vis.insert(road.second);
    cost += road.first;
 
    for (pair<int,int> r: roads[road.second])
    {
      pq.push(r);
    }
  }
  
  return cost;
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin >> n >> m;
 
  for (int i=0; i<m; ++i)
  {
    int a,b,c;
    cin >> a >> b >> c;
    roads[a].push_back({c, b});
    roads[b].push_back({c, a});
  }
 
  long long int tcost = mst(n);
  if (tcost == -1)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << tcost << endl;
  return 0;
}
