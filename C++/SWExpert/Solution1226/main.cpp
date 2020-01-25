#include<iostream>

using namespace std;

char** map;
bool flag;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

//X와 Y가 맵 밖으로 나갔을 경우
bool inbound(int x, int y) {
	if (x >= 0 && y >= 0 && x < 16 && y < 16)
		return true;
	return false;
}

void DFS(int x, int y) {
	//방문 처리
	map[x][y] = 1;
	if (map[x][y] != '1') {
		//변화
		for (int i = 0; i < 4; i++) {
			int tmpx = x + dir[i][0];
			int tmpy = y + dir[i][1];
			if (inbound(tmpx, tmpy)){
				//호출과 변화 해제
				if (map[tmpx][tmpy] == '0') {
					DFS(tmpx, tmpy);
				}
				//해당 조건 찾앚을 경우
				else if (map[tmpx][tmpy] == '3') {
					flag = true;
				}
			}
		}
	}
	//방문 처리 해제
	map[x][y] = 0;
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int C = 0;
		int N;
		cin >> N;
		map = new char*[16];
		for (int i = 0; i < 16; i++) {
			map[i] = new char[16];
		}
		int startx=0, starty=0;
		for (int i = 0; i < 16; i++) {
			char* tmp =new char[16];
			cin >> tmp;
			for (int j = 0; j < 16; j++) {
				map[i][j] = tmp[j];
				if (map[i][j] == '2') {
					startx = i;
					starty = j;
				}
			}
		}
		flag = false;
		DFS(startx, starty);
		if (flag)
			C = 1;
		else
			C = 0;
		cout << "#" << tc << " " << C<<"\n";

	}
}