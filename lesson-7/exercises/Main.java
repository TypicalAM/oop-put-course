import java.io.FileNotFoundException;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {
		DayOne dayOneFirst = new DayOne("Day01.txt");
		System.out.println(String.format("First task for the 1st day: %d", dayOneFirst.solveFirstTask()));
		DayOne dayOneSecond = new DayOne("Day01.txt");
		System.out.println(String.format("Second task for the 1st day: %d", dayOneSecond.solveSecondTask()));
	}

}
