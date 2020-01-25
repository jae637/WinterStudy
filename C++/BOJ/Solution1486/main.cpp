#include<iostream>
using namespace std;

int ans, K;

void DFS(int index, int sum, int* arr, int size) {
	if (index == size) {
		if (K <= sum&&ans > sum)
			ans = sum;
	}
	else {
		DFS(index + 1, sum + arr[index], arr, size);
		DFS(index + 1, sum, arr, size);
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int P;
		cin >> P >> K;
		int* arr = new int[P];
		for (int i = 0; i < P; i++) {
			cin >> arr[i];
		}
		ans = 2000000;
		DFS(0, 0, arr, P);
		printf("#%d %d\n", tc, ans - K);
	}
}