import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DayOne {

	private Scanner scanner;

	public DayOne(String filename) throws FileNotFoundException {
		this.scanner = new Scanner(new File(filename));
	}

	public int solveFirstTask() {
		int max = 0, batch = 0, mealCalorie = 0;
		Boolean inBatch = true;

		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			if (line.equals("")) {
				if (inBatch) {
					inBatch = false;
					if (batch > max) {
						max = batch;
					}
				}
			} else {
				mealCalorie = Integer.valueOf(line);
				if (inBatch) {
					batch += mealCalorie;
				} else {
					batch = mealCalorie;
					inBatch = true;
				}
			}
		}
		return max;
	}

	public int solveSecondTask() {
		int top1 = 0, top2 = 0, top3 = 0, batch = 0, mealCalorie = 0;
		Boolean inBatch = true;

		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			if (line.equals("")) {
				if (inBatch) {
					inBatch = false;
					if (batch > top3) {
						if (batch > top2) {
							if (batch > top1) {
								top3 = top2;
								top2 = top1;
								top1 = batch;
							} else {
								top3 = top2;
								top2 = batch;
							}
						} else {
							top3 = batch;
						}
					}
				}
			} else {
				mealCalorie = Integer.valueOf(line);
				if (inBatch) {
					batch += mealCalorie;
				} else {
					batch = mealCalorie;
					inBatch = true;
				}
			}
		}
		return top1+top2+top3;
	}
}
