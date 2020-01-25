#include<iostream>
#include<queue>

using namespace std;

char** map;
int** spaning;
int ans;
int dir[4][2] = { { 1,0 },{ 0,1 },{ -1,0 },{ 0,-1 } };

//X와 Y가 맵 밖으로 나갔을 경우
bool inbound(int x, int y,int size) {
	if (x >= 0 && y >= 0 && x < size && y < size)
		return true;
	return false;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int C = 0;
		int N;
		cin >> N;
		map = new char*[N];
		spaning = new int*[N];
		for (int i = 0; i < N; i++) {
			spaning[i] = new int[N];
			for (int j = 0; j < N; j++) {
				spaning[i][j] = -1;
			}
		}
		for (int i = 0; i < N; i++) {
			char* tmp = new char[N];
			cin >> tmp;
			map[i] = tmp;
		}
		ans = 20000000;
		spaning[0][0] = 0;
		queue<int*> q;
		q.push(new int[2]{ 0,0 });
		while (!q.empty())
		{
			int *pos = q.front();
			int x = pos[0];
			int y = pos[1];
			q.pop();
			for (int i = 0; i < 4; i++) {
				int tmpx = x + dir[i][0];
				int tmpy = y + dir[i][1];
				if (inbound(tmpx, tmpy,N)) {
					if (spaning[tmpx][tmpy] == -1) {
						spaning[tmpx][tmpy] = spaning[x][y] + map[tmpx][tmpy] - '0';
						q.push(new int[2] {tmpx,tmpy });
					}
					else {
						if (spaning[tmpx][tmpy] > spaning[x][y] + map[tmpx][tmpy] - '0') {
							spaning[tmpx][tmpy] = spaning[x][y] + map[tmpx][tmpy] - '0';
							q.push(new int[2]{ tmpx,tmpy });
						}
					}
				}
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}