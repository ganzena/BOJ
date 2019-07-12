import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class DragonCurve {
	int x; // 시작점
	int y; // 시작점
	int d; // 시작 방향
	int g; // 세대

	public DragonCurve() {
	}

	public DragonCurve(int x, int y, int d, int g) {
		super();
		this.x = x;
		this.y = y;
		this.d = d;
		this.g = g;
	}
}

public class Main {
	int[][] map = new int[101][101];
	int[] dirX = new int[] { 1, 0, -1, 0 };
	int[] dirY = new int[] { 0, -1, 0, 1 };
	int dcNum;
	int count = 0;
	List<DragonCurve> dcList = new ArrayList<DragonCurve>();

	public static void main(String[] args) {
		Main test = new Main();
		test.init();
		test.draw();
		test.count();
	}

	public void count() {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				if (map[i][j] == 1) {
					if (map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
						count++;
					}
				}
			}
		}

		System.out.println(count);
	}

	public void draw() {
		for (DragonCurve dc : dcList) {
			List<Integer> dirHist = new ArrayList<Integer>();
			dirHist.add(dc.d);
			while (dc.g > 0) {
				for (int i = dirHist.size() - 1; i >= 0; i--) {
					dirHist.add((dirHist.get(i) + 1) % 4);
				}
				dc.g--;
			}
			map[dc.y][dc.x] = 1;
			for (int i = 0; i < dirHist.size(); i++) {
				dc.x += dirX[dirHist.get(i)];
				dc.y += dirY[dirHist.get(i)];
				if (dc.x >= 0 && dc.x < 101 && dc.y >= 0 && dc.y < 101)
					map[dc.y][dc.x] = 1;
			}
		}
	}

	public void init() {
		Scanner sc = new Scanner(System.in);
		dcNum = sc.nextInt();
		for (int i = 0; i < dcNum; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			int d = sc.nextInt();
			int g = sc.nextInt();
			dcList.add(new DragonCurve(x, y, d, g));
		}
		sc.close();
	}
}