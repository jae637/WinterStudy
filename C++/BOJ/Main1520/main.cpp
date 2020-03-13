//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//int N, M;
//int map[500][500];
//int dp[500][500];
//int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
//
//bool inbound(int x, int y) {
//	if (x >= 0 && y >= 0 && x < N&&y < M)
//		return true;
//	return false;
//}
//int main() {
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			cin >> map[i][j];
//			dp[i][j] = 0;
//		}
//	}
//	dp[0][0] = 1;
//	queue<int> queuex;
//	queue<int> queuey;
//	queuex.push(0);
//	queuey.push(0);
//	while (!queuex.empty()) {
//		int x = queuex.front();
//		int y = queuey.front();
//		queuex.pop();
//		queuey.pop();
//		for (int i = 0; i < 4; i++) {
//			int tmpx = x + dir[i][0];
//			int tmpy = y + dir[i][1];
//			if (inbound(tmpx, tmpy) && map[x][y] > map[tmpx][tmpy]) {
//				queuex.push(tmpx);
//				queuey.push(tmpy);
//				dp[tmpx][tmpy]++;
//			}
//		}
//	}
//	cout << dp[N-1][M-1];
//}