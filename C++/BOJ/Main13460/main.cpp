#include<iostream>
#include<queue>

using namespace std;
int N=0, M=0;
char** map;
//이 판에서 나올수 잇는 모든 좌표값들(주소)
bool visit[10000];
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int main() {
	cin >> N >> M;
	map = new char*[N];
	for (int i = 0; i < N; i++)
		map[i] = new char[M];
	//첫 좌표 빨강파랑, 세로가로 순
	int pos=0;
	for (int i = 0; i < N; i++) {
		char* str= new char[M];
		cin >> str;
		for (int j = 0; j < M; j++) {
			if (str[j] == 'R') {
				pos += i * 1000 + j * 100;
				map[i][j] = '.';
			}
			else if (str[j] == 'B') {
				pos += i * 10 + j;
				map[i][j] = '.';
			}else
				map[i][j] = str[j];
		}
	}
	//입력 끝

	queue<int> q,tq;
	q.push(pos);
	int ans = 1;
	bool succse = false;
	//BFS 시작
	while (!q.empty()&&ans<=10) {
		int p = q.front();
		q.pop();
		visit[p] = true;
		int rx = p / 1000;
		int ry = (p / 100)%10;
		int bx = (p / 10) %10;
		int by = p % 10;
		for (int i = 0; i < 4; i++) {
			int rc = 0;
			int bc = 0;
			int tmprx = rx;
			int tmpry = ry;
			int tmpbx = bx;
			int tmpby = by;
			bool fall = false;
			//더이상 안움직일 경우
			while (rc < 2 || bc < 2) {
				tmprx += dir[i][0];
				tmpry += dir[i][1];
				tmpbx += dir[i][0];
				tmpby += dir[i][1];
				//파랑이 도착할 경우
				if (map[tmpbx][tmpby] == 'O') {
					fall = true;
					succse = false;
					break;
				}
				//빨강이 도착할 경우
				if (map[tmprx][tmpry] == 'O') {
					succse = true;
				}
				//빨강이 벽에 박을 경우 원상복구
				if (map[tmprx][tmpry] == '#') {
					rc = 2;
					tmprx -= dir[i][0];
					tmpry -= dir[i][1];
				}
				//파랑이 벽에 박을 경우 원상복구
				if (map[tmpbx][tmpby] == '#') {
					bc = 2;
					tmpbx -= dir[i][0];
					tmpby -= dir[i][1];
				}
				//파랑빨강벽 또는 빨강파랑벽 경우 원상복구
				if (tmpbx == tmprx&&tmpby == tmpry) {
					if (bc != 2) {
						tmpbx -= dir[i][0];
						tmpby -= dir[i][1];
						bc = 2;
					}
					else {
						tmprx -= dir[i][0];
						tmpry -= dir[i][1];
						rc = 2;
					}
				}
			}
			//정상적으로 도착에 경우 두번의 반복문을 나와야 함
			if (succse) {
				break;
			}
			//방문 한 후의 위치를 해싱함
			int hash = tmprx * 1000 + tmpry * 100 + tmpbx * 10 + tmpby;
			//해싱된 주소에 값이 없거나 파랑이 들어가지 않은 경우에만 큐에 넣음
			if (!visit[hash]&&!fall) {
				visit[hash] = true;
				tq.push(hash);
			}	
		}
		if (succse)
			break;
		//턴 증가
		if (q.empty()) {
			q.swap(tq);
			ans++;
		}
	}
	if (!succse)
		ans = -1;
	cout << ans;
}