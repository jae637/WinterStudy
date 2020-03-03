#include<iostream>
#include<algorithm>

using namespace std;

int M;

class Aer {
public:
	int index;
	int* score;
	int total;
	int count;
	Aer(int __index, int* __score, int __count) {
		index = __index;
		score = __score;
		total = 0;
		count = __count;
	};
	Aer(Aer *me) {
		index = me->index;
		score = me->score;
		total = me->total;
		count = me->count;
	}
	Aer() {}
};

Aer **aer;
Aer **tmp;

bool comp(Aer *a, Aer* b) {
	if (a->total == b->total) {
		if (a->count == b->count) {
			if (a->index > b->index) {
				return true;
			}
		}
		else if (a->count < b->count) {
			return true;
		}
	}
	else if (a->total < b->total) {
		return true;
	}
	return false;
}

void merge(Aer** aer, int l, int r,int end) {
	int i = l;
	int li = l;
	int ri = r;
	while (li != r && ri != end+1) {
		if (comp(aer[li], aer[ri])) {
			tmp[l++] = new Aer(aer[ri++]);
		}
		else {
			tmp[l++] = new Aer(aer[li++]);
		}
	}
	while (li != r) {
		tmp[l++] = new Aer(aer[li++]);
	}
	while (ri != end + 1) {
		tmp[l++] = new Aer(aer[ri++]);
	}
	for (; i <= end; i++) {
		aer[i] = new Aer(tmp[i]);
	}
}
void mergeSort(Aer** aer, int start, int end) {
	if (start != end) {
		int mid = (start + end) / 2;
		mergeSort(aer, start, mid);
		mergeSort(aer, mid+1, end);
		merge(aer, start, mid+1,end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N, P;
		cin >> N >> M >> P;
		int *scoreChart = new int[M];
		for (int i = 0; i < M; i++) {
			scoreChart[i] = 0;
		}
		aer = new Aer*[N];
		tmp = new Aer*[N];
		for (int i = 0; i < N; i++) {
			int* arr = new int[M];
			int count = 0;
			for (int j = 0; j < M; j++) {
				cin >> arr[j];
				if (arr[j] == 0) {
					scoreChart[j]++;
				}
				else {
					count++;
				}
			}
			aer[i] = new Aer(i + 1, arr, count);
			tmp[i] = new Aer();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				aer[i]->total += aer[i]->score[j] * scoreChart[j];
			}
		}

		mergeSort(aer, 0, N - 1);
		for (int i = 0; i < N; i++) {
			if (aer[i]->index == P) {
				cout << "#" << tc << " " << aer[i]->total << " " << i + 1 << '\n';
				break;
			}
		}
	}
}