#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;

const int maxn = 105;

int n, m;

struct matrix{
    ll a[maxn][maxn];
    matrix(){
        memset(a,0,sizeof(a));
    }
    matrix(int x){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
            a[i][i]=1;
    }
    ll sum(){
        ll ret=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ret+=a[i][j];
        return ret%mod;
    }
    matrix operator+(const matrix&other){
        matrix ret;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    ret.a[i][j]=(ret.a[i][j]+a[i][j]+other.a[i][j])%mod;
        return ret;
    }
    matrix operator*(const matrix&other){
        matrix ret;
        int i,j,k;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                for(k=0;k<n;k++)
                    ret.a[i][j]+=a[i][k]*other.a[k][j],
                    ret.a[i][j]%=mod;
        return ret;
    }
    matrix&operator*=(const matrix&other){*this=*this*other;
        return*this;
    }
    matrix operator^(ll index){
        matrix ret(1);
        matrix base(*this);
        while(index){
            if(index&1)
                ret*=base;
            base*=base;
            index>>=1;
        }
        return ret;
    }
    void print() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                printf("%d%c", a[i][j], j==n-1?'\n':' ');
            }
        }
    }
};

int main() {
    cin >> n >> m;
    matrix aa;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> aa.a[i][j];
    aa = aa^m;
    aa.print();
    return 0;
}