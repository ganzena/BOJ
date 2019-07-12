import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class CCTV {
	int r;
	int c;
	int num;

	public CCTV(int r, int c, int num) {
		super();
		this.r = r;
		this.c = c;
		this.num = num;
	}
}

public class Main {
	int[][] map; // 0 : 빈 칸 1 ~ 5 : CCTV 6 : 벽
	int n, m; // 세로, 가로
	List<CCTV> cctvList = new ArrayList<CCTV>();
	int[] rotateNum = new int[] {0, 4, 2, 4, 4, 1 };
	int[] dirR = new int[] { 0, -1, 0, 1 };
	int[] dirC = new int[] { 1, 0, -1, 0 };
	int counter = 100;

	public static void main(String[] args) {
		Main test = new Main();
		test.init();
		test.DFS(0);
		System.out.println(test.counter);
	}

	void DFS(int depth) {
		if (depth == (cctvList.size())) {
			int temp = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (map[i][j] == 0)
						temp++;
				}
			}
			counter = Math.min(counter, temp);
			return;
		}
		CCTV cctv = cctvList.get(depth);
		int[][] copyMap = new int[n][m];
		for (int dir = 0; dir < rotateNum[cctv.num]; dir++) {
			copyMap = copy(map, copyMap);
//			System.out.println("before");
//			print();
			if (cctv.num == 1) {
				mark(dir, cctv);
			} else if (cctv.num == 2) {
				mark(dir, cctv);
				mark(dir + 2, cctv);
			} else if (cctv.num == 3) {
				mark(dir, cctv);
				mark(dir + 1, cctv);
			} else if (cctv.num == 4) {
				mark(dir, cctv);
				mark(dir + 1, cctv);
				mark(dir + 2, cctv);
			} else if (cctv.num == 5) {
				mark(dir, cctv);
				mark(dir + 1, cctv);
				mark(dir + 2, cctv);
				mark(dir + 3, cctv);
			}
			DFS(depth + 1);
			map = copy(copyMap, map);
		}

	}
	
	int[][] copy(int[][] origin, int[][] target){
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				target[i][j] = origin[i][j];
			}
		}
		return target;
	}

	void mark(int dir, CCTV cctv) {
		dir = dir % 4;
		int r = cctv.r;
		int c = cctv.c;
		while (true) {
			if (r < 0 || r >= n || c < 0 || c >= m || map[r][c] == 6)
				break;
			map[r][c] = 7;
			r += dirR[dir];
			c += dirC[dir];
		}
	}

	void init() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		map = new int[n][m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int input = sc.nextInt();
				map[i][j] = input;
				if (input > 0 && input < 6)
					cctvList.add(new CCTV(i, j, input));
			}
		}
		sc.close();
	}
}
