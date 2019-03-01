#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 10;

int n, ans = 0, c = 0;
int a[maxn][maxn];
int res1[3][maxn<<1], res2[3][maxn<<1]; // 分别记录黑、白皇后的放置情况
// cur表示递归dfs每行，然后每次执行中for(j)表示遍历每列。每次摆放一个之后，这一列（res[0][j]表示第j列）、
// 这个元素的左对角线（res[1][cur+j]，即res[1][0,2,4,6]表示左对角线）、这个元素的右对角线（res[2][n+cur-j]，
// 即res[2][1,3,5,7]表示右对角线）。solve1先搜索白皇后，搜索到一个解之后调用solve2继续搜索黑皇后。

void solve2(int cur) {
	if(cur == n) {
		c++;
		// cout << "solve2" << endl;
		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < n; j++) {
		// 		cout << a[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		// cout << "solve2 end" << endl;
		return;
	}
	for(int j = 0; j < n; j++) {
		if(a[cur][j] && !res2[0][j] && !res2[1][cur+j] && !res2[2][n+cur-j]) {
			a[cur][j] = 0;
			res2[0][j] = 1; res2[1][cur+j] = 1; res2[2][n+cur-j] = 1;
			solve2(cur+1);
			a[cur][j] = 1;
			res2[0][j] = 0; res2[1][cur+j] = 0; res2[2][n+cur-j] = 0; // 回溯
		}
	}
	return;
}

void solve1(int cur) {
	// 每次白皇后搜到一组可行解后，去找对应的黑皇后的情况数c，最终这一组状态下的可行解数为1*c，加到总的解数中。
	if(cur == n) {
		c = 0; // 清空ans2
		solve2(0); // 从第0行开始搜索黑皇后
		ans += c;
		// cout << "solve1" << endl;
		// for(int i = 0; i < n; i++) {
		// 	for(int j = 0; j < n; j++) {
		// 		cout << a[i][j] << ' ';
		// 	}
		// 	cout << endl;
		// }
		// cout << "solve1 end" << endl;
		return;
	}
	for(int j = 0; j < n; j++) {
		if(a[cur][j] && !res1[0][j] && !res1[1][cur+j] && !res1[2][n+cur-j]) {
			a[cur][j] = 0;
			res1[0][j] = 1; res1[1][cur+j] = 1; res1[2][n+cur-j] = 1;
			solve1(cur+1);
			a[cur][j] = 1;
			res1[0][j] = 0; res1[1][cur+j] = 0; res1[2][n+cur-j] = 0;
		}
	}
	return;
}

int main() {
	while(cin >> n) {
		ans = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		solve1(0);
		printf("%d\n", ans);
		
	}
	return 0;
}