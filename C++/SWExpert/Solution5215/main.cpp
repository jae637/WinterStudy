#include<iostream>

using namespace std;
int* m;
int* c;
int N, L;
int ans;

void DFS(int index, int max, int manjok, int cal) {
	if (index == max) {
		if (cal <= L&&ans < manjok) {
			ans = manjok;
		}
	}
	else {
		if (cal > L)
			return;
		DFS(index + 1, max, manjok + m[index], cal + c[index]);
		DFS(index +1, max, manjok, cal );
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> L;
		ans = 0;
		m = new int[N];
		c = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> m[i]>>c[i];
		}
		DFS(0, N, 0, 0);
		cout << "#"<<tc<<" "<< ans << endl;
	}
}