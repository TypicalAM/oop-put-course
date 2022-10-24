package exercises;

public class Exercises {
	public static void main(String[] args) {
		WashingMachine beko = new WashingMachine("beko");
		beko.MakeSound();
		
		WashingMachine tester = new WashingMachine("fnaf5machine", 1987);
		tester.MakeSound();
		tester.Upgrader();
		tester.MakeSound();

		CreditCard myCard = new CreditCard(710, 49196213, "09/2026");
		CreditCard myStolenCard = new CreditCard(123, 2137, "");

		RfidScanner rfid = new RfidScanner();
		RfidScanner rfidCoolBeeper = new RfidScanner("BEEEEEEEEEEEEEEEEEEEEEEEEEEP");

		rfid.Approach(myCard);
		rfidCoolBeeper.Approach(myStolenCard);

		if (rfid.CardDemagnetizer(myStolenCard)) {
			System.out.println(
					String.format("Well, this is unfortunate, my expiry date is now %s", myStolenCard.expiredateStr));
		}
	}
}
