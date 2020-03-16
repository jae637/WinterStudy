#include<iostream>

using namespace std;
int N,cnt=0;
int arr[101];
//-1:사이클에 들어가지 않는 노드, 0:방문한적 없는 노드, 1:현재 DFS로직을 통해 방문하는지 확인, 2:싸이클에 포함되어있는 노드
int ans[101] = { 0, };

void check(int index) {
	if (ans[index]==1) {
		cnt++;
		ans[index] = 2;
		check(arr[index]);
	}
}

void DFS(int index) {
	//해당 조건 (사이클을 찾았을때)
	if (ans[index]==1) {
		check(index);
	}
	//한번도 방문하지 않았던 노드 탐색
	else if (ans[index]==0){
		//방문처리
		ans[index] = 1;
		//DFS
		DFS(arr[index]);
		//방문처리 해제
		//싸이클에 포함 안된 노드라면 제외
		if (ans[index] != 2)
			ans[index] = -1;
	}
	//방문 된 노드 일 경우
	else {
		return;
	}
}

int main() {
	cin >> N;
	cnt = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	};
	for (int i = 1; i <= N; i++) {
		if(ans[i]==0)
			DFS(i);
	}
	cout << cnt << endl;

	for (int i = 1; i <= N; i++) {
		if (ans[i]==2)
			cout << i << endl;
	}
}