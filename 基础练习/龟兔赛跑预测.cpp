#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;

const int maxn = 105;

int main() {
    int v1, v2, t, s, l;
    cin >> v1 >> v2 >> t >> s >> l;
    int sr = 0, st = 0;
    int flag1 = 0, flag2 = 0, i;
    for(i = 0; !(flag1||flag2); ) {
        if(sr >= l && st >= l) { flag1 = 1; flag2 = 1; break; }
        if(sr >= l) { flag1 = 1; break; }
        if(st >= l) { flag2 = 1; break; }
        sr += v1;
        st += v2;
        i++;
        // cout << i << ' ' << sr << ' ' << st << endl;
        if(sr >= l && st >= l) { flag1 = 1; flag2 = 1; break; }
        if(sr >= l) { flag1 = 1; break; }
        if(st >= l) { flag2 = 1; break; }
        if(sr - st >= t) {
            for(int j = 0; j < s; j++) {
                if(st >= l) { flag2 = 1; break; }
                st += v2; i++;
                if(st >= l) { flag2 = 1; break; }
            }
        }
        if(sr >= l && st >= l) { flag1 = 1; flag2 = 1; break; }
        if(sr >= l) { flag1 = 1; break; }
        if(st >= l) { flag2 = 1; break; }
        
    }
    if(flag1 && flag2) cout << "D\n" << i << endl;
    else if(flag1 && !flag2) cout << "R\n" << i << endl;
    else if(!flag1 && flag2) cout << "T\n" << i << endl;
    return 0;
}