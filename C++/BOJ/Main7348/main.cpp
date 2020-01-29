#include<iostream>

using namespace std;
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int arr[200] = { 0 };
		int max = 0;
		for (int j = 0; j < N; j++) {
			int first, second;
			cin >> first >> second;
			first--;
			second--;
			if (second < first) {
				int tmp = first;
				first = second;
				second = tmp;
			}
			for (int k = first / 2; k <= second / 2; k++) {
				arr[k] += 10;
			}
		}
		for (int j = 0; j < 200; j++) {
			if (max < arr[j])
				max = arr[j];
		}
		cout << max << endl;
	}
}