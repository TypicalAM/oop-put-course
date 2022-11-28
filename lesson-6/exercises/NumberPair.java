
public class NumberPair {
	private int a;
	private int b;

	// Returns the maximum number of the two provided, returns the former if they
	// are equal
	public int max() {
		return this.a > this.b ? this.a : this.b;
	}

	// Returns the minimal value of the two provided, returns the latter if they are
	// equal
	public int min() {
		return this.a < this.b ? this.a : this.b;
	}

	// Returns the average value of the two provided
	public int avg() {
		return (this.a + this.b) / 2;
	}

	// Create the pair of numbers
	public NumberPair(int a, int b) {
		this.a = a;
		this.b = b;
	}
}
