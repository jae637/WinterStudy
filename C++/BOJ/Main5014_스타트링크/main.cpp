#include<iostream>
#include<queue>;

using namespace std;
bool visit[1000001];
int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	visit[S] = true;
	int count = 0;
	int ans = -1;
	queue<int> q,tq;
	q.push(S);
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		if (tmp == G) {
			ans = count;
			break;
		}
		int up = tmp + U;
		int down = tmp - D;
		if (up <= F&&!visit[up]) {
			visit[up] = true;
			tq.push(up);
		}
		if (down > 0 && !visit[down]) {
			visit[down] = true;
			tq.push(down);
		}
		if (q.empty()) {
			while (!tq.empty()) {
				q.push(tq.front());
				tq.pop();
			}
			count++;
		}
	}
	if (ans >= 0)
		cout << ans<<endl;
	else
		cout << "use the stairs"<<endl;
}