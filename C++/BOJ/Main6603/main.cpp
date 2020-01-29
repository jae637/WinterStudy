#include<iostream>

using namespace std;
void DFS(int index,int count, int max, int* print,int* arr) {
	if (count == 6) {
		cout << print[0] << " " << print[1] << " " << print[2] << " " << print[3] << " " << print[4] << " " << print[5] << " " << endl;
	}
	else {
		for (int i = index; i < max; i++) {
			print[count] = arr[i];
			DFS(i + 1,count+1, max, print, arr);
		}
	}
}

int main() {
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			break;
		int *arr = new int[N];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		DFS(0,0, N, new int[6] , arr);
		cout << endl;
	}
}