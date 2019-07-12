import java.util.Scanner;

public class Main {
	int[][] map = new int[50][50]; // 0 empty 1 wall 2 cleaned
	// direction 0 North / 1 East / 2 South / 3 West
	int[] dirR = new int[] { -1, 0, 1, 0 };
	int[] dirC = new int[] { 0, 1, 0, -1 };
	int n, m;
	Robot robot = new Robot();

	public static void main(String[] args) {
		Main test = new Main();
		test.init();
		test.clean();
		test.count();
	}

	public void init() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		robot.r = sc.nextInt();
		robot.c = sc.nextInt();
		robot.dir = sc.nextInt();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = sc.nextInt();
			}
		}
		
		sc.close();
	}

	public void clean() {
		int rotateCount = 0;
		map[robot.r][robot.c] = 2;
		while (true) {
			int curDir = (robot.dir + 3) % 4;
			if (map[robot.r + dirR[curDir]][robot.c + dirC[curDir]] == 1
					|| map[robot.r + dirR[curDir]][robot.c + dirC[curDir]] == 2) {
				robot.dir = curDir;
				rotateCount++;
				if (rotateCount > 3) {
					if (map[robot.r - dirR[curDir]][robot.c - dirC[curDir]] == 1) {
						break;
					} else {

						robot.r -= dirR[curDir];
						robot.c -= dirC[curDir];
						map[robot.r][robot.c] = 2;
						rotateCount = 0;
					}
				}

				continue;
			} else {
				robot.dir = curDir;
				robot.r += dirR[curDir];
				robot.c += dirC[curDir];
				map[robot.r][robot.c] = 2;
				rotateCount = 0;
			}
		}
	}

	public void count() {
		int counter = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 2) {
					counter++;
				}
			}
		}
		System.out.println(counter);
	}

	public void print() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				System.out.print(map[i][j] + " ");
			}
			System.out.println();
		}

		System.out.println();
	}

}

class Robot {
	int r; // 2차원 배열에서 i에 해당
	int c; // 2차원 배열에서 j에 해당
	int dir;

	public Robot() {
		super();
	}

	public Robot(int r, int c, int dir) {
		super();
		this.r = r;
		this.c = c;
		this.dir = dir;
	}

	public int getR() {
		return r;
	}

	public void setR(int r) {
		this.r = r;
	}

	public int getC() {
		return c;
	}

	public void setC(int c) {
		this.c = c;
	}

	public int getDir() {
		return dir;
	}

	public void setDir(int dir) {
		this.dir = dir;
	}
}
