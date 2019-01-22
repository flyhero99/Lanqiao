#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

string a[100] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nighteen", "twenty",
                "twenty"};


int main() {
    a[30] = "thirty"; a[40] = "forty", a[50] = "fifty";
    int h, m; scanf("%d %d", &h, &m);
    if(m == 0) {
        if(0 <= h && h <= 9) cout << a[h] << " o'clock" << endl;
        else {
            int shi = h - h%10, ge = h%10;
            cout << a[shi] << ' ' << a[ge] << " o'clock" << endl;
        }
    }
    else {
        if(0 <= h && h <= 20) cout << a[h] << ' ';
        else {
            int shi = h - h%10, ge = h%10;
            cout << a[shi] << ' ' << a[ge] << ' ';
            // printf("%s %s \n", a[shi], a[ge]);
        }
        if(0 <= m && m <= 20) {
            cout << a[m] << endl;
        }
        else {
            int shi = m - m%10, ge = m%10;
            cout << a[shi] << ' ' << a[ge] << endl;
            // printf("%s %s \n", a[shi], a[ge]);
        }
    }
    return 0;
}