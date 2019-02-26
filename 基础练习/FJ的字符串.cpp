#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 10005;
typedef long long ll;

int main() {
    vector<string> vec;
    vec.push_back("A");
    for(int i = 1; i < 26; i++) {
        string t = vec[i-1];
        char c = 'A'+i;
        t = t + c;
        t = t + vec[i-1];
        // if(i < 10) cout << t << endl;
        vec.push_back(t);
    }
    int n; cin >> n;
    cout << vec[n-1] << endl;
    // for(int i = 0; i < 26; i++)
        // cout << vec[i] << endl;
    return 0;
}