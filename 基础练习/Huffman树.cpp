#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define HASH 9
const int maxn = 105;
typedef long long ll;

int main() {
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    for(int i = 1; i <= n; i++) {
        int x; cin >> x; q.push(x);
    }
    int sum = 0;
    while(q.size() > 1) {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        sum += x+y;
        q.push(x+y);
    }
    cout << sum << endl;
    return 0;
}