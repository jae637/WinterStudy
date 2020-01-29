import java.io.FileInputStream;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Solution1226 {
	public static int Answer;
								// 상하좌우
	public static int dir[][] = {{-1,0},{1,0},{0,-1},{0,1}};

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		for (int test_case = 0; test_case < 10; test_case++) {
			int T = sc.nextInt();
			char[][] ca = new char[16][16];
			int strx=0, stry=0;
			Stack<Integer[]> stack = new Stack<>();
			for (int i = 0; i < 16; i++) {
				ca[i] = sc.next().toCharArray();
				for (int j = 0; j < 16; j++) {
					if (ca[i][j] == '2') {
						strx = i;
						stry = j;
					}
				}
			}
			Integer[] arr= {strx,stry};
			stack.push(arr);
			Answer = solve(stack,ca);

			System.out.println("#" + (test_case + 1) + " " + Answer);
		}
		sc.close();
	}
	
	public static int solve(Stack<Integer[]> stack,char[][] ca) {
		if (stack.size()==0)
			return 0;
		else {
			Integer[] point = stack.pop();
			for(int i=0;i<4;i++) {
				int x= point[0]+dir[i][0];
				int y= point[1]+dir[i][1];
				if(0<=x&&x<ca.length&&0<=y&&y<ca[i].length) {
					if(ca[x][y]=='3') {
						return 1;
					}else if(ca[x][y]!='1') {
						Integer[] tmp = {x,y};
						stack.push(tmp);
						ca[x][y]='2';
					}
				}
			}
			return solve(stack,ca);
		}
	}
}
