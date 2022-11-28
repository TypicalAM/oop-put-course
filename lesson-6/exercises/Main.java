
public class Main {

	public static void main(String[] args) {
		// `Number` refactor
		
		// Return the biggest number
		System.out.println(new NumberPair(3,5).max());
		// Return the latter number
		System.out.println(new NumberPair(3,3).min());
		// Get the average
		System.out.println(new NumberPair(10,20).avg());
		System.out.println(new NumberPair(-5,5).avg());
		
		// `Logarithm` refactor
		
		// Return log of 5 and 3
		System.out.println(new Logarithm(5,3).doubleValue());
		
		// Negative argument
		try {
			System.out.println(new Logarithm(5,-1).doubleValue());
		} catch (ArithmeticException err) {
			System.out.println(String.format("Caught error - %s", err));
		}
		
		// Negative base
		try {
			System.out.println(new Logarithm(-1,5).doubleValue());
		} catch (ArithmeticException err) {
			System.out.println(String.format("Caught error - %s", err));
		}
		
		// Base equal to one
		try {
			System.out.println(new Logarithm(1,100).doubleValue());
		} catch (ArithmeticException err) {
			System.out.println(String.format("Caught error - %s", err));
		}
	}

}
