#include<iostream>
#include<queue>

using namespace std;
int **map;
int N,ans=987654321;
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

bool inbound(int x, int y) {
	if (x >= 0 && y >= 0 && x < N&&y < N)
		return true;
	return false;
}

void partition(int x, int y, int part) {
	if (map[x][y] == 1) {
		map[x][y] = part;
		for (int i = 0; i < 4; i++) {
			int tmpx = x + dir[i][0];
			int tmpy = y + dir[i][1];
			if (inbound(tmpx, tmpy) && map[tmpx][tmpy]==1) {
				partition(tmpx, tmpy, part);
			}
		}
	}
}
void BFS(int x, int y, int count,int part) {
	queue<int*> q,tq;
	bool visit[100][100] = { false };
	q.push(new int[2] { x,y });
	while (!q.empty()) {
		int* pos = q.front();
		q.pop();
		visit[pos[0]][pos[1]] = true;
		if (map[pos[0]][pos[1]] != 0 && map[pos[0]][pos[1]] != part) {
			if(ans>=count)
				ans = count - 1;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int tmpx = pos[0] + dir[i][0];
			int tmpy = pos[1] + dir[i][1];
			if (inbound(tmpx, tmpy) && map[tmpx][tmpy] != part&&!visit[tmpx][tmpy]) {
				visit[tmpx][tmpy] = true;
				tq.push(new int[2] { tmpx,tmpy });
			}
		}
		if (q.empty()) {
			while (!tq.empty()) {
				q.push(tq.front());
				tq.pop();
			}
			count++;
		}
	}
}
int main() {
	cin >> N;
	map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int part = 2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				partition(i, j, part++);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) {
				BFS(i, j, 0, map[i][j]);
			}
		}
	}
	cout << ans;
	//for (int i = 0; i < 100; i++) {
	//	for (int j = 0; j < 100; j++) {
	//		if (i == 0 && j == 0)
	//			cout << "1 ";
	//		else if (i == 49 && j == 49)
	//			cout << "1 ";
	//		else
	//			cout << "0 ";
	//	}
	//	cout << endl;
	//}
}