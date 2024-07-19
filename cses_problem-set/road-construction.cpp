#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
class DSU {
public:
    vector<int> parent, rank, size;
    int largestComponentSize;
 
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        largestComponentSize = 1;
 
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }
 
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
 
    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
 
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                size[rootY] = 0;
                largestComponentSize = max(largestComponentSize, size[rootX]);
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
                size[rootX] = 0;
                largestComponentSize = max(largestComponentSize, size[rootY]);
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                size[rootY] = 0;
                rank[rootX]++;
                largestComponentSize = max(largestComponentSize, size[rootX]);
            }
            return true;
        }
        return false;
    }
};
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
 
    DSU dsu(n);
    int components = n;
 
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
 
        if (dsu.unite(a, b)) {
            components--;
        }
 
        cout << components << " " << dsu.largestComponentSize << "\n";
    }
 
    return 0;
}
