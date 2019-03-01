#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 10005;
typedef long long ll;
typedef pair<ll, ll> pll;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int last = n-1, cnt = 0;
    bool odd = false;
    for(int i = 0; i < last; i++) {
        for(int j = last; j >= i; j--) {
            if(i == j) { // 没找到
                if(n % 2 == 0 || odd) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                else {
                    odd = true;
                    cnt += n/2 - i;
                }
            }
            else if(s[i] == s[j]) {
                for(int k = j; k < last; k++) {
                    swap(s[k], s[k+1]);
                    cnt++;
                }
                last--;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}