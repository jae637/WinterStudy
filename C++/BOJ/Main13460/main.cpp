#include<iostream>
#include<queue>

using namespace std;
int N=0, M=0;
char** map;
//�� �ǿ��� ���ü� �մ� ��� ��ǥ����(�ּ�)
bool visit[10000];
int dir[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };

int main() {
	cin >> N >> M;
	map = new char*[N];
	for (int i = 0; i < N; i++)
		map[i] = new char[M];
	//ù ��ǥ �����Ķ�, ���ΰ��� ��
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
	//�Է� ��

	queue<int> q,tq;
	q.push(pos);
	int ans = 1;
	bool succse = false;
	//BFS ����
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
			//���̻� �ȿ����� ���
			while (rc < 2 || bc < 2) {
				tmprx += dir[i][0];
				tmpry += dir[i][1];
				tmpbx += dir[i][0];
				tmpby += dir[i][1];
				//�Ķ��� ������ ���
				if (map[tmpbx][tmpby] == 'O') {
					fall = true;
					succse = false;
					break;
				}
				//������ ������ ���
				if (map[tmprx][tmpry] == 'O') {
					succse = true;
				}
				//������ ���� ���� ��� ���󺹱�
				if (map[tmprx][tmpry] == '#') {
					rc = 2;
					tmprx -= dir[i][0];
					tmpry -= dir[i][1];
				}
				//�Ķ��� ���� ���� ��� ���󺹱�
				if (map[tmpbx][tmpby] == '#') {
					bc = 2;
					tmpbx -= dir[i][0];
					tmpby -= dir[i][1];
				}
				//�Ķ������� �Ǵ� �����Ķ��� ��� ���󺹱�
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
			//���������� ������ ��� �ι��� �ݺ����� ���;� ��
			if (succse) {
				break;
			}
			//�湮 �� ���� ��ġ�� �ؽ���
			int hash = tmprx * 1000 + tmpry * 100 + tmpbx * 10 + tmpby;
			//�ؽ̵� �ּҿ� ���� ���ų� �Ķ��� ���� ���� ��쿡�� ť�� ����
			if (!visit[hash]&&!fall) {
				visit[hash] = true;
				tq.push(hash);
			}	
		}
		if (succse)
			break;
		//�� ����
		if (q.empty()) {
			q.swap(tq);
			ans++;
		}
	}
	if (!succse)
		ans = -1;
	cout << ans;
}