import java.io.FileInputStream;
import java.util.Scanner;

public class Main6603 {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int N = sc.nextInt();
			if(N==0)
				break;
			int arr[] = new int[N];
			for(int i=0;i<N;i++) {
				arr[i]=sc.nextInt();
			}
			DFS(arr, new int[6],0,0);
			System.out.println();
		}

		sc.close();
	}

	private static void DFS(int[] arr,int[] tmp, int c,int start) {
		if(c==6) {
			for (int i : tmp) {
				System.out.print(i+" ");
			}
			System.out.println();
			return;
		}
		for(int i=start;i<arr.length;i++) {
			tmp[c]=arr[i];
			DFS(arr,tmp,c+1,i+1);
		}
	}
}
