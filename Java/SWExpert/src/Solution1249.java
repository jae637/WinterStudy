import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Solution1249 {
	public static int[][] map;
	public static int[][] dir= {{1,0},{-1,0},{0,1},{0,-1}};
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int test_case=1;test_case<=T;test_case++) {
			int N=sc.nextInt();
			map=new int[N][N];
			for(int i=0;i<N;i++) {
				String tmp=sc.next();
				for(int j=0;j<N;j++) {
					map[i][j]=tmp.charAt(j)-'0';
				}
			}
			int[][] spanning=new int[N][N];
			for(int[] i :spanning)
				Arrays.fill(i, -1);
			Queue<String> q=new LinkedList<>();
			spanning[0][0]=map[0][0];
			q.offer("0 0");
			while(!q.isEmpty()) {
				String tmp=q.poll();
				int x=Integer.parseInt(tmp.split(" ")[0]);
				int y=Integer.parseInt(tmp.split(" ")[1]);
				for(int i=0;i<4;i++) {
					int tx=x+dir[i][0];
					int ty=y+dir[i][1];
					if(tx>=0&&tx<N&&ty>=0&&ty<N) {
						int result=spanning[x][y]+map[tx][ty];
						if(spanning[tx][ty]==-1) {
							spanning[tx][ty]=result;
							q.offer(tx+" "+ty);
						}else {
							if(spanning[tx][ty]>result) {
								spanning[tx][ty]=result;
								q.offer(tx+" "+ty);
							}
						}
					}
				}
			}
			
			
			
			System.out.println("#"+test_case+" "+spanning[N-1][N-1]);
		}
		sc.close();
	}
}
