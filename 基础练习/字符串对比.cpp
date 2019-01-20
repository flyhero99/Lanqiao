#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define HASH 9
const int maxn = 105;
typedef long long ll;

bool equal(string a, string b) {
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    string a, b; cin >> a >> b;
    int ans;
    if(a.length() != b.length()) {
        ans = 1;
    }
    else {
        int flag = 1;
        for(int i = 0; i < a.length(); i++) {
            if(toupper(a[i]) != toupper(b[i])) {
                flag = 0;
                break;
            }
        }
        if(!flag) {
            ans = 4;
        }
        else {
            if(equal(a, b)) ans = 2;
            else ans = 3;
        }
    }
    cout << ans << endl;
    return 0;
}