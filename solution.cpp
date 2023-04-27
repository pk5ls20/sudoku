#include<iostream>
using namespace std;
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<string>
const int N = 2e6 + 5;
typedef long long ll;
typedef pair<ll, ll> PII;
typedef double db;
int a[11][11];
bool hang[11][11];//行，数字
bool lie[11][11];//列，数字
bool kuai[11][11];//块，数字
int xy_id[11][11] = {
	{0,0,0,1,1,1,2,2,2},
	{0,0,0,1,1,1,2,2,2},
	{0,0,0,1,1,1,2,2,2},
	{3,3,3,4,4,4,5,5,5},
	{3,3,3,4,4,4,5,5,5},
	{3,3,3,4,4,4,5,5,5},
	{6,6,6,7,7,7,8,8,8},
	{6,6,6,7,7,7,8,8,8},
	{6,6,6,7,7,7,8,8,8},
};
void print() {
	cout << "++++++++++++++" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void dfs(int x, int y) {
	if (x == 9) {
		print();
		exit(0);
		return;//成功
	}
	if (y == 9) {
		dfs(x + 1, 0);//换行
		return;
	}
	if (a[x][y]) {//有的话就是下一个
		dfs(x, y + 1);
		return;
	}
	int id = xy_id[x][y];
	for (int k = 1; k <= 9; k++) {//抉择这个位置填什么数字
		if (hang[x][k] || lie[y][k]||kuai[id][k])continue;//不可以填
		a[x][y] = k;
		hang[x][k] = 1;
		lie[y][k] = 1;
		kuai[id][k] = 1;
		dfs(x, y + 1);
		a[x][y] = 0;
		hang[x][k] = 0;
		lie[y][k] = 0;
		kuai[id][k] = 0;
	}
	return;
}
int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> a[i][j];
			if (a[i][j] != 0) {
				hang[i][a[i][j]] = 1;//第i行的a[i][j]被用了
				lie[j][a[i][j]] = 1;//第j列的a[i][j]被用了
				int id = xy_id[i][j];
				kuai[id][a[i][j]] = 1;//第id块的a[i][j]被用了
			}
		}
	}
	dfs(0, 0);
}
