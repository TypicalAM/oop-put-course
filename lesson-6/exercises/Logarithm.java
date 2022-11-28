
public class Logarithm implements Number {
	private double base, argument;

	// Get the double value of the logarithm
	@Override
	public double doubleValue() {
		if (this.base <= 0) {
			throw new ArithmeticException(String.format("The base is less or equal to 0: %f", this.base));
		} else if (this.base == 1) {
			throw new ArithmeticException("The base is equal to one");
		} else if (this.argument <= 0) {
			throw new ArithmeticException(String.format("The argument is less or equal to 0: %f", this.argument));
		}
		return Math.log(this.argument) / Math.log(this.base);
	}

	// The logarithm constructor
	public Logarithm(double inputBase, double inputArgument) {
		this.base = inputBase;
		this.argument = inputArgument;
	}
}