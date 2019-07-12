import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

class House {
	int r;
	int c;
	int length;

	public House(int r, int c, int length) {
		super();
		this.r = r;
		this.c = c;
		this.length = length;
	}

}

class Chicken {
	int r;
	int c;

	public Chicken(int r, int c) {
		super();
		this.r = r;
		this.c = c;
	}

}

public class Main {

	int[][] map;
	int n, m; // m = 최대 치킨집 갯수
	int minLen = 99999;
	List<House> houseList = new ArrayList<House>();
	List<Chicken> chickenList = new ArrayList<Chicken>();
	List<Chicken> tempList = new ArrayList<Chicken>();
	public static void main(String[] args) {
		Main test = new Main();
		test.init();
		test.dfs(0, 0);
		System.out.println(test.minLen);
	}

	void dfs(int depth, int index) {
		if (depth == m) {
			int sum = 0;
			for(House h : houseList){
				int len = 99999;
				for(Chicken c : tempList){
					len = Math.min(len, Math.abs(h.r - c.r) + Math.abs(h.c - c.c));
				}
				sum += len;
			}
			
			minLen = Math.min(minLen, sum);

			return;
		}
		for (int i = index; i < chickenList.size(); i++) {
			tempList.add(chickenList.get(i));
			dfs(depth + 1, i + 1);
			tempList.remove(tempList.size() - 1);

		}
	}

	void init() {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		map = new int[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j] = sc.nextInt();
				if (map[i][j] == 1)
					houseList.add(new House(i, j, 9999));
				else if (map[i][j] == 2)
					chickenList.add(new Chicken(i, j));
			}
		}
		sc.close();
	}
}
