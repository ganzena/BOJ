import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static String INPUT = "src/input.txt";
	static FileInputStream fis;
	static BufferedReader br;
	static int total;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		inputInit();
		countCoin();

	}

	public static void inputInit() throws IOException {
//		fis = new FileInputStream(INPUT);
//		System.setIn(fis);
		br = new BufferedReader(new InputStreamReader(System.in));
		total = 1000 - Integer.parseInt(br.readLine());
	}

	public static void countCoin() {
		int count = 0;
		int [] coinArray = {500, 100, 50, 10, 5, 1};
		for(int i = 0 ; i < coinArray.length ; i++){
			count += total / coinArray[i];
			total %= coinArray[i];
		}
		
		System.out.println(count);
	}

}
