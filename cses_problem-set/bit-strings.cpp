#include <iostream>
using namespace std;
#define ll long long
ll MOD = 1e9 + 7;
ll power(ll base, ll expo) {
    ll ans = 1;
    while(expo) {
        if(expo & 1LL) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        expo >>= 1LL;
    }
    return ans;
}

int main() {
    ll n; cin >> n;
    cout << power(2LL, n) << endl;
    return 0;
}
