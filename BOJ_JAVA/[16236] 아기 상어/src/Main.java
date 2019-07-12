import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.math.*;

class Shark {
	int i; // row
	int j; // col
	int size;
	int exp;
	int time;

	public Shark(int i, int j, int size, int exp, int time) {
		super();
		this.i = i;
		this.j = j;
		this.size = size;
		this.exp = exp;
		this.time = time;
	}

}

public class Main {
	int time = 0;
	int n;
	int[][] map;
	int[] dirI = { 0, -1, 0, 1 };
	int[] dirJ = { 1, 0, -1, 0 };
	Shark shark;

	public static void main(String[] args) {
		Main test = new Main();
		test.init();

	}

	public void BFS() {
		Queue<Shark> q = new LinkedList<Shark>();
		q.add(shark);
		boolean [][] visited = new boolean[n][n];
		while(!q.isEmpty()){
			Shark nowShark = q.peek();
			q.poll();
			int curI = nowShark.i;
			int curJ = nowShark.j;
			visited[curI][curJ] = true;
			for(int i = 0 ; i < 4 ; i++){
				int nextI = curI + dirI[i];
				int nextJ = curJ + dirJ[i];
				if(nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= n)
					continue;
				if(visited[nextI][nextJ] == false && map[nextI][nextJ] <= nowShark.size){
					visited[nextI][nextJ] = true;
					Shark nextShark = nowShark;
					next
				}
			}
		}
	}
	

	public void init() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		map = new int[n][n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = sc.nextInt();
				if (map[i][j] == 9){
					shark = new Shark(i, j, 2, 2, 0);
					map[i][j] = 0;
				}
			}
		}

		sc.close();
	}
}
