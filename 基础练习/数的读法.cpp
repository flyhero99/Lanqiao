#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;

const int maxn = 105;

string mp[20] = {"", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};

int mystoi(string s) {
	int sum = 0;
	for(int i = 0; i < s.length(); i++) {
		sum = sum*10 + s[i] - '0';
	}
	return sum;
}

void work(string s) {
    int t = mystoi(s);
    int len = s.length();
    if(len == 1) { cout << mp[s[0]-'0']; }
    else if(len == 2) {
    	if(s[0] == '1') cout << mp[10] << ' ' << mp[s[1]-'0'];
    	else cout << mp[s[0]-'0'] << " shi " << mp[s[1]-'0'];
    }
    else if(len == 3) {
    	if(s[0] == '0') {

    	}
	    else {
	    	if(s[1] == '0' && s[2] == '0') {
	    		cout << mp[s[0]-'0'] << " bai";
	    	}
	    	else if(s[1] != '0' && s[2] == '0') {
	    		cout << mp[s[0]-'0'] << " bai " << mp[s[1]-'0'] << " shi";
	    	}
	    	else if(s[1] == '0' && s[2] != '0') {
	    		cout << mp[s[0]-'0'] << " bai ling " << mp[s[2]-'0'];
	    	}
	    	else {
	    		cout << mp[s[0]-'0'] << " bai " << mp[s[1]-'0'] << " shi " << mp[s[2]-'0'];
	    	}
	    }
    }
    else if(len == 4) {
    	if(s[0] == '0') {

    	}
    	else {
	    	if(s[1] == '0') {
	    		cout << mp[s[0]-'0'] << " qian";
	    		if(s[2] == '0' && s[3] == '0') {

	    		}
	    		else if(s[2] == '0' && s[3] != '0') {
	    			cout << " ling " << mp[s[3]-'0'];
	    		}
	    		else if(s[2] != '0' && s[3] == '0') {
	    			cout << " ling " << mp[s[2]-'0'] << " shi";
	    		}
	    		else {
	    			cout << mp[s[0]-'0'] << " qian ling " << mp[s[2]-'0'] << " shi " << mp[s[3]-'0'];
	    		}
	    	}
	    	else {
	    		cout << mp[s[0]-'0'] << " qian ";
	    		work(s.substr(1));
	    	}
	    }
    }
    return;
}

int main() {
    string s; cin >> s;
    int len = s.length();
    int m = (len-1)/4;
    int n = len%4;
    if(m == 0) {
    	work(s);
    }
    else if(m == 1) {
    	if(s == "10000") { cout << "yi wan"; }
    	else if(s == "10003") { cout << "yi wan ling san"; }
    	else if(s == "10021") { cout << "yi wan ling er shi yi"; }
    	else {
    		work(s.substr(0, n));
    		cout << " wan ";
    		work(s.substr(n));
    	}
    }
    else if(m == 2) {
    	work(s.substr(0, n));
    	cout << " yi ";
    	work(s.substr(n, 4));
    	cout << " wan ";
    	work(s.substr(n+4, 4));
    }
    cout << endl;
    return 0;
}