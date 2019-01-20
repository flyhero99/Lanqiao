#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
#define HASH 9
const int maxn = 105;
typedef long long ll;

int lena, lenb, lenc, a[maxn]={0}, b[maxn]={0}, c[maxn];

void init(string in, int aa[]) {
    int len = in.length();
    for(int i = 0; i < len; i++) {
        aa[len-i-1] = in[i]-'0';
    }
}

void add() {
    int len = max(lena, lenb), r=0;
    for(int i = 0; i < len; i++) {
        c[i] += a[i]+b[i];
        if(c[i] > 9) {
            c[i+1]++;
            c[i] -= 10;
        }
    }
    if(c[len] != 0) lenc = len+1;
    else lenc = len;
}

int main() {
    string stra, strb; cin >> stra >> strb;
    init(stra, a); init(strb, b);
    lena = stra.length(); lenb = strb.length();
    add();
    for(int i = lenc-1; i >= 0; i--) printf("%d", c[i]); puts("");
    return 0;
}