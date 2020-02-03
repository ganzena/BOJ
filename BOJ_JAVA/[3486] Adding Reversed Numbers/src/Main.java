import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	private final static String INPUT = "src/input.txt";
	static FileInputStream fis;
	static BufferedReader br;

	public static void main(String[] args) throws IOException {

		input();

		int n = Integer.parseInt(br.readLine());

		for (int i = 0; i < n; i++) {

			int sum = 0;
			String a, b;
			String[] line = br.readLine().split(" ");
			a = line[0];
			b = line[1];

			a = new StringBuffer(a).reverse().toString();
			b = new StringBuffer(b).reverse().toString();
			sum = Integer.parseInt(a) + Integer.parseInt(b);
			String str = Integer.toString(sum);
			str = new StringBuffer(str).reverse().toString();
			sum = Integer.parseInt(str);
			System.out.println(sum);
		}

	}

	public static void input() throws IOException {
		fis = new FileInputStream(INPUT);
		System.setIn(fis);
		br = new BufferedReader(new InputStreamReader(System.in));
	}
}