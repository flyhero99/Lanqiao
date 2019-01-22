#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;

const int maxn = 105;

void work(int tot) {
    int h = tot/3600;
    tot -= h*3600;
    int m = tot/60;
    tot -= m*60;
    cout << h << ":" << m << ":" << tot << endl;
    return;
}

int main() {
    int n; scanf("%d", &n); work(n); return 0;
}