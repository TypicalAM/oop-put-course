
public class Logarithm implements Number {
	private double base, argument;

	// Get the double value of the logarithm
	@Override
	public double doubleValue() {
		return Math.log(this.argument) / Math.log(this.base);
	}

	// The logarithm constructor
	public Logarithm(double inputBase, double inputArgument) {
		if (inputBase <= 0) {
			throw new ArithmeticException(String.format("The base is less or equal to 0: %f", this.base));
		} else if (inputBase == 1) {
			throw new ArithmeticException("The base is equal to one");
		} else if (inputArgument <= 0) {
			throw new ArithmeticException(String.format("The argument is less or equal to 0: %f", this.argument));
		}
		this.base = inputBase;
		this.argument = inputArgument;
	}
}