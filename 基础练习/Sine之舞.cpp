#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pii pair<int, int>
#define fi first
#define se second
const int maxn = 10005;
typedef long long ll;

// vector<string> ;
int n;

string a(int n) {
    char cnum[10];
    sprintf(cnum, "%d", n);
    string t = "sin(" + string(cnum) + ")";
    for(int i = 2; i <= n; i++) {
        char cnum2[10];
        sprintf(cnum2, "%d", n-i+1);
        string op = (n+i)&1 ? "+" : "-";
        t = "sin(" + string(cnum2) + op + t + ")";
    }
    return t;
}

string s(int n) {
    string res = "";
    char cnum[10];
    sprintf(cnum, "%d", n);
    res = a(1) + "+" + string(cnum);
    for(int i = 2; i <= n; i++) {
        char cnum[10];
        sprintf(cnum, "%d", n-i+1);
        res = "(" + res + ")" + a(i) + "+" + string(cnum);
    }
    return res;
}

int main() {
    cin >> n;
    // cout << a(n) << endl;
    cout << s(n) << endl;
    // if(strcmp(s(n).c_str(), "((sin(1)+3)sin(1–sin(2))+2)sin(1–sin(2+sin(3)))+1")) printf("asasada\n");
    return 0;
}