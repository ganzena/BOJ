import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	static String file = "src/input.txt";
	static int row, col;
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileInputStream fis = new FileInputStream(file);
		System.setIn(fis);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[]  str = br.readLine().split(" ");
	}

}
