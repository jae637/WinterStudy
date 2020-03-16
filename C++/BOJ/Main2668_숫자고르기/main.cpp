#include<iostream>

using namespace std;
int N,cnt=0;
int arr[101];
//-1:����Ŭ�� ���� �ʴ� ���, 0:�湮���� ���� ���, 1:���� DFS������ ���� �湮�ϴ��� Ȯ��, 2:����Ŭ�� ���ԵǾ��ִ� ���
int ans[101] = { 0, };

void check(int index) {
	if (ans[index]==1) {
		cnt++;
		ans[index] = 2;
		check(arr[index]);
	}
}

void DFS(int index) {
	//�ش� ���� (����Ŭ�� ã������)
	if (ans[index]==1) {
		check(index);
	}
	//�ѹ��� �湮���� �ʾҴ� ��� Ž��
	else if (ans[index]==0){
		//�湮ó��
		ans[index] = 1;
		//DFS
		DFS(arr[index]);
		//�湮ó�� ����
		//����Ŭ�� ���� �ȵ� ����� ����
		if (ans[index] != 2)
			ans[index] = -1;
	}
	//�湮 �� ��� �� ���
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