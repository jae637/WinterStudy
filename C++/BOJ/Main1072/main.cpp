#include<iostream>
#include<cmath>

using namespace std;
int main() {
	long long N, M;
	cin >> N >> M;
	int K = (double)M *100/ (double)N;
	long long min = 0;
	long long max = 1000000000;
	while (min != max) {
		long long mid = (min + max)/2;
		long long n = N + mid;
		long long m = M + mid;
		int k = (m*100) / double(n);
		if (k == K) {
			min = mid+1;
		}
		else {
			max = mid;
		}
	}
	long long n = N + min;
	long long m = M + min;
	double k = (double)m*100 / double(n);
	if ((int)k ==(int) K||N==0) {
		cout << "-1";
	}
	else {
		cout << min <<endl;
	}
}