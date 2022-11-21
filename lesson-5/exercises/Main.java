
public class Main {

	// Generate a new Euro instance, add and subtract some dollar to achieve
	// economic equilibrium
	public static void main(String[] args) {
		Euro mySpareChange = new Euro(10.0f);
		System.out.println(String.format("Well, I have some money, namely: %s %s (which is abbreviated as %s)",
				mySpareChange.balance(), mySpareChange.symbol(), mySpareChange.abbreviation()));
		
		// Add one Euro but in JPY
		mySpareChange = mySpareChange.addedCurrency(145.12f, "JPY"); 
		System.out.println(String.format("Well, I have some money, namely: %s %s (which is abbreviated as %s)",
				mySpareChange.balance(), mySpareChange.symbol(), mySpareChange.abbreviation()));
		
		// Check if we have any money left after my investments
		mySpareChange = mySpareChange.subtractedCurrency(10.366f, "USD");
		mySpareChange = mySpareChange.subtractedCurrency(0.57063f, "GBP");
		System.out.println(String.format("Well, I have some money, namely: %s %s (which is abbreviated as %s)",
				mySpareChange.balance(), mySpareChange.symbol(), mySpareChange.abbreviation()));
		
		// Just run it into the ground (we should have decreased below 0 Euro here)
		mySpareChange = mySpareChange.subtractedCurrency(10.366f, "USD");
		System.out.println(String.format("Well, I dont have any money, namely: %s %s (which is abbreviated as %s)",
				mySpareChange.balance(), mySpareChange.symbol(), mySpareChange.abbreviation()));
	}

}
