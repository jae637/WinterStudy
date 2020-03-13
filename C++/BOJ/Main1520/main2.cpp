#include<iostream>
#include<queue>

using namespace std;

int N, M;
int cnt;
int map[500][500];
int dp[500][500];
int dir[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

bool inbound(int x, int y) {
	if (x >= 0 && y >= 0 && x < N&&y < M)
		return true;
	return false;
}
void DFS(int x, int y) {
	if (x == N - 1 && y == M - 1) {
		dp[x][y]++;
	}else {
		for (int i = 0; i < 4; i++) {
			int tmpx = x + dir[i][0];
			int tmpy = y + dir[i][1];
			if (inbound(tmpx, tmpy) && map[tmpx][tmpy]<map[x][y]) {
				if (dp[tmpx][tmpy]==-1){
					dp[tmpx][tmpy] = 0;
					DFS(tmpx, tmpy);
				}
				dp[x][y] += dp[tmpx][tmpy];
			}
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;
	DFS(0, 0);
	cout << dp[0][0];
}