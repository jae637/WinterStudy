#include<iostream>

using namespace std;

bool judge[100001];
bool c[100001];
bool visit[100001] = { false, };
int arr[100001];

void check(int* arr, int idx) {
	if (!judge[idx]) {
		judge[idx] = true;
		check(arr, arr[idx]);
	}
}

void DFS(int* arr, int idx,int start) {
	if (!visit[idx]) {
		visit[idx] = true;
		c[idx] = true;
		DFS(arr, arr[idx],start);
		c[idx] = false;
	}
	else {
		if(c[idx])
			check(arr, idx);
	}
}
int main() {
	int T, N;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		judge[0] = true;
		for (int i = 1; i <= N; i++) {
			cin >> arr[i];	
			judge[i] = false;
			visit[i] = false;
			c[i] = false;
		}

		int count = 0;
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				DFS(arr, i,i);
			}
		}
		for (int i = 1; i <= N; i++) {
			if (!judge[i])
				count++;
		}
		cout << count << endl;
	}
}