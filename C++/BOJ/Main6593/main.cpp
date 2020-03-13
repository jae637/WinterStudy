#include<iostream>
#include<queue>

using namespace std;

char map[30][30][30];
int L, R, C;
int dir[6][3] = { {0,0,1},{0,1,0},{1,0,0},{0,0,-1},{0,-1,0},{-1,0,0} };

bool inbound(int l,int r,int c) {
	if (l >= 0 && r >= 0 && c >= 0 && l < L&&r < R&&c < C)
		return true;
	return false;
}

int main() {
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		int* pos;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				char* tmp = new char[C];
				cin >> tmp;
				for (int k = 0; k < C; k++) {
					map[i][j][k] = tmp[k];
					if (map[i][j][k] == 'S')
						pos = new int[3]{ i,j,k };
				}
			}
		}
		queue<int*> q;
		queue<int*> tq;
		q.push(pos);
		int cnt = 0;
		bool flag = false;
		while (!q.empty()) {
			pos = q.front();
			int l = pos[0];
			int r = pos[1];
			int c = pos[2];
			q.pop();
			if (map[l][r][c] == 'E') {
				flag = true;
				break;
			}
			for (int i = 0; i < 6; i++) {
				int tmpl = l + dir[i][0];
				int tmpr = r + dir[i][1];
				int tmpc = c + dir[i][2];
				if (inbound(tmpl, tmpr, tmpc) && (map[tmpl][tmpr][tmpc] == '.' || map[tmpl][tmpr][tmpc] == 'E')) {
					if (map[tmpl][tmpr][tmpc] != 'E')
						map[tmpl][tmpr][tmpc] = 'S';
					tq.push(new int[3]{ tmpl,tmpr,tmpc });
				}
			}
			if (q.empty()) {
				while (!tq.empty()) {
					q.push(tq.front());
					tq.pop();
				}
				cnt++;
			}
			delete pos;
		}
		if (flag)
			cout << "Escaped in " << cnt << " minute(s)."<<endl;
		else
			cout << "Trapped!"<<endl;
	}
}