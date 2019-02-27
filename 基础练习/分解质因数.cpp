#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 10005;
typedef long long ll;
typedef pair<ll, ll> pll;

void factor(vector<pll> &a, ll n) {
    ll tmp = (ll) ((double)sqrt(n) + 1);
    ll now = n;
    for(int i = 2; i*i <= now; i++) {
        if(now % i == 0) {
            ll x = i, y = 0;
            while(now % i == 0) {
                now /= i;
                y++;
            }
            a.push_back(make_pair(x, y));
        }
    }
    if(now != 1) {
        a.push_back(make_pair(now, 1ll));
    }
}

int main() {
    ll a, b; cin >> a >> b;
    vector<pll> vec;
    for(int i = a; i <= b; i++) {
        vec.clear();
        factor(vec, i);
        cout << i << "=";
        if(vec[0].fi == i) {
            cout << i << endl;
            continue;
        }
        for(int j = 0; j < vec.size(); j++) {
            while(vec[j].se > 0) {
                vec[j].se--;
                cout << vec[j].fi;
                if(vec[j].se == 0 && j == vec.size()-1) cout << endl;
                else cout << "*";
            }
        }
    }
    return 0;
}