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
   double x1, y1, x2, y2, x3, y3, x4, y4;
   double m1, n1, m2, n2;
   cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
   m1 = min(max(x1, x2), max(x3, x4));
   n1 = min(max(y1, y2), max(y3, y4));
   m2 = max(min(x1, x2), min(x3, x4));
   n2 = max(min(y1, y2), min(y3, y4));
   if(m1 > m2 && n1 > n2) {
       double t = (m1 - m2) * (n1 - n2);
       printf("%.2f", t);
    }
    else
        cout << "0.00" << endl;
    return 0; 
}